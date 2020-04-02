#pragma once
#include "Cheltuiala.h"
#include <vector>
using namespace std;

class Repository
{
private:
	vector<Cheltuiala> elem;
public:
	Repository();
	Repository(const Repository&);
	void addElem(Cheltuiala);
	void delElem(Cheltuiala);
	void updateElem(Cheltuiala, int, int, char*);
	vector<Cheltuiala> getAll();
	Cheltuiala getFromPosition(int);
	Cheltuiala getById(int);
	bool findElem(Cheltuiala);
	int getSize();
	//void populate();
	//void updateElem(Cheltuiala);
	~Repository();
};
