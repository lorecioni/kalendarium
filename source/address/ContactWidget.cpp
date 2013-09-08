#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <map>
#include <algorithm>
#include <QObject>
#include <QWidget>
#include <QFormLayout>
#include <QString>
#include <QSpacerItem>
#include <QMessageBox>
#include "Rubrica.h"
#include "ContactWidget.h"

ContactWidget::ContactWidget(Rubrica* rubrica, int id){

    resize(400, 150);
    setWindowTitle("Search contact");

    name = new QLabel("Name: ", this);
    surname = new QLabel("Surname: ", this);
    phone = new QLabel("Phone: ", this);
    email = new QLabel("Email: ", this);
    nameEdit = new QLineEdit(this);
    surnameEdit = new QLineEdit(this);
    phoneEdit = new QLineEdit(this);
    emailEdit = new QLineEdit(this);
    remove = new QPushButton("Remove", this);
    quit = new QPushButton("Quit", this);
    modify = new QPushButton("Modify", this);
    layout = new QFormLayout(this);
    //space = new QSpacerItem(20, 50);

    _id = id;
    _rubrica = rubrica;


    _name = rubrica->_vector[id].getName();
    _surname  = rubrica->_vector[id].getSurname();
    _phone = rubrica->_vector[id].getPhone();
    _email = rubrica->_vector[id].getEmail();

    nameEdit->setText(_name);
    surnameEdit->setText(_surname);
    phoneEdit->setText(_phone);
    emailEdit->setText(_email);

    layout->addRow(name, nameEdit);
    layout->addRow(surname, surnameEdit);
    layout->addRow(phone, phoneEdit);
    layout->addRow(email, emailEdit);
    //layout->spacerItem(space);
    layout->addRow(modify, remove);
    layout->addRow(quit);
    setLayout(layout);

    QObject::connect(quit, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(modify, SIGNAL(clicked()), this, SLOT(modContact()));
    QObject::connect(remove, SIGNAL(clicked()), this, SLOT(removeContact()));


}

void ContactWidget::modContact(){
   QMessageBox* alert = new QMessageBox;

    alert->setIcon(QMessageBox::Warning);
    alert->setText("The contact has been modified");
    alert->setInformativeText("Save your changes?");
    alert->setWindowTitle("Modify");
    alert->setStandardButtons(QMessageBox::Cancel | QMessageBox::Ok);
    alert->setDefaultButton(QMessageBox::Ok);
    int ret = alert->exec();

    switch(ret){
    case QMessageBox::Ok:
        {
    _name = nameEdit->text();
    _surname = surnameEdit->text();
    _phone = phoneEdit->text();
    _email = emailEdit->text();

    _rubrica->_vector[_id].setName(_name);
    _rubrica->_vector[_id].setSurname(_surname);
    _rubrica->_vector[_id].setPhone(_phone);
    _rubrica->_vector[_id].setEmail(_email);
            break;
        }
    case QMessageBox::Cancel:
        break;
    default:
        break;
    }

}

void ContactWidget::removeContact(){
    QString tmpName, tmpSurname, tmpPhone, tmpEmail;

    QMessageBox* alert = new QMessageBox;
    alert->setText("The contact will be cancelled!");
    alert->setInformativeText("Continue?");
    alert->setIcon(QMessageBox::Warning);
    alert->setWindowTitle("Remove");
    alert->setStandardButtons(QMessageBox::Cancel | QMessageBox::Ok);
    alert->setDefaultButton(QMessageBox::Ok);
    int ret = alert->exec();

    switch(ret){
    case QMessageBox::Ok:
        {
            tmpName = _rubrica->_vector[((_rubrica->_counter) - 1)].getName();
            tmpSurname = _rubrica->_vector[((_rubrica->_counter) -1)].getSurname();
            tmpPhone = _rubrica->_vector[((_rubrica->_counter) - 1)].getPhone();
            tmpEmail = _rubrica->_vector[((_rubrica->_counter) -1)].getEmail();

            _rubrica->_vector[_id].setName(tmpName);
            _rubrica->_vector[_id].setSurname(tmpSurname);
            _rubrica->_vector[_id].setPhone(tmpPhone);
            _rubrica->_vector[_id].setEmail(tmpEmail);
            _rubrica->_vector[_id].setId(_id);

	  _rubrica->_vector.erase(_id);
	    
            this->close();

            _rubrica->_counter = (_rubrica->_counter) - 1;
            break;
        }
    case QMessageBox::Cancel:
        break;
    default:
        break;
    }
}

#include "ContactWidget.moc"
