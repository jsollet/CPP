/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsollett <jsollett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:39:37 by jsollett          #+#    #+#             */
/*   Updated: 2023/02/01 17:21:11 by jsollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <algorithm>
#include <functional>
#include <ctime>
#include <iostream>
#include <iomanip>

#include "Account.hpp"

	int	Account::_nbAccounts = 0;
	int	Account::_totalAmount = 0;
	int	Account::_totalNbDeposits = 0;
	int	Account::_totalNbWithdrawals = 0;


Account::Account(int initial_deposit)
{
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" <<  this->_amount << ";created" << std::endl;
	_totalAmount += _amount;
	_nbAccounts++;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount << ";closed" << std::endl;
}

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}



/* ************************************************************************** */
/*                                                                            */
/* displayAccountsInfos  affiche que des variables statiques :                */
/* ce qui implique pas de this->                                              */
/* (les autres variables membres non statiques doivent être désignées par     */
/* this-> ou Account::                                                        */
/* ************************************************************************** */

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:"<< _nbAccounts;
	std::cout << ";total:" << _totalAmount;
	std::cout << ";deposits:" << _totalNbDeposits;
	std::cout << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/* displayTimestamp: annee de reference 01/01/1900 d'où +1900 pour l'année    */
/* aussi +1 pour le mois.                                                     */
/* setw() fixe la largeur pour cout, et setfill() remplace les caractères     */
/* non imprimés                                                               */
/* ************************************************************************** */

void	Account::_displayTimestamp( void )
{
	const std::time_t t = std::time(0);

	std::tm* now = std::localtime(&t);
	std::cout << '[' <<(now->tm_year + 1900)
	<< std::setw(2)<< std::setfill('0') << (now->tm_mon + 1)
	<< std::setw(2)<< std::setfill('0') << now->tm_mday
	<< '_'
	<< std::setw(2)<< std::setfill('0')<< now->tm_hour
	<< std::setw(2)<< std::setfill('0')<< now->tm_min
	<< std::setw(2)<< std::setfill('0')<< now->tm_sec << "] ";
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	std::cout << ";deposit:" << deposit;
	this->_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
	this->_nbDeposits++;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";nb_deposits:" << this->_nbDeposits << std::endl ;


}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	std::cout << ";withdrawal:";
	if (this->_amount < withdrawal)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	else
	{
		std::cout << withdrawal;
		this->_amount -= withdrawal;
		_totalAmount -= withdrawal;
		this->_nbWithdrawals++;
		_totalNbWithdrawals++;
		std::cout << ";amount:" << this->_amount;
		std::cout << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return (true);
	}
}

int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout<<"index:"<< this->_accountIndex
	<< ";amount:" << this->_amount
	<< ";deposits:" << this->_nbDeposits
	<< ";withdrawals:" << this->_nbWithdrawals
	<< std::endl;
}
