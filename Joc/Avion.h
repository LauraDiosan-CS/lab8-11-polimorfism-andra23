#pragma once
#include<string>
#include<iostream>
using namespace std;
class Avion {
private:
	string x;
	int y;
	string orientareCoada;
public:
	Avion();
	Avion(string x, int y, string orientareCoada);
	Avion(const Avion& a);
	~Avion();
	string getX();
	int getY();
	string getOrientareCoada();
	void setX(string x);
	void setY(int y);
	void setOrientareCoada(string orientareCoada);
	Avion& operator=(const Avion& a);
	bool operator==(const Avion&);
	friend ostream& operator<<(ostream& os, const Avion& c);
};

