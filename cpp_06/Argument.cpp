#include "Argument.hpp"

bool	Argument::debug = false;

Argument::Argument(): argv("")
{
if (Argument::debug)
		std::cout << "Default constructor Argument" << std::endl;
}

Argument::Argument(const std::string &input)
	:argv(input)
{
	if (Argument::debug)
		std::cout << "Param. constructor Argument" << std::endl;
}

Argument::Argument(Argument const &rhs): argv(rhs.getArgv()),
arg_t(rhs.getType())
{
	if (Argument::debug)
		std::cout << "Copy. constructor Argument" << std::endl;
}

Argument	&Argument::operator=(const Argument &rhs)
{
	if (this != &rhs)
	{
		this->argv = rhs.getArgv();//pb la avec const...
		this->arg_t = rhs.getType();
	}
	if (Argument::debug)
		std::cout << "Op =  Argument" << std::endl;
	return (*this);
}

Argument::~Argument()
{
	if (Argument::debug)
		std::cout << "Destructor  Argument" << std::endl;
}

const std::string	&Argument::getArgv() const
{
	return (this->argv);
}

unsigned int		Argument::getType() const
{
	return (this->arg_t);
}

bool	Argument::is_char_print()
{// ici...
	char	tmp = this->argv[0];
//	if (isdigit(tmp))
//		printf("----->%c\n", tmp);
	
	if (this->argv.length() == 1 && isdigit(tmp) == false)
	{
		int		ascii=static_cast<int>(this->argv[0]);
		printf("%d\n", ascii);
		if (ascii > 32 && ascii < 127)
			return (true);
		else
			return (false);
	/*	char	tmp = input[0];
		if (isprint(tmp))
			return (true);
		else
			return (false);
	*/
	}
	else
		return (false);
	
}
