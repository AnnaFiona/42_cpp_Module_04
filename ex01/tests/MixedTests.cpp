# include "../WrongCat.hpp"
# include "../Cat.hpp"
# include "../Dog.hpp"
#include "tests.hpp"

void	mixed_constructor_tests(std::streambuf *filebuf, std::streambuf *coutbuf)
{
	//ex00:
	const WrongAnimal	*wcat = new WrongCat();
	const Animal		*animal = new Animal();
	const Animal		*cat = new Cat();
	const Animal		*dog = new Dog();

	compare(filebuf, coutbuf, "type:", wcat->getType(), "WrongAnimal", 'n');
	compare(filebuf, coutbuf, NULL, animal->getType(), "Animal", 'n');
	compare(filebuf, coutbuf, NULL, cat->getType(), "Animal", 'n');
	compare(filebuf, coutbuf, NULL, dog->getType(), "Animal", 'y');
	wcat->makeSound();
	animal->makeSound();
	cat->makeSound();
	dog->makeSound();
	cat->Animal::makeSound();

	delete dog;
	delete cat;
	delete animal;
	delete wcat;

	//ex01:
	Animal	**animals = new Animal*[10];
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	for (int x = 0; x < 5; x++)
		animals[x] = new Dog;
	for (int x = 5; x < 10; x++)
		animals[x] = new Cat;

	for (int x = 0; x < 10; x++)
		animals[x]->makeSound();
		
	delete i;
	delete j;//should not create a leak
	for (int x = 0; x < 10; x++)
		delete animals[x];
	delete [] animals;
}


void    mixed_tests()
{
	std::cout << "///Mixed-Class tests///" << std::endl;
	constructor_tests_framework(&mixed_constructor_tests, "my_output/mixed.txt", \
									"right_output/mixed.txt", "messages:");
	std::cout << std::endl;
}