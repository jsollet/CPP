#ifndef ITER_HPP
# define  ITER_HPP

#include <iostream>
#include <string>

const std::string red("\033[0;31m");
const std::string green("\033[1;32m");
const std::string yellow("\033[1;33m");
const std::string cyan("\033[0;36m");
const std::string magenta("\033[0;35m");
const std::string reset("\033[0m");

/*
!!! La fonction  size() n'est pas celle définie dans c++11 !!!

https://stackoverflow.com/questions/2384107/how-does-this-template-magic-determine-array-parameter-size
https://stackoverflow.com/questions/437150/can-someone-explain-this-template-code-that-gives-me-the-size-of-an-array

*/
/*
1) template prend les tableau par référence.
	=> la version sans référence recevrai un pointeur, (...size(T a[]))
	=> d'où size(T (&a)...)
2) N existe SEULEMENT durant la compilation.
	=> N et T sont déduits par le "template argument deduction"
	=> ie par le type réel de l'argument passé au template.
	=> le compil. va créer une fonction spécifique à T et N.
*/
template<typename T, size_t N>
size_t size(T (&a)[N])
{
	(void)(a);
	return (N);
}

template<typename T>
void square(T &arg) {arg = arg*arg;}

template<typename T>
void print(T arg) {std::cout << arg << std::endl;}

template<typename T>
void printInline(T arg) {std::cout << arg;}


template<typename T>
void printSpace(T arg) {std::cout << arg << " ";}

template<typename T>
void add1(T &arg) {arg += 1;}

template<typename T>
void iter(T a[], size_t size, void (*fn) (T &))
{
	for (size_t i= 0; i < size; ++i)
	{
		fn(a[i]);
	}
	return;
}


#endif
