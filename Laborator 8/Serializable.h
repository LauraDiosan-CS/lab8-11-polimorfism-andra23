#pragma once
#include<iostream>
#include <memory>
using namespace std;
class Serializable {
public:
	static unique_ptr<Serializable> fromString(string linie, string fileName) {};
	virtual string toStringCSV() = 0;
	virtual string toStringHTML() = 0;
	~Serializable() {};

};

