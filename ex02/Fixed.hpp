#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					fixed_value;
		static const int	fract;
	public:
		Fixed();
		Fixed(const Fixed &obj);
		Fixed	&operator=(const Fixed &obj);
		Fixed	operator+(const Fixed &obj);
		Fixed	operator-(const Fixed &obj);
		Fixed	operator*(const Fixed &obj);
		Fixed	operator/(const Fixed &obj);
		Fixed	operator++(int);
		Fixed	operator--(int);
		Fixed	&operator++(void);
		Fixed	&operator--(void);
		bool	operator<(const Fixed &obj);
		bool	operator>(const Fixed &obj);
		bool	operator==(const Fixed &obj);
		bool	operator<=(const Fixed &obj);
		bool	operator>=(const Fixed &obj);
		bool	operator!=(const Fixed &obj);
		~Fixed();
		Fixed(const int p);
		Fixed(const float p);
		float			toFloat( void ) const;
		int				toInt( void ) const;
		int				getRawBits( void ) const;
		void			setRawBits( int const raw );
		static Fixed	&min(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a, const Fixed &b);
		static Fixed	&max(Fixed &a, Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);
};

std::ostream	&operator<<(std::ostream &os, const Fixed &obj);



#endif