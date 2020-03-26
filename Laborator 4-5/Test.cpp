#include "test.h"
#include "Repository.h"

void test_entitate()
//testeaza crearea corecta a entitatii
{
	Cheltuiala c1 = Cheltuiala(14, 100, "mancare");
	assert(c1.getZi() == 14);
	assert(c1.getSuma() == 100);
	//assert(c1.get_tip() == "mancare");
}

void test_gasire()
//testeaza gasirea unui element
{
	Repository repository;
	Cheltuiala c1 = Cheltuiala(14, 100, "mancare");
	Cheltuiala c2 = Cheltuiala(1, 80, "gaz");
	assert(repository.getFromPosition(0) == c1);
}

void test_adaugare()
//testeaza adaugarea unui element
{
	Repository repository;
	Cheltuiala c1 = Cheltuiala(14, 100, "mancare");
	Cheltuiala c2 = Cheltuiala(1, 80, "gaz");
	repository.addElem(c1);
	assert(repository.getSize() == 1);
	repository.addElem(c2);
	assert(repository.getSize() == 2);
}

void test_stergere()
//testeaza stergerea unui element
{
	Repository repository;
	Cheltuiala c1 = Cheltuiala(14, 100, "mancare");
	Cheltuiala c2 = Cheltuiala(1, 80, "gaz");
	Cheltuiala c3 = Cheltuiala(29, 130, "benzina");
	Cheltuiala c4 = Cheltuiala(17, 100, "electricitate");
	repository.addElem(c1);
	repository.addElem(c2);
	repository.addElem(c3);
	repository.addElem(c4);
	repository.delElem(c2);
	assert(repository.getSize() == 3);
	repository.delElem(c1);
	repository.delElem(c2);
	assert(repository.getSize() == 2);
}
