#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

# define FRACTBITS 8

class	Fixed
{
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed& other);
		Fixed&	operator=(const Fixed& other);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:
		int					_rawBits;
		static const int	_fracBits = FRACTBITS;
};

#endif