#pragma once
#include "Repo.h"
#include<iostream>
#include<fstream>
#include<string.h>
#include<vector>
#include<sstream>
using namespace std;
// DERIVED CLASS
template <class T>
class RepoFile : public Repo<T> {
protected:
	const char* fis;
public:
	RepoFile();
	~RepoFile();
	RepoFile(const char*);
	virtual void addElem(T);
	virtual int delElem(int);
	virtual int updateElem(int i, T);
	virtual void loadFromFile(const char* fileName);
	virtual void saveToFile();
	void clearFile(const char*);
};
template<class T>
RepoFile<T>::RepoFile() {

};
template<class T>
RepoFile<T>::~RepoFile() {

};
template <class T>
RepoFile<T>::RepoFile(const char* fis) {

	loadFromFile(fis);
}
template<class T>
void RepoFile<T>::addElem(T a) {

	Repo<T>::addElem(a);
	saveToFile();
}
template <class T>
int RepoFile<T>::delElem(int i) {
	int bol;
	bol = Repo<T>::delElem(i);
	saveToFile();
	return bol;

}
template<class T>
int RepoFile<T>::updateElem(int i, T a) {
	int bol;
	bol = Repo<T>::updateElem(i, a);
	saveToFile();
	return bol;
}
template<class T>
void RepoFile<T>::loadFromFile(const char* fileName) {
	Repo<T>::clearMap();
	fis = fileName;
	//fis = new char[strlen(fileName) + 1];
	//strcpy_s(fis, strlen(fileName) + 1, fileName);
	string linie;
	ifstream f(fileName);
	while (getline(f, linie)) {
		if (!linie.empty()) {
			T e(linie, fis);
			Repo<T>::addElem(e);
		}
		else break;

	}
	f.close();
}
template<class T>
void RepoFile<T>::saveToFile() {
	
    ofstream f(fis);
	map<int, T> elem;
	elem = Repo<T>::getAll();
	for (auto i = elem.begin(); i != elem.end(); i++) {
		f <<i->second<< "\n";
	}
	f.close();

}

template<class T>
void RepoFile<T>::clearFile(const char* fileName) {

	std::ifstream File;
	std::string filepath = fileName;
	File.open(filepath.c_str(), std::ifstream::out | std::ifstream::trunc);
	if (!File.is_open() || File.fail()) {

		File.close();
		printf("\nError : failed to erase file content !");
	}
	File.close();
}




