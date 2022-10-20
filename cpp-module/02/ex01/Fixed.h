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

    int toInt() const;
    float toFloat() const;

    int getRawBits() const;
    void setRawBits(int const raw);

    ~Fixed();



private:
    int _raw;
    static const int _rawBits;
};

std::ostream &operator<<(std::ostream &out, Fixed const &value);


#endif
