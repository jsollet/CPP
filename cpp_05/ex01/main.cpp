#include "Bureaucrat.hpp"
#include "Form.hpp"
int main()
{
	Bureaucrat::debug = false;
	Form::debug = false;


	std::cout << "---------------------- test Form (copy et =) ---------------------- "<< std::endl;
	/* test pour savoir si le bureaucrat a le bon niveau lors de la
	formation du formulaire
	*/
	Form f10("form 10", false, 24, 34);
	Form f11(f10);
	Form f12;
	f12 = f10;
	std::cout << "original:\t" << f10 << std::endl;
	std::cout << "copie:\t\t" << f11  << std::endl;
	std::cout << "op = :\t\t" << f12 << std::endl;

	std::cout << "---------------------- test Form (outrange) ---------------------- "<< std::endl;
	try
	{
		std::cout<< "start:\t\t" << "sign level = 0" << std::endl;
		Form	Formulaire = Form("formulaire",false, 0, 20);
		Formulaire.getName();
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout<< "start:\t\t" << "sign level = 151" << std::endl;
		Form	Formulaire1 = Form("formulaire",false, 151, 20);
		Formulaire1.getName();
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	try
	{
		std::cout<< "start:\t\t" << "exec level = 0" << std::endl;
		Form	Formulaire = Form("formulaire",false, 10, 0);
		Formulaire.getName();
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout<< "start:\t\t" << "exec level = 151" << std::endl;
		Form	Formulaire1 = Form("formulaire",false, 51, 151);
		Formulaire1.getName();
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "---------------- test bon niveau ----------------- "<< std::endl;

	try
	{
		Bureaucrat	Alfred = Bureaucrat("Alfred", 100);
		Bureaucrat	Sylvester = Bureaucrat("Sylvester",1);
		Form	F1 = Form("formulaire F1",false, 51, 15);
		std::cout<< magenta<< "start:\t\t" << Alfred << std::endl;
		std::cout<< "start:\t\t" << Sylvester << std::endl;

		std::cout<< "start:\t\t" << F1 << reset << std::endl;
	std::cout << "---------------- test signature ----------------- "<< std::endl;
		std::cout<< "Before Sylvester signs:\t\t" << F1 << std::endl;
		F1.beSigned(Sylvester);
		std::cout<< "after Sylvester signed:\t\t" << F1 << std::endl;
		Sylvester.signForm(F1);
		Form	F2 = Form("formulaire F2",false, 51, 15);
		std::cout << Alfred << std::endl << F2 << std::endl;
		std::cout<< "Before Alfred try to sign:\t\t" << std::endl;
		Alfred.signForm(F2);
		F2.beSigned(Alfred);
		std::cout<< "after Alfred tried to sign:\t\t" << F2 << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "---------------------- FIN ---------------------- "<< std::endl;
	return (0);
}
