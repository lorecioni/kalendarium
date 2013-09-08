#ifndef MAIN_GUI
#define MAIN_GUI

#include "TablesContainer.h"
#include <QMainWindow>
#include<QMenuBar>
#include <QCalendarWidget>
#include<QAction>
#include <QMenu>
#include <QMessageBox>
#include <QSizePolicy>

#include "Address_Book/Rubrica.h"

class MainGui : public QMainWindow {
  
  Q_OBJECT
  
public :
  
    explicit MainGui(EventManager * dispenser_,Rubrica * addressBook ,QWidget* parent = 0, Qt::WindowFlags flags = 0);
  
  
  
private :
  
  TablesContainer * tableContainer;
  QMenuBar menuBar;
  QMenu file;
  QAction * exit;
  QAction * about;
  
  QMenu rubrica;
  QAction * addConctat;
  QAction * clearAll;
  QAction * searchConctat;
  QAction * showConctats;
  
  void setupActions();
  
  EventManager * dispenser;
  Rubrica * addressBook;
  
  
  public slots :
    
    void showAboutWindow();
  
  
};





#endif