#ifndef  CLOCK_WIDGET
#define CLOCK_WIDGET

#include <QWidget>
#include<QTimer>
#include <QLabel>
#include <QDateTime>
#include <QVBoxLayout>
#include <QFont>

class ClockWidget : public QWidget{
  
  Q_OBJECT
  
public :
  
    explicit ClockWidget(QWidget* parent = 0, Qt::WindowFlags f = 0);

private :
  
  QTimer timer;
  QLabel dateLabel;
  QLabel timeLabel;
  QVBoxLayout layout;


public slots :
  
  void updateLabel();


};




#endif