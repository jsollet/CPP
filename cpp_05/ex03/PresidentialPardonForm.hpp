#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class PresidentialPardonForm: public Form
{
	public:
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &ppf);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);
		~PresidentialPardonForm();

		const std::string	getTarget(void) const;

		bool				execute(const Bureaucrat &executor) const;
		static bool			debug;

	private:
		const std::string	target;
		PresidentialPardonForm();

};

#endif
