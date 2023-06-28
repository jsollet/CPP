// programme de test pour se familiariser avec les containers
#include <iostream>

#include <string>
#include <exception>
#include <stdexcept>
#include <algorithm>
#include <sstream>
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
//void stat(std::vector<T> &v)
void stat(T  &v)
{
	std::cout << "empty:" <<  v.empty() << std::endl;
	std::cout << "size:" <<  v.size() << std::endl;
	if (typeid(T) != typeid(std::deque<int>))// ne fonctionne pas ?
	std::cout << "capacity:"<<v.capacity() << std::endl;
	std::cout << "max_size:" << v.max_size() << std::endl;
}

template<typename T>
void print(std::vector<T> &v)
{// ne fonctionne que pour les vecteurs 
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

template<typename T>
typename T::iterator  easyfind(T &container, int tbs)// que doit-elle retourner ?
{
/*	for (typename T::iterator it = begin(container); it != end(container); ++it)
	{
		if (*it == tbs)
			return (it);
	}
*/
	typename T::iterator it= find(begin(container), end(container), tbs);
	return (it);
//	return (end(container));
}

template<typename T>
void print_copy(T &v)
{// ne fct pas
//	std::cout << magenta;
	typename T::iterator end = begin(v) + v.size() -1;;
	typename T::iterator start = begin(v);
	std::cout << magenta << *start << "   " << *end << reset <<std::endl;
//	 	std::ostream_iterator<T> out_it (std::cout,", ");// la ca foire
//		std::copy(start, end, out_it);
		//	std::copy(v.begin(), v.end(), out_it);
//	std::cout<< reset << std::endl;
}

int main()
{
    std::list<int> ls;
	std::vector<int> v;
	std::deque<int> q;

	stat(v);
//	stat(q);
	for (int i=0; i <= 10 ; ++i)
	{
		v.push_back(i);
		ls.push_back(10 - i);
		q.push_front(i);
		q.push_back(i);
		stat(v);
	}
	for (int i = 0;i <= 14; ++i)
	{
	std::cout << green;
	printf("la position %d (distance p/r debut) est-elle correcte dans le vector? %ld\n",i, std::distance(v.begin(), easyfind(v,i)));
	std::cout <<red;
	printf("position de %d (distance p/r debut) est-elle correcte dans la liste? %ld\n",i, std::distance(ls.begin(), easyfind(ls,i)));
	std::cout << magenta;

	printf("position de %d (distance p/r debut) est-elle correcte dans la double queue? %ld\n",i, std::distance(q.begin(), easyfind(q,i)));
//	printf("position de %d (distance p/r debut) est-elle correcte dans la liste? %ld\n",i, easyfind(ls,i));
	std::cout << reset;
	}
	printf("la position 3 est-elle correcte ? %ld\n", easyfind(v,3) - v.begin());
	printf("le 44 est dans la liste ? %d\n", *easyfind(ls,44)); 
	print(v);
//	print(ls); //genere l'erreur sur print car une list pas un vector
	print1(v);
	print1(ls);
	std::cout << magenta;
	print1(q);
	std::cout << reset;

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
