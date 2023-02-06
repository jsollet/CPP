/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   awesome_notebook.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsollett <jsollett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:52:14 by jsollett          #+#    #+#             */
/*   Updated: 2023/02/03 15:47:35 by jsollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include "Contact.hpp"
#include "PhoneBook.hpp"

void	ask_field(std::string *str, int len)
{
	std::string	user_answer;
	std::string	field[5] = {"first name", "last name", "nick name","phone number", "little darkest secret" };

	std::cout << "Please, add the information of your contact:" << std::endl;
	for (int i=0; i < len; i++)
	{
		std::cout << "Enter the " << field[i] << " of your contact:" << std::endl;
		do
		{
			std::getline(std::cin, str[i]);
		} while(str[i].empty());
	}
}

int main()
{
	PhoneBook	book;
	std::string	user_request;
	std::string	command[3] = {"ADD", "SEARCH", "EXIT"};
	std::string	fields[5];

	while (true)
	{
		std::cout << "ADD, SEARCH or EXIT" << std::endl;

		std::getline(std::cin, user_request);
		if (user_request.compare(command[0]) == 0)
		{
			ask_field(fields, 5);
			Contact aPerson(fields[0], fields[1], fields[2], fields[3], fields[4]);
			book.add_record(aPerson);
		}
		if (user_request.compare(command[1]) == 0)
		{
			book.print_pb();
		}
		if (user_request.compare(command[2]) == 0)
		{
			break ;
		}
	}
	return (0);
}
