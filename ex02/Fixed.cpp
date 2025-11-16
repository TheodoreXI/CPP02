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
	
	os << "raw value " << obj.getRawBits() << "\n" << obj.toFloat();
	return (os);
}

Fixed	Fixed::operator+(const Fixed &obj)
{
	return (Fixed(this->fixed_value+obj.fixed_value));
}

Fixed	Fixed::operator-(const Fixed &obj)
{
	return (Fixed(this->fixed_value-obj.fixed_value));
}

Fixed	Fixed::operator*(const Fixed &obj)
{
	Fixed a(this->toFloat() * obj.toFloat());
	return (a);
}

Fixed	Fixed::operator/(const Fixed &obj)
{
	return (Fixed(this->fixed_value/obj.fixed_value));
}

Fixed	Fixed::operator++(int a)
{
	Fixed cpy;
	cpy = *this;
	this->fixed_value += 1;
	return (cpy);
}

Fixed	Fixed::operator--(int a)
{
	Fixed cpy;
	cpy = *this;
	this->fixed_value -= 1;
	return (cpy);
}

Fixed	&Fixed::operator++(void)
{
	this->fixed_value += 1;
	return (*this);
}

Fixed	&Fixed::operator--(void)
{
	this->fixed_value -= 1;
	return (*this);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a.fixed_value < b.fixed_value)
		return (a);
	return (b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.fixed_value < b.fixed_value)
		return (a);
	return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a.fixed_value > b.fixed_value)
		return (a);
	return (b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.fixed_value > b.fixed_value)
		return (a);
	return (b);
}

bool	Fixed::operator<(const Fixed &obj)
{
	if (this->fixed_value < obj.fixed_value)
		return (true);
	return (false);
}

bool	Fixed::operator>(const Fixed &obj)
{
	if (this->fixed_value > obj.fixed_value)
		return (true);
	return (false);
}

bool	Fixed::operator==(const Fixed &obj)
{
	if (this->fixed_value == obj.fixed_value)
		return (true);
	return (false);
}

bool	Fixed::operator<=(const Fixed &obj)
{
	if (this->fixed_value <= obj.fixed_value)
		return (true);
	return (false);
}

bool	Fixed::operator>=(const Fixed &obj)
{
	if (this->fixed_value >= obj.fixed_value)
		return (true);
	return (false);
}

bool	Fixed::operator!=(const Fixed &obj)
{
	if (this->fixed_value != obj.fixed_value)
		return (true);
	return (false);
}
