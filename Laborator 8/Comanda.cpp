#include"Comanda.h"
#include<sstream>
#include<string.h>
#include<stdio.h>
#include<vector>
#include "Mancare.h"
#include "Shopping.h"
//#include <memory>
Comanda::Comanda() {
	//cout << "const implicit";
	this->numeClient = NULL;
	this->adresaClient = "";
	this->pretTotal = 0;
}
Comanda::Comanda(const char* numeClient, string  adresaClient, float pretTotal) {
	//cout << "constructor with param" << endl;
	this->numeClient = new char[strlen(numeClient) + 1];
	strcpy_s(this->numeClient, strlen(numeClient) + 1, numeClient);
	this->adresaClient = adresaClient;
	this->pretTotal = pretTotal;
}
Comanda::Comanda(const Comanda& c) {
	//cout << "copy constructor" << endl;
	this->numeClient = new char[strlen(c.numeClient) + 1];
	strcpy_s(this->numeClient, strlen(c.numeClient) + 1, c.numeClient);
	this->adresaClient = c.adresaClient;
	this->pretTotal = c.pretTotal;
}
Comanda::~Comanda() {
	//cout << "Destructor";
	if (this->numeClient) {
		delete[] this->numeClient;
		this->numeClient = NULL;
	}
	this->adresaClient = "";
	this->pretTotal = 0;
}
vector<string> Comanda::readLineFromFile(string linie, string fileName) {

	string parsed, parsed1;
	stringstream input_stringstream(linie);
	stringstream input_stringstream1(fileName);
	vector<string> s;
	vector<string> v;
	while (getline(input_stringstream1, parsed1, '.')) {

		v.push_back(parsed1);
	}
	if (v[v.size() - 1].compare("csv") == 0) {


		while (getline(input_stringstream, parsed, ',')) {

			s.push_back(parsed);
		}
	}
	else if (v[v.size() - 1].compare("html") == 0)
		while (getline(input_stringstream, parsed, '/')) {
			s.push_back(parsed);
		}
	else
		while (getline(input_stringstream, parsed, ',')) {
			s.push_back(parsed);
		}
	v.clear();
	return s;

}
Comanda::Comanda(string linie, string fileName) {

	string tok1, tok2, tok3;
	vector<string> s;
	s = readLineFromFile(linie, fileName);
	tok1 = s[0];
	tok2 = s[1];
	tok3 = s[2];
	this->numeClient = new char[tok1.length() + 1];
	strcpy_s(this->numeClient, tok1.length() + 1, tok1.c_str());
	this->adresaClient = tok2;
	this->pretTotal = stof(tok3);
	s.clear();
}
Comanda& Comanda::fromString(string linie, string fileName) {

	vector<string> s;
	s = readLineFromFile(linie, fileName);
	if (s.size() == 4) {
		//unique_ptr<Mancare> m(new Mancare(linie, fileName));
		Mancare* m = new Mancare(linie, fileName);
		return *m;
	}
	else {
		//unique_ptr<Shopping> s(new Shopping(linie, fileName));
		Shopping* s = new Shopping(linie, fileName);
		return *s;
	}
}
string Comanda::toStringCSV()
{
	char* array = this->numeClient;
	float pret = this->pretTotal;
	string adresaS = this->adresaClient;
	std::string numeClientS(array); // CONVERT CHAR* TO STRING
	std::string pretS = std::to_string(pret);
	vector<string> atr;
	atr.push_back(numeClientS);
	atr.push_back(adresaS);
	atr.push_back(pretS);
	string outstring;
	for (unsigned int i = 0; i < atr.size(); i++) {

		outstring += atr[i];
		if (i < atr.size() - 1) {

			outstring += ",";
		}
	}
	return outstring;

}
string Comanda::toStringHTML()
{
	char* array = this->numeClient;
	float pret = this->pretTotal;
	string adresaS = this->adresaClient;
	std::string numeClientS(array); // CONVERT CHAR TO STRING
	std::string pretS = std::to_string(pret);
	vector<string> atr;
	atr.push_back(numeClientS);
	atr.push_back(adresaS);
	atr.push_back(pretS);
	string outstring;
	for (unsigned int i = 0; i < atr.size(); i++) {

		outstring += atr[i];
		if (i < atr.size() - 1) {

			outstring += "/";
		}
	}
	return outstring;

}
char* Comanda::getNumeClient() {

	return this->numeClient;
}
string Comanda::getAdresaClient() {

	return this->adresaClient;
}
float Comanda::getPretTotal() {

	return this->pretTotal;
}
void Comanda::setNumeClient(const char* numeClient) {

	if (this->numeClient) {
		delete[] this->numeClient;
	}
	this->numeClient = new char[strlen(numeClient) + 1];
	strcpy_s(this->numeClient, strlen(numeClient) + 1, numeClient);
}
void Comanda::setAdresaClient(const string adresaClient) {

	this->adresaClient = adresaClient;
}
void Comanda::setPretTotal(float pretTotal) {

	this->pretTotal = pretTotal;
}

Comanda& Comanda::operator=(const Comanda& c) {

	this->setNumeClient(c.numeClient);
	this->setAdresaClient(c.adresaClient);
	this->setPretTotal(c.pretTotal);
	return *this;
}

bool Comanda::operator==(const Comanda& c) {

	return (strcmp(this->numeClient, c.numeClient) == 0) && (this->adresaClient.compare(c.adresaClient) == 0) && (this->pretTotal == c.pretTotal);
}
ostream& operator<<(ostream& os, const Comanda& c) {

	os << "Nume client: " << c.numeClient << "|" << " Adresa client: " << c.adresaClient << "|" << " Pret total: " << c.pretTotal;
	return os;
}


