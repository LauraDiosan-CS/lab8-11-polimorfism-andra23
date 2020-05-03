#pragma once
#include "Comanda.h"
#include<vector>
using namespace std;
class Shopping : public Comanda {
private:
	vector<string>listaCumparaturi;
	char* numeMagazin;
public:
	Shopping();
	Shopping(const char*, const string, float, vector<string>, const char*);
	Shopping(const Shopping&);
	~Shopping();
	Shopping(string, string);
	string toStringCSV();
	string toStringHTML();
	vector<string> getListaCumparaturi();
	void setListaCumparaturi(vector<string>);
	char* getNumeMagazin();
	void setNumeMagazin(const char* numeMagazin);
	Shopping& operator=(const Shopping&);
	bool operator==(const Shopping&);
	friend ostream& operator<<(ostream& os, const Shopping& s);

};

