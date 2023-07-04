#include "Span.hpp"

int main()
{
	Span sp = Span(5);
	Span sp1 = Span(5);
	std::cout << "\n-------------  Test addNumber  -------------\n\n";
	std::cout << "taille allouée du span = " << sp.getSize() << std::endl << std::endl;
	sp.addNumber(1); 
	sp.print(green, reset);
	sp.addNumber(2);
	sp.print(green, reset);
	sp.addNumber(3);
	std::cout << "\n-------------  Test sp1=sp  -------------\n\n";
	sp1 = sp;
	sp.print(green, reset);
	sp.addNumber(4);
	sp.print(green, reset);
	std::cout << "\n-------------  Test sp2(sp)  -------------\n\n";
 	Span sp2(sp);
	sp.addNumber(5);
	sp.print(green, reset);
	sp.addNumber(6);
	sp.print(green, reset);
	sp.addNumber(7);
	sp.print(green, reset);
	sp.addNumber(8);
	sp.print(green, reset);
	sp.addNumber(9);
	sp.print(green, reset);
	std::cout << "\n-------------  Test operator=  -------------\n\n";
	sp.print(green, reset);
	sp1.print(red, reset);
	std::cout << "\n-------------    Test Copie    -------------\n\n";
	sp.print(green, reset);
	sp2.print(red, reset);
	std::cout << "\n-------------    Test Populate    -------------\n\n";
	try
	{
	std::cout << "\n-----------    exception too big    -----------\n\n";
	Span err = Span(4444);
	err.populate(-10000000 , 10000000, 500000);
	}
	catch(const std::exception& e)
	{
		std::cerr << red << e.what() << reset << std::endl;
	}

	try
	{
	std::cout << "\n--------    exception negative arg.    --------\n\n";
	Span err = Span(4444);
	err.populate(-10000000 , 10000000, -2);
	}
	catch(const std::exception& e)
	{
		std::cerr << red << e.what() << reset << std::endl;
	}	

	try
	{
	std::cout << "\n--------    exception inverted arg.    --------\n\n";
	Span err = Span(4444);
	err.populate(10000000 , -10000000, 100);
	}
	catch(const std::exception& e)
	{
		std::cerr << red << e.what() << reset << std::endl;
	}	
	
	std::cout << "\n----------- 2 fois spanning 25 numbers -----------\n\n";
	Span spp = Span(50);
	spp.populate(0 , 10000, 25);
	spp.print(cyan,reset);
	spp.populate(-10000,0, 25);
	spp.print(cyan,reset);
	std::cout << "min = " << spp.min()<<std::endl;
	std::cout << "max = " << spp.max()<<std::endl;
	std::cout << "shortest span = "<< spp.shortestSpan() << std::endl;
	std::cout << "longest span = "<< spp.longestSpan() << std::endl;
	spp.print(red, reset);
	std::cout << "\n-----------  spanning 500000 numbers   -----------\n\n";
	Span spp1 = Span(500000);
	spp1.populate(-10000000 , 10000000, 500000);
	std::cout << "min = " << spp1.min()<<std::endl;
	std::cout << "max = " << spp1.max()<<std::endl;
	std::cout << "shortest span = "<< spp1.shortestSpan() << std::endl;
	std::cout << "longest span = "<< spp1.longestSpan() << std::endl;
	std::cout << "\n-------------  fin programme  -------------\n";
	return 0;
}
