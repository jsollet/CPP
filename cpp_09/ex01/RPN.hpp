#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <stack>

// choix du container... stack

const std::string red("\033[0;31m");
const std::string green("\033[1;32m");
const std::string yellow("\033[1;33m");
const std::string cyan("\033[0;36m");
const std::string magenta("\033[0;35m");
const std::string reset("\033[0m");

class RPN
{
	private:
		RPN();
		RPN(const RPN &rhs);
		RPN &operator=(const RPN &rhs);
	public:
		RPN(std::string arg);
		~RPN();

		bool	is_plausible() const;

		void	test();
		template<typename T> void reverse(std::stack<T> &pile);
		template<typename T> void print(std::stack<T> &pile);
		void	loadPgrm();

		void	add();
		void	mul();
		void	min();
		void	div();


	class parserError: public std::exception
	{
		virtual const char *what() const throw()
		{
			return "Parser: bad input";
		}
	} parse;

	class Error: public std::exception
	{
		virtual const char *what() const throw()
		{
			return "Error";
		}
	} error;

	class divisionByZero: public std::exception
	{
		virtual const char *what() const throw()
		{
			return "Error: division by 0";
		}
	} divBy0;
	
	private:
		std::string				arg;
		std::stack<double>		operand;
		std::stack<std::string>	pgrm;
};

#endif
