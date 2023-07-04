#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << cyan << "top = " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "size = "<<  mstack.size() << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737); //[...] mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
    	std::cout << green << *it << std::endl;
		++it;
	}

	MutantStack<int> cstack(mstack);
	std::cout << reset <<"\n-------------    Test Copie    -------------\n"
	<< cyan <<"MutantStack<int> cstack(mstack);" ;
	std::cout << reset<< "\n----   vert mstack  |  rouge cstack   ------\n\n";
	while (!cstack.empty())
	{
		std::cout << green << &mstack.top()<< "\t" <<mstack.top() << reset << std::endl;
		std::cout << red << &cstack.top() << "\t" << cstack.top() << reset << std::endl;
		cstack.pop();
		mstack.pop();
	}
	
	mstack.push(5);
	mstack.push(3);
	mstack.push(5);
	mstack.push(737); //[...] mstack.push(0);
	MutantStack<int> equal;
	equal = mstack;
	std::cout << "\n----------    Test operator=     ----------\n"
	<< cyan <<"MutantStack<int> equal = mstack;" ;
	std::cout << reset<< "\n----   vert mstack  |  rouge equal   ------\n\n";
	while (!equal.empty())
	{
		std::cout << green << &mstack.top()<< "\t" <<mstack.top() << reset << std::endl;
		std::cout << red << &equal.top() << "\t" << equal.top() << reset << std::endl;
		equal.pop();
		mstack.pop();
	}

	std::cout << "\n----------    Test avec list    -----------\n";
	std::list<int> mlist;
	
	mlist.push_back(5);
	mlist.push_back(17);
	std::cout << cyan<< "top = "<< mlist.back() << std::endl;
	mlist.pop_back();
	std::cout << "size = " << mlist.size() << std::endl;
	
	mlist.push_back(3);
	mlist.push_back(5);
	mlist.push_back(737); //[...] mstack.push(0);
	std::list<int>::iterator lit = mlist.begin();
	std::list<int>::iterator lite = mlist.end();
	++lit;
	--lit;
	while (lit != lite)
	{
    	std::cout << green << *lit << std::endl;
		++lit;
	}
	std::cout << reset << "\n-------------  fin programme  -------------\n";

	return 0;
}
