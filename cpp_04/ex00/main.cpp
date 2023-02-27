#include <iostream>
#include <string>
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

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
	const Animal *A5 = new Cat("Felix");
	const Animal *A6 = new Dog("Pluto");
	Animal A7("Minou");
	const Cat *B1 = new Cat("Biscotte");
	Cat B2("Lucifer");
	const Dog *D1 = new Dog("Rintintin");
	Dog D2("Milou");
	std::cout << std::endl << "------------ test copy constructor  -------------" << std::endl;
	const Animal A4(*A2);
	const Cat B3(*B1);
	const Dog D3(*D1);

	std::cout << std::endl << "------------ test operator (diff class)  -------------" << std::endl;
	A7 = *D1;
	A7 = B2;
//	B2 = *D1;
//	D1 = *A2;
	std::cout << std::endl << "------------ test operator (same class) -------------" << std::endl;
	A0 = *A2;
	B2 = *B1;
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
	delete(A1);
	delete(A2);
	delete(A5);
	delete(A6);
	delete(B1);
	delete(D1);
	delete(WA);
	delete(WC);
	return 0;
}
