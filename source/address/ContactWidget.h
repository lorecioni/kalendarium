#ifndef CONTACTWIDGET_H
#define CONTACTWIDGET_H

#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QObject>
#include <QWidget>
#include <QFormLayout>
#include <QString>
#include <QSpacerItem>
#include "Rubrica.h"

class ContactWidget: public QWidget {
    Q_OBJECT

public:
    ContactWidget(Rubrica* rubrica, int id);
    QLabel* name;
    QLabel* surname;
    QLabel* phone;
    QLabel* email;
    QLineEdit* nameEdit;
    QLineEdit* surnameEdit;
    QLineEdit* phoneEdit;
    QLineEdit* emailEdit;
    QPushButton* quit;
    QPushButton* modify;
    QPushButton* remove;
    //QSpacerItem* space;
    QFormLayout* layout;

    QString _name;
    QString _surname;
    QString _phone;
    QString _email;

    int _id;
    Rubrica* _rubrica;

public slots:
    virtual void modContact();
    virtual void removeContact();
};


#endif // CONTACTWIDGET_H
