#ifndef SEARCHWIDGET_H
#define SEARCHWIDGET_H

#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QObject>
#include <QWidget>
#include <QFormLayout>
#include <QString>
#include "Rubrica.h"

class SearchWidget: public QWidget{

Q_OBJECT

public:
    SearchWidget(Rubrica* rubrica, QWidget* parent = 0);
    QLineEdit* nameEdit;
    QLineEdit* surnameEdit;
    QLabel* nameLabel;
    QLabel* surnameLabel;
    QPushButton* searchButton;
    QPushButton* quitButton;
    QFormLayout* layout;

    void setName(QString name){
        _name = name;
    }

    void setSurname(QString surname){
        _surname = surname;
    }

    QString getName(){
        return _name;
    }

    QString getSurname(){
        return _surname;
    }

public slots:
    void saveAttributes();
    void searchContact();

private:
    QString _name;
    QString _surname;
    Rubrica* _rubrica;
};


#endif // SEARCHWIDGET_H
