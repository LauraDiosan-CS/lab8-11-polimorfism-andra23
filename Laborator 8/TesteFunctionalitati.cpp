#include "Service.h"
#include "RepoCSV.h"
#include <assert.h>
#include "ValidareComanda.h"
#include "ValidareMancare.h"
#include "ValidareShopping.h"
#include "Login.h"
void searchByName() {

	RepoCSV<Comanda&> r("Teste.CSV");
	ValidareMancare v1;
	ValidareShopping v2;
	Service<Comanda&> s(r, v1, v2);
	assert(s.getSize() == 0);
	vector<string>lista1;
	lista1.push_back("Mere");
	lista1.push_back("Cicolata");
	Mancare* m = new Mancare("Mara", "Strada Pacurari", 23, lista1);
	s.addElem(*m);
	vector<string> lista;
	lista.push_back("Portocale");
	lista.push_back("Servetele");
	lista.push_back("Caiete");
	Shopping* so = new Shopping("Elena", "Strada Napoca Nr.5", 43, lista, "CoraM");
	s.addElem(*so);
	vector<string> lista2;
	lista2.push_back("Portocale");
	lista2.push_back("Paine");
	lista2.push_back("Biscuiti");
	Mancare* m1 = new Mancare("Ionut", "Strada Pacurari nr.21", 65, lista2);
	s.addElem(*m1);
	map<int, Comanda&> res;
	res = s.show("Elena");
	assert(res.find(0)->second == *so);
	r.clearFile("Teste.CSV");
}
void loginTest() {

	LoginManager lo;
	bool lol = false;
	lol = lo.login("Ana", "adrH");
	assert(lol == true);
	lol = lo.login("Elena", "aafTb");
	assert(lol == false);
}
