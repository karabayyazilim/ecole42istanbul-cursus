#include <iomanip>
#include "PhoneBook.h"

PhoneBook::PhoneBook() {
    index = 0;
    size = 0;
}

bool PhoneBook::addContact(const string &firstName, const string &lastName, const string &nickName,
                           const string &phoneNumber, const string &darkestSecret) {
    if (index > 7)
        index = 0;
    if(size < 8)
        size++;
    if(firstName.empty() || lastName.empty() || nickName.empty() || phoneNumber.empty())
        return false;
    _contacts[index].setFirstName(firstName);
    _contacts[index].setLastName(lastName);
    _contacts[index].setNickName(nickName);
    _contacts[index].setPhoneNumber(phoneNumber);
    _contacts[index].setDarkestSecret(darkestSecret);
    index++;
    return true;
}

bool PhoneBook::showContactID(int index) {
    if(index > size)
        return false;
    cout << std::setw(5) << index << "|";
    cout << formatString(_contacts[index].getFirstName()) << "|";
    cout << formatString(_contacts[index].getLastName()) << "|";
    cout << formatString(_contacts[index].getNickName()) << "|" << endl;
    return true;
}

void PhoneBook::showContacts() {
    for(int i = 0; i < size; i++)
        showContactID(i);
}

const string PhoneBook::formatString(const string &text) {
    string tmp;
    if (text.length() > 10)
        return text.substr(0, 9) + '.';
    for (int i = 10 - text.length(); i > 0; i--)
        tmp.append(" ");
    tmp.append(text);
    return tmp;
}

bool PhoneBook::isNumber(const string text) {
    for(int i = text.length() - 1; i >= 0; i--)
        if(!(text[i] >= '0' && text[i] <= '9'))
            return false;
    return true;
}
