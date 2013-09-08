#include "MainGui.h"

MainGui::MainGui(EventManager * dispenser_,Rubrica * addressBook, QWidget* parent, Qt::WindowFlags flags): QMainWindow(parent, flags)
{

  QIcon icon;
  icon.addFile("IconaBeta2.q.png");
  this->setWindowIcon(icon);
  
  this->dispenser = dispenser_;
  this->addressBook = addressBook;
  
  
  
  tableContainer = new TablesContainer(QDateTime::currentDateTime(),dispenser,this );

  this->setCentralWidget(tableContainer);
  this->setAnimated(true);
  this->setMenuBar(&menuBar);
  
  QSizePolicy policy;
  policy.setVerticalPolicy(QSizePolicy::Expanding);
  policy.setHorizontalPolicy(QSizePolicy::Expanding);
  this->setSizePolicy(policy);
 
 
  
  setupActions();
  
  this->resize(1100,700);
  
  connect(exit,SIGNAL (triggered(bool)),this, SLOT(close()));
  connect(about,SIGNAL (triggered(bool)),this, SLOT(showAboutWindow()));
}

void MainGui::setupActions()
{

   exit = new QAction(&file);
   exit->setIcon(QIcon::fromTheme("application-exit"));
  about = new QAction(&file);
  about->setIcon(QIcon::fromTheme("help-about"));
  
  addConctat = new QAction(&rubrica);
  addConctat->setIcon(QIcon::fromTheme("list-add"));
  clearAll = new QAction(&rubrica);
  clearAll->setIcon(QIcon::fromTheme("application-exit"));
  searchConctat = new QAction(&rubrica);
  searchConctat->setIcon(QIcon::fromTheme("edit-find"));
  showConctats = new QAction(&rubrica);
  showConctats->setIcon(QIcon::fromTheme("document-open"));
  
  menuBar.addMenu(&file);
  menuBar.addMenu(&rubrica);
  menuBar.addAction(about);
  
  file.setTitle("File");
  file.addAction(exit);
  
  exit->setText("Exit");
  about->setText("About");
  
  rubrica.setTitle("Address Book");
  rubrica.addAction(addConctat);
  rubrica.addAction(searchConctat);
  rubrica.addAction(showConctats);
  rubrica.addAction(clearAll);
    
  addConctat->setText("AddConctat");
  clearAll->setText("Clear All");
  searchConctat->setText("Search Conctat");
  showConctats->setText("Show All Conctats");
  
  connect (addConctat,SIGNAL (triggered(bool)),addressBook,SLOT (addContact()));
    connect (searchConctat,SIGNAL (triggered(bool)),addressBook,SLOT (searchContact()));
      connect (showConctats,SIGNAL (triggered(bool)),addressBook,SLOT (stampContacts()));
        connect (clearAll,SIGNAL (triggered(bool)),addressBook,SLOT (clearAll()));
  
  
}


void MainGui::showAboutWindow()
{

  QMessageBox * msg = new QMessageBox;
  msg->setInformativeText("Thanks to the Developers : \n Giulio Galvan \n ");
  msg->setStandardButtons(QMessageBox::Close);
  msg->show();
}
