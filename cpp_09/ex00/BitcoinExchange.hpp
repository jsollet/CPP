#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <algorithm>
#include <sstream>

// choix du container...

const std::string red("\033[0;31m");
const std::string green("\033[1;32m");
const std::string yellow("\033[1;33m");
const std::string cyan("\033[0;36m");
const std::string magenta("\033[0;35m");
const std::string reset("\033[0m");

class BitcoinExchange
{// a verifier
	public:
		BitcoinExchange();
 		BitcoinExchange(const BitcoinExchange &rhs);
		~BitcoinExchange();
		
 		BitcoinExchange	&operator=(const BitcoinExchange &rhs); 
	private:

};

#endif

