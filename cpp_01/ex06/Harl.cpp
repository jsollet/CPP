#include <iostream>
#include <string>
#include "Harl.hpp"

Harl::Harl(){}
Harl::~Harl(){}

void Harl::debug(void)
{
	std::cout << "[ " << "DEBUG" << " ]" << std::endl;
	std::cout << "0 " << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-" 
	   	"ketchup burger. I really do !" << std::endl << std::endl;
}

void Harl::info(void)
{
	std::cout << "[ " << "INFO" << " ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon"  
		" in my burger ! If you did, I wouldn’t be asking for more !" << std::endl << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[ " << "WARNING" << " ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming "
		"for years whereas you started working here since last month." << std::endl << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ " << "ERROR" << " ]" << std::endl;
	std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl << std::endl;
}

void Harl::unknow(void)
{
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string	function_name[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	typedef void(Harl::*FP)();
	FP functionPointers[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error, &Harl::unknow};
	int	count = 0;
	for (int i=0; i < 4; i++)
	{
		if (level == function_name[i])
		{
			(this->*functionPointers[i])();
			break ;
		}
		else 
			count++;
	}
	if (count == 4)
		(this->*functionPointers[4])();
}

void	Harl::escalate(std::string level)
{
	std::string	function_name[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	typedef void(Harl::*FP)();
	FP functionPointers[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error, &Harl::unknow};
	int start_level = 0;
	for (int i=0; i < 4; i++)
	{
		if (level == function_name[i])
		{
			break ;
		}
		else 
			start_level++;
	}
	switch(start_level){
	case 0 :
	{
		for (int i = start_level; i < 4; i++)
		{
			(this->*functionPointers[i])();
		}
		break ;
	}
	case 1:
	{
		for (int i = start_level; i < 4; i++)
		{
			(this->*functionPointers[i])();
		}
		break ;
	}
	case 2:
	{
		for (int i = start_level; i < 4; i++)
		{
			(this->*functionPointers[i])();
		}
		break ;
	}
	case 3:
	{
		(this->*functionPointers[3])();
		break ;
	}
	default:
		(this->*functionPointers[4])();
	}
}
