#ifndef EVENT_DISPERNSER
#define  EVENT_DISPERNSER

#include <QObject>
#include "Event.h"
#include <QDateTime>
#include <vector>
#include <map>
#include <algorithm>

class EventManager: public QObject{
  /*eventVector must be manteined sorted 
   * 
   */ 
  Q_OBJECT
   
  
public :
  
  EventManager();
    virtual ~EventManager();
    
      
private :
  
 map <QDate ,vector<Event> > eventMap;
  
 
  
public :
  
  void displayAll();  // for debug


  
  public slots :
    
    
    vector<Event> getEventsForDate(const QDate& date);
    vector<Event> getEventsForDate(const QDateTime & datetime);
   
    void addEvent(const Event& event);					
    void  removeEvent(const Event& event);
    void removeEvent(const QDateTime & datetime);
    bool searchEvent(const Event& event) ;  //todo
  
};





#endif