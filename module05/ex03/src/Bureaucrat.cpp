#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade)
	: _name(name), _grade(grade)
{
	if (_grade < MAX_GRADE)
		throw GradeTooHighException();
	if (_grade > MIN_GRADE)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	: _name(other._name), _grade(other._grade)
{}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other) {
		_grade = other._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{}

const std::string& Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::incrementGrade()
{
	if (_grade - 1 < MAX_GRADE)
		throw GradeTooHighException();
	_grade -= 1;
}

void Bureaucrat::decrementGrade()
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

void Bureaucrat::signForm(AForm& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " succesfully signed form " << form.getFormName()
			<< std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << _name << " couldn't sign form " << form.getFormName()
			<< " because: " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(const AForm& form)
{
	try
	{
		form.execute(*this);
		std::cout << _name << " succesfully executed form " << form.getFormName()
			<< std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << _name << " couldn't execute form " << form.getFormName()
			<< " because: " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}
