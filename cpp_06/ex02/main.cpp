#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>

// https://stackoverflow.com/questions/7560114/random-number-c-in-some-range
int random(int min, int max)
{
	static bool start = true;
	if (start)
	{
		srand(time(NULL));
		start = false;
	}
	return (min + rand() % (1 + max - min));
}

Base *generate(void)
{
	int	ran = random(1,3);
	switch (ran){
	case 1:
	{
		std::cout << "Instanciation of class :" << red << "A\n" << reset;
		return (new A);
	}
	case 2:
	{
		std::cout << "Instanciation of class :"  << green << "B\n"<< reset;
		return (new B);
	}
	case 3:
	{
		std::cout << "Instanciation of class :"  << cyan << "C\n" << reset;
		return (new C);
	}
	default:
	{
		return (NULL);
	}
	}
}


void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
	{
		std::cout << red << "Type of object is A\n" << reset;
	}
	else if (dynamic_cast<B*>(p) != NULL)
	{
		std::cout << green <<"Type of object is B\n" << reset;
	}
	else if (dynamic_cast<C*>(p) != NULL)
	{
		std::cout << cyan <<"Type of object is C\n"<< reset;
	}
	else
		std::cout << "unknown pointer type\n";
}


void identify(Base& p)
{
	try
	{
		A	&a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << red << "Type of object is A\n" << reset;

	}
	catch (std::exception &e){}

	try
	{
		B	&b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << green << "Type of object is B\n" << reset;
	}
	catch (std::exception &e){}

	try
	{
		C	&c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << cyan << "Type of object is C\n" << reset;;
	}
	catch (std::exception &e){}
	return ;
}

int main(void)
{
	Base	*ptr;
	for (int i=0;i != 20; i++)
	{
		ptr = generate();
		Base &ref = *ptr;
		std::cout <<i<< "\t" << "dynamic_cast< *>(ptr) (Identification from pointer) :\t";
		identify(ptr);
		// std::cout << std::endl;
		std::cout <<i<< "\t" << "dynamic_cast< &>(ptr) (Identification from reference) :\t";
		identify(ref);
		std::cout << std::endl;

		delete ptr;
	}
	return (0);
}
