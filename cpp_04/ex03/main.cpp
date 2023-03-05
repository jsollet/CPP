#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	const std::string red("\033[0;31m");
	const std::string green("\033[1;32m");
	const std::string yellow("\033[1;33m");
	const std::string cyan("\033[0;36m");
	const std::string magenta("\033[0;35m");
	const std::string reset("\033[0m");
	std::cout<< green << "---------- Test Officiel ----------"<< std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
	
	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
    me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
	std::cout<< yellow << "---------- Test multiple cycle  ----------"<< std::endl;
	ICharacter* Rambo = new Character("rambo");
	ICharacter* Terminator = new Character("terminator");
	for (int i=0; i < 6; i++)
	{
		IMateriaSource* src1 = new MateriaSource();
		src1->learnMateria(new Ice());
		AMateria* tmp1;
		tmp1 = src1->createMateria("ice");
		Terminator->equip(tmp1);
		Terminator->use(0, *Rambo);
		delete src1;
	}
	delete Rambo;
	delete Terminator;
	std::cout<< magenta << "---------- Test surcharge d'inventaire  ----------"<< std::endl;
	IMateriaSource* materia_source = new MateriaSource();
	materia_source->learnMateria(new Cure());
	ICharacter* alf = new Character("Alf");
	for (int i = 0; i < 156; i++)
	{
		alf->equip(materia_source->createMateria("cure"));
	}
	delete materia_source;
	delete alf;
	std::cout<< magenta << "---------- copy et op= ----------"<< std::endl;
	IMateriaSource* ms = new MateriaSource();
	AMateria *cure = new Cure();
	ms->learnMateria(cure);
	ms->learnMateria(new Ice());
	Character* bert = new Character("Bert");
	bert->equip(ms->createMateria("cure"));
	bert->equip(ms->createMateria("ice"));
	bert->equip(ms->createMateria("cure"));
	bert->equip(ms->createMateria("ice"));
	Character *Dr = new Character(*bert);

	for (int i= 0; i < 4; i++)
	{
		std::cout << Dr->getStock(i)->getType() << "  <--Dr ";
		std::cout <<"bert--> "<< bert->getStock(i)->getType() << std::endl;
	}
	Dr->use(0, *bert);

	bert->equip(ms->createMateria("cure"));
	bert->equip(ms->createMateria("ice"));
	bert->equip(ms->createMateria("cure"));
	bert->equip(ms->createMateria("ice"));
	
	Character *dobb = new Character("Dobb");
	*dobb = *bert;
	
	for (int i= 0; i < 4; i++)
	{
		std::cout << dobb->getStock(i)->getType() << "  <--dobb";
		std::cout <<"bert--> "<< bert->getStock(i)->getType() << std::endl;
	}
	
	dobb->use(0, *bert);
	dobb->use(1, *bert);
	
	delete ms;
	delete bert;
	delete Dr;
	delete dobb;
	std::cout<< magenta << "---------- FIN  ----------"<< std::endl;
	return 0;
}
