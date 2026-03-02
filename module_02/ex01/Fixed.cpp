#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) : _rawBits(0)
{
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
  std::cout << "Int constructor called" << std::endl;
  _rawBits = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
  std::cout << "Float constructor called" << std::endl;
  _rawBits = roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& other)
{
  std::cout << "Copy constructor called" << std::endl;
  *this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &other)
      _rawBits = other._rawBits;
  return *this;
}

Fixed::~Fixed(void)
{
  std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat(void) const
{
  return (float)_rawBits / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
  return _rawBits >> _fractionalBits;
}

int Fixed::getRawBits(void) const
{
  return _rawBits;
}

void Fixed::setRawBits(int const raw)
{
  _rawBits = raw;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
  out << fixed.toFloat();
  return out;
}
