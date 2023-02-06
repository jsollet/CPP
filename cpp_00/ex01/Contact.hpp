/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsollett <jsollett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:52:28 by jsollett          #+#    #+#             */
/*   Updated: 2023/01/31 16:57:26 by jsollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
#include <iostream>

class Contact
{
	private:
		std::string	first_name;
		std::string last_name;
		std::string phone_number;
		std::string	nick_name;
		std::string	darkest_secret;
	public:
		Contact();
		Contact(std::string first, std::string last,std::string nick, std::string phone, std::string secret);
		~Contact();
		std::string get_first_name() const;
		std::string get_last_name() const;
		std::string get_phone_number() const;
		std::string	get_nick_name() const;
		std::string get_darkest_secret() const;
};
#endif
