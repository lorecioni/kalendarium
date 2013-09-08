#include <QtGui/QApplication>
#include "Event.h"
#include "EventCreator.h"
#include <iostream>
#include <QtGui/QClipboard>
#include <QtGui/QWidget>
#include <QtGui/QVBoxLayout>
#include <QDateTime>
#include <QTime>
#include <QDate>

#include <iostream>

#include "EventManager.h"
#include "WeekModel.h"
#include <QTableView>


int main(int argc, char** argv)
{
  QApplication app(argc,argv);
  //QWidget mainw;
  
  QVBoxLayout layout;
  QDateTime timer;
  timer.setDate(QDate::currentDate());
  timer.setTime(QTime::currentTime());
  Event evento1 (timer,strg,"title pappa");
  

 
  evento1.display();
  
  QDateTime timer2;
  timer2 = timer.addSecs(3700
  );
 
  string strg1 = "ahahahahah";
  Event evento2 (timer2,strg1,"title ahah");
 
 

 
 
 
  EventManager dispenser;
  
  dispenser.addEvent(evento1);
 dispenser.addEvent(evento2);

 //rubrica
 
 Rubrica addressBook;
 
 
 
 
  
  MainGui maingui(&dispenser,&addressBook);
  maingui.show();

  
  return app.exec();
  
  
  
  return 0;
  }
  
  
  





