#pragma once
#include <iostream>
#include <string>
#include "Repository.h"
using namespace std;

class Service
{
private:
	Repository repo;
	vector<Repository> undo;
public:
	Service();
	void addElem(Cheltuiala&);
	//void deleteElem(Cheltuiala&);
	void delById(Cheltuiala&, int);
	void updateElem(Cheltuiala, int, int, char*);
	vector<Cheltuiala> getAll();
	vector<Cheltuiala> sortCheltuieli();
	vector<Cheltuiala> greaterThan(int);
	vector<Cheltuiala> fromADay(int);
	Cheltuiala getById(int);
	void populate();
	//bool compareBySum(Cheltuiala, Cheltuiala);
	int sumByTip(string);
	void undo_operation();
	~Service();

};