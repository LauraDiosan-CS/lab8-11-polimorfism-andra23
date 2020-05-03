#pragma once
#include "Service.h"
#include "Mancare.h"
#include "Shopping.h" 
class UI {
private:
	bool logIn = false;
	Service<Mancare, Shopping>* s;
	void addComandaMancare();
	void showComenziMancare();
	void deleteComandaMancare();
	void updateComandaMancare();
	void addComandaShopping();
	void showComenziShopping();
	void deleteComandaShopping();
	void updateComandaShopping();
	void choseFile();
	void login();
	void searchByName();
	void Logout();
	void PrintMenu();

public:
	UI(Service<Mancare, Shopping>& serv) :s(&serv) {  };
	~UI(){}
	void showUI();

};



