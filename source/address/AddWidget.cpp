#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QObject>
#include <QWidget>
#include <QFormLayout>
#include <QString>
#include <QSpacerItem>
#include <map>
#include <algorithm>
#include "Rubrica.h"
#include "ContactWidget.h"
#include "AddWidget.h"


AddWidget::AddWidget(Rubrica* rubrica, QWidget* parent){

resize(400, 150);

setWindowTitle("Add contact");

nameLabel = new QLabel("Name", this);
surnameLabel = new QLabel("Surname", this);
phoneLabel = new QLabel("Phone", this);
emailLabel = new QLabel("E-mail", this);
nameEdit = new QLineEdit(this);
surnameEdit = new QLineEdit(this);
phoneEdit = new QLineEdit(this);
emailEdit = new QLineEdit(this);
save = new QPushButton("Save", this);
quit = new QPushButton("Quit", this);

layout = new QFormLayout;
layout->addRow(nameLabel, nameEdit);
layout->addRow(surnameLabel, surnameEdit);
layout->addRow(phoneLabel, phoneEdit);
layout->addRow(emailLabel, emailEdit);
layout->addRow(save, quit);
setLayout(layout);


_id = rubrica->_counter;
_name = "";
_surname = "";
_phone = "";
_email = "";

_rubrica = rubrica;

QObject::connect(save, SIGNAL(clicked()), this, SLOT(saveAll()));
QObject::connect(quit, SIGNAL(clicked()), this, SLOT(close()));
QObject::connect(save, SIGNAL(clicked()), this, SLOT(close()));
}

void AddWidget::saveAll(){
    _name = nameEdit->text();
    _surname = surnameEdit->text();
    _phone = phoneEdit->text();
    _email = emailEdit->text();

    if(_name!="" || _surname!= "" || _phone!="" || _email!= ""){

    _rubrica->_vector[_id].setName(_name);
    _rubrica->_vector[_id].setSurname(_surname);
    _rubrica->_vector[_id].setPhone(_phone);
    _rubrica->_vector[_id].setPhone(_phone);
    _rubrica->_vector[_id].setEmail(_email);

    _rubrica->incCounter();
   }
}

#include "AddWidget.moc"
