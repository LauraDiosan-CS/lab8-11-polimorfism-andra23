#include "UI.h"
#include "Service.h"
#include "Mancare.h"
#include "Shopping.h" 
#include"ValidareComanda.h"
#include "ValidareMancare.h"
#include "ValidareShopping.h"
#include "Login.h"
#include "RepoCSV.h"
#include "RepoHTML.h"
#include "MyException.h"
void UI::choseFile() {
	int o;
	cout << "******Alegeti tipul de fisier cu care doriti sa lucrati ( csv/html):****** \n";
	cout << "1.Fisier CSV. \n";
	cout << "2.Fisier HTML" << endl;
	cin >> o;
	if (o == 1) {
		cout << "Ati ales fisierul de tip CSV." << endl;
		RepoCSV<Mancare>& rm = *new RepoCSV<Mancare>("Mancare.csv");
		RepoCSV<Shopping>& rs = *new RepoCSV<Shopping>("Shopping.csv");
		ValidareMancare& vm = *new ValidareMancare;
		ValidareShopping& vs = *new ValidareShopping;
		Service<Mancare, Shopping>* s = new Service<Mancare, Shopping>(rm, rs, vm, vs);
		this->s = s;
	}
	else if (o == 2) {
		RepoHTML<Mancare>& rm = *new RepoHTML<Mancare>("Mancare.html");
		RepoHTML<Shopping>& rs = *new RepoHTML<Shopping>("Shopping.html");
		ValidareMancare& vm = *new ValidareMancare;
		ValidareShopping& vs = *new ValidareShopping;
		Service<Mancare, Shopping>* s = new Service<Mancare, Shopping>(rm, rs, vm, vs);
		this->s = s;
	}
	else if (o == 11) exit(0);
	else {
		cout << "Invalid choice!" << endl;
		choseFile();
	}
}
void UI::addComandaMancare() {

	char numeClient[10];
	string adresaClient;
	string cuv;
	float pretTotal;
	vector<string> listaPreparate = { };
	int n;
	cout << "Nume Client: "; cin >> numeClient;
	cout << "Adresa Client: "; std::getline(std::cin >> std::ws, adresaClient);
	cout << "Pret Total: "; cin >> pretTotal;
	cout << "Lista Preparate \n";
	cout << "Numar preparate: "; cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Preparat" << " " << i << ":";
		cin >> cuv;
		listaPreparate.push_back(cuv);
	}

	Mancare m(numeClient, adresaClient, pretTotal, listaPreparate);
	s->addElem1(m);

}
void UI::showComenziMancare() {

	map<int, Mancare> elem;
	elem = s->showElem1();
	for (auto i = elem.begin(); i != elem.end(); i++) {
		cout << "Comanda de tip Mancare" << " " << (i->first) << "\n";
		cout << " " << endl;
		cout << (i->second) << endl;
		cout << "-------------------------------" << endl;
	}
}
void UI::addComandaShopping() {

	char numeClient[10];
	string adresaClient;
	string cuv;
	float pretTotal;
	vector<string> listaCumparaturi;
	char numeMagazin[10];
	int n;
	cout << "Nume Client: "; cin >> numeClient;
	cout << "Adresa Client: "; std::getline(std::cin >> std::ws, adresaClient);
	cout << "Pret Total: "; cin >> pretTotal;
	cout << "Lista cumparaturi \n";
	cout << "Numar cumparaturi: "; cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Produsul " << " " << i << ":";
		cin >> cuv;
		listaCumparaturi.push_back(cuv);
	}
	cout << "Nume magazin: "; cin >> numeMagazin;
	Shopping sp(numeClient, adresaClient, pretTotal, listaCumparaturi, numeMagazin);
	s->addElem2(sp);
}
void UI::showComenziShopping() {
	map<int, Shopping> elem;
	elem = s->showElem2();
	for (auto i = elem.begin(); i != elem.end(); i++) {
		cout << "Comanda de tip Shopping" << " " << (i->first) << "\n";
		cout << " " << endl;
		cout << (i->second) << endl;
		cout << "-------------------------------" << endl;
	}
}
void UI::deleteComandaMancare() {
	int pos;
	cout << "Dati pozitia comenzii pe care doriti sa o stergeti: "; cin >> pos;
	try {
		s->delElem1(pos);
		cout << "Elementul a fost sters cu succes.";
	} 
	catch (MyException& e) { cout << "An exception occurred." << "->"; cout << e.getMessage(); }

}
void UI::updateComandaMancare() {
	int pos;
	char numeClient[10];
	string adresaClient;
	string cuv;
	float pretTotal;
	int n;
	vector<string> listaPreparate;
	cout << "Dati pozitia comenzii pe care doriti sa o modificati: "; cin >> pos;
	cout << "Nume Client: "; cin >> numeClient;
	cout << "Adresa Client: "; std::getline(std::cin >> std::ws, adresaClient);
	cout << "Pret Total: "; cin >> pretTotal;
	cout << "Lista Preparate \n";
	cout << "Numar preparate: "; cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Preparat" << " " << i << ":";
		cin >> cuv;
		listaPreparate.push_back(cuv);
	}
	Mancare m(numeClient, adresaClient, pretTotal, listaPreparate);
	try {
		s->updateElem1(pos,m);
		cout << "Elementul a fost modificat cu succes.";
	}
	catch (MyException& e) { cout << "An exception occurred." << "->"; cout << e.getMessage(); }
	
}
void UI::updateComandaShopping() {

	int pos;
	char numeClient[10];
	string adresaClient;
	string cuv;
	float pretTotal;
	vector<string> listaCumparaturi;
	char numeMagazin[10];
	int n;
	cout << "Dati pozitia comenzii pe care doriti sa o stergeti: " << endl; cin >> pos;
	cout << "Nume Client: "; cin >> numeClient;
	cout << "Adresa Client: "; std::getline(std::cin >> std::ws, adresaClient);
	cout << "Pret Total: "; cin >> pretTotal;
	cout << "Lista cumparaturi \n";
	cout << "Numar cumparaturi: "; cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Produsul " << " " << i << ":";
		cin >> cuv;
		listaCumparaturi.push_back(cuv);
	}
	cout << "Nume magazin: "; cin >> numeMagazin;
	Shopping sp(numeClient, adresaClient, pretTotal, listaCumparaturi, numeMagazin);
	try {
		s->updateElem2(pos, sp);
		cout << "Elementul a fost modificat cu succes.";
	}
	catch (MyException& e) { cout << "An exception occurred." << "->"; cout << e.getMessage(); }

}
void UI::deleteComandaShopping() {
	int pos;
	cout << "Dati pozitia comenzii pe care doriti sa o stergeti: "; cin >> pos;
	try {
		s->delElem2(pos);
		cout << "Elementul a fost sters cu succes.";
	}
	catch (MyException& e) { cout << "An exception occurred." << "->"; cout << e.getMessage(); }

}
void UI::searchByName() {
	string numeClient;
	cout << "Nume client: "; std::getline(std::cin >> std::ws, numeClient);
	cout << "Comenzi de tip mancare:" << endl;
	map<int, Mancare> elem;
	elem = s->showT(numeClient);
	for (auto i = elem.begin(); i != elem.end(); i++) {
		cout << "Comanda" << " " << i->first << endl;
		cout << i->second << endl;
	}
	cout << "Comenzi de tip shopping:" << endl;
	map<int, Shopping> elem1;
	elem1 = s->showV(numeClient);
	for (auto i = elem1.begin(); i != elem1.end(); i++) {
		cout << "Comanda" << " " << i->first << endl;
		cout << i->second << endl;
	}

}
void UI::login() {
	LoginManager lo;
	//bool login = false;
	string username, password;
	while (!logIn) {
		cout << "**********Autentificare**********" << endl;
		cout << "Username: "; cin >> username;
		cout << "Password: "; cin >> password;
		logIn = lo.login(username, password);
	}
	cout << "Istoric comenzi: " << endl;
	cout << "Comenzi Mancare:" << endl;
	map<int, Mancare> elem;
	elem = s->showElem1();
	for (auto i = elem.begin(); i != elem.end(); i++) {
		cout << "Comanda" << " " << i->first << endl;
		cout << i->second << endl;
	}
	cout << "Comenzi Shopping: " << endl;
	map<int, Shopping> elem1;
	elem1 = s->showElem2();
	for (auto i = elem1.begin(); i != elem1.end(); i++) {

		cout << "Comanda" << " " << i->first << endl;
		cout << i->second << endl;

	}
}
void UI::Logout() {

	logIn = false;
}
void UI::showUI() {

	choseFile();
	login();
	PrintMenu();
}

