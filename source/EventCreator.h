#ifndef BASE_EVENT
#define BASE_EVENT

#include "Event.h"
#include <QtGui/QWidget>

#include <QtGui/QTextEdit>
#include <QString>
#include <QMenu>
#include <QAction>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMouseEvent>
#include <QLineEdit>
#include <QDateTimeEdit>
#include <QLabel>


#include <QVBoxLayout>
#include <QAction>
#include <QMenu>
#include <iostream>
#include <QTime>

#include "EventManager.h"
#include <QMessageBox>

class EventCreator : public QWidget {

    Q_OBJECT

public :

       enum Role{
      
      add,
      modify,
      remove 
      
    };
    
    
    EventCreator( Event originalEvent,EventManager * dispenser,Role role, QWidget * parent =0 );
    virtual ~EventCreator();
    
 
    

    
private:
   
  
  bool firstedit;
  Role role;  
    
    QTextEdit text;
    QPushButton editbutton;
    QVBoxLayout layout;
    QHBoxLayout hlayout;
    QDateTimeEdit timeline;
    
    QLineEdit titleEdit;
    
  

protected:

    void mousePressEvent ( QMouseEvent * event );


public slots :


    void updateStatus();
    void buildNewEvent ( QString str, QDateTime datetime,QString title);
    

signals :

    void eventToUpdate ( QString,QDateTime,QString);
    
    void eventChanged(bool);
    
    void addNewEvent(Event);
    void removeOldEvent(Event);



private :

    Event originalEvent;
    Event newEvent;
    
      EventManager  *  dispenser;
    
    void buildinterface(void);
    void buildInterfaceforRemove(void);
    void buildInterfaceforModify(void);





};


#endif
