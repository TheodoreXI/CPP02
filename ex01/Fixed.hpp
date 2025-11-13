#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <math.h>

class Fixed
{
	private:
		int					fixed_value;
		static const int	fract;
	public:
		Fixed();
		Fixed(const Fixed &obj);
		Fixed &operator=(const Fixed &obj);
		~Fixed();
		Fixed(const int p);
		Fixed(const float p);
		float			toFloat( void ) const;
		int				toInt( void ) const;
		int				getRawBits( void ) const;
		void			setRawBits( int const raw );
};

std::ostream	&operator<<(std::ostream &os, const Fixed &obj);



#endif