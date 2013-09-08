
#ifndef EVENT
#define EVENT

#include <ctime>
#include <iostream>
#include <QString>
#include <QObject>
#include <QDateTime>
#include <iostream>

#include <QTime>

using namespace std;


class Event : public QObject {

    Q_OBJECT

private :

    string title;
  
    string _description;

    QDateTime clock;


public :



    Event(QDateTime time,string description,string title);
    Event ();
    Event(const Event& event);   //copy constructor


    void setTm(QDateTime time);
    QDateTime getTm(void) const;
    
    

    void setDescription(string str);
    string getDescription()const ;
    
        void setTitle(string str);
    string getTitle()const ;

    void display();
    
    
  bool operator < (const Event &event)const; 		//needed for STL vector::sort to work
  void operator = (const Event &event);
  bool operator == (const Event &event)const;


public slots :

  //  void updateEvent (QString str,QDateTime time );
    
   

};




#endif
