#pragma once
#include "Comanda.h"
#include<vector>
using namespace std;
class Mancare : public Comanda {
private:
	vector<string>listaPreparate;
public:
	Mancare();
	Mancare(const char*, const string, float, vector<string>);
	Mancare(const Mancare&);
	~Mancare();
	Mancare(string, string);
	string toStringCSV();
	string toStringHTML();
	vector<string> getListaPreparate();
	void setListaPreparate(vector<string>);
	Mancare& operator=(const Mancare&);
	bool operator==(const Mancare&);
	friend ostream& operator<<(ostream& os, const Mancare& c);
	//Comanda* clone() { return new Mancare(*this); }

};
