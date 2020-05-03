#include"Shopping.h"
#include<sstream>
#include<string.h>
Shopping::Shopping() {

	this->numeMagazin = NULL;
}
Shopping::Shopping(const char* n, const string a, float p, vector<string> l, const char* numeMagazin) :Comanda(n, a, p) {

	listaCumparaturi = l;
	this->numeMagazin = new char[strlen(numeMagazin) + 1];
	strcpy_s(this->numeMagazin, strlen(numeMagazin) + 1, numeMagazin);

}
Shopping::Shopping(const Shopping& s) : Comanda(s) {

	listaCumparaturi = s.listaCumparaturi;
	this->numeMagazin = new char[strlen(s.numeMagazin) + 1];
	strcpy_s(this->numeMagazin, strlen(s.numeMagazin) + 1, s.numeMagazin);
}
Shopping::~Shopping() {
}
Shopping::Shopping(string linie, string fileName) :Comanda(linie, fileName) {

	vector<string> s = Comanda::readLineFromFile(linie, fileName);
	string tok4, tok5;
	tok4 = s[s.size() - 2];
	tok5 = s[s.size() - 1];
	vector<string> lista;
	string pars;
	stringstream iss(tok4);
	while (getline(iss, pars, ' ')) {

		lista.push_back(pars);
	}
	this->listaCumparaturi = lista;
	this->numeMagazin = new char[tok5.length() + 1];
	strcpy_s(this->numeMagazin, tok5.length() + 1, tok5.c_str());
}
string Shopping::toStringCSV() {

	string outstring;
	outstring = Comanda::toStringCSV();
	vector<string>lista = this->listaCumparaturi;
	char* array = this->numeMagazin;
	std::string numeMagazinS(array);
	outstring += ",";
	for (unsigned int i = 0; i < lista.size(); i++) {

		outstring += lista[i];
		if (i < lista.size() - 1) {

			outstring += " ";
		}
	}
	outstring += ",";
	outstring += numeMagazinS;
	outstring += " ";

	return outstring;
}
string Shopping::toStringHTML() {

	string outstring;
	outstring = Comanda::toStringHTML();
	vector<string>lista = this->listaCumparaturi;
	char* array = this->numeMagazin;
	std::string numeMagazinS(array);
	outstring += "/";
	for (unsigned int i = 0; i < lista.size(); i++) {

		outstring += lista[i];
		if (i < lista.size() - 1) {

			outstring += " ";
		}
	}
	outstring += ",";
	outstring += numeMagazinS;
	outstring += " ";

	return outstring;
}

vector<string>Shopping::getListaCumparaturi() {

	return listaCumparaturi;
}
void Shopping::setListaCumparaturi(vector<string> l) {

	listaCumparaturi = l;
}
char* Shopping::getNumeMagazin() {
	return numeMagazin;
}
void Shopping::setNumeMagazin(const char* numeMagazin) {
	if (this->numeMagazin) {
		delete[] this->numeMagazin;
	}
	this->numeMagazin = new char[strlen(numeMagazin) + 1];
	strcpy_s(this->numeMagazin, strlen(numeMagazin) + 1, numeMagazin);

}
Shopping& Shopping::operator=(const Shopping& s) {

	this->Comanda::operator=(s);
	this->setListaCumparaturi(s.listaCumparaturi);
	this->setNumeMagazin(s.numeMagazin);
	return *this;
}

bool Shopping::operator==(const Shopping& s) {

	return (Comanda::operator==(s) && (this->listaCumparaturi == s.listaCumparaturi) && (strcmp(this->numeMagazin, s.numeMagazin) == 0));
}
ostream& operator<<(ostream& os, const Shopping& s) {

	os << " Nume client: " << s.numeClient << endl;
	os << " Adresa client: " << s.adresaClient << endl;
	os << " Pret total: " << s.pretTotal << endl;
	os << " Lista cumparaturi: ";
	for (int i = 0; i < s.listaCumparaturi.size(); i++)
		os << s.listaCumparaturi[i] << " ";
	os << endl;
	os << " Nume magazin: " << s.numeMagazin;
	os << endl;
	return os;
}


