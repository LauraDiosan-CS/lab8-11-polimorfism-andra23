#include"assert.h"
#include<vector>
#include "TesteEntitati.h"
#include "Comanda.h"
#include "Mancare.h"
#include "Shopping.h"
#include<string>
void testComanda() {
	Comanda c("Anca", "Strada Pacurari Nr.12", 197);
	c.setNumeClient("Mara");
	assert(strcmp(c.getNumeClient(), "Mara") == 0);
	c.setAdresaClient("Strada Mihai Viteazul Nr.12");
	string adresa = "Strada Mihai Viteazul Nr.12";
	assert(c.getAdresaClient().compare(adresa) == 0);
	c.setPretTotal(200);
	assert(c.getPretTotal() == 200);
	Comanda c2 = c;
	Comanda c3;
	c3 = c2;
	assert(c3 == c2);

}
void testMancare() {
	vector<string> lista;
	lista.push_back("Salata");
	lista.push_back("Paine");
	Mancare m("Anca", "Strada Dorobantilor Nr.14", 22, lista);
	vector<string>lista1;
	lista1.push_back("Portocale");
	lista1.push_back("Paine");
	m.setNumeClient("Mara");
	assert(strcmp(m.getNumeClient(), "Mara") == 0);
	m.setListaPreparate(lista1);
	assert(m.getListaPreparate()[0].compare("Portocale") == 0 && m.getListaPreparate()[1].compare("Paine") == 0);
	Mancare m2 = m;
	Mancare m3;
	m3 = m2;
	assert(m3 == m2);

}
void testShopping() {
	vector<string> lista;
	lista.push_back("Paine");
	lista.push_back("Fata de masa");
	lista.push_back("Lumanare");
	Shopping s("Anca", "Strada Dorobantilor Nr.14", 218, lista, "Lidl");
	vector<string>lista1;
	lista1.push_back("Cana");
	lista1.push_back("Servetele");
	s.setNumeClient("Mara");
	assert(strcmp(s.getNumeClient(), "Mara") == 0);
	s.setListaCumparaturi(lista1);
	assert(s.getListaCumparaturi()[0].compare("Cana") == 0 && s.getListaCumparaturi()[1].compare("Servetele") == 0);
	s.setNumeMagazin("Iulius");
	assert(strcmp(s.getNumeMagazin(), "Iulius") == 0);



}