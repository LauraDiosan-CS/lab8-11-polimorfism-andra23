#include "assert.h"
#include "TesteValidare.h"
#include "RepoFile.h"
#include "Mancare.h"
#include "Shopping.h"
#include "ValidareComanda.h"
#include "ValidareMancare.h"
#include "ValidareShopping.h"
#include "Service.h"
#include "RepoHTML.h"
#include "RepoCSV.h"
#include "MyException.h"
void testValidareComanda() {
	RepoHTML<Mancare> r1("Teste.html");
	RepoHTML<Shopping> r2("Teste.html");
	ValidareMancare v;
	ValidareShopping sv;
	Service<Mancare, Shopping> s(r1, r2, v, sv);
	assert(s.getSize1() == 0);
	assert(s.getSize2() == 0);
	vector<string> lista;
	lista.push_back("Portocale");
	lista.push_back("Paine");
	lista.push_back("Biscuiti");
	Mancare m1("Anca", "Strada Dorobantilor Nr.23", -9, lista);
	bool exceptionThrown = false;
	try {
		s.addElem1(m1);
	}
	catch (MyException e)
	{
		exceptionThrown = true;
	}
	assert(exceptionThrown);
	vector<string> lista1;
	Mancare m2("Anca", "Strada Dorobantilor Nr.23", 23, lista1);
	bool exceptionThrown1 = false;
	try {
		s.addElem1(m2);
	}
	catch (MyException e)
	{
		exceptionThrown1 = true;
	}
	assert(exceptionThrown1);
	vector<string> lista2;
	lista.push_back("Portocale");
	lista.push_back("Servetele");
	lista.push_back("Caiete");
	Shopping sp("Anca", "Strada Dorobantilor Nr.23", -9, lista2, "CoraM");
	bool exceptionThrown2 = false;
	try {
		s.addElem2(sp);
	}
	catch (MyException e)
	{
		exceptionThrown2 = true;
	}
	assert(exceptionThrown2);
	vector<string> lista3;
	Shopping sp1("Anca", "Strada Dorobantilor Nr.23", 23, lista3, "CoraM");
	bool exceptionThrown3 = false;
	try {
		s.addElem2(sp1);
	}
	catch (MyException e)
	{
		exceptionThrown3 = true;
	}
	assert(exceptionThrown3);
}

