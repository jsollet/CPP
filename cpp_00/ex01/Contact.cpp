/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsollett <jsollett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:52:22 by jsollett          #+#    #+#             */
/*   Updated: 2023/01/31 16:57:38 by jsollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>
#include "Contact.hpp"

Contact::Contact()
{
}

Contact::Contact(std::string first, std::string last, std::string nick, std::string phone, std::string secret)
{
	first_name = first;
	last_name = last;
	nick_name = nick;
	phone_number = phone;
	darkest_secret = secret;
}

Contact::~Contact()
{
}

std::string	Contact::get_first_name() const
{
	return(first_name);
}

std::string	Contact::get_last_name() const
{
	return(last_name);
}

std::string	Contact::get_phone_number() const
{
	return(phone_number);
}

std::string	Contact::get_nick_name() const
{
	return(nick_name);
}

std::string	Contact::get_darkest_secret() const
{
	return(darkest_secret);
}
