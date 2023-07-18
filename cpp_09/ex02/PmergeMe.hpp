#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <algorithm>
#include <iterator>
#include <sstream>

# include <ctime>
# include <sys/time.h>
// les 2 container 
#include <vector>
#include <list>

const std::string red("\033[0;31m");
const std::string green("\033[1;32m");
const std::string yellow("\033[1;33m");
const std::string cyan("\033[0;36m");
const std::string magenta("\033[0;35m");
const std::string reset("\033[0m");

class PmergeMe
{
	public:
	struct	s_pair
	{
		int	max;
		int	min;
	};

	public:
	struct	vector_data
	{
		std::vector<int>	a;
		std::vector<int>	b;
		std::vector<int>	d;
		std::vector<s_pair>	map;
	};

	public:
	struct	list_data
	{
		std::list<int>	a;
		std::list<int>	b;
		std::list<int>	d;
		std::list<s_pair>	map;
	};


	private:
		PmergeMe();
		PmergeMe(const PmergeMe &rhs);
		PmergeMe &operator=(const PmergeMe &rhs);
	public:
		PmergeMe(int argc, char *argv[]);
		~PmergeMe();

		template<typename C> void	load(C &container, char *argv[]);
		
		vector_data	pairwise(std::vector<int> data);
		vector_data	mapping(vector_data &data);
		vector_data	rearrange(vector_data &data);
		vector_data	bSI(vector_data &data);
		void	recursion(vector_data &data);
		bool	check(void);
		void	printResult(void);

	// list
		int		get(std::list<int> &data, size_t index);
		list_data	pairwise(std::list<int> data);
		list_data	mapping(list_data &data);
		list_data	rearrange(list_data &data);
		list_data	bSI(list_data &data);
		void	recursion(list_data &data);
		bool	check_list(void);

	private:
		std::vector<int>	data_vector;
		std::list<int>		data_list;
		std::vector<int>	main_chain;
		std::list<int>		main_list;
		struct	timeval		vectorStart;
		struct	timeval		vectorEnd;
		struct	timeval		listStart;
		struct	timeval		listEnd;
	public:
	class parserError: public std::exception
	{
		virtual const char *what() const throw()
		{
			return "Parser: bad input";
		}
	} parser;
	
	class Error: public std::exception
	{
		virtual const char *what() const throw()
		{
			return "Error";
		}
	} error;
};



#endif
