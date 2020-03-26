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
	void updateElem(Cheltuiala);
	vector<Cheltuiala> getAll();
	Cheltuiala getFromPosition(int);
	bool findElem(Cheltuiala);
	int getSize();
	~Repository();
};
