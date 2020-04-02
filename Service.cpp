#include "Service.h"
#include<algorithm>
using namespace std;

Service::Service()
//constructor
{
	this->repo;
	this->undo.push_back(this->repo);
}

void Service::addElem(Cheltuiala& c)
/*adauga un element in memorie
input: c: Cheltuiala, elementul de adaugat*/
{
	undo.push_back(this->repo);
	repo.addElem(c);
}



Cheltuiala Service::getById(int d)
//gaseste o cheltuiala in functie de id-ul ei
{
	return repo.getById(d);
}

void Service::updateElem(Cheltuiala c, int z, int s, char* t)
/*modifica un element
input: c: Cheltuiala, elementul de modificat
	   z:int, noua zi (intre 1-28/29/30/31)
	   s:int, noua suma (pozitiva)
	   t: char*, noul tip*/
{
	undo.push_back(this->repo);
	repo.updateElem(c, z, s, t);
}


/*bool compareBySum(Cheltuiala c1, Cheltuiala c2)
{
	return (c1.getSuma() > c2.getSuma());
}*/

vector<Cheltuiala> Service::sortCheltuieli()
{
	vector<Cheltuiala>all_tip=getAll();
	sort(all_tip.begin(), all_tip.end());
	return all_tip;
}

vector<Cheltuiala> Service::fromADay(int z)
{
	vector<Cheltuiala> cheltuieli = getAll();
	vector<Cheltuiala> ok;
	for (Cheltuiala c : cheltuieli)
		if (c.getZi() == z)
			ok.push_back(c);
	return ok;
		
}

vector<Cheltuiala> Service::greaterThan(int suma)
/*gaseste toate cheltuielile cu suma mai mare decat o suma limita
input: suma: int, suma limita
output: elementele gasite*/
{
	vector<Cheltuiala> chelt = getAll();
	vector<Cheltuiala> ok;
	for (Cheltuiala c : chelt)
		if (c.getSuma() >= suma)
			ok.push_back(c);
	return ok;
}


void Service::delById(Cheltuiala& c, int d)
/*sterge o cheltuiala in functie de id
input: d: int, id-ul cautat
*/
{
	undo.push_back(this->repo);
	c = repo.getById(d);
	repo.delElem(c);
}



vector<Cheltuiala> Service::getAll()
/*returneaza toate elementele salvate
uotput: repo.getAll: obiecte de tip "Cheltuiala"*/
{
	return repo.getAll();
}

void Service::populate()
//populeaza 
{
	Cheltuiala c1 = Cheltuiala(1, 14, 100, "mancare");
	Cheltuiala c2 = Cheltuiala(2, 1, 80, "gaz");
	Cheltuiala c3 = Cheltuiala(3, 29, 130, "benzina");
	Cheltuiala c4 = Cheltuiala(4, 17, 100, "electricitate");
	Cheltuiala c5 = Cheltuiala(5, 1, 100, "mancare");
	Cheltuiala c6 = Cheltuiala(6, 1, 80, "mancare");
	Cheltuiala c7 = Cheltuiala(7, 1, 130, "benzina");
	Cheltuiala c8 = Cheltuiala(8, 17, 90, "haine");
	repo.addElem(c1);
	repo.addElem(c2);
	repo.addElem(c3);
	repo.addElem(c4);
	repo.addElem(c5);
	repo.addElem(c6);
	repo.addElem(c7);
	repo.addElem(c8);
	
}

int Service::sumByTip(string t)
/*calculeaza suma unui anume tip
input: t: string, tipul pt care se va face suma
output: int,suma aferenta*/
{
	int suma=0;
	vector<Cheltuiala> chelt = getAll();
	for (int i=0; i<chelt.size(); i++)
		if (chelt[i].getTip() == t)
			suma = chelt[i].getSuma()+suma;
	return suma;
}

void Service::undo_operation()
//reface ultima operatie
{
	auto actual_state = undo.back();
	undo.pop_back();
	this->repo = actual_state;
	this->undo = undo;
}

Service::~Service()
//destructor
{}

