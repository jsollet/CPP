
#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class RobotomyRequestForm: public Form
{
	public:
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &ppf);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);
		~RobotomyRequestForm();

		const std::string	getTarget(void) const;

		bool				execute(const Bureaucrat &executor) const;
		static bool			debug;

	private:
		const std::string	target;
		RobotomyRequestForm();

};

#endif
