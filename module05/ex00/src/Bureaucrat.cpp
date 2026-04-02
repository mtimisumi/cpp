#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade)
: _name(name), _grade(grade)
{
	if (_grade < MAX_GRADE)
		throw GradeTooHighException();
	if (_grade > MIN_GRADE)
		throw GradeTooLowException();
}

const std::string&	Bureaucrat::getName() const
{
	return _name;
}

int	Bureaucrat::getGrade() const
{
	return _grade;
}

void	Bureaucrat::incrementGrade()
{
	if (_grade - 1 < MAX_GRADE)
	throw GradeTooHighException();
	_grade -= 1;
}

void	Bureaucrat::decrementGrade()
{
	if (_grade + 1 > MIN_GRADE)
		throw GradeTooLowException();
	_grade += 1;
}

const char*	Bureaucrat::GradeTooHighException::what() const noexcept
{
	return "Grade is too high";
}

const char*	Bureaucrat::GradeTooLowException::what() const noexcept
{
	return "Grade is too low";
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}