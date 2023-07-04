#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <exception>
#include <stdexcept>
#include <algorithm>
#include <iterator>
#include <climits>
#include <vector>

const std::string red("\033[0;31m");
const std::string green("\033[1;32m");
const std::string yellow("\033[1;33m");
const std::string cyan("\033[0;36m");
const std::string magenta("\033[0;35m");
const std::string reset("\033[0m");

class	Span
{
	public :
		Span(unsigned int N);
		Span(const Span &rhs);
		~Span();
		Span				&operator=(const Span &rhs);

		unsigned int 		getSize() const;
		std::vector<int>	getVector() const;
		unsigned int		shortestSpan() const;
		unsigned int		longestSpan() const;
		void				addNumber(int number);

		void		print(std::string start, std::string end) const;
		void		populate(int min, int max,  int size); 
		
		int				min() const;
		int				max() const;

		class logicError: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class lengthError: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class invalidArgument: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
	
	private :
		unsigned int			N;
		std::vector<int>		*Elem;
		Span();
};
#endif
