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
//	const Animal* meta = new Animal();//pure virtual
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const std::string red("\033[0;31m");
	const std::string green("\033[1;32m");
	const std::string yellow("\033[1;33m");
	const std::string cyan("\033[0;36m");
	const std::string magenta("\033[0;35m");
	const std::string reset("\033[0m");

	std::cout << std::endl << "type of [Animal* j = new Dog() = " << j->getType() << " " << std::endl;
	std::cout << std::endl << "type of [Animal* i = new Cat() = " << i->getType() << " " << std::endl;
	std::cout << std::endl << "------------ test getType -------------" << std::endl;
	std::cout << "Cat " << i->getType() << " " << std::endl;
	std::cout << "Dog " << j->getType() << " " << std::endl;
//	std::cout << "Meta " << meta->getType() << " " << std::endl;
//	delete(meta);
	delete(j);
	delete(i);

	std::cout << std::endl << "------------ test animal -------------" << std::endl;
//	const Animal *A1 = new Animal("Bestiole 1");
//	const Animal *A2 = new Animal("Bestiole 2");
	const Animal *A5 = new Cat("Felix", "I am hungry");
	const Animal *A6 = new Dog("Pluto", "Bones, Bones,...");
	const Cat *B1 = new Cat("Biscotte", "Would ate a mice ");
	const Dog *D1 = new Dog("Rintintin", "Tired to be a good dog");
	std::cout << cyan <<"------------ test exo 1 -------------" << std::endl;
//	const Animal* j1 = new Dog();
//	const Animal* i1 = new Cat();
// 	delete j1;
//	delete i1;
	Animal	*animal[12];
	for (int i = 0;i < 12; i++)
	{
		if (i % 2 == 0)
			animal[i] = new Cat();
		else
			animal[i] = new Dog();
	}
	for (int i = 0; i < 12; i++)
	{
		std::cout << i<< "     " <<animal[i]->getType();
		animal[i]->makeSound();
		std::cout<<std::endl;
	}
//	delete(A1);
//	delete(A2);
	delete(A5);
	delete(A6);
	delete(B1);
	delete(D1);
	for (int i = 0; i < 12; i++)
	{
		delete (animal[i]);
	}
	std::cout << green <<  std::endl << "------------ DEEP COPY ------------------"<<std::endl;
	std::cout << std::endl << "------------ Cat *Maxi = new Cat(*Felix) ------------------"<<std::endl;
	std::cout << "------------ before copy : Felix.idea <-- [ idea  nb...]  ------------------"<< std::endl;
	std::cout << "------------ after copy : Felix.idea <-- [new idea of Felix nb...]  ------------------"<< std::endl;
	Cat *Felix = new Cat("Felix", "");

	for (int i = 0; i < 12; i++)
	{
		std::string s="Idea nb ";
		s += std::to_string(i);
		Felix->getBrain()->setIdea(i, s);
	}
	Cat *Maxi = new Cat(*Felix);
	for (int i = 0; i < 12; i++)
	{
		std::string s="new idea of Felix nb ";
		s += std::to_string(i);
		Felix->getBrain()->setIdea(i, s);
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
	}
	for (int i= 0; i< 12; i++)
	{
		std::cout << i << " Felix : " << Felix->getBrain()->getIdea(i);
		std::cout << "\t Tigrou: " << Tigrou->getBrain()->getIdea(i) << std::endl;

	}
	delete(Tigrou);
	delete(Felix);
	delete(Maxi);

	std::cout << red << std::endl << "------------ SHALLOW COPY ------------------"<<std::endl;
	std::cout << "------------ before copy : XFeli.idea <-- [ Wrong idea  nb...]  ------------------"<< std::endl;
	std::cout << "------------ after copy : XFeli.idea <-- [new wrong idea of XFeli nb...]  ------------------"<< std::endl;
	WrongCat	*WC1 = new WrongCat("XFeli","");

	for (int i = 0; i < 12; i++)
	{
		std::string s="Wrong Idea nb ";
		s += std::to_string(i);
		WC1->getBrain()->setIdea(i, s);
	}
	WrongCat *Xmai(WC1);
	for (int i = 0; i < 12; i++)
	{
		std::string s="new wrong idea of XFeli nb ";
		s += std::to_string(i);
		WC1->getBrain()->setIdea(i, s);
	}
	for (int i= 0; i< 12; i++)
	{
		std::cout << i << " XFeli : " << WC1->getBrain()->getIdea(i);
		std::cout << "\t XMai : " << Xmai->getBrain()->getIdea(i) << std::endl;
	}
	delete(WC1);
/*	std::cout << std::endl<< "------------  *XTigrou = XFeli ------------------"<< std::endl;
	std::cout << "------------ after = : Felix.idea <-- [old idea of Felix nb...]  ------------------"<< std::endl;
	WrongCat WC2 = WrongCat("Felix", "");
	WrongCat XTigrou = WrongCat("Tigrou", "");
//	WrongCat XTigrou("Tigrou", "");
	XTigrou  = WC2;
	for (int i = 0; i < 12; i++)
	{
		std::string s="old wrong idea of XFeli nb ";
		s += std::to_string(i);
		WC2.getBrain()->setIdea(i, s);
	}
	for (int i= 0; i< 12; i++)
	{
		std::cout << i << " XFeli : " << WC2.getBrain()->getIdea(i);
		std::cout << "\t XTigrou: " << XTigrou.getBrain()->getIdea(i) << std::endl;

	}
	std::cout << reset;
//	delete (XTigrou);
//	delete (Xmai);
//	delete (WC2);
*/
	std::cout << reset << "------------ FIN -------------" << std::endl;
	return 0;
}
