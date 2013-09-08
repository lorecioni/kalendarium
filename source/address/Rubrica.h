#ifndef RUBRICA_H
#define RUBRICA_H

#include "Contact.h"
#include <QVector>
#include <QObject>
#include <QDebug>
#include <QWidget>
#include <algorithm>
#include <map>

using namespace std;

class Rubrica: public QObject {

Q_OBJECT

public:
  Rubrica();
  virtual ~Rubrica();

  void setCounter(int counter) {
      _counter = counter;
  }

  int search(QString name, QString surname);



 //Memoria statica
  map <int, Contact> _vector;
  int _counter;   //numero di contatti presenti in rubrica


public slots:
virtual void addContact();
virtual void searchContact();
virtual void incCounter();
virtual void stampContacts();
virtual void clearAll();

};

#endif // RUBRICA_H