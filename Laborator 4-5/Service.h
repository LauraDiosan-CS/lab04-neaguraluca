#pragma once
#include <iostream>
#include <string>
#include "Repository.h"
using namespace std;

class Service
{
private:
	Repository repo;
public:
	Service();
	void addElem(Cheltuiala&);
	void deleteElem(Cheltuiala&);
	void updateElem(Cheltuiala&);
	vector<Cheltuiala> getAll();
	~Service();

};