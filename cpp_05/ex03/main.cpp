#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main()
{
	Bureaucrat::debug = false;
	Form::debug = false;
	PresidentialPardonForm::debug = false;
	ShrubberyCreationForm::debug = false;
	RobotomyRequestForm::debug = false;
	Intern::debug = false;

	
	std::cout << "------------------ test intern ---------------------- "<< std::endl;
	Intern	intern1;

	std::string test[5]={"", "robotomy request", "shrubbery creation", "presidential pardon", "Robotomy request"};

		Bureaucrat					Sylvester = Bureaucrat("Sylvester",1);
		Form	*f1;
		for (int i=0; i<5 ; i++)
		{
			f1 = intern1.makeForm(test[i], "bender");
			if (f1)
			{
				f1->beSigned(Sylvester);
				Sylvester.executeForm(*f1);
				std::cout << *f1 << std::endl;
				delete (f1);
			}
		}
	std::cout << "---------------------- FIN ---------------------- "<< std::endl;
	return (0);
}
