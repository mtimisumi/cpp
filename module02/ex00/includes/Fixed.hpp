#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed
{
	public:
		Fixed();
		~Fixed();


	private:
		int					value;
		static const int	fractional = 8;

};

#endif