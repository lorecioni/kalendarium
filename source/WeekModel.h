#ifndef WEEK_MODEL
#define WEEK_MODEL

#include <QAbstractTableModel>
#include <QDateTime>
#include <QVariant>
#include "EventManager.h"
#include <QTime>
#include <QString>

class WeekModel : public  QAbstractTableModel {
  
  Q_OBJECT
  
public :
  
    explicit WeekModel(QDateTime currentDateTime ,EventManager * dispenser, QObject* parent=0);
    virtual ~WeekModel();
  
    virtual int rowCount(const QModelIndex& parent = QModelIndex()) const;
    virtual int columnCount(const QModelIndex& parent = QModelIndex()) const;
    virtual bool setData(const QModelIndex& index, const QVariant& value,const QVariant& value2, int role = Qt::EditRole);
    virtual QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
    virtual Qt::ItemFlags flags(const QModelIndex& index) const;
    virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    virtual bool setHeaderData(int section, Qt::Orientation orientation, const QVariant& value, int role = Qt::EditRole);
    
    bool isForHour (QTime time,Event event);
    
    void setHeaders(); 
    
    void setBlankCells();
    void addStrings(   );
    
    void printV();//delete me
    
     QDateTime buildDatetimeFromIndex(QModelIndex index );
     QDateTime getMondayDate(QDateTime currentDateTime);
     
     
     virtual QVariant data2(const QModelIndex& index, int role = Qt::DisplayRole) const;
     
     QDateTime getMondayDate (){
     
       return mondayDate;
    }
    
    
private :
  
  int row;
  int col;
  
  QDateTime mondayDate;
  EventManager * dispenser;
  
  QString V[168];    
  QString W[168];
  QString VerticalHeader[24];
  QString HorizontalHeader [7];
  
  
  public slots:
  
 void updateView();
 void setMondayDate( QDateTime mondayDate); //fixme
  
  

  
};






#endif