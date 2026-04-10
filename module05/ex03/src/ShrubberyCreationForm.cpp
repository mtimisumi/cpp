#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), _target(other._target)
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	AForm::executeOK(executor);
	std::ofstream outfile(_target + "_shrubbery");
	if (!outfile) {
		std::cout << "Error: could not create file\n";
		return ;
	}
	outfile <<	"           &&& &&  & &&        \n"
				"        && &||&||& ()|/ @,&&   \n"
				"      & ||(/&/&||/& /_/)_&/_&  \n"
				"   &() &||&|()|/&|| '%  & ()   \n"
				"  &_|_&&_| |& |&&/&__%_/_& &&  \n"
				"&& && & &| &|/& & % ()& /&&    \n"
				"  ()&_---()&|&||&&-&&--%---()~ \n"
				"       &&    ||||              \n"
				"               |||             \n"
				"               |||             \n"
				"               |||             \n"
				"        , -=-~  .-^- _         \n";
}
