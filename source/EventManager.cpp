#include "EventManager.h"
#include <vector>
#include <iostream>

EventManager::EventManager()
{

}

vector< Event > EventManager::getEventsForDate(const QDate& date)
{
  // it must receive a date with Hms = 00:00:00
 
    
    std::cout << date.toString().toStdString() << std::endl;

return eventMap[date];

}

vector< Event > EventManager::getEventsForDate(const QDateTime& datetime)
{

  
  // it must receive a date with Hms = 00:00:00
 
    vector<Event > tmpVector;

    unsigned int i =0;
    
  

    while (   i <eventMap[datetime.date()].size()) {
      
 

        if (eventMap[datetime.date()].at(i).getTm()>= datetime && eventMap[datetime.date()].at(i).getTm()<  datetime.addSecs(3600)){
       
	  tmpVector.push_back( (eventMap[datetime.date()].at(i)));
	    
	}
	    ++i;
	

    }

return tmpVector;

}
  

  




EventManager::~EventManager()
{
    eventMap.clear();

}


void EventManager::addEvent(const Event& event)
{

    eventMap[event.getTm().date()].push_back(event);
    
 

}

void EventManager::removeEvent(const Event& event)
{
    //potential bug : identical event

    QDate keymap = event.getTm().date();
   
    unsigned int i = 0;

    bool found = false;

    while ( found == false && i !=eventMap[keymap].size()) {

        if ((eventMap[keymap].at(i) )== event){
           eventMap[keymap].erase(eventMap[keymap].begin()+i);
	
	  found = true;
	}

        ++i;
    }

}


void EventManager::removeEvent(const QDateTime& datetime)
{

    //potential bug : identical event

    QDate keymap = datetime.date();
   
    unsigned int i = 0;

    bool found = false;

    while ( found == false && i !=eventMap[keymap].size()) {

        if ((eventMap[keymap].at(i).getTm() )== datetime){
           eventMap[keymap].erase(eventMap[keymap].begin()+i);
	
	  found = true;
	}

        ++i;
    }

}


void EventManager::displayAll()
{
  
  map<QDate ,vector<Event> > ::iterator itr;
  
  

  for ( itr =eventMap.begin() ; itr != eventMap.end();itr ++){
    
    for (unsigned int i =0; i != (*itr).second.size();i++)
    (*itr).second.at(i).display();
  }
}




bool EventManager::searchEvent(const Event& event)
{
// to fix



std :: cout<< "qui"<< event.getDescription() << std::endl;

std::map < QDate , vector<Event> >::iterator itr;

std::cout << "error point"<< std::endl;

 itr = eventMap.begin() ;
 
 std::cout << "erro2"<< std::endl;
 
 bool found = false;
 
 
 
while (itr != eventMap.end() && found == false)
  {
  
  std::vector<Event>::iterator itr2;
  itr2 = std::find(itr->second.begin(),itr->second.end(),event);
  if (itr2 != itr->second.end())
    found = true;

  itr++;
}

return found;
  
}


/*
bool EventManager::searchEvent(const Event& event)
{

  
  map <QDate ,vector<Event> >::iterator mapItr;
  
  QDate tmp = event.getTm().date();
    
 
    eventMap[tmp].push_back(event);  ////
    
       eventMap.find(event.getTm().date());
   //  mapItr = eventMap.find(tmp);
  
 
  
  if(mapItr != eventMap.end()){
  
  std::vector<Event>::iterator itr;
  itr = std::find(mapItr->second.begin(),mapItr->second.end(),event);
  

  
  if ( itr != eventMap[event.getTm().date()].end() )
    return true;
  else  
    
  return false;
  }
  
  else 
    return false;
}
*/

#include "EventManager.moc"

