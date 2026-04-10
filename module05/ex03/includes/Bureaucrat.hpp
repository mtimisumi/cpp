#pragma once

#include <iostream>
#include <string>

#define MAX_GRADE 1
#define MIN_GRADE 150

class AForm;

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

		void signForm(AForm& form);
		void executeForm(const AForm& form);

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
