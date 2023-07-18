#include "PmergeMe.hpp"

int	to_int(std::string top)
{
	int						to_int;
	std::string				tmp;
	std::stringstream		buffer;

	tmp = top;

	
	if (!(buffer << tmp) || !(buffer >> to_int) || !(buffer >> std::ws).eof())
		throw std::invalid_argument("Not an integer");
	if (to_int < 0)
		throw std::invalid_argument("negative integer");
	return (to_int);
	
}


PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe &rhs)
{
	*this = rhs;
	return;
}

PmergeMe::~PmergeMe(){}

PmergeMe	&PmergeMe::operator=(const PmergeMe &rhs)
{
	if (this != &rhs)
	{
		this->data_vector = rhs.data_vector;
	}
	return (*this);
}

int		PmergeMe::get(std::list<int> &data, size_t index)
{
	std::list<int>::iterator	iter = data.begin();
	for (size_t i = 0; i < index || i < data.size(); i++)
	{
		iter++;
	}
	return (*(--iter));
}

template<typename C>
void	PmergeMe::load(C &cont, char *argv[])
{
	int	i = 1;
	int	c_int;
	while (argv[i] != NULL)
	{
		try
		{
			c_int = to_int(argv[i]);
			cont.push_back(c_int);
		}
		catch (std::exception &e)
		{
			std::cout <<red << e.what() << '\n' << reset;
			exit (-1);
		}
		++i;
	}
	typename C::iterator	it1, it2, it3;
	try
	{
		for (it1 = cont.begin(); it1 != cont.end(); ++it1)
		{
			it3 = it1;
			it3++;
			for (it2 = it3; it2 != cont.end(); ++ it2)
			{
				if (*it1 == *it2)
				{
					throw std::invalid_argument("duplicates");
					exit(-1);
				}
			}
		}
	}
	catch (std::exception &e)
	{
		std::cout <<red << e.what() << '\n' << reset;
		exit (-1);
	}
}

PmergeMe::vector_data	PmergeMe::pairwise(std::vector<int> data)
{
	PmergeMe::vector_data	result;
	result.d = data;

	std::vector<int>::iterator it1, it2, it3;
	it1 = data.begin();
	it2 = it1;
	it2++;
		while ((it1 != data.end())&&(it2 != data.end()))
		{
			if (*it1 > *it2)
			{
				result.a.push_back(*it1);
				result.b.push_back(*it2);
			}
			else
			{
				result.a.push_back(*it2);
				result.b.push_back(*it1);
			}
			it1++;it1++;
			it2 = it1;
			it2++;
		}
		it3 = --data.end();
		if (data.size() % 2 == 1)
			result.b.push_back(*it3);
	return (result);
}

PmergeMe::list_data	PmergeMe::pairwise(std::list<int> data)
{
	PmergeMe::list_data	result;
	result.d = data;

	std::list<int>::iterator it1, it2, it3;
	it1 = data.begin();
	it2 = it1;
	it2++;
		while ((it1 != data.end())&&(it2 != data.end()))
		{
			if (*it1 > *it2)
			{
				result.a.push_back(*it1);
				result.b.push_back(*it2);
			}
			else
			{
				result.a.push_back(*it2);
				result.b.push_back(*it1);
			}
			it1++;it1++;
			it2 = it1;
			it2++;
		}
		it3 = --data.end();
		if (data.size() % 2 == 1)
			result.b.push_back(*it3);
	return (result);
}

PmergeMe::vector_data	PmergeMe::mapping(PmergeMe::vector_data &a)
{
	std::vector<int>::iterator it1, it2, it3;
	std::vector<PmergeMe::s_pair>::iterator	it_map;
	it1 = a.a.begin();
	it2 = a.b.begin();
	PmergeMe::s_pair item;
	while (it1 != a.a.end())
	{
		item.max = (*it1);
		item.min = (*it2);
		a.map.push_back(item);
		it1++;
		it2++;
	}
	return (a);
}

PmergeMe::list_data	PmergeMe::mapping(PmergeMe::list_data &a)
{
	std::list<int>::iterator it1, it2, it3;
	std::list<PmergeMe::s_pair>::iterator	it_map;
	it1 = a.a.begin();
	it2 = a.b.begin();
	PmergeMe::s_pair item;
	while (it1 != a.a.end())
	{
		item.max = (*it1);
		item.min = (*it2);
		a.map.push_back(item);
		it1++;
		it2++;
	}
	return (a);
}

PmergeMe::vector_data	PmergeMe::rearrange(PmergeMe::vector_data &a)
{
	std::vector<int>::iterator it1;
	std::vector<PmergeMe::s_pair>::iterator	it_map;
	std::vector<s_pair>::iterator	it_item;
	std::vector<int>	tmp;
	it1 = a.a.begin();
	while (it1 != a.a.end())
	{
		it_map = a.map.begin();
		while (it_map->max != (*it1))
			it_map++;
		tmp.push_back(it_map->min);
		it1++;
	}
	if (a.b.size() - a.a.size() == 1)
		tmp.push_back(*(--a.b.end()));
	a.b.clear();
	a.b = tmp;
	return (a);
}

PmergeMe::list_data	PmergeMe::rearrange(PmergeMe::list_data &a)
{
	std::list<int>::iterator it1;
	std::list<PmergeMe::s_pair>::iterator	it_map;
	std::list<s_pair>::iterator	it_item;
	std::list<int>	tmp;
	it1 = a.a.begin();
	while (it1 != a.a.end())
	{
		it_map = a.map.begin();
		while (it_map->max != (*it1))
			it_map++;
		tmp.push_back(it_map->min);
		it1++;
	}
	if (a.b.size() - a.a.size() == 1)
		tmp.push_back(*(--a.b.end()));
	a.b.clear();
	a.b = tmp;
	return (a);
}

