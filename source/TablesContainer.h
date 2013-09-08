#ifndef TABLES_CONTAINER
#define  TABLES_CONTAINER



#include "WeekModel.h"
#include "QPushButton"
#include "QWidget"
#include "QTableView"
#include "QVBoxLayout"
#include "QHBoxLayout"
#include "QTextEdit"
#include "EventCreator.h"
#include <QToolBar>
#include <QAction>
#include <QIcon>
#include <QLabel>
#include <QTextEdit>
#include <QSize>
#include "ClockWidget.h"

class TablesContainer : public QWidget{
  
 Q_OBJECT
 
private :
  
  QToolBar toolbar;
  QAction * next;
  QAction * previous; 
  QLabel label;
  QTextEdit textEdit;
  
  QLabel dateLabel;
  QPushButton removeButton;
  QPushButton modifyButton;
  QPushButton addButton; 
  
  ClockWidget clockWidget;
  
  WeekModel * model;
  QTableView table;
  
  QVBoxLayout * mainLayout;
  QVBoxLayout vlayout;
  QHBoxLayout  * hlayout;
  
  EventManager *  dispenser;
  QModelIndex currentindex;
  
  
  void buildInterface();
  void setupConnections();
 
  
  
public : 
  
    explicit TablesContainer(QDateTime mondayDate,EventManager * dispenser_ ,QWidget* parent = 0);
    virtual ~TablesContainer();
    
    
    private slots :
      
    
    void updateEditor();
  
public slots :

  void removeSelectedEvent(bool);
  void modifySelectedEvent(bool);
  void addEvent(bool);
  
  void ToNextMondayDate();
  void ToPreviousMonday();
  void updateView();
  
  void updateCurrentIndex(QModelIndex  index);
    
    
   
   
signals :
  
  void timeArrowPressed(QDateTime);
  
  
  
};




#endif