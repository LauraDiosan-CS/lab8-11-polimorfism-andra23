#include "RepoFile.h"
#include "RepoCSV.h"
#include "RepoHTML.h"
#include "Comanda.h"
#include "Shopping.h"
#include "Mancare.h"
#include "Service.h"
#include<assert.h>

void addElemComanda() {

	RepoCSV<Comanda&> r("TesteCSV.CSV");
	assert(r.getSize() == 0);
	Comanda* c= new Comanda("Anca", "Strada Dorobantilor Nr.23", 450);
	r.addElem(*c);
	r.loadFromFile("TesteCSV.csv");
	assert(r.getSize() == 1);
	r.clearFile("TesteCSV.csv");
}
void deleteElemComanda() {

	RepoHTML<Comanda&> r("TesteHTML.html");
	// TEST FISIER HTML
	assert(r.getSize() == 0);
	Comanda* c=new Comanda("Anca", "Strada Dorobantilor Nr.23", 450);
	r.addElem(*c);
	assert(r.getSize() == 1);
	r.delElem(0);
	r.loadFromFile("TesteHTML.html");
	assert(r.getSize() == 0);
	r.clearFile("TesteHMTL.html");
}
void updateElemComanda() {

	RepoHTML<Comanda&> r("TesteHTML.html");
	assert(r.getSize() == 0);
	Comanda* c=new Comanda("Anca", "Strada Dorobantilor Nr.23", 450);
	r.addElem(*c);
	assert(r.getSize() == 1);
	Comanda *c1=new Comanda("Mara", "Strada Dorobantilor Nr.23", 400);
	r.updateElem(0, *c1);
	r.loadFromFile("TesteHtml.html");
	map<int, Comanda&> elemente;
	elemente = r.getAll();
	map<int, Comanda&> ::iterator itr = elemente.find(0);
	assert(strcmp((itr->second).getNumeClient(), "Mara") == 0);
	r.clearFile("TesteHTML.html");
	elemente.clear();
}
void getAllComanda() {
	RepoCSV<Comanda&> r("TesteCSV.csv");
	assert(r.getSize() == 0);
	Comanda* c=new Comanda("Anca", "Strada Dorobantilor Nr.23", 450);
	r.addElem(*c);
	Comanda* c1=new Comanda("Ionut", "Strada Pacurari Nr.12", 33);
	r.addElem(*c1);
	r.loadFromFile("TesteCSV.csv");
	map<int, Comanda&> elemente;
	elemente = r.getAll();
	assert(r.getSize() == 2);
	assert(elemente.find(0)->second == *c && (elemente.find(1)->second) == *c1);
	r.clearFile("TesteCSV.csv");
	elemente.clear();
}
void addElemMancare() {

	RepoCSV<Comanda&> r("TesteCSV.csv");
	assert(r.getSize() == 0);
	vector<string> lista;
	lista.push_back("Portocale");
	lista.push_back("Paine");
	lista.push_back("Biscuiti");
	Mancare* m=new Mancare("Anca", "Strada Dorobantilor Nr.23", 450.00, lista);
	r.addElem(*m);
	r.loadFromFile("TesteCSV.csv");
	assert(r.getSize() == 1);
	r.clearFile("TesteCSV.csv");
	lista.clear();

}
void deleteElemMancare() {

	RepoHTML<Comanda&> r("TesteHTML.html");
	assert(r.getSize() == 0);
	vector<string> lista;
	lista.push_back("Portocale");
	lista.push_back("Paine");
	lista.push_back("Biscuiti");
	Mancare* m=new Mancare("Anca", "Strada Dorobantilor Nr.23", 450, lista);
	r.addElem(*m);
	r.loadFromFile("TesteHTML.html");
	assert(r.getSize() == 1);
	r.delElem(0);
	r.loadFromFile("TesteHTML.html");
	assert(r.getSize() == 0);
	r.clearFile("TesteHTML.html");
	lista.clear();
}
void updateElemMancare() {
	RepoHTML<Comanda&> r("TesteHTML.html");
	assert(r.getSize() == 0);
	vector<string> lista;
	lista.push_back("Portocale");
	lista.push_back("Paine");
	lista.push_back("Biscuiti");
	Mancare* m=new Mancare("Anca", "Strada Dorobantilor Nr.23", 45, lista);
	r.addElem(*m);
	r.loadFromFile("TesteHTML.html");
	assert(r.getSize() == 1);
	vector<string>lista1;
	lista1.push_back("Mere");
	lista1.push_back("Cicolata");
	Mancare* m1=new Mancare("Mara", "Strada Pacurari", 23, lista1);
	r.updateElem(0, *m1);
	r.loadFromFile("TesteHTML.html");
	map<int,Comanda&> elemente;
	elemente = r.getAll();
	Mancare& ma = dynamic_cast<Mancare&>(elemente.find(0)->second); // cast teste
	assert(strcmp(ma.getNumeClient(), "Mara") == 0);
	assert(ma.getListaPreparate() == lista1);
	r.clearFile("TesteHTML.html");
	lista.clear();
	lista1.clear();
	elemente.clear();
}
void getAllMancare() {

	RepoCSV<Comanda&> r("TesteCSV.csv");
	r.loadFromFile("TesteCSV.csv");
	assert(r.getSize() == 0);
	vector<string> lista;
	lista.push_back("Portocale");
	lista.push_back("Paine");
	lista.push_back("Biscuiti");
	Mancare* m=new Mancare("Anca", "Strada Dorobantilor Nr.23", 450, lista);
	r.addElem(*m);
	vector<string>lista1;
	lista1.push_back("Mere");
	lista1.push_back("Cicolata");
	Mancare*m1=new Mancare("Ionut", "Strada Pacurari Nr.12", 33, lista1);
	r.addElem(*m1);
	r.loadFromFile("TesteCSV.csv");
	map<int,Comanda&> elemente;
	elemente = r.getAll();
	assert(r.getSize() == 2);
	assert(elemente.find(0)->second == *m && elemente.find(1)->second == *m1);
	r.clearFile("TesteCSV.csv");
	lista.clear();
	lista1.clear();
	elemente.clear();
}
void addElemShopping() {

	RepoCSV<Comanda&> r("TesteCSV.csv");
	assert(r.getSize() == 0);
	vector<string> lista;
	lista.push_back("Portocale");
	lista.push_back("Servetele");
	lista.push_back("Caiete");
	Shopping* s=new Shopping("Anca", "Strada Dorobantilor Nr.23", 450, lista, "CoraM");
	r.addElem(*s);
	r.loadFromFile("TesteCSV.csv");
	assert(r.getSize() == 1);
	r.clearFile("TesteCSV.csv");
	lista.clear();
}
void deleteElemShopping() {

	RepoCSV<Comanda&> r("TesteCSV.csv");
	assert(r.getSize() == 0);
	vector<string> lista;
	lista.push_back("Portocale");
	lista.push_back("Servetele");
	lista.push_back("Caiete");
	Shopping*s=new Shopping("Anca", "Strada Dorobantilor Nr.23", 450, lista, "CoraM");
	r.addElem(*s);
	assert(r.getSize() == 1);
	r.delElem(0);
	assert(r.getSize() == 0);
	r.clearFile("TesteCSV.csv");
	lista.clear();
}
void updateElemShopping() {

	RepoCSV<Comanda&> r("TesteCSV.csv");
	assert(r.getSize() == 0);
	vector<string> lista;
	lista.push_back("Portocale");
	lista.push_back("Servetele");
	lista.push_back("Caiete");
	Shopping*s=new Shopping("Anca", "Strada Dorobantilor Nr.23", 45, lista, "CoraM");
	r.addElem(*s);
	assert(r.getSize() == 1);
	Shopping*s1=new Shopping("Ionut", "Strada Pacurari", 33, lista, "CoraM");
	r.updateElem(0, *s1);
	r.loadFromFile("TesteCSV.csv");
	map<int, Comanda&> elem;
	elem = r.getAll();
	assert(strcmp(elem.find(0)->second.getNumeClient(), "Ionut") == 0 && elem.find(0)->second.getPretTotal() == 33);
	r.clearFile("TesteCSV.csv");
	lista.clear();
	elem.clear();
}

void getAllShopping() {

	RepoCSV<Comanda&> r("TesteCSV.csv");
	assert(r.getSize() == 0);
	vector<string> lista;
	lista.push_back("Portocale");
	lista.push_back("Paine");
	lista.push_back("Biscuiti");
	Shopping*s=new Shopping("Anca", "Strada Dorobantilor Nr.23", 45, lista, "Lidl");
	r.addElem(*s);
	vector<string>lista1;
	lista1.push_back("Mere");
	lista1.push_back("Cicolata");
	Shopping*s1=new Shopping("Ionut", "Strada Pacurari Nr.12", 33, lista1, "Iulius");
	r.addElem(*s1);
	r.loadFromFile("TesteCSV.csv");
	map<int,Comanda&> elemente;
	elemente = r.getAll();
	assert(r.getSize() == 2);
	r.clearFile("TesteCSV.csv");
	lista.clear();
	lista1.clear();
	elemente.clear();
}
