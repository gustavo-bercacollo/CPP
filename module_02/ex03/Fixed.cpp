#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) : _value(0)
{
  //std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
  //std::cout << "Int constructor called" << std::endl;
  _value = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
  //std::cout << "Float constructor called" << std::endl;
  _value = roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& other)
{
  //std::cout << "Copy constructor called" << std::endl;
  *this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
  //std::cout << "Copy assignment operator called" << std::endl;
  if (this != &other)
      _value = other._value;
  return *this;
}

Fixed::~Fixed(void)
{
  //std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat(void) const
{
  return (float)_value / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
  return _value >> _fractionalBits;
}

int Fixed::getRawBits(void) const
{
  return _value;
}

void Fixed::setRawBits(int const raw)
{
  _value = raw;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
  out << fixed.toFloat();
  return out;
}

bool Fixed::operator>(const Fixed& other) const
{
  return this->_value > other._value;
}

bool Fixed::operator<(const Fixed& other) const
{
  return this->_value < other._value;
}

bool Fixed::operator>=(const Fixed& other) const
{
  return this->_value >= other._value;
}

bool Fixed::operator<=(const Fixed& other) const
{
  return this->_value <= other._value;
}

bool Fixed::operator==(const Fixed& other) const
{
  return this->_value == other._value;
}

bool Fixed::operator!=(const Fixed& other) const
{
  return this->_value != other._value;
}

Fixed Fixed::operator+(const Fixed& other) const
{
  Fixed sum;
  sum.setRawBits(this->_value + other._value);
  return sum;
}

Fixed Fixed::operator-(const Fixed& other) const
{
  Fixed sub;
  sub.setRawBits(this->_value - other._value);
  return sub;
}

Fixed Fixed::operator*(const Fixed& other) const
{
  Fixed mul;
  mul.setRawBits((this->_value * other._value) >> _fractionalBits);
  return mul;
}

Fixed Fixed::operator/(const Fixed& other) const
{
  Fixed div;
  div.setRawBits((this->_value << _fractionalBits) / other._value);
  return div;
}

Fixed& Fixed::operator++()
{
  _value++;
  return *this;
}

Fixed Fixed::operator++(int)
{
  Fixed temp(*this);
  _value += 1;
  return temp;
}

Fixed& Fixed::operator--()
{
  _value--;
  return *this;
}

Fixed Fixed::operator--(int)
{
  Fixed temp(*this);
  _value -= 1;
  return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
  return (a < b ? a : b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
  return (a < b ? a : b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
  return (a > b ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
  return (a > b ? a : b);
}
