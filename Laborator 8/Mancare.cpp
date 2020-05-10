#include"Mancare.h"
#include<sstream>
Mancare::Mancare() {
	//this->listaPreparate = { "" };
}

Mancare::Mancare(const char* n, const string a, float p, vector<string> l) :Comanda(n, a, p) {

	for (auto i = l.begin(); i != l.end(); ++i)
		listaPreparate.push_back(*i);

}
Mancare::Mancare(const Mancare& m) : Comanda(m) {

	listaPreparate = m.listaPreparate;
}
Mancare::~Mancare() {
}
Mancare::Mancare(string linie, string fileName) :Comanda(linie, fileName) {

	vector<string> s = Comanda::readLineFromFile(linie, fileName);
	string tok4;
	tok4 = s[s.size() - 1];
	vector<string> lista;
	string pars;
	stringstream iss(tok4);
	while (getline(iss, pars, ' ')) {

		lista.push_back(pars);
	}
	this->listaPreparate = lista;
}
string Mancare::toStringCSV() {

	string outstring;

	outstring = Comanda::toStringCSV();
	vector<string>lista = this->listaPreparate;
	outstring += ",";
	for (unsigned int i = 0; i < lista.size(); i++)
	{
		outstring += lista[i];

		if (i < lista.size() - 1)
		{
			outstring += " ";
		}
	}
	return outstring;


}
string Mancare::toStringHTML() {

	string outstring;
	outstring = Comanda::toStringHTML();
	vector<string>lista = this->listaPreparate;
	outstring += "/";
	for (unsigned int i = 0; i < lista.size(); i++)
	{
		outstring += lista[i];
		if (i < lista.size() - 1)
		{
			outstring += " ";
		}
	}
	return outstring;
}

vector<string> Mancare::getListaPreparate() {

	return listaPreparate;
}

void Mancare::setListaPreparate(vector<string> l) {

	listaPreparate = l;

}

Mancare& Mancare::operator=(const Mancare& m) {

	this->Comanda::operator=(m);
	this->setListaPreparate(m.listaPreparate);
	return *this;
}

bool Mancare::operator==(const Mancare& m) {

	return (Comanda::operator==(m) && (this->listaPreparate == m.listaPreparate));
}
ostream& operator<<(ostream& os, const Mancare& m)
{
	os << " Nume client: " << m.numeClient << endl;
	os << " Adresa client: " << m.adresaClient << endl;
	os << " Pret total: " << m.pretTotal << endl;
	os << " Lista Preparate:";
	for (auto i = m.listaPreparate.begin(); i != m.listaPreparate.end(); ++i)
		os << *i << " ";
	os << endl;
	return os;
}



