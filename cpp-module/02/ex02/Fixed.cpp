#include "Fixed.h"

const int Fixed::_rawBits = 8;

Fixed::Fixed() {
    this->_raw = 0;
    //cout << "Default constructor called" << endl;
}

Fixed::Fixed(const int fixednumber) {
    this->_raw = fixednumber * 256.0;
    //cout << "Int constructor called" << endl;
}

Fixed::Fixed(const float fixednumber) {
    this->_raw = roundf(fixednumber * 256.0f);
    //cout << "Float constructor called" << endl;
}

Fixed::Fixed(const Fixed &fixed) {
    //cout << "Copy constructor called" << endl;
    this->setRawBits(fixed._raw);
}

Fixed &Fixed::operator=(Fixed const &fixed) {
    //cout << "Copy assigment operator called" << endl;
    if (this == &fixed)
        return *this;
    this->_raw = fixed._raw;
    return *this;
}

bool Fixed::operator>(const Fixed &fixed) {
    return this->_raw > fixed._raw;
}

bool Fixed::operator<(const Fixed &fixed) {
    return this->_raw < fixed._raw;
}

bool Fixed::operator>=(const Fixed &fixed) {
    return this->_raw >= fixed._raw;
}

bool Fixed::operator<=(const Fixed &fixed) {
    return this->_raw <= fixed._raw;
}

bool Fixed::operator==(const Fixed &fixed) {
    return this->_raw == fixed._raw;
}

bool Fixed::operator!=(const Fixed &fixed) {
    return this->_raw != fixed._raw;
}

Fixed Fixed::operator+(const Fixed &fixed) {
    this->_raw += fixed._raw;
    return *this;
}

Fixed Fixed::operator-(const Fixed &fixed) {
    this->_raw -= fixed._raw;
    return *this;
}

Fixed Fixed::operator*(const Fixed &fixed) {
    this->_raw *= fixed.toInt();
    return *this;
}

Fixed Fixed::operator/(const Fixed &fixed) {
    this->_raw = this->toFloat() * fixed.toFloat();
    return *this;
}

Fixed Fixed::operator++() {
    this->_raw++;
    return *this;
}

Fixed Fixed::operator--() {
    --this->_raw;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp(*this);
    this->_raw++;
    return tmp;
}

Fixed Fixed::operator--(int) {
    Fixed tmp(*this);
    this->_raw--;
    return tmp;
}


int Fixed::toInt() const {
    return this->_raw / 256.0f;
}

float Fixed::toFloat() const {
    return this->_raw / 256.0f;
}


int Fixed::getRawBits() const {
    //cout << "getRawBits member function called" << endl;
    return _raw;
}

void Fixed::setRawBits(const int raw) {
    this->_raw = raw;

}

Fixed::~Fixed() {
    //cout << "Destructor called" << endl;
}

Fixed &Fixed::min(Fixed &fixednumber, Fixed &fixednumber2) {
    return fixednumber._raw < fixednumber2._raw ? fixednumber : fixednumber2;
}

const Fixed &Fixed::min(const Fixed &fixednumber, const Fixed &fixednumber2) {
    return fixednumber._raw < fixednumber2._raw ? fixednumber : fixednumber2;
}

Fixed &Fixed::max(Fixed &fixednumber, Fixed &fixednumber2) {
    return fixednumber._raw > fixednumber2._raw ? fixednumber : fixednumber2;
}

const Fixed &Fixed::max(const Fixed &fixednumber, const Fixed &fixednumber2) {
    return fixednumber._raw > fixednumber2._raw ? fixednumber : fixednumber2;
}


std::ostream& operator<<(std::ostream &out, Fixed const &value)
{
    out << value.toFloat();
    return (out);
}