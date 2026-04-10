#include "AForm.hpp"

AForm::AForm(const std::string& formName, int signGrade, int executeGrade)
	: _formName(formName),  _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (_signGrade < MAX_GRADE || _executeGrade < MAX_GRADE)
		throw GradeTooHighException();
	if (_signGrade > MIN_GRADE || _executeGrade > MIN_GRADE)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
	: _formName(other._formName), _isSigned(other._isSigned),
	  _signGrade(other._signGrade), _executeGrade(other._executeGrade)
{}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other) {
		_isSigned = other._isSigned;
	}
	return *this;
}

AForm::~AForm()
{}

const std::string& AForm::getFormName() const
{
	return _formName;
}

bool AForm::getIsSigned() const
{
	return _isSigned;
}

int AForm::getSignGrade() const
{
	return _signGrade;
}

int AForm::getExecuteGrade() const
{
	return _executeGrade;
}

void AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > _signGrade)
		throw GradeTooLowException();
	_isSigned = true;
}

void AForm::executeOK(const Bureaucrat& executor) const
{
	if (!_isSigned)
		throw FormNotSignedException();
	if (executor.getGrade() > _executeGrade)
		throw GradeTooLowException();
}

const char*	AForm::GradeTooHighException::what() const noexcept
{
	return "Grade is too high";
}

const char*	AForm::GradeTooLowException::what() const noexcept
{
	return "Grade is too low";
}

const char* AForm::FormNotSignedException::what() const noexcept
{
	return "Form is not signed";
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
	os << f.getFormName() << " with sign grade " << f.getSignGrade()
		<< " and execute grade " << (f.getExecuteGrade() ? "signed" : "unsigned");

	// we should call a virtual function that will print our data

	return os;
}