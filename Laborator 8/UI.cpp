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
		RepoCSV<Comanda&>& r = *new RepoCSV<Comanda&>("Comenzi.csv");
		ValidareMancare& vm = *new ValidareMancare;
		ValidareShopping& vs = *new ValidareShopping;
		Service<Comanda&>* s = new Service<Comanda&>(r, vm, vs);
		this->s = s;
	}
	else if (o == 2) {

		RepoHTML<Comanda&>& r = *new RepoHTML<Comanda&>("Comenzi.html");
		ValidareMancare& vm = *new ValidareMancare;
		ValidareShopping& vs = *new ValidareShopping;
		Service<Comanda&>* s = new Service<Comanda&>(r, vm, vs);
		this->s = s;
	}
	else if (o == 8) exit(0);
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
	Mancare* m = new Mancare(numeClient, adresaClient, pretTotal, listaPreparate);
	s->addElem(*m);

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
	Shopping* sp = new Shopping(numeClient, adresaClient, pretTotal, listaCumparaturi, numeMagazin);
	s->addElem(*sp);
}
void UI::showComenzi() {

	map<int, Comanda&> elem;
	elem = s->showElem();
	for (auto i = elem.begin(); i != elem.end(); i++) {
		cout << "Comanda" << " " << (i->first) << "\n";
		cout << " " << endl;
		cout << (i->second).toStringCSV() << endl;
		cout << "-------------------------------" << endl;
	}
}

void UI::deleteComanda() {
	int pos;
	cout << "Dati pozitia comenzii pe care doriti sa o stergeti: "; cin >> pos;
	try {
		s->delElem(pos);
		cout << "Elementul a fost sters cu succes.";
	}
	catch (MyException& e) { cout << "An exception occurred." << "->"; cout << e.getMessage(); }

}

void UI::updateComanda() {

	int pos;
	char numeClient[10];
	string adresaClient;
	string cuv;
	float pretTotal;
	int n;
	vector<string> listaPreparate;
	cout << "Dati pozitia comenzii pe care doriti sa o modificati: "; cin >> pos;
	std::map<int, Comanda&>::iterator it;
	map<int, Comanda&> elem = s->showElem();
	it = elem.find(pos);
	dynamic_cast<Comanda&> (s->showElem().find(pos)->second); // covert to derived class 
	if (typeid(s->showElem().find(pos)->second) == typeid(Mancare)) {
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
		Mancare* m = new Mancare(numeClient, adresaClient, pretTotal, listaPreparate);
		try {
			s->updateElem(pos, *m);
			cout << "Elementul a fost modificat cu succes.";
		}
		catch (MyException& e) { cout << "An exception occurred." << "->"; cout << e.getMessage(); }

	}
	else {
		vector<string> listaCumparaturi;
		char numeMagazin[10];
		int k;
		cout << "Nume Client: "; cin >> numeClient;
		cout << "Adresa Client: "; std::getline(std::cin >> std::ws, adresaClient);
		cout << "Pret Total: "; cin >> pretTotal;
		cout << "Lista cumparaturi \n";
		cout << "Numar cumparaturi: "; cin >> k;
		for (int i = 0; i < k; i++) {
			cout << "Produsul " << " " << i << ":";
			cin >> cuv;
			listaCumparaturi.push_back(cuv);
		}
		cout << "Nume magazin: "; cin >> numeMagazin;
		Shopping* sp = new Shopping(numeClient, adresaClient, pretTotal, listaCumparaturi, numeMagazin);
		try {
			s->updateElem(pos, *sp);
			cout << "Elementul a fost modificat cu succes.";
		}
		catch (MyException& e) { cout << "An exception occurred." << "->"; cout << e.getMessage(); }
	}
}
void UI::searchByName() {

	string numeClient;
	cout << "Nume client: "; std::getline(std::cin >> std::ws, numeClient);
	cout << "Comenzi: " << endl;
	map<int, Comanda&> elem;
	elem = s->show(numeClient);
	for (auto i = elem.begin(); i != elem.end(); i++) {
		cout << "Comanda" << " " << i->first << endl;
		cout << (i->second).toStringCSV() << endl;
	}
}

void UI::login() {

	LoginManager lo;
	string username, password;
	while (!logIn) {
		cout << "**********Autentificare**********" << endl;
		cout << "Username: "; cin >> username;
		cout << "Password: "; cin >> password;
		logIn = lo.login(username, password);
	}
	showComenzi();
}
void UI::Logout() {

	logIn = false;
}
void UI::showUI() {

	choseFile();
	login();
	PrintMenu();
}
void UI::PrintMenu() {

	cout << endl;
	while (true) {
		cout << endl;
		std::cout << "\n";
		std::cout << "********** Main Menu **********" << std::endl;
		std::cout << "Alegeti o optiune: " << std::endl;
		std::cout << "(1): Adaugare comanda de tip mancare." << std::endl;
		std::cout << "(2): Adaugare comanda de tip shopping." << std::endl;
		std::cout << "(3): Stergere comanda." << std::endl;
		std::cout << "(4): Modificare comanda." << std::endl;
		std::cout << "(5): Cautare dupa nume client." << std::endl;
		std::cout << "(6): Afisare comenzi." << std::endl;
		std::cout << "(7): Logout." << std::endl;
		std::cout << "(8): Exit." << std::endl;
		int opt;
		cin >> opt;
		switch (opt) {
		case 1: {
			try { addComandaMancare(); }
			catch (MyException& e) { cout << "An exception occurred." << "->"; cout << e.getMessage(); } break; }
		case 2: {
			try { addComandaShopping(); }
			catch (MyException& e) { cout << "An exception occurred." << "->"; cout << e.getMessage(); } break; }
		case 3: {deleteComanda(); break;
		}
		case 4: {updateComanda(); break;
		}
		case 5: {searchByName(); break;
		}
		case 6: {showComenzi(); break; }
		case 7: {Logout(); showUI(); break; }
		case 8: {cout << "LA REVEDERE!" << endl; exit(0); }
		default: {cout << "OPTIUNEA NU EXISTA! VA RUGAM SELECTATI UNA DIN OPTIUNILE EXISTENTE:" << endl; }
		}
	}
}





