// prgm test pour exo00


#include "BitcoinExchange.hpp"
#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <iterator>
#include <algorithm>
#include <sstream>

#include <map>
#include <fstream> // voir cpp_01/ex04
				   //
//https://stackoverflow.com/questions/2390912/checking-for-an-empty-file-in-c
bool	is_empty(std::ifstream& pFile)
{
	return pFile.peek() == std::ifstream::traits_type::eof();
}

bool	is_plausible(std::string line)
{
	if ((line.substr(4,1) == (line.substr(7,1)) && line.substr(4,1) =="-"))
	{
		if (line.substr(11,1) == "|")
			return (true);
		else
			return (false);
	}
	return (false);
}

int		getfrom(std::string &tmp)
{
	std::stringstream	buffer;
	int					to_int;

	if (!(buffer << tmp) || !(buffer >> to_int) || !(buffer >> std::ws).eof())
	{
		std::cout << red << to_int << "   " << buffer << reset << tmp <<std::endl<< std::endl;
		return (-1);
	}
	else
		return (to_int);
}
template<typename T, typename U>
T		getfrom1(U tmp)
{
	std::stringstream	buffer;
	T					toT;

	if (!(buffer << tmp) || !(buffer >> toT) || !(buffer >> std::ws).eof())
	{
		std::cout << red << toT << "   " << buffer << reset << tmp <<std::endl<< std::endl;
		return (-1);
	}
	else
		return (toT);
}




bool	leap_year(int year)
{
	if ((year % 4 == 0 && year % 100  != 0) || year % 400 == 0)
	{
		return (true);
	}
	else
		return (false);
}

bool	validate_date(int year, int month, int day)
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

int		createKey(int year, int month, int day)
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
	return (1000 * year + cumul + day);
}

int main(int argc, char *argv[])
{
	//scalarconverter
	std::stringstream	buffer;
	int					to_int;
	std::string			tmp;
	bool				format_0;
	int					year;
	int					month;
	int					day;
	std::map<int, double>		map;
	if (argc != 2)
	{
		std::cerr << "error\n";
		return (-1);
	}
	std::ifstream input(argv[1]);
	if (!input || is_empty(input))
	{
		input.close();
		return (-1);
	}
	std::string	read;
	while (std::getline(input, read))
	{
		//std::cout << read << std::endl;
		format_0 = is_plausible(read);
//		std::cout << std::boolalpha << format_0 << std::noboolalpha << std::endl;
		if (format_0)
		{
			std::string y = read.substr(0,4);
			std::string m = read.substr(5,2);
			std::string d = read.substr(8,2);
			// test pour obtenir une valeur
			std::string v = read.substr(12, std::string::npos);	
			// 	https://stackoverflow.com/questions/13684264/how-to-disambiguate-function-templates-that-differ-only-by-return-type
			double	vfrom =getfrom1<double>(v);
			int key = createKey(getfrom(y),getfrom(m),getfrom(d));
			map[key] = vfrom;
			year = getfrom(y);
			month = getfrom(m);
			day = getfrom(d);
		std::cout << green <<"year = "<< year << " month = " << month << " day = " << day  << red << " valeur = " << vfrom << std::endl;
		}
	}
	std::map<int, double>::iterator iter;	
	for (iter = map.begin(); iter != map.end(); ++iter)
	{
		std::cout  << iter->first<< "  " << iter->second<<std::endl;
	}


	std::cout << "-------------- test validate --------------\n";
	std::cout << green <<std::boolalpha << validate_date(2004, 2, 29) << std::noboolalpha << reset <<std::endl;
	std::cout << red<<  std::boolalpha << validate_date(2005, 2, 29) << std::noboolalpha << reset <<std::endl;
	std::cout << red <<std::boolalpha << validate_date(2005, 11, 31) << std::noboolalpha <<reset<< std::endl;
	std::cout << green <<std::boolalpha << validate_date(2004, 4, 9) << std::noboolalpha << reset <<std::endl;

	
	std::cout << "-------------- test createkey --------------\n";
	std::cout << std::endl << "key for 2004-2-29 = "<<createKey(2004,2,29)<< std::endl;
	std::cout << std::endl << "key for 2004-2-28 = "<<createKey(2004,2,28)<< std::endl;
	std::cout << std::endl << "key for 2004-2-27 = "<<createKey(2004,2,27)<< std::endl;
	std::cout << std::endl << "key for 2004-3-1 = "<<createKey(2004,3,1)<< std::endl;
	std::cout << std::endl << "key for 2004-3-2 = "<<createKey(2004,3,2)<< std::endl;
	std::cout << "-------------- FIN --------------\n";
	return (0);
}	
