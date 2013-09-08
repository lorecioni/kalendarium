#ifndef ADDWIDGET_H
#define ADDWIDGET_H

#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QObject>
#include <QWidget>
#include <QFormLayout>
#include <QString>
#include <QSpacerItem>
#include "Rubrica.h"

class AddWidget: public QWidget{

   Q_OBJECT

public:

    AddWidget(Rubrica* rubrica, QWidget* parent = 0);
    QLabel* nameLabel;
    QLabel* surnameLabel;
    QLabel* phoneLabel;
    QLabel* emailLabel;
    QLineEdit* nameEdit;
    QLineEdit* surnameEdit;
    QLineEdit* phoneEdit;
    QLineEdit* emailEdit;
    QPushButton* save;
    QPushButton* quit;

    QFormLayout* layout;


    QString _name, _surname, _phone, _email;
    int _id;
    Rubrica* _rubrica;

public slots:
    void saveAll();
};

#endif // ADDWIDGET_H
