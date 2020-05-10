#pragma once
#include<map>
#include<iostream>
using namespace std;
template < class T>
class Repo {
protected:

	map<int, T> elem = {};
	int key = 0;
public:
	Repo<T>();
	virtual ~Repo<T>();
	virtual void addElem(T);
	virtual int delElem(int i);
	virtual int updateElem(int i, const T nou);
	int getSize();
	map<int, T> getAll();
	void clearMap();
    T find(int i);

};
template<class T>Repo<T>::Repo() {
}
template<class T>Repo<T>::~Repo() {
}
template<class T>void Repo<T>::addElem(T e) {

	elem.insert(pair<int, T>(key++, e));
	

}
template<class T>int Repo<T>::delElem(int i) {
	auto itr = elem.find(i);
	if (itr != elem.end()) {
		elem.erase(itr);
		return 0;
	}
	else
		return -1;

}

template< class T>int Repo<T>::updateElem(int i, const T nou) {

	
	if (i >= 0 && i < elem.size()) {
		delElem(i);
		elem.emplace(i, nou);
		return 0;
	}
	else
		return -1;
}

template<class T>int Repo<T>::getSize() {

	return elem.size();

}
template<class T>map<int, T> Repo<T>::getAll() {

	return elem;
}
template<class T>void Repo<T>::clearMap() {

	elem.clear();
	key = 0;


}
template<class T>T Repo<T>::find(int i)
{
	int poz = 0;
	for (auto itr = elem.begin(); itr != elem.end(); itr++) {
		if (poz == i) { return itr->second; }
		else { itr++; poz++; }
	}
	
	
}







