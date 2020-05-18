#pragma once
#include "Avion.h"
#include<map>
#include<iostream>
using namespace std;
class Tabla {
private: 

	char tabla[10][10];
	map<char, int> m;
public:
	void addInMap() {

		m.insert(pair<char, int>('A', 1));
		m.insert(pair<char, int>('B', 2));
		m.insert(pair<char, int>('C', 3));
		m.insert(pair<char, int>('D', 4));
		m.insert(pair<char, int>('E', 5));
		m.insert(pair<char, int>('F', 6));
		m.insert(pair<char, int>('G', 7));
		m.insert(pair<char, int>('H', 8));
		m.insert(pair<char, int>('I', 9));
		m.insert(pair<char, int>('J', 10));
		
	}
	void addAvion(Avion a) {
		for(int i=1;i<=10;i++)
			for (int j = 1; j <= 10; j++) {

				tabla[m[a.getX()]][a.getY()] = "*";
			}
	}



};
