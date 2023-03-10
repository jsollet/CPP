#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat::debug = false;


	try
	{
		std::cout << "------------- out of range --------------- "<< std::endl;
		std::cout<< "start:\t\t" << "Alfred = 0" << std::endl;
		Bureaucrat	Alfred = Bureaucrat("Alfred", 0);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << "------------- out of range --------------- "<< std::endl;
		std::cout<< "start:\t\t" << "Alfred = 151" << std::endl;
		Bureaucrat	Alfred = Bureaucrat("Alfred", 151);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << "--------------- increment ---------------- "<< std::endl;
		Bureaucrat	Alfred = Bureaucrat("Alfred", 3);
		std::cout<< "start:\t\t" << Alfred << std::endl;
		++Alfred;
		std::cout<< "++increment:\t"<< Alfred << std::endl;
		Alfred++;
		std::cout<< "increment++:\t"<< Alfred << std::endl;
		Alfred++;
		std::cout<< "increment++:\t"<< Alfred << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << "--------------- decrement ---------------- "<< std::endl;
		Bureaucrat	Alfred = Bureaucrat("Alfred", 148);
		std::cout<< "start:\t\t" << Alfred << std::endl;
		--Alfred;
		std::cout<< "--decrement:\t"<< Alfred << std::endl;
		Alfred--;
		std::cout<< "decrement--:\t"<< Alfred << std::endl;
		Alfred--;
		std::cout<< "decrement--:\t"<< Alfred << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << "----------------- ++/-- ------------------ "<< std::endl;
		Bureaucrat	Alfred = Bureaucrat("Alfred", 100);
		std::cout<< "start:\t\t" << Alfred << std::endl;
		--Alfred;
		std::cout<< "--decrement:\t"<< Alfred << std::endl;
		Alfred--;
		std::cout<< "decrement--:\t"<< Alfred << std::endl;
		Alfred--;
		std::cout<< "decrement--:\t"<< Alfred << std::endl;
		++Alfred;
		std::cout<< "++increment:\t"<< Alfred << std::endl;
		Alfred++;
		std::cout<< "increment++:\t"<< Alfred << std::endl;
		Alfred++;
		std::cout<< "increment++:\t"<< Alfred << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
