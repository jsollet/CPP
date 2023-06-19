#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
#include <iostream>
#include <string>
#include <stdexcept>
#include <exception>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <limits>
#include <cctype>

const std::string red("\033[0;31m");
const std::string green("\033[1;32m");
const std::string yellow("\033[1;33m");
const std::string cyan("\033[0;36m");
const std::string magenta("\033[0;35m");
const std::string reset("\033[0m");


class	ScalarConverter
{
	public:
		enum		type_arg {unknow = 0, char_t, int_t, float_t, double_t};
		enum		specialNumber {ras, all};
	private:
		ScalarConverter();
		ScalarConverter(const std::string &Argv);
		ScalarConverter(const ScalarConverter &rhs);
		ScalarConverter &operator=(const ScalarConverter &rhs);
	public:
		~ScalarConverter();
			
		static	const std::string	&getArgv();
		static	bool				is_char_print();
		static	bool				is_int();
		static	bool				is_float();
		static	bool				is_double();
		static	bool				is_unknow();
		
		static	void				convert(const std::string &str);

		static	type_arg			getType();
		static	specialNumber		getFlag();
		static	char				getChar();
		static	int					getInt();
		static	float				getFloat();
		static	double				getDouble();

		static	void				charToAll();
		static	void				intToAll();
		static	void				floatToAll();
		static	void				doubleToAll();
		static	void				toAll();

		static bool			debug;
	private:
		static	type_arg			type;
		static	specialNumber		flag;
		static	std::string			argv;
		static	unsigned int		arg_t;
		static	char				convertedChar;
		static	int					convertedInt;
		static	float				convertedFloat;
		static	double				convertedDouble;

};

std::ostream& operator<<(std::ostream &os, ScalarConverter &arg);

#endif
