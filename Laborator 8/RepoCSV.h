#pragma once
#include "RepoFile.h"
template <class T>
class RepoCSV :public RepoFile<T> {
private:
	const char* fis;
public:
	RepoCSV();
	~RepoCSV();
	RepoCSV(const char*);
	void saveToFile();
};
template<class T>
RepoCSV<T>::RepoCSV() {

};
template<class T>
RepoCSV<T>::~RepoCSV() {

};
template <class T>
RepoCSV<T>::RepoCSV(const char* fisier) {
	fis = fisier;
	RepoFile<T>::loadFromFile(fis);
}

template<class T>
void RepoCSV<T>::saveToFile() {

	ofstream f(fis);
	map<int, T> elem;
	elem = Repo<T>::getAll();
	T e;
	for (auto i = elem.begin(); i != elem.end(); i++) {
		e = i->second;
		f << e.toStringCSV() << "\n";
	}

	f.close();

}

