// programme de test pour se familiariser avec les containers
#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <algorithm>
#include <vector> //dynamic continuous array
#include <deque>  //double-ended queue
#include <list>   //doubly-linked list

/* liste des containers associatifs (non demandés)
#include <set>
#include <map>
#include <multiset>
#include <multimap>
*/
/*
// ici la template function easyfind 
template<typename T>
easyfind(T &arg, int tbs)
{
}
*/

const std::string red("\033[0;31m");
const std::string green("\033[1;32m");
const std::string yellow("\033[1;33m");
const std::string cyan("\033[0;36m");
const std::string magenta("\033[0;35m");
const std::string reset("\033[0m");

template<typename T>
void stat(std::vector<T> &v)
{
	std::cout << "empty:" <<  v.empty() << std::endl;
	std::cout << "size:" <<  v.size() << std::endl;
	std::cout << "capacity:"<<v.capacity() << std::endl;
	std::cout << "max_size:" << v.max_size() << std::endl;
}

template<typename T>
void print(std::vector<T> &v)
{
	for(typename std::vector<T>::iterator  iter=v.begin(); iter !=v.end();++iter)
		std::cout <<red << *iter << " ";
	std::cout << reset <<std::endl;
}

template<typename T>
void print1(T &v)
{// fonctionne bien
	for(typename T::iterator it=begin(v); it !=end(v); ++it)
		std::cout <<green << *it << " ";
	std::cout << reset <<std::endl;
		
}

int main()
{
    std::list<int> ls;
	
	std::vector<int> v;
	stat(v);
	for (int i=0; i < 10 ; ++i)
	{
		v.push_back(i);
		ls.push_back(10 - i);
		stat(v);
	}
	print(v);
	print(ls);
	print1(v);
	print1(ls);
	for (int i=0; i < v.size() ; ++i)
		std::cout << v[i] << std::endl;
	try
	{
		v.at(1) = - v[1];
		v.resize(12);
		v.at(10) = 999;
	}
	catch (const std::out_of_range & exc)
	{
		 std::cout << exc.what() << '\n';
	}
	for (int i=0; i < v.size() ; ++i)
		std::cout << v[i] << std::endl;
	return(0);
}
