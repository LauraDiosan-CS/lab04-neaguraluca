#include "test.h"
#include "Repository.h"


void testEntitate()
//testeaza crearea corecta a entitatii
{
	Cheltuiala c1 = Cheltuiala(1, 14, 100, "mancare");
	assert(c1.getZi() == 14);
	assert(c1.getSuma() == 100);
	//assert(c1.get_tip() == "mancare");
}

void testGasire()
//testeaza gasirea unui element
{
	Repository repository;
	Cheltuiala c1 = Cheltuiala(1, 14, 100, "mancare");
	Cheltuiala c2 = Cheltuiala(2, 1, 80, "gaz");
	assert(repository.getFromPosition(0) == c1);
	assert(repository.getById(2) == c2);
}

void testAdaugare()
//testeaza adaugarea unui element
{
	Repository repository;
	Cheltuiala c1 = Cheltuiala(1, 14, 100, "mancare");
	Cheltuiala c2 = Cheltuiala(2, 1, 80, "gaz");
	repository.addElem(c1);
	assert(repository.getSize() == 1);
	repository.addElem(c2);
	assert(repository.getSize() == 2);
}

void testStergere()
//testeaza stergerea unui element
{
	Repository repository;
	Cheltuiala c1 = Cheltuiala(1, 14, 100, "mancare");
	Cheltuiala c2 = Cheltuiala(2, 1, 80, "gaz");
	Cheltuiala c3 = Cheltuiala(3, 29, 130, "benzina");
	Cheltuiala c4 = Cheltuiala(4, 17, 100, "electricitate");
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

void testSortare()
{
	Cheltuiala c1 = Cheltuiala(1, 14, 180, "mancare");
	Cheltuiala c2 = Cheltuiala(2, 1, 80, "gaz");
	Cheltuiala c3 = Cheltuiala(3, 29, 130, "benzina");
	Cheltuiala c4 = Cheltuiala(4, 17, 100, "electricitate");
	Service serv;
	vector<Cheltuiala> chelt = serv.sortCheltuieli();
	assert(chelt[0] == c2);
	assert(chelt[3] == c1);
}

void testGasireZi()
{
	Cheltuiala c1 = Cheltuiala(1, 14, 180, "mancare");
	Cheltuiala c2 = Cheltuiala(2, 1, 80, "gaz");
	Cheltuiala c3 = Cheltuiala(3, 14, 130, "benzina");
	Cheltuiala c4 = Cheltuiala(4, 17, 100, "electricitate");
	Service serv;
	vector<Cheltuiala> chelt = serv.fromADay(14);
	assert(chelt[0] == c1);
	assert(chelt[1] == c3);
}

void testSumaTip()
{
	Cheltuiala c1 = Cheltuiala(1, 14, 180, "mancare");
	Cheltuiala c2 = Cheltuiala(2, 1, 80, "gaz");
	Cheltuiala c3 = Cheltuiala(3, 14, 130, "benzina");
	Cheltuiala c4 = Cheltuiala(4, 17, 100, "gaz");
	Service serv;
	assert(serv.sumByTip("gaz") == 180);
}

void testSumaMaiMare()
{
	Cheltuiala c1 = Cheltuiala(1, 14, 180, "mancare");
	Cheltuiala c2 = Cheltuiala(2, 1, 80, "gaz");
	Cheltuiala c3 = Cheltuiala(3, 14, 130, "benzina");
	Cheltuiala c4 = Cheltuiala(4, 17, 100, "electricitate");
	Service serv;
	vector<Cheltuiala> chelt = serv.greaterThan(101);
	assert(chelt[0] == c3);
}