void UI::PrintMenu()
{
	cout << endl;
	while (true) {
		cout << endl;
		std::cout << "\n";
		std::cout << "********** Main Menu **********" << std::endl;
		std::cout << "Alegeti o optiune: " << std::endl;
		std::cout << "(1): Adaugare comanda de tip mancare." << std::endl;
		std::cout << "(2): Stergere comanda de tip mancare." << std::endl;
		std::cout << "(3): Modificare comanda de tip mancare." << std::endl;
		std::cout << "(4): Adaugare comanda de tip shopping." << std::endl;
		std::cout << "(5): Stergere comanda de tip shopping." << std::endl;
		std::cout << "(6): Modificare comanda de tip shopping." << std::endl;
		std::cout << "(7): Afisare comenzi de tip mancare." << std::endl;
		std::cout << "(8): Afisare comenzi de tip shopping." << std::endl;
		std::cout << "(9): Cautare dupa nume client." << std::endl;
		std::cout << "(10): Logout." << std::endl;
		std::cout << "(11): Exit." << std::endl;
		int opt;
		cin >> opt;
		switch (opt) {
		case 1: {try { addComandaMancare(); }
			  catch (MyException& e) { cout << "An exception occurred." << "->"; cout << e.getMessage(); } break; }
		case 2: {deleteComandaMancare(); break; }
		case 3: {updateComandaMancare(); break; }
		case 4: { try { addComandaShopping(); }
			  catch (MyException& e) { cout << "An exception occurred." << "->"; cout << e.getMessage(); } break; }
		case 5: {deleteComandaShopping(); break; }
		case 6: {updateComandaShopping();  break; }
		case 7: { showComenziMancare(); break; }
		case 8: { showComenziShopping(); break; }
		case 9: { searchByName(); break; }
		case 10: {  Logout(); showUI(); break; }
		case 11: {  cout << "LA REVEDERE!" << endl; exit(0); }
		default: {cout << "OPTIUNEA NU EXISTA! VA RUGAM SELECTATI UNA DIN OPTIUNILE EXISTENTE:" << endl; }
		}
	}
}




