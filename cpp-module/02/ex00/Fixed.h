#ifndef _FIXED_H_
#define _FIXED_H_

#include <iostream>

using std::cout;
using std::endl;

class Fixed {
public:
    Fixed();
    Fixed(const Fixed& fixed);
    Fixed& operator=(Fixed& fixed);

    int getRawBits() const;
    void setRawBits(int const raw);

    ~Fixed();

private:
    int _raw;
    static const int _rawBits;
};


#endif
