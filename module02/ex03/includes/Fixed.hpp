#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

# define FRACTBITS 8

class	Fixed
{
	public:
		Fixed();
		~Fixed();
		Fixed(int const value);
		Fixed(float const value);
		Fixed(const Fixed& other);
		Fixed&	operator=(const Fixed& other);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		int		toInt(void) const;
		float	toFloat(void) const;

		bool	operator>(const Fixed& other) const;
		bool	operator<(const Fixed& other) const;
		bool	operator>=(const Fixed& other) const;
		bool	operator<=(const Fixed& other) const;
		bool	operator==(const Fixed& other) const;
		bool	operator!=(const Fixed& other) const;

		Fixed	operator+(const Fixed& other) const;
		Fixed	operator-(const Fixed& other) const;
		Fixed	operator*(const Fixed& other) const;
		Fixed	operator/(const Fixed& other) const;

		Fixed&	operator++();
		Fixed	operator++(int);
		Fixed&	operator--();
		Fixed	operator--(int);

		static Fixed&			min(Fixed& a, Fixed& b);
		static Fixed&			max(Fixed& a, Fixed& b);
		static const Fixed&		min(const Fixed& a, const Fixed& b);
		static const Fixed&		max(const Fixed& a, const Fixed& b);

	private:
		int					_rawBits;
		static const int	_fractBits = FRACTBITS;
};

std::ostream&	operator<<(std::ostream& os, const Fixed& fx);

#endif