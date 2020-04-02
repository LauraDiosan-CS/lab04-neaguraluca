#include "Repository.h"

Repository::Repository()
{
	this->elem;
}


Repository::Repository(const Repository& r)
{
	this->elem = r.elem;
}

void Repository::addElem(Cheltuiala c)
/*adauga un element
input: c: Cheltuiala, elementul de adaugat*/
{
	elem.push_back(c);
}

void Repository::delElem(Cheltuiala c) 
/*sterge un element
input: c: Cheltuiala, elementul de sters*/
{
	vector<Cheltuiala>::iterator it;
	it = find(elem.begin(), elem.end(), c);
	if (it != elem.end()) elem.erase(it);
}

void Repository::updateElem(Cheltuiala c, int s, int z, char* t)
/*modifica un element 
input: c: Cheltuiala, elementul de modificat
	   z:int, noua zi (intre 1-28/29/30/31)
	   s:int, noua suma (pozitiva)
	   t: char*, noul tip*/
{
	for (int i = 0; i < elem.size(); i++)
		if (elem[i] == c)
		{
			elem[i].setSuma(s);
			elem[i].setZi(z);
			elem[i].setTip(t);
		}
}

vector<Cheltuiala> Repository::getAll()
/*creaza un vector de obiecte "Cheltuiala"
output: elem: obiecte de tip "Cheltuiala"*/
{
	return elem;
}


Cheltuiala Repository::getFromPosition(int pos)
/*gaseste cheltuiala aferenta pozitii date
input: pos: int, pozitia de la care se cauta
output: elem[pos]: elementul gasit*/
{
	if ((0<=pos) and (pos<getSize()))
		return elem[pos];
}

Cheltuiala Repository::getById(int d)
/*gaseste cheltuiala aferenta id-ului dat
input: d: int, pozitia de la care se cauta
output: elem[i]: Cheltuiala, elementul gasit*/
{
	for (int i = 0; i < getSize(); i++)
		if (elem[i].getId() == d)
			return elem[i];
}

bool Repository::findElem(Cheltuiala c) 
/*verifica daca exista o anumita cheltuiala
output: true: daca exista o astfel de cheltuiala
		false: in caz contrar*/
{
	vector<Cheltuiala>::iterator it;
	it = find(elem.begin(), elem.end(), c);
	if (it != elem.end()) return true;
	return false;

}

int Repository::getSize()
//returneaza numarul de elemente salvate
{
	return elem.size();
}

Repository::~Repository()
//destructor
{}