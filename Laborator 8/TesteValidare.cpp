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
	RepoHTML<Comanda&> r("Teste.html");
	ValidareMancare v1;
	ValidareShopping v2;
	Service<Comanda&> s(r,v1, v2);
	assert(s.getSize() == 0);
	vector<string> lista;
	lista.push_back("Portocale");
	lista.push_back("Paine");
	lista.push_back("Biscuiti");
	Mancare* m1=new Mancare("Anca", "Strada Dorobantilor Nr.23", -9, lista);
	bool exceptionThrown = false;
	try {
		s.addElem(*m1);
	}
	catch (MyException e)
	{
		exceptionThrown = true;
	}
	assert(exceptionThrown);
	vector<string> lista1;
	Mancare*m2=new Mancare("Anca", "Strada Dorobantilor Nr.23", 23, lista1);
	bool exceptionThrown1 = false;
	try {
		s.addElem(*m2);
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
	Shopping*sp=new Shopping("Anca", "Strada Dorobantilor Nr.23", -9, lista2, "CoraM");
	bool exceptionThrown2 = false;
	try {
		s.addElem(*sp);
	}
	catch (MyException e)
	{
		exceptionThrown2 = true;
	}
	assert(exceptionThrown2);
	vector<string> lista3;
	Shopping*sp1=new Shopping("Anca", "Strada Dorobantilor Nr.23", 23, lista3, "CoraM");
	bool exceptionThrown3 = false;
	try {
		s.addElem(*sp1);
	}
	catch (MyException e)
	{
		exceptionThrown3 = true;
	}
	assert(exceptionThrown3);
}


