/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsollett <jsollett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:57:36 by jsollett          #+#    #+#             */
/*   Updated: 2023/02/03 17:14:59 by jsollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <limits>
#include "Contact.hpp"
#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{

}

PhoneBook::~PhoneBook()
{

}

void PhoneBook::add_record(Contact aPerson)
{
	PhoneBook::max = 8;
	static int count;

	if (count<PhoneBook::max)
	{
		PhoneBook::contact_array[count] = aPerson;
		count++;
	}
	else
	{
		for (int i=0; i < PhoneBook::max - 1; i++)
		{
			PhoneBook::contact_array[i] = PhoneBook::contact_array[i + 1];
		}
		PhoneBook::contact_array[PhoneBook::max - 1] = aPerson;
	}
}

std::string	PhoneBook::truncate(std::string str, size_t width, std::string end)
{
	std::string	res;

	if (str.length() < width)
	{
		return (str);
	}
	else
	{
		res = str.substr(0, width - 1) + end;
		return (res);
	}
}

size_t		PhoneBook::size()
{
	size_t	size = 0;

	while (size < 8 && contact_array[size].get_first_name().compare(""))
	{
		size++;
	}
	return (size);
}

void	PhoneBook::print_contact_no(int index)
{
	std::cout << "contact number = " << index << std::endl;
	std::cout << "First name = " << contact_array[index - 1].get_first_name() << std::endl;
	std::cout << "Last name = " << contact_array[index - 1].get_last_name() << std::endl;
	std::cout << "Nick name = " << contact_array[index - 1].get_nick_name()<< std::endl;
	std::cout << "Phone number = " << contact_array[index - 1].get_phone_number() << std::endl;
	std::cout << "Darkest secret = " << contact_array[index - 1].get_darkest_secret ()<< std::endl;
	std::cout << std::endl;
}

void	PhoneBook::print_line(std::string index, std::string str1, std::string str2, std::string str3)
{
	std::cout << std::setw(10)<< std::right << index << std::left << "|"
		<< std::setw(10)<< std::right << truncate(str1, 10, ".") << "|"
		<< std::setw(10)<< std::right << truncate(str2, 10, ".") << "|"
		<< std::setw(10)<< std::right << truncate(str3, 10, ".") << "|" << std::endl;
}

void	PhoneBook::print_line(size_t index, std::string str1, std::string str2, std::string str3)
{
	std::cout << std::setw(10)<< std::right << index << std::left << "|"
		<< std::setw(10)<< std::right << truncate(str1, 10, ".") << "|"
		<< std::setw(10)<< std::right << truncate(str2, 10, ".") << "|"
		<< std::setw(10)<< std::right << truncate(str3, 10, ".") << "|" << std::endl;
}

void	PhoneBook::print_pb()
{
	if (size() == 0)
	{
		std::cout << "PhoneBook vide" << std::endl;
		return ;
	}
	print_line("index", "First name", "Last name", "Nick name");
	for (size_t i = 1; i < size() + 1 ; i++)
	{
		print_line(i, contact_array[i-1].get_first_name(), contact_array[i-1].get_last_name(), contact_array[i-1].get_nick_name());
	}
	std::string	ans;
	while (true)
	{
		std::cout << "Enter index (1.." << size() << ")" << std::endl;
		std::getline(std::cin, ans);
		if (ans.length() == 1 && std::isdigit(ans[0]))
		{
			if (atoi(ans.c_str()) >=1 && atoi(ans.c_str()) <= (int)size())
			{
				print_contact_no(atoi(ans.c_str()));
				break ;
			}
			else
				continue ;
		}
		else
			continue ;
	}
}
