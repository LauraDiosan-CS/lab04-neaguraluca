#include "cheltuiala.h"
#include <cstddef>
#include <string.h>
#include <sstream>

Cheltuiala::Cheltuiala()
//constructor
{
	this->zi = 0;
	this->suma = 0;
	this->tip = NULL;
}

Cheltuiala::Cheltuiala(int zi, int suma, const char* tip)
//constructor cu paramentrii
{
	this->tip = new char[strlen(tip) + 1];
	strcpy_s(this->tip, strlen(tip) + 1, tip);
	this->zi = zi;
	this->suma = suma;
}

Cheltuiala::Cheltuiala(const Cheltuiala& s)
{
	this->tip = new char[strlen(s.tip) + 1];
	strcpy_s(this->tip, strlen(s.tip) + 1, s.tip);
	this->zi = s.zi;
	this->suma = s.suma;
}

int Cheltuiala::getZi()
//returneaza ziua unei anumite cheltuieli
{
	return this->zi;
}


int Cheltuiala::getSuma()
//returneaza suma unei anumite cheltuieli
{
	return this->suma;
}

char* Cheltuiala::getTip()
//returneaza tipul unei anumite cheltuieli
{
	return this->tip;
}

void Cheltuiala::setZi(int z)
/*modifica ziua unei anumite cheltuieli
input: z: int, cuprins intre 1 si 28/29/30/31(dupa caz), noua zi
*/
{
	this->zi = z;
}

void Cheltuiala::setSuma(int s)
/*modifica suma unei anumite cheltuieli
input: s:int, pozitiv, noua suma
*/
{
	this->suma = s;
}

void Cheltuiala::setTip(char* t)
/*modifica tipul unei anumite cheltuieli
input: t: *char, noul tip*/
{
	if (tip) delete[]tip;
	tip = new char[strlen(t) + 1];
	strcpy_s(tip, strlen(t) + 1, t);
}

Cheltuiala& Cheltuiala:: operator=(const Cheltuiala& c)
//operator de atribuire
{
	this->setZi(c.zi);
	this->setSuma(c.suma);
	this->setTip(c.tip);
	return *this;
}

bool Cheltuiala::operator==(const Cheltuiala& c)
//operator de egalitate
{
	return (zi == c.zi) and (suma == c.suma) and (strcmp(tip, c.tip) == 0);
}

ostream& operator<<(ostream& os, Cheltuiala c) 
//afisarea unui obiect de tip "Cheltuiala"
{
	os <<"Ziua: "<< c.zi << " suma: " << c.suma << " tipul: " << c.tip << endl;
	return os;
}

istream& operator>>(istream& is, Cheltuiala& c)
//citirea unui obiect de tip "Cheltuiala"
{
	cout << "Dati ziua: ";
	int z;
	cin >> z;
	cout << "Dati suma: ";
	int s;
	cin >> s;
	cout << "Dati tipul: ";
	char* tip = new char[10];
	is >> tip;
	c.setTip(tip);
	c.setZi(z);
	c.setSuma(s);
	delete[] tip;
	return is;
}

Cheltuiala::~Cheltuiala()
//destructor
{
	zi = -1;
	suma = -1;
	tip = NULL;
}