#pragma once
#include "Repo.h"
#include "RepoFile.h"
#include "ValidareComanda.h"
#include<iostream>
#include "Service.h"
#include<string>
#include "MyException.h"
#include "Serializable.h"
using namespace std;
template <class T>
class Service {
private:
	Repo<Comanda&>& r;
	ValidareComanda& v1;
	ValidareComanda& v2;
public:
	Service(Repo<Comanda&>& repo, ValidareComanda& valid1, ValidareComanda& valid2) :r(repo), v1(valid1), v2(valid2) { r = repo; v1 = valid1; v2 = valid2; };
	~Service();
	void addElem(T t);
	int delElem(int);
	int updateElem(int, T);
	int getSize();
	Comanda& find(int i);
	map<int,Comanda&> showElem();
	map<int,Comanda&> show(string);
	string getType(T);
};
template<class T> Service<T>::~Service() {

}
template<class T> void Service<T>::addElem(T t) {
	
	if (getType(t).compare(typeid(Mancare).name()) == 0) {

		v1.validareComanda(t);
	}
	else {
		v2.validareComanda(t);
	}
	
	r.addElem(t);
	
	
}
template<class T> int Service<T>::delElem(int i)
{
	if (r.delElem(i) == -1)
		throw MyException("Acest element nu exista.");
	return 0;

}
template<class T> int Service<T>::updateElem(int i, T t) {

	if (r.updateElem(i, t) == -1)
		throw MyException("Acest element nu exista.");
	return 0;
}
template<class T> int Service<T>::getSize() {

	return r.getSize();
}
template<class T> map<int,Comanda&> Service<T>::showElem() {

	return r.getAll();
}
template<class T> Comanda& Service<T>::find(int i) {

	return r.find(i);
}
template<class T> map<int,Comanda&> Service<T>::show(string username) {

	int key = 0;
	map<int, Comanda&> elem;
	elem = r.getAll();
	map<int, Comanda&> rez;
	for (auto i = elem.begin(); i != elem.end(); i++) {
		string ch_username = i->second.getNumeClient();
		if (username.compare(ch_username) == 0) {
			rez.insert(pair<int, Comanda&>(key++, i->second));

		}
	}
	return rez;
}
template<class T> string Service<T>::getType(T t) {

	return typeid(t).name();
}


