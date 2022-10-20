#include "Fixed.h"

const int Fixed::_rawBits = 8;

Fixed::Fixed() {
    this->_raw = 0;
    cout << "Default constructor called" << endl;
}

Fixed::Fixed(const int fixednumber) {
    this->_raw = fixednumber * 256.0;
    cout << "Int constructor called" << endl;
}

Fixed::Fixed(const float fixednumber) {
    this->_raw = roundf(fixednumber * 256.0f);
    cout << "Float constructor called" << endl;
}

Fixed::Fixed(const Fixed &fixed) {
    cout << "Copy constructor called" << endl;
    this->setRawBits(fixed._raw);
}

Fixed &Fixed::operator=(Fixed const &fixed) {
    cout << "Copy assigment operator called" << endl;
    if (this == &fixed)
        return *this;
    this->_raw = fixed._raw;
    return *this;
}

int Fixed::toInt() const {
    return this->_raw / 256.0f;
}

float Fixed::toFloat() const {
    return this->_raw / 256.0f;
}


int Fixed::getRawBits() const {
    cout << "getRawBits member function called" << endl;
    return _raw;
}

void Fixed::setRawBits(const int raw) {
    this->_raw = raw;

}

Fixed::~Fixed() {
    cout << "Destructor called" << endl;
}


std::ostream& operator<<(std::ostream &out, Fixed const &value)
{
    out << value.toFloat();
    return (out);
}