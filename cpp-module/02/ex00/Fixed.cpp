#include "Fixed.h"

const int Fixed::_rawBits = 8;

Fixed::Fixed() {
    this->_raw = 0;
    cout << "Default constructor called" << endl;
}

Fixed::Fixed(const Fixed &fixed) {
    cout << "Copy constructor called" << endl;
    this->setRawBits(fixed.getRawBits());
}

Fixed &Fixed::operator=(Fixed &fixed) {
    cout << "Copy assigment operator called" << endl;
    if (this == &fixed)
        return *this;
    this->_raw = fixed.getRawBits();
    return *this;
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