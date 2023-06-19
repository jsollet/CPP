#include "ScalarConverter.hpp"

ScalarConverter::type_arg			ScalarConverter::type = unknow;
ScalarConverter::specialNumber 		ScalarConverter::flag = ras;

bool								ScalarConverter::debug = false;
std::string							ScalarConverter::argv = "";
unsigned int						ScalarConverter::arg_t = 0;
char								ScalarConverter::convertedChar = ' ';
int									ScalarConverter::convertedInt = 0;
float								ScalarConverter::convertedFloat = 0.0f;
double								ScalarConverter::convertedDouble = 0.0;

ScalarConverter::ScalarConverter()
{
if (ScalarConverter::debug)
		std::cout << "Default constructor ScalarConverter" << std::endl;
}

ScalarConverter::ScalarConverter(const std::string &input)
{
	ScalarConverter::argv = input;
	if (ScalarConverter::debug)
		std::cout << "Param. constructor ScalarConverter" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const &rhs)
{
	ScalarConverter::argv = rhs.getArgv();
	ScalarConverter::arg_t = rhs.getType();
	if (ScalarConverter::debug)
		std::cout << "Copy. constructor ScalarConverter" << std::endl;
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &rhs)
{
	if (this != &rhs)
	{
		this->argv = rhs.getArgv();
		this->arg_t = rhs.getType();
	}
	if (ScalarConverter::debug)
		std::cout << "Op =  ScalarConverter" << std::endl;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
	if (ScalarConverter::debug)
		std::cout << "Destructor  ScalarConverter" << std::endl;
}

const std::string	&ScalarConverter::getArgv()
{
	return(argv);
}

char	ScalarConverter::getChar()
{
	return (convertedChar);
}

int		ScalarConverter::getInt()
{
	return (convertedInt);
}

float	ScalarConverter::getFloat()
{
	return (convertedFloat);
}

double	ScalarConverter::getDouble()
{
	return (convertedDouble);
}

ScalarConverter::type_arg	ScalarConverter::getType()
{
	return (type);
}

ScalarConverter::specialNumber	ScalarConverter::getFlag()
{
	return (flag);
}

bool	ScalarConverter::is_char_print()
{
	char	tmp = argv[0];
	
	if (argv.length() == 1 && isdigit(tmp) == false)
	{
		int		ascii=static_cast<int>(argv[0]);
		if (ascii >= 32 && ascii < 127)
		{
			type = char_t;
			convertedChar = tmp;
			return (true);
		}
		else
		{
			return (false);
		}
	}
	else
			return (false);
}

bool	ScalarConverter::is_int()
{// a test avec stringstream c++98 compliant (testé sur online c++ shell) ok
	std::stringstream	buffer;
	int					to_int;
	std::string			tmp;

	tmp = argv;
	if (!(buffer << tmp) || !(buffer >> to_int) || !(buffer >> std::ws).eof())
	{
		return (false);
	}
	else
		{
			type = int_t;
			convertedInt = to_int;
			return (true);
		}
}

bool	ScalarConverter::is_double()
{
	std::stringstream	buffer;
	double				to_double;
	std::string			tmp;
	bool				decimal_point;
	bool				nan;
	bool				inf;

	
	tmp = argv;
	nan = (tmp.find("nan") != std::string::npos);
	inf = (tmp.find("inf") != std::string::npos);
	decimal_point = (tmp.find_first_of(".", 0) == tmp.find_last_of(".",
		tmp.length() -1) && (tmp.find_first_of(".",0) != std::string::npos));
	if (decimal_point || nan || inf)
	{
		if (!(buffer << tmp) || !(buffer >> to_double) || !(buffer >> std::ws).eof())
		{
			return (false);
		}
		else
			{
				type = double_t;
				if (nan || inf)
					flag = all;
				convertedDouble = to_double;
				return (true);
			}
	}
	else
		return (false);
}

