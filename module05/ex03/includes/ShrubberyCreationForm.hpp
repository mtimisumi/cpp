#pragma once

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm() override;

		void executeAction() const override;
		void printTarget(std::ostream& os) const override;

	private:
		std::string _target;
};