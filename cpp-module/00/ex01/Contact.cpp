#include "Contact.h"

const string& Contact::getFirstName() {
    return this->_firstName;
}

void Contact::setFirstName(const string &firstName) {
    this->_firstName = firstName;
}

const string &Contact::getLastName() {
    return this->_lastName;
}

void Contact::setLastName(const string &lastName) {
    this->_lastName = lastName;
}

const string &Contact::getNickName() {
    return this->_nickName;
}

void Contact::setNickName(const string &nickName) {
    this->_nickName = nickName;
}

const string &Contact::getPhoneNumber() {
    return this->_phoneNumber;
}

void Contact::setPhoneNumber(const string &phoneNumber) {
    this->_phoneNumber = phoneNumber;
}

const string &Contact::getDarkestSecret() {
    return this->_darkestSecret;
}

void Contact::setDarkestSecret(const string &darkestSecret) {
    this->_darkestSecret = darkestSecret;
}


