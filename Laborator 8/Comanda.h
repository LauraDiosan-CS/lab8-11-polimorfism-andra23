#pragma once
#include <string>
#include<iostream>
#include<vector>
#include "Serializable.h"
using namespace std;
class Comanda :Serializable {
protected:
	char* numeClient;
	string adresaClient;
	float pretTotal;
public:
	Comanda();
	Comanda(const char* numeClient, string adresaClient, float pretTotal);
	Comanda(const Comanda& c);
	~Comanda();
	Comanda(string, string);
	virtual string toStringCSV();
	virtual string toStringHTML();
	static Comanda& fromString(string linie, string fileName);
	char* getNumeClient();
	string getAdresaClient();
	float getPretTotal();
	void setNumeClient(const char* numeClient);
	void setAdresaClient(string adresaClient);
	void setPretTotal(float pretTotal);
	Comanda& operator=(const Comanda& c);
	bool operator==(const Comanda&);
	friend ostream& operator<<(ostream& os, const Comanda& c);
	static vector<string> readLineFromFile(string, string);


};

