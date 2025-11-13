#include "Fixed.hpp"

const int	Fixed::fract = 8;

Fixed::Fixed(void): fixed_value(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &obj)
{
	std::cout << "Copy constructor called\n";
	fixed_value = obj.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &obj)
{
	std::cout << "Copy assignment operator called\n";
	this->fixed_value = obj.getRawBits();
	return (*this);
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called\n";
	return (fixed_value);
}

void	Fixed::setRawBits( int const raw )
{
	fixed_value = raw << fract;
	std::cout << "setRawBits member function called\n";
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}