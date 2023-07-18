#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <fstream>
#include <map>

// choix du container... map

const std::string red("\033[0;31m");
const std::string green("\033[1;32m");
const std::string yellow("\033[1;33m");
const std::string cyan("\033[0;36m");
const std::string magenta("\033[0;35m");
const std::string reset("\033[0m");

class BitcoinExchange
{
	private:
		BitcoinExchange();
 		BitcoinExchange(const BitcoinExchange &rhs);
 		BitcoinExchange	&operator=(const BitcoinExchange &rhs); 
	public:
		~BitcoinExchange();
		
		BitcoinExchange(const char *argv);

		bool 	is_plausible(std::string line, std::string sep) const;
		int		getfrom(std::string &tmp) const;
		template<typename T, typename U> T getfromfloat(U tmp);
		bool	leap_year(int year);
		bool	validate_date(int year, int month, int day);
		int		createKey(int year, int month, int day);
		int		computeKey(std::string &read);
		void	getHistoricPrice(std::ifstream &input, std::map<int, float>
		&ref);
		int	getDate(std::string &read);
	
	class unknowSeparator: public std::exception
	{
		virtual const char* what() const throw()
		{
    		return "Parser: invalid separator";
		}
	} Separator;

	class noInput: public std::exception
	{
		virtual const char* what() const throw()
		{
			return "Error: could not open file.";
		}
	} noInput;

	class badArgument: public std::exception
	{
		virtual const char* what() const throw()
		{
			return "Error: bad input";
		}
	} badArg;

	class tooBigValue: public std::exception
	{
		virtual const char* what() const throw()
		{
			return "Error: too large a number.";
		}
	} tooBig;

	class negativeNumber: public std::exception
	{
		virtual const char* what() const throw()
		{
			return "Error: not a positive number.";
		}
	} negative;
	
	private:
		std::ifstream			inputFile;
		std::ifstream			quotFile;
		std::map<int, float>	*quotation;
};

#endif
