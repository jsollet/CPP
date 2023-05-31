#ifndef ARGUMENT_HPP
# define ARGUMENT_HPP
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


class	Argument
{// premier essai
	public:
		Argument();
		Argument(const std::string &Argv);
		Argument(const Argument &rhs);
		Argument &operator=(const Argument &rhs);
		~Argument();
			
		const std::string	&getArgv()  const;// avant const
		unsigned int		getType() const;


		bool				is_char_print();
		bool				is_int();
		bool				is_float();
		bool				is_double();

		enum				type_arg {unknow = 0, char_t, int_t, float_t, double_t};
		static bool			debug;
	private:
		std::string			argv;// peut etre la le pb ligne 29 cpp avant const
		unsigned int		arg_t;
		
		char				convertedChar;
		int					convertedInt;
		float				convertedFloat;
		double				convertedDouble;

	//	bool				is_char_print(std::string &Argv);
};



#endif
