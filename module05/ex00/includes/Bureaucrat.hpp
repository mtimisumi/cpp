#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>

class Bureaucrat
{
	public:
		Bureaucrat(const std::string& name, int grade);

		const std::string& getName() const;
		int getGrade() const;

	private:
		const std::string _name;
		int _grade;
};

#endif