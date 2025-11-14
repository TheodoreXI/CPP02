#include "Fixed.hpp"

const int	Fixed::fract = 8;

Fixed::Fixed(void): fixed_value(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &obj)
{
	std::cout << "Copy constructor called\n";
	*this = obj;
}

Fixed &Fixed::operator=(const Fixed &obj)
{
	std::cout << "Copy assignment operator called\n";
	this->fixed_value = obj.getRawBits();
	return (*this);
}

int	Fixed::getRawBits( void ) const
{
	return (fixed_value);
}

void	Fixed::setRawBits( int const raw )
{
	fixed_value = raw << fract;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed::Fixed(const int p)
{
	std::cout << "Int constructor called\n";
	fixed_value = p << fract;
}

Fixed::Fixed(const float p)
{
	std::cout << "Float constructor called\n";
	fixed_value = p * (1 << fract);
}

float	Fixed::toFloat(void) const
{
	return ((float)fixed_value / (1 << fract));
}

int	Fixed::toInt(void) const
{
	return (fixed_value / (1 << fract));
}

std::ostream	&operator<<(std::ostream &os, const Fixed &obj)
{
	os << obj.toFloat();
	return (os);
}