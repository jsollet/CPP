#include "RPN.hpp"

static	int	to_int(std::string top)
{
	int						to_int;
	std::string				tmp;
	std::stringstream		buffer;

	tmp = top;
	if (!(buffer << tmp) || !(buffer >> to_int) || !(buffer >> std::ws).eof())
		return (-1);
	else
		return (to_int);
}

RPN::RPN() {}

RPN::RPN(const RPN &rhs):arg(rhs.arg),operand(rhs.operand), pgrm(rhs.pgrm){}

RPN::~RPN(){}

RPN	&RPN::operator=(const RPN &rhs)
{
	if (this != &rhs)
	{
		this->arg = rhs.arg;
		this->operand = rhs.operand;
		this->pgrm = rhs.pgrm;
	}
	return (*this);

}
// prefiltre en fonction du nb de chiffres p/r au nb d'opérateurs, et sur 
// l'absence de caractères non numériques et +-*/ cheque aussi si la pile ne
// contiendra que le résultat. EN FAIT VALIDE LA LIGNE OU PAS.
// https://stackoverflow.com/questions/14506831/whats-the-fastest-way-to-check-if-input-string-is-a-correct-rpn-expression
bool	RPN::is_plausible() const
{
	int	size_stack = 0;
	std::string charToString = "";
	std::string line = arg;
	if (arg.find_first_not_of(" 0123456789+-*/", 0) != std::string::npos)
		return (false);
	else
	{
		for (std::string::iterator iter=line.begin(); iter != line.end(); ++iter)
		{
			charToString = "";
			charToString = *iter + charToString;
			if (charToString.find_first_of("0123456789",0) != std::string::npos)
				++size_stack;
			else if (charToString.find_first_of("+-*/",0) != std::string::npos)
				--size_stack;
			if (size_stack <= 0)
				return (false);
		}
		if (size_stack == 1)
			return (true);
		else
			return (false);
	}
}

template<typename T>
void	RPN::print(std::stack<T> &stack)
{
	std::cout << yellow << std::endl;
	std::stack<T>	tmp;
	while (!stack.empty())
	{
		T top = stack.top();
		stack.pop();
		std::cout <<top << std::endl;
		tmp.push(top);
	}
	while (!tmp.empty())
	{
		T top = tmp.top();
		tmp.pop();
		stack.push(top);
	}
	std::cout << reset  << std::endl;
}

template<typename T>
void	RPN::reverse(std::stack<T> &pile)
{
	std::stack<T>	tmp;
	tmp = pile;
	while (!pile.empty())
		pile.pop();
	while (!tmp.empty())
	{
		T top = tmp.top();
		tmp.pop();
		pile.push(top);
	}
}

void	RPN::loadPgrm()
{
	std::string charToString = "";
	for(size_t i = 0; i < arg.size();++i)
	{
		std::string token = arg[i] + charToString;
		if (!(token == " "))
		{
			pgrm.push(token);
		}
	}
	reverse<std::string>(pgrm);
}

void	RPN::min()
{
	double op2 = operand.top();
	operand.pop();
	double op1 = operand.top();
	operand.pop();
	operand.push(op1 - op2);
}

void	RPN::add()
{
	double op2 = operand.top();
	operand.pop();
	double op1 = operand.top();
	operand.pop();
	operand.push(op1 + op2);
}

void	RPN::mul()
{
	double op2 = operand.top();
	operand.pop();
	double op1 = operand.top();
	operand.pop();
	operand.push(op1 * op2);
}

void	RPN::div()
{
	double op2 = operand.top();
	operand.pop();
	double op1 = operand.top();
	operand.pop();
	if (op2 != 0)
		operand.push(op1 / op2);
	else
		throw(divBy0);
}

void	RPN::test()
{
	try
	{
		if (!is_plausible())
			throw(error);
	}
	catch (std::exception &e)
	{
		std::cout <<red << e.what() << '\n' << reset;
	}
}

RPN::RPN(std::string arg):arg(arg)
{
	test();
	if (is_plausible())
	{
		loadPgrm();
		if (pgrm.size() == 1)
		{
			double number = to_int(pgrm.top());
			operand.push(number);
			pgrm.pop();
		}
		else
		while (!pgrm.empty())
		{
			while (std::isdigit(pgrm.top()[0]))
			{
				double number = to_int(pgrm.top());
				operand.push(number);
				pgrm.pop();
			}
			switch (pgrm.top()[0])
			{
				case '+':
					add();
					pgrm.pop();
				break;
				case '-':
					min();
					pgrm.pop();
				break;
				case '*':
					mul();
					pgrm.pop();
				break;
				case '/':
					try
					{
						div();
						pgrm.pop();
					}
					catch (std::exception &e)
					{
						std::cout <<red << e.what() << '\n' << reset;
						exit (-1);
					}
				break;
			}
		}
		std::cout << green << operand.top() << reset<<  std::endl;
	}
}
