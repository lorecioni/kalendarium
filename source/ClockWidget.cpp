#include "ClockWidget.h"


ClockWidget::ClockWidget(QWidget* parent, Qt::WindowFlags f): QWidget(parent, f)
{

  
  
  timer.setInterval(1000);
  timer.start();
  
  layout.addWidget(&dateLabel);
  layout.addWidget(&timeLabel);
  
  
  dateLabel.setAlignment(Qt::AlignCenter);
  timeLabel.setAlignment(Qt::AlignCenter);
  
  dateLabel.setStyleSheet("QLabel { border : 1px solid black; background-color : white; color : black}");
  
  QFont font;
  font.setBold(false);
  //font.setPixelSize(10);
  font.setPointSize(16);
  font.setStretch(95);
  font.setCapitalization(QFont::Capitalize);
  
 QFont fontB;
 fontB.setPixelSize(12);
  
  dateLabel.setFont(font);
  timeLabel.setFont(fontB);
  
  
  
  this->setLayout(&layout);
  
  connect(&timer,SIGNAL (timeout()),this,SLOT (updateLabel()));
  
  
  
}

void ClockWidget::updateLabel()
{

    dateLabel.setText(QDate::currentDate().toString());
    timeLabel.setText(QTime::currentTime().toString());
}




#include "ClockWidget.moc"