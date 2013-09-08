#include "TablesContainer.h"


TablesContainer::~TablesContainer()
{

    //delete model;

}


TablesContainer::TablesContainer(QDateTime mondayDate,EventManager* dispenser_ ,QWidget* parent): QWidget(parent)
{
  
  
    this->dispenser = dispenser_;
    model = new WeekModel(mondayDate,dispenser,this);
 

      buildInterface();
    
      updateView();
      setupConnections();
      
      

    
}

void TablesContainer::buildInterface()
{
  
  
  
  
  
  next = new QAction(&toolbar);
  previous = new QAction(&toolbar);
  


  toolbar.setWindowTitle("Weekly View");
  toolbar.addAction(previous);
  toolbar.insertSeparator(next);
  toolbar.addWidget(&label);
  toolbar.addAction(next);
  
  previous->setIcon(QIcon::fromTheme("go-previous"));
  next->setIcon((QIcon::fromTheme("go-next")));
      
  textEdit.setReadOnly(true);
  QSizePolicy policy;
 // policy.setVerticalPolicy(QSizePolicy::Fixed);
  policy.setVerticalPolicy(QSizePolicy::MinimumExpanding);
  textEdit.setSizePolicy(policy);
    
 
  
      
    removeButton.setText("Remove");
    modifyButton.setText("Modify");
    addButton.setText("Add Event");

    
    vlayout.addWidget(&clockWidget);
    vlayout.addWidget(&removeButton);
    vlayout.addWidget(&modifyButton);
    vlayout.addWidget(&addButton);
    vlayout.addWidget(&textEdit);
    

    hlayout = new QHBoxLayout();

 
    table.setModel(model);

    hlayout->addWidget(&table);
    hlayout->addLayout(&vlayout);
    
    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(&toolbar);
    mainLayout->addLayout(hlayout);
    
    
    
    this->setLayout(mainLayout);
}


void TablesContainer::setupConnections()
{
    
    //connect buttons

    connect(&removeButton,SIGNAL (clicked(bool)),this,SLOT(removeSelectedEvent(bool)) );
    connect (&modifyButton,SIGNAL (clicked(bool)),this,SLOT ( modifySelectedEvent(bool)));
    connect(&addButton,SIGNAL (clicked(bool)),this,SLOT (addEvent(bool)));

    //connect actions  fixme
    
    connect (next,SIGNAL ( triggered(bool)),this,SLOT (ToNextMondayDate()));
    connect (previous,SIGNAL ( triggered(bool)),this,SLOT (ToPreviousMonday()));
    connect (this,SIGNAL (timeArrowPressed(QDateTime)),model,SLOT(setMondayDate(QDateTime))); 
    connect (next,SIGNAL ( triggered(bool)),this,SLOT (updateView()));
    connect (previous,SIGNAL ( triggered(bool)),this,SLOT (updateView()));
    
    //table connection
    
    connect (&table,SIGNAL (clicked(QModelIndex)),this,SLOT(updateCurrentIndex(QModelIndex)));
      connect ( &table,SIGNAL (clicked(QModelIndex)),this,SLOT (updateEditor()));
  
}


void TablesContainer::updateView()
{

  QString tmp;
  tmp = "From ";
  tmp.append(model->getMondayDate().date().toString());
  tmp.append(" To ");
  tmp.append(model->getMondayDate().addDays(6).date().toString());
  
  label.setText(tmp);
  
}


void TablesContainer::removeSelectedEvent(bool)

{

    QItemSelectionModel   * selectionmodel =  (table.selectionModel());

    QDateTime eventdate = model->buildDatetimeFromIndex(selectionmodel->currentIndex());

    vector <Event > tmpVector = dispenser->getEventsForDate(eventdate);

    if (tmpVector.size() > 0)
    {

        QWidget * widget = new QWidget ;
        QHBoxLayout * layout = new QHBoxLayout(widget);

        EventCreator ** V = new EventCreator * [tmpVector.size()];


        for ( int i =0; i < tmpVector.size(); i++)
        {
            V[i] = new EventCreator((tmpVector.at(i)),dispenser,EventCreator::remove,widget);
            layout->addWidget((V[i]));

	    
            connect ( V[i],SIGNAL (eventChanged(bool)),model,SLOT (updateView()));
	    connect ( V[i],SIGNAL (eventChanged(bool)),this,SLOT (updateEditor()));
	    //connect(V[i] ,SIGNAL (eventChanged(bool)),widget,SLOT (close()));
	    
	       

        }

        widget->setWindowTitle("Remove Events");
        widget->setLayout(layout);
        widget->show();



    }



}

void TablesContainer::modifySelectedEvent(bool )
{

    QItemSelectionModel   * selectionmodel =  (table.selectionModel());

    QDateTime eventdate = model->buildDatetimeFromIndex(selectionmodel->currentIndex());

    vector <Event > tmpVector = dispenser->getEventsForDate(eventdate);

    if (tmpVector.size() > 0)
    {

        QWidget * widget = new QWidget ;
        QHBoxLayout * layout = new QHBoxLayout(widget);

        EventCreator ** V = new EventCreator * [tmpVector.size()];


        for ( int i =0; i < tmpVector.size(); i++)
        {
            V[i] = new EventCreator((tmpVector.at(i)),dispenser,EventCreator::modify,widget);
            layout->addWidget((V[i]));

	    
            connect ( V[i],SIGNAL (eventChanged(bool)),model,SLOT (updateView()));
	      connect ( V[i],SIGNAL (eventChanged(bool)),this,SLOT (updateEditor()));
	    //connect(V[i] ,SIGNAL (eventChanged(bool)),widget,SLOT (close()));

        }

        widget->setWindowTitle("Modify Events");
        widget->setLayout(layout);
        widget->show();



    }


}

void TablesContainer::addEvent(bool )
{



    QItemSelectionModel   * selectionmodel =  (table.selectionModel());

    QDateTime eventdate = model->buildDatetimeFromIndex(selectionmodel->currentIndex());


    QWidget * widget = new QWidget ;
    QHBoxLayout * layout = new QHBoxLayout(widget);

    Event  newevent(eventdate,"Nessun Appuntamento Presente","Untitled");
  
    
      
    
    EventCreator* eventCreator= new EventCreator(newevent,dispenser,EventCreator::add, widget); 
    
  
      connect ( eventCreator,SIGNAL (eventChanged(bool)),model,SLOT (updateView()));
        connect ( eventCreator,SIGNAL (eventChanged(bool)),this,SLOT (updateEditor()));
    
    layout->addWidget(eventCreator);






    widget->setWindowTitle("Add Event");
    widget->setLayout(layout);
    widget->show();



}


void TablesContainer::ToNextMondayDate()
{

  emit timeArrowPressed(model->getMondayDate().addDays(7));
  
}

void TablesContainer::ToPreviousMonday()
{

  emit timeArrowPressed(model->getMondayDate().addDays(-7));
  
}

void TablesContainer::updateCurrentIndex(QModelIndex index)
{

  currentindex = index;
 
  
}




void TablesContainer::updateEditor()
{
 textEdit.setText((model->data2(currentindex)).toString());
}




#include "TablesContainer.moc"

