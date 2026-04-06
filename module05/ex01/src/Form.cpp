#include "Form.hpp"

Form::Form(const std::string& formName, int signGrade, int executeGrade)
	: _formName(formName),  _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (_signGrade < MAX_GRADE || _executeGrade < MAX_GRADE)
		throw GradeTooHighException();
	if (_signGrade > MIN_GRADE || _executeGrade > MIN_GRADE)
		throw GradeTooLowException();
}

Form::Form(const Form& other)
	: _formName(other._formName), _isSigned(other._isSigned),
	  _signGrade(other._signGrade), _executeGrade(other._executeGrade)
{}

Form& Form::operator=(const Form& other)
{
	if (this != &other) {
		_isSigned = other._isSigned;
	}
	return *this;
}

Form::~Form()
{}

const std::string& Form::getFormName() const
{
	return _formName;
}

bool Form::getIsSigned() const
{
	return _isSigned;
}

int Form::getSignGrade() const
{
	return _signGrade;
}

int Form::getExecuteGrade() const
{
	return _executeGrade;
}

void Form::beSigned(const Bureaucrat& b)
{
	if (_isSigned) {
		std::cout << b.getName() << " couldn't sign " << _formName
			<< " because the form is already signed\n";
		return ;
	}
	if (_signGrade < b.getGrade()) {
		std::cout << b.getName() << " couldn't sign " << _formName
			<< " because the grade is too low to sign\n";
		return ;
	}
	_isSigned = true;
}

const char*	Form::GradeTooHighException::what() const noexcept
{
	return "Grade is too high";
}

const char*	Form::GradeTooLowException::what() const noexcept
{
	return "Grade is too low";
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
	os << f.getFormName() << " with sign grade " << f.getSignGrade()
		<< " and execute grade " << (f.getExecuteGrade() ? "signed" : "unsigned");

	return os;
}