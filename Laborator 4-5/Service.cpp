#include "Service.h"

Service::Service()
//constructor
{
	this->repo;
}

void Service::addElem(Cheltuiala& c)
/*adauga un element in memorie
input: c: Cheltuiala, elementul de adaugat*/
{
	repo.addElem(c);
}

void Service::deleteElem(Cheltuiala& c)
/*sterge un element din memorie
input: c: Cheltuiala, elementul de sters*/
{
	repo.delElem(c);
}

void Service::updateElem(Cheltuiala& c)
/*modifica un element
input: c: Cheltuiala, elementul de modificat*/
{
	repo.updateElem(c);
}

vector<Cheltuiala> Service::getAll()
/*returneaza toate elementele salvate
uotput: repo.getAll: obiecte de tip "Cheltuiala"*/
{
	return repo.getAll();
}

Service::~Service()
//destructor
{}