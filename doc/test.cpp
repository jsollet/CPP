#include <iostream>
#include <string>

template<typename T>
T sum(T a, T b)
{
    return a + b;
}

template<class T>
struct Summator
{
    T operator()(T a, T b)
    {
        return sum<T>(a, b);
    }
};

template<template<typename> class TFunctor, class T>
T doSomething(T a, T b)
{
    return TFunctor<T>()(a, b);
    //Equivalent to this:
    //TFunctor<T> functor;
    //return functor(a, b);
}

	template<typename F, typename T>
T callFunc(T a, T b, F f)
{
    return f(a, b);
}

int main()
{
	
	Summator b;
	int a= callFunc(1,2, sum<int>);
	std::cout << doSomething<Summator>(3,4)<< std::endl;
	std::cout << b.(3,4)<< std::endl;


}
