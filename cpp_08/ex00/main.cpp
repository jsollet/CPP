#include "easyfind.hpp"

int main()
{
	std::vector<int>::iterator	vec_iter;
	std::vector<int> v;

    std::list<int> ls;
	std::list<int>::iterator	ls_iter;
	std::deque<int> q;
	std::deque<int>::iterator	q_iter;

	for (size_t i=0; i <= 5 ; ++i)
	{
		v.push_back(i);
		ls.push_back(10 - i);
		q.push_front(i);
		q.push_back(i);
	}

	std::cout << "\n-------------  Test vector  -------------\n\n";
	std::cout << "taille du container = " << v.size() << std::endl << std::endl;
	std::cout << red << "end of vector = " << *end(v) << "adresse = " << &(*end(v))
	<< reset << std::endl << std::endl;
	std::cout << magenta << "contenu du vecteur \n" << reset;
	for (size_t i = 0;i < v.size(); ++i)
	{
		std::cout << "v["<<i<<"] = " << v[i] << "\tadresse = " << &v[i] << std::endl;
	}
	std::cout << std::endl;
	try
	{
	for (size_t i = 0; i <= 7; ++i)
		{
			vec_iter =easyfind(v, i);
			if (vec_iter != end(v))
			{
				std::cout << "valeur(" << i<<")  = "<< *vec_iter ;
				std::cout <<" et adresee = " << &(*vec_iter) << std::endl;
			}
		}
	}
	catch (const std::out_of_range & exc)
	{
		 std::cout << exc.what() << '\n';
	}



	std::cout << "\n-------------   Test list   -------------\n";
	std::cout << "taille du container = " << ls.size() << std::endl << std::endl;
	std::cout << red << "end of list = " << *end(ls) << "\t adresse = " << &(*end(ls))
	<< reset << std::endl << std::endl;

	std::cout << magenta << "contenu de la liste \n" << reset;
	ls_iter = ls.begin();
	for (size_t i = 0;i < ls.size(); ++i)
	{
		std::cout << "ls<"<<i<<"> = " << *(ls_iter) << "\tadresse = " <<
		&(*(ls_iter)) << std::endl;
		(ls_iter)++;
	}
	std::cout << std::endl;
	try
	{
	for (size_t i = 0; i <= 7; ++i)
		{
			ls_iter =easyfind(ls , 10 - i);
			if (ls_iter != end(ls))
			{
				std::cout << "Index:" << i<<"  = "<< *ls_iter ;
				std::cout <<" et adresee = " << &(*ls_iter) << std::endl;
			}
		}
	}
	catch (const std::out_of_range & exc)
	{
		 std::cout << exc.what() << '\n';
	}
	
	std::cout << "\n-------------  Test queue   -------------\n";

	std::cout << "taille du container = " << q.size() << std::endl << std::endl;
	std::cout << red << "end of list = " << *end(q) << "\t adresse = " <<
	&(*end(q))
	<< reset << std::endl << std::endl;

	std::cout << magenta << "contenu de la queue \n" << reset;
	q_iter = q.begin();
	for (size_t i = 0;i < q.size(); ++i)
	{
		std::cout << "q("<<i<<") = " << *(q_iter) << "\tadresse = " <<
		&(*(q_iter)) << std::endl;
		(q_iter)++;
	}
	std::cout << std::endl;
	try
	{
	for (size_t i = 0; i <= 10; ++i)
		{
			q_iter =easyfind(q , i);
			if (q_iter != end(q))
			{
				std::cout << "Index:" << i<<"  = "<< *q_iter ;
				std::cout <<" et adresee = " << &(*q_iter) << std::endl;
			}
		}
	}
	catch (const std::out_of_range & exc)
	{
		 std::cout << exc.what() << '\n';
	}
	
	std::cout << "\n-------------  fin programme  -------------\n";
	return(0);
}
