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

void ShrubberyCreationForm::executeAction() const
{
	std::ofstream outfile(_target + "_shrubbery");
	if (!outfile.is_open()) {
		throw std::runtime_error("Failed to create file");
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
