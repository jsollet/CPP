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
	std::cout << std::endl << "------------ test sound -------------" << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	std::cout << std::endl << "------------ test destructor -------------" << std::endl;
	delete(meta);
	delete(j);
	delete(i);

	std::cout << std::endl << "------------ test animal -------------" << std::endl;
	Animal A0("Alien");
	const Animal *A1 = new Animal("Bestiole 1");
	const Animal *A2 = new Animal("Bestiole 2");
	const Animal *A3(A1);// n'appelle aucun constructeur?
	printf("A3 address = %p\n", (void *)A3);
	const Animal *A5 = new Cat("Felix", "I am hungry");
	const Animal *A6 = new Dog("Pluto", "Bones, Bones,...");
	Animal A7("Minou");
	const Cat *B1 = new Cat("Biscotte", "Would ate a mice ");
//	Cat B2("Lucifer", "Would like to play"); // LEAK
	const Cat *B2 = new Cat("Lucifer", "Would like to play"); // LEAK
	const Dog *D1 = new Dog("Rintintin", "Tired to be a good dog");
	Dog D2("Milou", " I hate Haddock ");
//	B2.makeSound();
	std::cout << std::endl << "------------ test copy constructor  -------------" << std::endl;
	const Animal A4(*A2);
	const Cat B3(*B1);
	const Dog D3(*D1);
	Cat B4(*B2);
	B4=*B1;
	std::cout<<red;
	Cat CC;
	CC = *B2;
	std::cout<<reset;
	std::cout << std::endl << "------------ test operator (diff class)  -------------" << std::endl;
	A7 = *D1;
//	A7 = B2;
//	A7 = *B2;
//	B2 = *D1;
//	D1 = *A2;
	std::cout << std::endl << "------------ test operator (same class) -------------" << std::endl;
	A0 = *A2;
//	B2 = B1;
//	B2 = B1;
	D2 = *D1;
	std::cout << std::endl << "------------ test animal  sound  -------------" << std::endl;
	A1->makeSound();
	A2->makeSound();
	A3->makeSound();
	A5->makeSound();
	A6->makeSound();
	A7.makeSound();
	std::cout << std::endl << "------------ test Wrong (no virtual sound) -------------" << std::endl;
	std::cout << "------------ test WrongAnimal = new WrongCat -------------" << std::endl;
	const WrongAnimal *WA = new WrongCat();
	WA->makeSound();
	std::cout << "------------ test WrongCat = new WrongCat -------------" << std::endl;
	const WrongCat *WC = new WrongCat();
	WC->makeSound();
	std::cout << "------------ test exo 1 -------------" << std::endl;
	std::cout<<red;
	const Animal* j1 = new Dog();
	const Animal* i1 = new Cat();
   	delete j1;
	delete i1;
	std::cout<<reset;
	delete(A1);
	delete(A2);
	delete(A5);
	delete(A6);
	delete(B1);
	delete(B2);// pb malloc car ligne 66 efface B2 !!
	delete(D1);
	delete(WA);
	delete(WC);
	std::cout << "------------ FIN -------------" << std::endl;
	return 0;
}
