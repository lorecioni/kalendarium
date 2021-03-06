#include "SearchWidget.h"
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QObject>
#include <QWidget>
#include <map>
#include <algorithm>
#include <QFormLayout>
#include <QString>
#include <QMessageBox>
#include "Rubrica.h"
#include "ContactWidget.h"

SearchWidget::SearchWidget(Rubrica* rubrica, QWidget* parent) {

    this->setFixedSize(400, 100);
    this->setWindowTitle("Search contact");

    nameEdit = new QLineEdit(this);
    surnameEdit = new QLineEdit(this);
    nameLabel = new QLabel("Name: ", this);
    surnameLabel = new QLabel("Surname: ", this);
    searchButton = new QPushButton("Search", this);
    quitButton = new QPushButton("Quit", this);

    layout = new QFormLayout(this);

    layout->addRow(nameLabel, nameEdit);
    layout->addRow(surnameLabel, surnameEdit);
    layout->addRow(searchButton, quitButton);
    this->setLayout(layout);

    _name = "";
    _surname = "";

    _rubrica = rubrica;

    QObject::connect(searchButton, SIGNAL(clicked()), this, SLOT(saveAttributes()));
    QObject::connect(quitButton, SIGNAL(clicked(bool)), this, SLOT(close()));
    QObject::connect(searchButton, SIGNAL(clicked()), this, SLOT(searchContact()));


}

void SearchWidget::saveAttributes(){
    QString name, surname;
    name = nameEdit->text();
    surname = surnameEdit->text();
    this->setName(name);
    this->setSurname(surname);
}


void SearchWidget::searchContact(){
    if((_name != "") || (_surname != "")){

    int id = 0;
    id = _rubrica->search(_name,_surname);

    if(id == -1){
        QMessageBox* error = new QMessageBox;
        error->setText("Contact not found!");
        error->setIcon(QMessageBox::Critical);
        error->setWindowTitle("Error");
        error->exec();
    }
    else
    {
        this->close();
        ContactWidget* contWidget = new ContactWidget(_rubrica, id);
        contWidget->show();
    }
}
    else
    {
        QMessageBox* error2 = new QMessageBox;
        error2->setText("Missing parameter!");
        error2->setIcon(QMessageBox::Information);
        error2->setWindowTitle("Error");
        error2->exec();
    }

}

#include "SearchWidget.moc"
