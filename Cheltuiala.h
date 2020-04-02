#pragma once
#include <iostream>
#include <string>
using namespace std;

class Cheltuiala
{
private:
	int id;
	int zi;
	int suma;
	char* tip;
public:
	Cheltuiala();
	Cheltuiala(int, int, int, const char*);
	Cheltuiala(const Cheltuiala&);
	Cheltuiala& operator=(const Cheltuiala&);
	int getZi();
	int getSuma();
	char* getTip();
	void setZi(int);
	void setSuma(int);
	void setTip(char*);
	int getId();
	void setId(int);
	bool operator==(const Cheltuiala&);
	~Cheltuiala();
	friend ostream& operator<<(std::ostream& os, Cheltuiala c);
	friend istream& operator>>(istream&, Cheltuiala&);
	bool operator<(const Cheltuiala&);
};