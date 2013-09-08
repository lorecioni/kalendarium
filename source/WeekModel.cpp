#include "WeekModel.h"
#include <QVariant>
#include "Event.h"
#include <vector>
#include <QString>
#include <iostream>

WeekModel::WeekModel(QDateTime currentDateTime ,EventManager * dispenser, QObject* parent): QAbstractTableModel( parent)
{

    col = 7;
    row = 24;
    this->dispenser = dispenser;
    this->mondayDate = getMondayDate(currentDateTime);

    updateView();
    setHeaders();

   
    
   
}


 

void WeekModel::setBlankCells()
{	
  
     for (int i =0;i<col;i++) {
                   
	for (int j=0;j<row;j++) {
	  
           QModelIndex index = this->createIndex(j,i,this);

                setData(index,"","", Qt::EditRole);
		

            }
		}
		
 
}

void WeekModel::setHeaders()
{

  for (int i = 0; i< row;i++)
    setHeaderData(i,Qt::Vertical,i,Qt::EditRole);
  
  setHeaderData(0,Qt::Horizontal,"Monday",Qt::EditRole);
  setHeaderData(1,Qt::Horizontal,"Tuesday",Qt::EditRole);
  setHeaderData(2,Qt::Horizontal,"Wednesday",Qt::EditRole);
  setHeaderData(3,Qt::Horizontal,"Thursday",Qt::EditRole);
  setHeaderData(4,Qt::Horizontal,"Friday",Qt::EditRole);
  setHeaderData(5,Qt::Horizontal,"Saturday",Qt::EditRole);
  setHeaderData(6,Qt::Horizontal,"Sunday",Qt::EditRole);
  
}




void WeekModel::updateView()
{

  //delete
  std::cout << "checks for date "<< mondayDate.toString().toStdString() << std::endl;
  std::cout << "check elements" << std::endl;
  dispenser->displayAll();
    
  setBlankCells();
  addStrings();
  
 QModelIndex topLeftIndex = QAbstractItemModel::createIndex ( 0, 0,this );
 QModelIndex bottomRightIndex = QAbstractItemModel::createIndex ( 23, 6 ,this);
 
 
   
   emit dataChanged(topLeftIndex,bottomRightIndex);

}

void WeekModel::addStrings()
{

  
  QDateTime datetime = mondayDate;
  
    for (int i =0;i<col;i++) {
        
        std::vector<Event> tmpVector = dispenser->getEventsForDate(datetime.date());
     
        
	for (int j=0;j<row;j++) {
	  
           QModelIndex index = this->createIndex(j,i,this);

                   

		for (unsigned int  k = 0 ;k<tmpVector.size();k++) {
	      
	    	    
                if ((isForHour(datetime.time(),tmpVector.at(k)) == true)) {

                    QString tmpString;
                    tmpString = data(index,Qt::DisplayRole).toString();
		    if (tmpString != "")
		    tmpString.append(" \n");
		    tmpString.append( tmpString.fromStdString(tmpVector.at(k).getTitle())  );
		    
		    
		    std::cout << "get" << tmpString.toStdString() << std::endl;

                   // setData(index,tmpString,Qt::EditRole);
		    
		    //
		    QString tmpString2;
                    tmpString2 = data2(index,Qt::DisplayRole).toString();
		    if (tmpString2 != "")
		    tmpString2.append(" \n");
		    tmpString2.append( tmpString2.fromStdString(tmpVector.at(k).getDescription())  );

                    setData(index,tmpString,tmpString2,Qt::EditRole);
		    
		    
		    
		    }
              
		  
	    
		  }
		    datetime = datetime.addSecs(3600);
		  }
    
  
    }

  
}



bool WeekModel::isForHour(QTime time, Event event)
{


    if (event.getTm().time() >= time && event.getTm().time() <= time.addSecs(3599)) {
        return true;
    }

    else {
        return false;
    }

}




int WeekModel::columnCount(const QModelIndex& parent) const
{
    return col;
}


int WeekModel::rowCount(const QModelIndex& parent) const
{

    return row;
}

WeekModel::~WeekModel() 
{

}



bool WeekModel::setData(const QModelIndex& index, const QVariant& value,const QVariant& value2, int role)
{
  
    if (index.row() < row && index.column() < col && role == Qt::EditRole)
    {
        V[index.column()*(row)+index.row()]=value.toString(); 
	
	std::cout << "impostando" << value.toString().toStdString() << std::endl;
	W[index.column()*(row)+index.row()]=value2.toString(); 
	
        return true;
    }
    else
        return false;

}

QVariant WeekModel::data(const QModelIndex& index, int role ) const
{


    if ( index.column() < col && index.row() < row &&  role == Qt::DisplayRole) {
        
        return V[(index.column())*(row)+index.row()];
    }
    else
        return QVariant();

}

QVariant WeekModel::data2(const QModelIndex& index, int role) const
{

     if ( index.column() < col && index.row() < row &&  role == Qt::DisplayRole) {
        
        return W[(index.column())*(row)+index.row()];
    }
    else
        return QVariant();
  
}



Qt::ItemFlags WeekModel::flags(const QModelIndex& index) const
{
  
  return Qt::ItemIsEnabled;
}





bool WeekModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant& value, int role)
{
  if ( orientation == Qt::Horizontal)
  {
  HorizontalHeader[section]= value.toString();
  emit headerDataChanged(Qt::Horizontal,section,section++);
  return true;
}
else if (orientation == Qt::Vertical)
{
 VerticalHeader[section] = value.toString();

  emit headerDataChanged(Qt::Vertical,section,section++);
  return true;
}
else
{
  return false;
}
}



QVariant WeekModel::headerData(int section, Qt::Orientation orientation, int role) const
{
  
  
    if (orientation == Qt::Vertical && role == Qt::DisplayRole)
    {	
      
      
      return VerticalHeader[section];
      
    }
    else if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
      return   HorizontalHeader[section];
    else 
      return QVariant();
}



QDateTime WeekModel::buildDatetimeFromIndex(QModelIndex index )
{

  QDateTime tmpdate = mondayDate;
  
     for (int i = 0;i < ((row)*index.column() + index.row());i++)
     {
           
	 tmpdate = tmpdate.addSecs(3600);

                

            }
		
		
  
  return tmpdate;
}


QDateTime WeekModel::getMondayDate(QDateTime currentDateTime)
{

  QDateTime tmpdDateTime;
  tmpdDateTime.setDate(currentDateTime.date());
  for(int k =  currentDateTime.date().dayOfWeek(); k >1; k--)
    tmpdDateTime = tmpdDateTime.addDays(-1);
  
  return tmpdDateTime;
  
  
  
}

void WeekModel::setMondayDate(QDateTime mondayDate)
{

      
       this->mondayDate = mondayDate;
       updateView();
     
}



//delete me


void WeekModel::printV()
{

    for (int i =0; i <167;i++)
        std::cout << V[i].toStdString() << std::endl;

     std::cout << " end row " << row << col << std::endl;
}






#include "WeekModel.moc"
