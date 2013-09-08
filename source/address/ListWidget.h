#ifndef LISTWIDGET_H
#define LISTWIDGET_H

#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QObject>
#include <QWidget>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QString>
#include <QList>
#include <QSpacerItem>
#include <QListWidget>
#include "Rubrica.h"
#include "Contact.h"
#include <map>
#include <QScrollBar>
#include <algorithm>

class ListWidget: public QWidget{

    Q_OBJECT

public:
    ListWidget(Rubrica* rubrica, QWidget* parent = 0);
    QListWidget* _list;
    QPushButton* _showContact;
    QPushButton* _quit;
    QFormLayout* _layout;
    QVBoxLayout* _vLayout;
    //QLineEdit* _searchEdit;
    //QLabel* _searchLabel;
    QScrollBar* _scrollBar;  
    QList<QListWidgetItem*> * _selectedList;

public slots:
    void setSelection();
    void showContact();
   // void updateList();

private:
    QString _name;
    QString _surname;
    Rubrica* _rubrica;
    int _id;

};

#endif // LISTWIDGET_H
