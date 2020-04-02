#pragma once
#include "Service.h"
#include "Test.h"
#include "Repository.h"
#include "Cheltuiala.h"
#include <iostream>
#include <string>

class UI
{
private:
	Service serv;
public:
	UI();
	void meniu();
	void toAdd(Service&);
	void toDelete(Service&);
	void toUpdate(Service&);
	void toShow(Service&);
	void toPopulate(Service&);
	void fromADay(Service&);
	void sortCheltuieli(Service&);
	void sumByTip(Service&);
	void greaterSum(Service&);
	void showUI(Service&);
	~UI();
};