#pragma once

#include "Bureaucrat.hpp"
#include <iomanip>

class AForm
{
	private:
		const std::string	_formName;
		bool 				_isSigned = false;
		const int			_signGrade;
		const int			_executeGrade;

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
		virtual void execute(const Bureaucrat& executor) const;
		virtual void printTarget(std::ostream& os) const = 0;

	protected:
		virtual void executeAction() const = 0;

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
		class FormAlreadySignedException : public std::exception
		{
			public:
				const char* what() const noexcept override;
		};
		class FormNotSignedException : public std::exception
		{
			public:
				const char* what() const noexcept override;
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& f);