bool	ScalarConverter::is_float()
{
	std::stringstream	buffer;
	double				to_float;
	std::string			tmp;
	bool				end_f;
	bool				decimal_point;
	bool				end_ff;
	bool				nanf;
	bool				inff;


	tmp = argv;
	nanf = (tmp.find("nanf") != std::string::npos);
	inff = (tmp.find("inff") != std::string::npos);
	end_f = (tmp.find_first_of("f",0) == tmp.find_last_of("f",tmp.length() -1)
		&& (tmp.find_first_of("f", 0) != std::string::npos));
	end_ff = (tmp.find_first_of("f",0) == (tmp.find_last_of("f",
	tmp.length() - 1) - 1));
	decimal_point = (tmp.find_first_of(".", 0) == tmp.find_last_of(".",
		tmp.length() -1));
	if (((end_f || end_ff) && decimal_point) || inff || nanf)
	{
		tmp = tmp.substr(0, tmp.length() - 1 );
		if  (!(buffer << tmp) || !(buffer >> to_float)
		|| !(buffer >> std::ws).eof())
		{
			return (false);
		}
		else
			{
				type = float_t;
				if (nanf || inff)
					flag = all;
				convertedFloat =to_float;
				return (true);
			}
	}
		return (false);
}

bool	ScalarConverter::is_unknow()
{
	if ((!is_char_print()) && (!is_int()) && (!is_float()) && (!is_double()))
	{
		type = unknow;
		return (true);
	}
	else
		return (false);
}

void	ScalarConverter::charToAll()
{
	convertedInt = static_cast<int>(getChar());
	convertedFloat = static_cast<float>(getChar());
	convertedDouble = static_cast<double>(getChar());
}

void	ScalarConverter::intToAll()
{
	convertedChar = static_cast<char>(getInt());
	convertedFloat = static_cast<float>(getInt());
	convertedDouble = static_cast<double>(getInt());
}


void	ScalarConverter::floatToAll()
{
	convertedInt = static_cast<int>(getFloat());
	convertedChar = static_cast<char>(getFloat());
	convertedDouble = static_cast<double>(getFloat());
}


void	ScalarConverter::doubleToAll()
{
	convertedInt = static_cast<int>(getDouble());
	convertedFloat = static_cast<float>(getDouble());
	convertedChar = static_cast<char>(getDouble());
}

void	ScalarConverter::toAll()
{
	int	choice = getType();

	switch(choice)
	{
		case 1:
			charToAll();
			break;
		case 2:
			intToAll();
			break;
		case 3:
			floatToAll();
			break;
		case 4:
			doubleToAll();
			break;
	}

}


std::ostream& operator<<(std::ostream &os, ScalarConverter &arg)
{
	{
		if ((arg.getInt() < 32 || arg.getInt() >= 127) && arg.getFlag() !=
		ScalarConverter::all && arg.getType() != ScalarConverter::unknow )
		{
			if (arg.getInt() < 0)
				os << "char: Impossible\n";
			else
				os << "char: Non displayable\n";
		} else 
		if (arg.getFlag() == ScalarConverter::all || arg.getType() == ScalarConverter::unknow)
		{
			os << "char: Impossible\n";
		} else
		{
			os << "char: " << "'" << arg.getChar() << "'" << std::endl;
		}
	}
	{
		if (arg.getFlag() == ScalarConverter::all || arg.getType() ==
		ScalarConverter::unknow)
			os << "int: Impossible\n";
		else
			os << "int: " << arg.getInt() << std::endl;
	}
	{
		if (arg.getType() == ScalarConverter::unknow)
			os << "double: Impossible\n";
		else
		if (arg.getFlag() == ScalarConverter::all)
			os << "double: "<< arg.getDouble() <<  std::endl;
		else
		{
			if (arg.getDouble() - arg.getInt() == 0)
				os << "double: "<< arg.getDouble() << ".0" << std::endl;
			else
				os << std::setprecision(15) <<  "double: "<< arg.getDouble() << std::endl;
		}
	}
	{
		if (arg.getType() == ScalarConverter::unknow)
			os << "float: Impossible\n";
		else
		if (arg.getFlag() == ScalarConverter::all)
			os << "float: "<<arg.getFloat() << "f" << std::endl ;
		else
		{
			if (arg.getFloat() - arg.getInt() == 0)
				os <<  std::setprecision(15) << "float: "<<arg.getFloat() << ".0f"<< std::endl ;
			else
				os <<std::setprecision(15) << "float: "<<arg.getFloat() << "f"<< std::endl ;
		}
	}
	return os;
}
void	ScalarConverter::convert(const std::string &str)
{
	ScalarConverter	arg1(str);

	arg1.is_char_print();
	arg1.is_int();
	arg1.is_float();
	arg1.is_double();
	arg1.is_unknow();
	arg1.toAll();
	std::cout << green << arg1 << reset <<std::endl;

}
