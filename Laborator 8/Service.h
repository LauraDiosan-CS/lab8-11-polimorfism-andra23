#pragma once
#include "Repo.h"
#include "RepoFile.h"
#include "ValidareComanda.h"
#include<iostream>
#include "Service.h"
#include<string>
#include "MyException.h"
template <class T, class V>
class Service {
private:
	Repo<T>& r1;
	Repo<V>& r2;
	ValidareComanda& v1;
	ValidareComanda& v2;
public:
	Service(Repo<T>& repo1, Repo<V>& repo2, ValidareComanda& valid1, ValidareComanda& valid2):r1(repo1), r2(repo2), v1(valid1), v2(valid2){ r1 = repo1; r2 = repo2; v1 = valid1; v2 = valid2; };
	~Service();
	void addElem1(T t);
	void addElem2(V v);
	int delElem1(int);
	int delElem2(int);
	int updateElem1(int, T);
	int updateElem2(int, V);
	int getSize1();
	int getSize2();
	map<int, T> showElem1();
	map<int, V> showElem2();
	map<int, T> showT(string);
	map<int, V> showV(string);
};
template<class T, class V> Service<T, V>::~Service() {

}

template<class T, class V> void Service<T, V>::addElem1(T t) {

	v1.validareComanda(t);
	r1.addElem(t);
}
template<class T, class V> void Service<T, V>::addElem2(V v) {

	v2.validareComanda(v);
	r2.addElem(v);
}
template<class T, class V> int Service<T, V>::delElem1(int i)
{
	if (r1.delElem(i) == -1)
		throw MyException("Acest element nu exista.");
	return 0;

}
template<class T, class V> int Service<T, V>::delElem2(int i) {

	if (r2.delElem(i) == -1)
		throw MyException("Acest element nu exista.");
	return 0;
}

template<class T, class V> int Service<T, V>::updateElem1(int i, T t) {

	if (r1.updateElem(i,t) == -1)
		throw MyException("Acest element nu exista.");
	return 0;
}
template<class T, class V> int Service<T, V>::updateElem2(int i, V v) {

	if (r2.updateElem(i,v) == -1)
		throw MyException("Acest element nu exista.");
	return 0;
}

template<class T, class V> int Service<T, V>::getSize1() {

	return r1.getSize();
}
template<class T, class V> int Service<T, V>::getSize2() {

	return r2.getSize();
}
template<class T, class V> map<int, T> Service<T, V>::showElem1() {

	return r1.getAll();
}
template<class T, class V> map<int, V> Service<T, V>::showElem2() {

	return r2.getAll();
}
template<class T, class V> map<int, T> Service<T, V>::showT(string username) {

	int key = 0;
	map<int, T> elem;
	elem = r1.getAll();
	map<int, T> rez;
	for (auto i = elem.begin(); i != elem.end(); i++) {
		string ch_username = i->second.getNumeClient();
		if (username.compare(ch_username) == 0) {
			rez.insert(pair<int, T>(key++, i->second));

		}
	}
	return rez;
}
template<class T, class V> map<int, V> Service<T, V>::showV(string username) {

	int key = 0;
	map<int, V> elem;
	elem = r2.getAll();
	map<int, V> rez;
	for (auto i = elem.begin(); i != elem.end(); i++) {
		string ch_username = i->second.getNumeClient();
		if (username.compare(ch_username) == 0) {
			rez.insert(pair<int, V>(key++, i->second));

		}
	}
	return rez;
}


