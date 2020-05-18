#include"Avion.h"
Avion::Avion() {
	//cout << "const implicit";
	this->x = { '\0' };
	this->y = 0;
	this->orientareCoada = { '\0' };
}Avion::Avion(string x, int y, string orientareCoada) {
	//cout << "constructor with param" << endl;
	this->x = x;
	this->y = y;
	this->orientareCoada = orientareCoada;
}
Avion::Avion(const Avion& a) {
	//cout << "copy constructor" << endl;
	this->x = a.x;
	this->y = a.y;
	this->orientareCoada=a.orientareCoada;
}
Avion::~Avion() {
	//cout << "Destructor";
	this->x = { '\0' };
	this->y =0;
	this->orientareCoada = { '\0' };
}
string Avion:: getX() {

	return this->x;
}
int Avion::getY() {

	return this->y;
}
string Avion::getOrientareCoada() {

	return this->orientareCoada;
}
void Avion::setX(string x) {

	this->x = x;
}
void Avion::setY(int y) {
	this->y = y;
}
void Avion:: setOrientareCoada(string orientareCoada) {

	this->orientareCoada = orientareCoada;
}Avion& Avion::operator=(const Avion& a) {

	this->setX(a.x);
	this->setY(a.y);
	this->setOrientareCoada(a.orientareCoada);
	return *this;
}
bool Avion::operator==(const Avion& a) {

	return (this->x.compare(a.x) == 0) && (this->y == a.y) && (this->orientareCoada.compare(a.orientareCoada) == 0);
}
ostream& operator<<(ostream& os, const Avion& a) {

	os << "Coordonata X: " << a.x << "|" << " Coordonata Y: " << a.y << "|" << " Orientare coada:" << a.orientareCoada;
	return os;
}