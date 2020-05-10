// Laborator 8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "TesteEntitati.h"
#include "TesteRepo.h"
#include "RepoFile.h"
#include "Mancare.h"
#include "Shopping.h"
#include "Service.h"
#include "UI.h"
#include "TesteValidare.h"
#include "ValidareComanda.h"
#include "ValidareMancare.h"
#include "ValidareShopping.h"
#include "TesteFunctionalitati.h"
using namespace std;


int main()
{
	testComanda();
	testMancare();
	testShopping();
	addElemComanda();
	deleteElemComanda();
	updateElemComanda();
	getAllComanda();
	addElemMancare();
	deleteElemMancare();
	updateElemMancare();
	getAllMancare();
	addElemShopping();
	deleteElemShopping();
	updateElemShopping();
	getAllShopping();
	searchByName();
	//loginTest();

	ValidareMancare vm;
	ValidareShopping vs;
	RepoFile<Comanda&> r;
	Service<Comanda&> s(r,vm,vs);
	UI u(s);
	u.showUI();


}

