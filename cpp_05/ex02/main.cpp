#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	Bureaucrat::debug = false;
	Form::debug = false;
	PresidentialPardonForm::debug = false;
	ShrubberyCreationForm::debug = false;
	RobotomyRequestForm::debug = false;
	
	std::cout << "------------------test  president. ---------------------- "<< std::endl;
	try
	{
		Bureaucrat					Alfred = Bureaucrat("Alfred", 100);
		Bureaucrat					Sylvester = Bureaucrat("Sylvester",1);
		PresidentialPardonForm		F1 = PresidentialPardonForm("Big Boss");
		std::cout<< "Before Sylvester signs:\t" << F1 << std::endl;
		F1.beSigned(Sylvester);
		std::cout<< "after Sylvester signed:\t" << F1 << std::endl;
		Sylvester.executeForm(F1);
		Alfred.executeForm(F1);
	}
	catch (std::exception &e)
	{
		std::cout <<e.what() << std::endl;
	}
	std::cout << "------------------test shrubbery  ---------------------- "<< std::endl;
	try
	{
		Bureaucrat					Alfred = Bureaucrat("Alfred", 100);
		Bureaucrat					Sylvester = Bureaucrat("Sylvester",1);
		ShrubberyCreationForm		F1 = ShrubberyCreationForm("Baobab");
		ShrubberyCreationForm		F2 = ShrubberyCreationForm("Platane");
		std::cout<< "Before Sylvester signs:\t" << F1 << std::endl;
		F1.beSigned(Sylvester);
		std::cout<< "after Sylvester signed:\t" << F1 << std::endl;
		Sylvester.executeForm(F1);
		Alfred.executeForm(F2);
	}
	catch (std::exception &e)
	{
		std::cout <<e.what() << std::endl;
	}
	std::cout << "------------------test robotomy  ---------------------- "<< std::endl;
	try
	{
		Bureaucrat					Alfred = Bureaucrat("Alfred", 100);
		Bureaucrat					Sylvester = Bureaucrat("Sylvester",1);
		RobotomyRequestForm			F1 = RobotomyRequestForm("Zombie 1");
		RobotomyRequestForm			F2 = RobotomyRequestForm("Zombie 2");
		std::cout<< "Before Sylvester signs:\t" << F1 << std::endl;
		F1.beSigned(Sylvester);
		std::cout<< "after Sylvester signed:\t" << F1 << std::endl;
		Sylvester.executeForm(F1);
		Sylvester.executeForm(F1);
		Sylvester.executeForm(F1);
		Sylvester.executeForm(F1);
		Sylvester.executeForm(F1);
		Sylvester.executeForm(F1);
		std::cout << std::endl;
		std::cout<< "Before Sylvester signs:\t" << F2 << std::endl;
		Alfred.executeForm(F2);
		F2.beSigned(Sylvester);
		std::cout<< "after Sylvester signed:\t" << F2 << std::endl;
		Alfred.executeForm(F2);
	}
	catch (std::exception &e)
	{
		std::cout <<e.what() << std::endl;
	}
	
	std::cout << "---------------------- FIN ---------------------- "<< std::endl;
	return (0);
}
