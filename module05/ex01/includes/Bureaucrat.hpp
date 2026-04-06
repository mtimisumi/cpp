#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

# define MAX_GRADE 1
# define MIN_GRADE 150

class Bureaucrat
{
	public:
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		const std::string& getName() const;
		int getGrade() const;

		void incrementGrade();
		void decrementGrade();

		void beSigned();

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
		std::string	_name;
		int			_grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif