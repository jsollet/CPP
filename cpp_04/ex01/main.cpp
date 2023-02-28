#include <iostream>
#include <string>
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const std::string red("\033[0;31m");
	const std::string reset("\033[0m");

	std::cout << std::endl << "type of [Animal* j = new Dog() = " << j->getType() << " " << std::endl;
	std::cout << std::endl << "type of [Animal* i = new Cat() = " << i->getType() << " " << std::endl;
	std::cout << std::endl << "------------ test getType -------------" << std::endl;
	std::cout << "Cat " << i->getType() << " " << std::endl;
	std::cout << "Dog " << j->getType() << " " << std::endl;
	std::cout << "Meta " << meta->getType() << " " << std::endl;
/*	std::cout << std::endl << "------------ test sound -------------" << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	std::cout << std::endl << "------------ test destructor -------------" << std::endl;
*/	delete(meta);
	delete(j);
	delete(i);

	std::cout << std::endl << "------------ test animal -------------" << std::endl;
	const Animal *A1 = new Animal("Bestiole 1");
	const Animal *A2 = new Animal("Bestiole 2");
	const Animal *A5 = new Cat("Felix", "I am hungry");
	const Animal *A6 = new Dog("Pluto", "Bones, Bones,...");
	const Cat *B1 = new Cat("Biscotte", "Would ate a mice ");
	const Dog *D1 = new Dog("Rintintin", "Tired to be a good dog");
	std::cout << "------------ test exo 1 -------------" << std::endl;
	std::cout<<red;
	const Animal* j1 = new Dog();
	const Animal* i1 = new Cat();
   	delete j1;
	delete i1;
	std::cout<<reset;
	Animal	*animal[12];
	for (int i = 0;i < 12; i++)
	{
		if (i % 2 == 0)
			animal[i] = new Cat();
		else
			animal[i] = new Dog();
	}//https//:github.com/lschrafstetter/42_cpp04/blob/master/ex01/main.cpp
	for (int i = 0; i < 12; i++)
	{
		std::cout << i<< "     " <<animal[i]->getType();
		animal[i]->makeSound();
		std::cout<<std::endl;
	}
	std::cout << std::endl << "------------ Cat *Maxi = new Cat(*Felix) ------------------"<<std::endl;
	std::cout << "------------ before copy : Felix.idea <-- [ idea  nb...]  ------------------"<< std::endl;
	std::cout << "------------ after copy : Felix.idea <-- [new idea of Felix nb...]  ------------------"<< std::endl;
	Cat *Felix = new Cat("Felix", "");

	for (int i = 0; i < 12; i++)
	{
		std::string s="Idea nb ";
		s += std::to_string(i);
		Felix->getBrain()->setIdea(i, s);
//		std::cout << i << "  " << Felix->getBrain()->getIdea(i) << std::endl;
	}
	Cat *Maxi = new Cat(*Felix);
	for (int i = 0; i < 12; i++)
	{
		std::string s="new idea of Felix nb ";
		s += std::to_string(i);
		Felix->getBrain()->setIdea(i, s);
//		std::cout << i << "  " << Felix->getBrain()->getIdea(i) << std::endl;
	}
	for (int i= 0; i< 12; i++)
	{
		std::cout << i << " Felix : " << Felix->getBrain()->getIdea(i);
		std::cout << "\t Maxi : " << Maxi->getBrain()->getIdea(i) << std::endl;

	}

	std::cout << std::endl<< "------------  *Tigrou = *Felix ------------------"<< std::endl;
	std::cout << "------------ after = : Felix.idea <-- [old idea of Felix nb...]  ------------------"<< std::endl;
	Cat *Tigrou = new Cat("Tigrou", "");

	*Tigrou  = *Felix;
	for (int i = 0; i < 12; i++)
	{
		std::string s="old idea of Felix nb ";
		s += std::to_string(i);
		Felix->getBrain()->setIdea(i, s);
//		std::cout << i << "  " << Felix->getBrain()->getIdea(i) << std::endl;
	}
	for (int i= 0; i< 12; i++)
	{
		std::cout << i << " Felix : " << Felix->getBrain()->getIdea(i);
		std::cout << "\t Tigrou: " << Tigrou->getBrain()->getIdea(i) << std::endl;

	}

	delete(Tigrou);
	delete(Felix);
	delete(Maxi);
	for (int i = 0; i < 12; i++)
	{
		delete (animal[i]);
	}	
	
	delete(A1);
	delete(A2);
	delete(A5);
	delete(A6);
	delete(B1);
	delete(D1);
	std::cout << "------------ FIN -------------" << std::endl;
	return 0;
}
