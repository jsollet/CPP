#include "BitcoinExchange.hpp"

static bool	is_empty(std::ifstream& pFile)
{
	return pFile.peek() == std::ifstream::traits_type::eof();
}

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &rhs)
	:quotation(rhs.quotation){}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	std::map<int,float>			tmp;
	std::map<int,float>::iterator	it_quote;

	for (it_quote = rhs.quotation->begin(); it_quote != rhs.quotation->end();
		++it_quote)
		{
			tmp[(it_quote->first)] = (it_quote->second);
		}
	delete quotation;
	quotation = &tmp;
	tmp.clear();
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
	delete  quotation;
}



BitcoinExchange::BitcoinExchange(const char *arg)
:inputFile(arg), quotFile("./data_00/data.csv")
,quotation(new std::map<int,float>())
{
	try
	{
		if (!inputFile || is_empty(inputFile) || (!quotFile ||
		is_empty(quotFile)))
		{
			inputFile.close();
			throw noInput;
		}
	}
	catch (std::exception &e)
	{
		std::cout << red <<  e.what() << reset << '\n';
		exit (-1);
	}
	
	getHistoricPrice(quotFile, *quotation);
	
	std::string	read;
	std::getline(inputFile, read);
	while (std::getline(inputFile, read))
	{
		std::string y = read.substr(0,4);
		std::string m = read.substr(5,2);
		std::string d = read.substr(8,2);
		std::string date = read.substr(0, 10);
		if (is_plausible(read, "|"))
		{
			std::string v = read.substr(12, std::string::npos);
			float	vfrom = getfromfloat<float>(v);
			try
			{
				if (vfrom < 0)
					throw(negative);
				if (vfrom > 1000)
					throw(tooBig);
			}
			catch (std::exception &e)
			{
				std::cout <<red << e.what() << '\n' << reset;
			}
			int	key = getDate(read);
			if (key > 0 && vfrom >= 0 && vfrom <= 1000 )
			{
				float value = vfrom * quotation->find(key)->second;
				std::cout << green << date <<" => " << vfrom << " = " <<value <<
				std::endl;
			}
		}
		else
		{
			std::cout << red << "Error: bad input => " << date << std::endl;
		}
	}
}

int	BitcoinExchange::getDate(std::string &read)
{
	std::string y = read.substr(0,4);
	std::string m = read.substr(5,2);
	std::string d = read.substr(8,2);
	try
	{
		if (y.find_first_not_of("0123456789", 0) != std::string::npos)
			throw (badArg);
		if (m.find_first_not_of("0123456789", 0) != std::string::npos)
			throw (badArg);
		if (d.find_first_not_of("0123456789", 0) != std::string::npos)
			throw (badArg);
	}
	catch (std::exception &e)
	{
		std::cout <<red << e.what() << " => " << read.substr(0,10);
		std::cout << "\n"<< reset;
		return (0);
	}
	if (is_plausible(read, "|"))
	{
		int key = createKey(getfrom(y),getfrom(m),getfrom(d));
		std::map<int, float>::iterator	found= quotation->find(key);
		std::map<int, float>::iterator	iter = quotation->begin();
		std::map<int, float>::iterator	prec;
		if (quotation->find(key) != quotation->end())
			return (found->first);
		else
		{
			while (iter->first < key && iter != quotation->end())
				iter++;
			if (iter == quotation->begin())
			{
				std::cout << "Date before historic quotation." << std::endl;
				return (-1);
			}
			else
			{
				iter--;
				prec = iter--;
				return (prec->first);
			}
		}
	}
	return (0);
}



bool	BitcoinExchange::is_plausible(std::string line, std::string sep) const
{
	int	pos;
	
	if (sep == "|")
		pos = 11;
	else
		pos = 10;
	if ((line.substr(4,1) == (line.substr(7,1)) && line.substr(4,1) =="-"))
	{
		if (line.substr(pos,1) == sep)
			return (true);
		else
		{
			return (false);
		}
	}
	return (false);
}

int		BitcoinExchange::getfrom(std::string &tmp) const
{
	std::stringstream	buffer;
	int					to_int;

	if (!(buffer << tmp) || !(buffer >> to_int) || !(buffer >> std::ws).eof())
	{
		return (-1);
	}
	else
		return (to_int);
}

template<typename T, typename U>
T		BitcoinExchange::getfromfloat(U tmp)
{
	std::stringstream	buffer;
	T					toT;

	if (!(buffer << tmp) || !(buffer >> toT) || !(buffer >> std::ws).eof())
	{
		return (-1);
	}
	else
		return (toT);
}

bool	BitcoinExchange::leap_year(int year)
{
	if ((year % 4 == 0 && year % 100  != 0) || year % 400 == 0)
	{
		return (true);
	}
	else
		return (false);
}

bool	BitcoinExchange::validate_date(int year, int month, int day)
{
	const int dayNumber[12] = {31, 28, 31, 30, 31, 30, 31,31,30, 31,30,31};
	const int dayNumberLeap[12] = {31, 29, 31, 30, 31, 30, 31,31,30, 31,30,31};
	if (year <= 1990 || !(month >= 1 && month <= 12) )
		return (false);
	else if (!leap_year(year) && !(day >= 1 && day <= dayNumber[month-1]))
		return (false);
	else if (leap_year(year) && !(day >= 1 && day <= dayNumberLeap[month-1]))
		return (false);
	return (true);
}

int		BitcoinExchange::createKey(int year, int month, int day)
{
	int	cumul = 0;

	const int dayNumber[12] = {31, 28, 31, 30, 31, 30, 31,31,30, 31,30,31};
	const int dayNumberLeap[12] = {31, 29, 31, 30, 31, 30, 31,31,30, 31,30,31};
	if (leap_year(year))
	{
		for (int i=0 ; i < month - 1; ++i)
			cumul += dayNumberLeap[i];
	}
	else
	{
		for (int i=0 ; i < month - 1; ++i)
			cumul += dayNumber[i];
	}
	return (1000 * year +  cumul + day);
}

int		BitcoinExchange::computeKey(std::string &read)
{
	try
	{
		if (is_plausible(read, "|"))
		{
			std::string y = read.substr(0,4);
			std::string m = read.substr(5,2);
			std::string d = read.substr(8,2);
			int key = createKey(getfrom(y),getfrom(m),getfrom(d));
			return (key);
		}
		else
			throw (Separator);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << '\n';
		return (-1);
	}
}

void	BitcoinExchange::getHistoricPrice(std::ifstream &input, std::map<int,
float> &ref)
{
	std::string	read;
	while (std::getline(input, read))
	{
		if (is_plausible(read, ","))
		{
			std::string y = read.substr(0,4);
			std::string m = read.substr(5,2);
			std::string d = read.substr(8,2);
			std::string v = read.substr(11, std::string::npos);
			double	vfrom =getfromfloat<double>(v);
			int key = createKey(getfrom(y),getfrom(m),getfrom(d));
			ref[key] = vfrom;
		}
	}
}
