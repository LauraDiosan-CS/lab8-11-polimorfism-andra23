#pragma once
#include "Service.h"
#include "Mancare.h"
#include "Shopping.h" 
class UI {
private:
	bool logIn = false;
	Service<Comanda&>* s;
	void addComandaMancare();
	void deleteComanda();
	void updateComanda();
	void addComandaShopping();
	void showComenzi();
	void choseFile();
	void login();
	void searchByName();
	void Logout();
	void PrintMenu();
public:
	UI(Service<Comanda&>& serv) :s(&serv) {  };
	~UI(){}
	void showUI();

};



