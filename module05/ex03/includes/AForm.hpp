#pragma once

#include "Bureaucrat.hpp"

class AForm
{
	public:
		AForm(const std::string& formName, int signGrade, int executeGrade);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

		const std::string& getFormName() const;
		bool getIsSigned() const;
		int getSignGrade() const;
		int getExecuteGrade() const;

		void beSigned(const Bureaucrat& b);
		virtual void execute(const Bureaucrat& executor) const = 0;
		void executeOK(const Bureaucrat& executor) const;

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
		class FormNotSignedException : public std::exception
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

std::ostream& operator<<(std::ostream& os, const AForm& f);
