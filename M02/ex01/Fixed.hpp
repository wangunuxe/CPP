#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
private:
    int _rawBits;
    static const int _fractionalBits;
public:
    Fixed();
    Fixed(int const n);
    Fixed(float const f);

    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);

    ~Fixed();

    int getRawBits(void) const;
    void setRawBits(int const raw);

    float toFloat(void) const;
    int toInt(void) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& f);

#endif 

// ***"<<" is a binary operator***
//     **When you write: std::cout << a
//       The compiler rewrites it as: operator<<(std::cout, a);
// ***ixed(int const n)
    // Fixed(int const n) is a constructor to initialize a Fixed object :  converts n into the fixed-point representation defined by the class and uses that representation to initialize the object’s internal state (_rawBits).