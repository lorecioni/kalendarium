#ifndef CONTACT_H
#define CONTACT_H

#include <QString>
#include <QObject>

class Contact{
public:
Contact();

void setName(QString name = '\0'){
_name = name;
}

QString getName(void) const{
return _name;
}

void setSurname(QString surname = '\0'){
_surname = surname;
}

QString getSurname (void) const {
return _surname;
}

void setPhone (QString phone = '\0') {
_phone = phone;
}

QString getPhone (void) const {
return _phone;
}

void setEmail (QString email = '\0') {
_email = email;
}

QString getEmail (void) const{
return _email;
}

int getId(void) const {
    return _id;
}

void setId(int id){
    _id = id;
}

private:
int _id;
QString _name;
QString _surname;
QString _phone;
QString _email;
};

#endif // CONTACT_H
