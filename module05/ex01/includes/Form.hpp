#pragma once

#include "Bureaucrat.hpp"

class Form
{
	public:
		Form(const std::string& formName, int signGrade, int executeGrade);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		const std::string& getFormName() const;
		bool getIsSigned() const;
		int getSignGrade() const;
		int getExecuteGrade() const;

		void beSigned(const Bureaucrat& b);

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
		const std::string	_formName;
		bool 				_isSigned = false;
		const int			_signGrade;
		const int			_executeGrade;
};

std::ostream& operator<<(std::ostream& os, const Form& f);
