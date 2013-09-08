#include "EventCreator.h"



EventCreator::EventCreator( Event originalEvent,EventManager * dispenser,Role role, QWidget * parent):QWidget(parent), text(this) , originalEvent(originalEvent)
{


    this->dispenser = dispenser;
    this->originalEvent = originalEvent;
    firstedit = true;
    this->role = role;

    if (role == remove) {
        buildInterfaceforRemove();
    }
    else
        buildInterfaceforModify();

    buildinterface();
}




void EventCreator::updateStatus()

{
    if (role == add || role == modify){
	      
	      emit eventToUpdate( text.toPlainText(),timeline.dateTime(),titleEdit.text());
   
  
	      if (dispenser->searchEvent(newEvent)  == false || role == modify)
	      {

	      if (firstedit == false || role ==modify)
	      emit removeOldEvent(originalEvent);

	      emit addNewEvent(newEvent);

	      emit eventChanged(true);
	      originalEvent = newEvent;
	      firstedit = false;
	      }

	      else

	      {
	      QMessageBox * msg = new QMessageBox;
	      msg->setInformativeText("Impossible to Add an Event with same Date !");
	      msg->setDefaultButton(QMessageBox::Close);
	      msg->show();


	      }
	      }
    else
    {
      emit removeOldEvent(originalEvent);
      emit eventChanged(true);
      editbutton.setEnabled(false);
      editbutton.setText("Removed");
      text.setReadOnly(true);
      timeline.setReadOnly(true);
      titleEdit.setReadOnly(true);
     }

}


void EventCreator::buildinterface(void )
{





    timeline.setDateTime(originalEvent.getTm());
    text.setText(QString::fromStdString(originalEvent.getDescription()));
    text.setReadOnly(false);
    timeline.setReadOnly(false);
    
    titleEdit.setReadOnly(false);
    titleEdit.setText(QString::fromStdString(originalEvent.getTitle()));


    hlayout.addWidget(&titleEdit);
    hlayout.addWidget(&timeline);
    hlayout.addWidget(&editbutton);
    layout.addLayout(&hlayout);
    layout.addWidget(&text);

    this->setLayout(&layout);






}

void EventCreator::buildInterfaceforModify(void )
{




    editbutton.setText("Save");


    connect(&editbutton,SIGNAL (clicked(bool)),this,SLOT (updateStatus()));
    connect ( this, SIGNAL (eventToUpdate(QString,QDateTime,QString)), this,SLOT (buildNewEvent(QString,QDateTime,QString)));


    connect ( this,SIGNAL (removeOldEvent(Event)),dispenser,SLOT (removeEvent(Event)));
    connect ( this,SIGNAL (addNewEvent(Event)),dispenser,SLOT (addEvent(Event)));






}

void EventCreator::buildInterfaceforRemove(void )
{

    editbutton.setText("Remove");


    connect(&editbutton,SIGNAL (clicked(bool)),this,SLOT (updateStatus()));
    connect ( this,SIGNAL (removeOldEvent(Event)),dispenser,SLOT (removeEvent(Event)));
   

}



void EventCreator::buildNewEvent(QString str, QDateTime datetime,QString title)
{

    newEvent = Event(datetime,str.toStdString(),title.toStdString());
    std::cout << "newevent"<< std::endl;

}



void EventCreator::mousePressEvent(QMouseEvent* event)
{

    if (event->button() == Qt::RightButton)
    {

        QMenu * menu = new QMenu(this);
        QAction  * modify = new QAction(menu);
        modify->setText("Modifica Evento");
        QAction  * save = new QAction(menu);
        save->setText("Salva");


        menu->addAction(save);



        connect(save,SIGNAL (triggered(bool)),this,SLOT(updateStatus()));
        menu->exec(QCursor::pos());


    }
}

EventCreator::~EventCreator()
{

}






#include "EventCreator.moc"