PmergeMe::vector_data	PmergeMe::bSI(PmergeMe::vector_data &a)
{
	std::vector<int>::iterator it2;
	it2 = a.b.begin();
	std::vector<int>::iterator	lower;
	while (it2 != a.b.end())
	{
		lower = std::lower_bound(main_chain.begin(), main_chain.end(), (*it2));
		main_chain.insert(lower, (*it2));
		it2++;
	}
	return (a);
}

PmergeMe::list_data	PmergeMe::bSI(PmergeMe::list_data &a)
{
	std::list<int>::iterator it2;
	it2 = a.b.begin();
	std::list<int>::iterator	lower;
	while (it2 != a.b.end())
	{
		lower = std::lower_bound(main_list.begin(), main_list.end(), (*it2));
		main_list.insert(lower, (*it2));
		it2++;
	}
	return (a);
}


void		PmergeMe::recursion(PmergeMe::vector_data &data)
{
	if (data.a.size() == 1)
		main_chain.push_back(data.a[0]);
	else
	{
		PmergeMe::vector_data a;
		
		a = PmergeMe::pairwise(data.a);
		a = PmergeMe::mapping(a);
		recursion(a);
		a = PmergeMe::rearrange(a);
		a = PmergeMe::bSI(a);
	}
}

void		PmergeMe::recursion(PmergeMe::list_data &data)
{
	if (data.a.size() == 1)
		main_list.push_back(get(data.a, 0));
	else
	{
		PmergeMe::list_data a;
		
		a = PmergeMe::pairwise(data.a);
		a = PmergeMe::mapping(a);
		recursion(a);
		a = PmergeMe::rearrange(a);
		a = PmergeMe::bSI(a);
	}
}
bool		PmergeMe::check(void)
{
	std::vector<int>::iterator	iter = data_vector.begin();
	std::vector<int>::iterator	next;
	if (main_chain.size() == data_vector.size())
	{
		while (iter != data_vector.end())
		{
			if (binary_search(main_chain.begin(), main_chain.end(), *iter))
			{
				iter++;
				continue ;
			}
			else
			{
				std::cout << red << "NOT GOOD\n";
				return (false);
			}
		}
		iter = main_chain.begin();
		next = iter;
		next++;
		while (next != main_chain.end())
		{
			if (*iter > *next)
			{
				std::cout << red << "NOT GOOD\n";
				return (false);
			}
			iter++;
			next++;
		}
		std::cout << green << "vector: all is good\n";
		return (true);
	}
	else
	{
		std::cout << red << "NOT GOOD\n";
		return (false);
	}
}

bool		PmergeMe::check_list(void)
{
	std::list<int>::iterator	iter = data_list.begin();
	std::list<int>::iterator	next;
	if (main_chain.size() == data_vector.size())
	{
		while (iter != data_list.end())
		{
			if (binary_search(main_list.begin(), main_list.end(), *iter))
			{
				iter++;
				continue ;
			}
			else
			{
				std::cout << red << "NOT GOOD\n";
				return (false);
			}
		}
		iter = main_list.begin();
		next = iter;
		next++;
		while (next != main_list.end())
		{
			if (*iter > *next)
			{
				std::cout << red << "NOT GOOD\n";
				return (false);
			}
			iter++;
			next++;
		}
		std::cout << green << "list:   all is good\n";
		return (true);
	}
	else
	{
		std::cout << red << "NOT GOOD\n";
		return (false);
	}
}

void	PmergeMe::printResult()
{
	long int timeVector = 1E6*vectorEnd.tv_sec + vectorEnd.tv_usec -
		(1E6*vectorStart.tv_sec + vectorStart.tv_usec);
	long int timeList = 1E6*listEnd.tv_sec + listEnd.tv_usec -
		(1E6*listStart.tv_sec + listStart.tv_usec);
	std::cout << "Before:\t"<< magenta;
	for (size_t i = 0; i < data_vector.size(); ++i)
		std::cout << data_vector[i]<< " ";
	std::cout << reset<< "\nAfter:\t"<< green;
	for (size_t i = 0; i < main_chain.size(); ++i)
		std::cout << main_chain[i]<< " ";
	std::cout << std::endl << reset << "Time to process a range of "<<
	data_vector.size() << " elements with std::vector :\t"<< magenta <<
	timeVector << " µs";
	std::cout << std::endl << reset << "and Time to process a range of "<<
	data_list.size() << " elements with std::list :\t"<< magenta <<
	timeList << " µs";
	std::cout << reset << std::endl;
}

PmergeMe::PmergeMe(int argc, char	*argv[])
{
	(void) argc;
	gettimeofday(&vectorStart, NULL);
	load(data_vector, argv);
	{
		std::vector<int>::iterator it1, it2, it3;
		vector_data a;
		a.a = data_vector;
		recursion(a);
		gettimeofday(&vectorEnd, NULL);
//		check();
	}
	gettimeofday(&listStart, NULL);
	load(data_list, argv);
	{
		std::list<int>::iterator it1, it2, it3;
		list_data	a;
		a.a = data_list;
		recursion(a);
		gettimeofday(&listEnd, NULL);
		
//		check_list();
	}
	printResult();
}

