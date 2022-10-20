#ifndef _FIXED_H_
#define _FIXED_H_

#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

class Fixed {
public:
    Fixed();
    Fixed(const int fixednumber);
    Fixed(const float fixednumber);
    Fixed(const Fixed& fixed);

    Fixed& operator=(Fixed const &fixed);
    bool operator>(Fixed const &fixed);
    bool operator<(Fixed const &fixed);
    bool operator<=(Fixed const &fixed);
    bool operator>=(Fixed const &fixed);
    bool operator==(Fixed const &fixed);
    bool operator!=(Fixed const &fixed);

    Fixed operator+(Fixed const &fixed);
    Fixed operator-(Fixed const &fixed);
    Fixed operator*(Fixed const &fixed);
    Fixed operator/(Fixed const &fixed);

    Fixed operator++();
    Fixed operator--();
    Fixed operator++(int);
    Fixed operator--(int);

    int toInt() const;
    float toFloat() const;

    int getRawBits() const;
    void setRawBits(int const raw);

    static Fixed& min(Fixed& fixednumber, Fixed& fixednumber2);
    static const Fixed& min(Fixed const &fixednumber, Fixed const &fixednumber2);
    static Fixed& max(Fixed& fixednumber, Fixed& fixednumber2);
    static const Fixed& max(Fixed const &fixednumber, Fixed const &fixednumber2);

    ~Fixed();



private:
    int _raw;
    static const int _rawBits;
};

std::ostream &operator<<(std::ostream &out, Fixed const &value);


#endif
