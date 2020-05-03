#pragma once
#pragma once
#include "RepoFile.h"
template <class T>
class RepoHTML :public RepoFile<T> {
private:
	const char* fis;
public:
	RepoHTML();
	~RepoHTML();
	RepoHTML(const char*);
	void loadFromFile(const char* fileName);
	void saveToFile();
};
template<class T>
RepoHTML<T>::RepoHTML() {

};
template<class T>
RepoHTML<T>::~RepoHTML() {

};
template <class T>
RepoHTML<T>::RepoHTML(const char* fisier) {

	fis = fisier;
	loadFromFile(fis);
}
template<class T>
void RepoHTML<T>::loadFromFile(const char* fileName) {

	Repo<T>::clearMap();
	fis = fileName;
	string linie;
	ifstream f(fileName);
	while (getline(f, linie, '<')) {
		if (linie.size() > 1) {
			T e(linie, fis);
			Repo<T>::addElem(e);
		}
		getline(f, linie, '>');
	}
	f.close();
}
template<class T>
void RepoHTML<T>::saveToFile() {

	ofstream f(fis);
	map<int, T> elem;
	elem = Repo<T>::getAll();
	T e;
	f << "<!DOCTYPE html>\n";
	f << "<html>\n";
	f << "<body>\n";
	for (auto i = elem.begin(); i != elem.end(); i++) {
		f << "<p>";
		e = i->second;
		f << e.toStringHTML();
		f << "</p>\n";
	}
	f << "</body>\n";
	f << "</html>\n";

	f.close();

}


