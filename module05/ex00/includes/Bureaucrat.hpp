#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

# define MAX_GRADE 1
# define MIN_GRADE 150

class Bureaucrat
{
	public:
		// default constructor
		Bureaucrat(const std::string& name, int grade);

		const std::string& getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();

	private:
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const noexcept override;
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const noexcept override;
		};

	private:
		const std::string	_name;
		int					_grade;
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& b);

#endif