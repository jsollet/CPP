#include <iostream>

int	main(void)
{
	std::string		str = "HI THIS IS BRAIN";
	std::string		*stringPTR = &str;
	std::string		&stringREF = str;

	std::cout<<"adresse de la string: "<< "\t\t" << &str << std::endl;
	std::cout<<"adresse dans stringPTR: "<<"\t" << stringPTR << std::endl;
	std::cout<<"adresse dans stringREF: "<< "\t" << &stringREF << std::endl << std::endl;
	std::cout<<"valeur de la string: "<< "\t\t" << str << std::endl;
	std::cout<<"valeur pointee dans stringPTR: "<< "\t"<< *stringPTR << std::endl;
	std::cout<<"valeur pointee dans stringREF: "<< "\t" << stringREF << std::endl;
	return (0);
}
