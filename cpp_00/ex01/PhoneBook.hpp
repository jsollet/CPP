/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsollett <jsollett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:55:54 by jsollett          #+#    #+#             */
/*   Updated: 2023/02/01 11:29:44 by jsollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
	private:
		int	max;
		Contact	contact_array[8];
		int	taille;


	public:
		PhoneBook();
		~PhoneBook();
		std::string	truncate(std::string str, size_t width, std::string end);
		size_t	size();
		void	add_record(Contact aPerson);
		void	print_contact_no(int index);
		void	print_line(std::string index, std::string str1, std::string str2, std::string str3);
		void	print_line(size_t index, std::string str1, std::string str2, std::string str3);
		void	print_pb();
};
#endif
