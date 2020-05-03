#include "RepoFile.h"
#include "RepoCSV.h"
#include "RepoHTML.h"
#include "Comanda.h"
#include "Shopping.h"
#include "Mancare.h"
#include "Service.h"
#include<assert.h>

void addElemComanda() {

	RepoCSV<Comanda> r("TesteCSV.CSV");
	assert(r.getSize() == 0);
	Comanda c("Anca", "Strada Dorobantilor Nr.23", 450);
	r.addElem(c);
	r.loadFromFile("TesteCSV.csv");
	assert(r.getSize() == 1);
	r.clearFile("TesteCSV.csv");
}

void deleteElemComanda() {

	RepoHTML<Comanda> r("TesteHTML.html");
	// TEST FISIER HTML
	assert(r.getSize() == 0);
	Comanda c("Anca", "Strada Dorobantilor Nr.23", 450);
	r.addElem(c);
	assert(r.getSize() == 1);
	r.delElem(0);
	r.loadFromFile("TesteHTML.html");
	assert(r.getSize() == 0);
	r.clearFile("TesteHMTL.html");
}
void updateElemComanda() {

	RepoHTML<Comanda> r("TesteHTML.html");
	assert(r.getSize() == 0);
	Comanda c("Anca", "Strada Dorobantilor Nr.23", 450);
	r.addElem(c);
	assert(r.getSize() == 1);
	Comanda c1("Mara", "Strada Dorobantilor Nr.23", 400);
	r.updateElem(0, c1);
	r.loadFromFile("TesteHtml.html");
	map<int, Comanda> elemente;
	elemente = r.getAll();
	map<int, Comanda> ::iterator itr = elemente.find(0);
	assert(strcmp((itr->second).getNumeClient(), "Mara") == 0);
	r.clearFile("TesteHTML.html");
	elemente.clear();
}
void getAllComanda() {
	RepoCSV<Comanda> r("TesteCSV.csv");
	assert(r.getSize() == 0);
	Comanda c("Anca", "Strada Dorobantilor Nr.23", 450);
	r.addElem(c);
	Comanda c1("Ionut", "Strada Pacurari Nr.12", 33);
	r.addElem(c1);
	r.loadFromFile("TesteCSV.csv");
	map<int, Comanda> elemente;
	elemente = r.getAll();
	assert(r.getSize() == 2);
	assert(elemente[0] == c && elemente[1] == c1);
	r.clearFile("TesteCSV.csv");
	elemente.clear();
}
void addElemMancare() {
	RepoCSV<Mancare> r("TesteCSV.csv");
	assert(r.getSize() == 0);
	vector<string> lista;
	lista.push_back("Portocale");
	lista.push_back("Paine");
	lista.push_back("Biscuiti");
	Mancare m("Anca", "Strada Dorobantilor Nr.23", 450.00, lista);
	r.addElem(m);
	r.loadFromFile("TesteCSV.csv");
	assert(r.getSize() == 1);
	r.clearFile("TesteCSV.csv");
	lista.clear();

}
void deleteElemMancare() {

	RepoHTML<Mancare> r("TesteHTML.html");
	assert(r.getSize() == 0);
	vector<string> lista;
	lista.push_back("Portocale");
	lista.push_back("Paine");
	lista.push_back("Biscuiti");
	Mancare m("Anca", "Strada Dorobantilor Nr.23", 450, lista);
	r.addElem(m);
	r.loadFromFile("TesteHTML.html");
	assert(r.getSize() == 1);
	r.delElem(0);
	r.loadFromFile("TesteHTML.html");
	assert(r.getSize() == 0);
	r.clearFile("TesteHTML.html");
	lista.clear();

}
void updateElemMancare() {
	RepoHTML<Mancare> r("TesteHTML.html");
	assert(r.getSize() == 0);
	vector<string> lista;
	lista.push_back("Portocale");
	lista.push_back("Paine");
	lista.push_back("Biscuiti");
	Mancare m("Anca", "Strada Dorobantilor Nr.23", 45, lista);
	r.addElem(m);
	r.loadFromFile("TesteHTML.html");
	assert(r.getSize() == 1);
	vector<string>lista1;
	lista1.push_back("Mere");
	lista1.push_back("Cicolata");
	Mancare m1("Mara", "Strada Pacurari", 23, lista1);
	r.updateElem(0, m1);
	r.loadFromFile("TesteHTML.html");
	map<int, Mancare> elemente;
	elemente = r.getAll();
	assert(strcmp(elemente[0].getNumeClient(), "Mara") == 0);
	r.clearFile("TesteHTML.html");
	lista.clear();
	lista1.clear();
	elemente.clear();
}
void getAllMancare() {

	RepoCSV<Mancare> r("TesteCSV.csv");
	r.loadFromFile("TesteCSV.csv");
	assert(r.getSize() == 0);
	vector<string> lista;
	lista.push_back("Portocale");
	lista.push_back("Paine");
	lista.push_back("Biscuiti");
	Mancare m("Anca", "Strada Dorobantilor Nr.23", 450, lista);
	r.addElem(m);
	vector<string>lista1;
	lista1.push_back("Mere");
	lista1.push_back("Cicolata");
	Mancare m1("Ionut", "Strada Pacurari Nr.12", 33, lista1);
	r.addElem(m1);
	r.loadFromFile("TesteCSV.csv");
	map<int, Mancare> elemente;
	elemente = r.getAll();
	assert(r.getSize() == 2);
	assert(elemente[0] == m && elemente[1] == m1);
	r.clearFile("TesteCSV.csv");
	lista.clear();
	lista1.clear();
	elemente.clear();
}
void addElemShopping() {

	RepoCSV<Shopping> r("TesteCSV.csv");
	assert(r.getSize() == 0);
	vector<string> lista;
	lista.push_back("Portocale");
	lista.push_back("Servetele");
	lista.push_back("Caiete");
	Shopping s("Anca", "Strada Dorobantilor Nr.23", 450, lista, "CoraM");
	r.addElem(s);
	r.loadFromFile("TesteCSV.csv");
	assert(r.getSize() == 1);
	r.clearFile("TesteCSV.csv");
	lista.clear();
}
void deleteElemShopping() {

	RepoCSV<Shopping> r("TesteCSV.csv");
	assert(r.getSize() == 0);
	vector<string> lista;
	lista.push_back("Portocale");
	lista.push_back("Servetele");
	lista.push_back("Caiete");
	Shopping s("Anca", "Strada Dorobantilor Nr.23", 450, lista, "CoraM");
	r.addElem(s);
	assert(r.getSize() == 1);
	r.delElem(0);
	assert(r.getSize() == 0);
	r.clearFile("TesteCSV.csv");
	lista.clear();
}
void updateElemShopping() {

	RepoCSV<Shopping> r("TesteCSV.csv");
	assert(r.getSize() == 0);
	vector<string> lista;
	lista.push_back("Portocale");
	lista.push_back("Servetele");
	lista.push_back("Caiete");
	Shopping s("Anca", "Strada Dorobantilor Nr.23", 45, lista, "CoraM");
	r.addElem(s);
	assert(r.getSize() == 1);
	Shopping s1("Ionut", "Strada Pacurari", 33, lista, "CoraM");
	r.updateElem(0, s1);
	r.loadFromFile("TesteCSV.csv");
	map<int, Shopping> elem;
	elem = r.getAll();
	assert(strcmp(elem[0].getNumeClient(), "Ionut") == 0 && elem[0].getPretTotal() == 33);
	r.clearFile("TesteCSV.csv");
	lista.clear();
	elem.clear();
}
void getAllShopping() {

	RepoCSV<Shopping> r("TesteCSV.csv");
	assert(r.getSize() == 0);
	vector<string> lista;
	lista.push_back("Portocale");
	lista.push_back("Paine");
	lista.push_back("Biscuiti");
	Shopping s("Anca", "Strada Dorobantilor Nr.23", 45, lista, "Lidl");
	r.addElem(s);
	vector<string>lista1;
	lista1.push_back("Mere");
	lista1.push_back("Cicolata");
	Shopping s1("Ionut", "Strada Pacurari Nr.12", 33, lista1, "Iulius");
	r.addElem(s1);
	r.loadFromFile("TesteCSV.csv");
	map<int, Shopping> elemente;
	elemente = r.getAll();
	assert(r.getSize() == 2);
	r.clearFile("TesteCSV.csv");
	lista.clear();
	lista1.clear();
	elemente.clear();
}
