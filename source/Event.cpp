
#include "Event.h"


using namespace std;

Event::Event()
{

  
  clock.setDate(QDate::currentDate());
  _description = "Nessun Appuntamento presente";
  title = "Untitled";
  
  
}


QDateTime Event::getTm(void ) const
{

  return clock;
  
}

void Event::setTm(QDateTime time)
{

  clock = time; 
}




Event::Event(QDateTime time, string description,string title) : _description(description), clock(time),title(title) {
    


}

/*
void Event::updateEvent(  QString str, QDateTime time )
{

    setTm(time);
    setDescription(str.toStdString());

}
*/


void Event::display()
{
    QString str = clock.toString();
    std::cout << _description  << endl << str.toStdString() << std::endl;
        std::cout << title  << endl << str.toStdString() << std::endl;
    
  
}


string Event::getDescription() const
{

    return _description;
}

void Event::setDescription(string str)
{
    _description= str;

}

string Event::getTitle() const
{
return title;
  
}

void Event::setTitle(string str)
{

  this->title = str;
}





//STL


bool Event::operator<(const Event& event) const
{

  if(this->clock < event.clock)
    return true;
  else
    return false;
  
}

bool Event::operator==(const Event& event) const
{

    if(this->clock == event.clock)
    return true;
  else
    return false;
}

void Event::operator=(const Event& event)
{

  this->clock = event.clock;
  this->_description = event._description;
  this->title = event.title;
  
}


Event::Event(const Event& event ): QObject()
{

  this->clock = event.clock;
  this->_description = event._description;
  this->title = event.title;
  
}










#include "Event.moc"
