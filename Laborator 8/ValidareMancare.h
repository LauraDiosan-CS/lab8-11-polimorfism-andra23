#pragma once
#include "Mancare.h"
#include "ValidareComanda.h"
class ValidareMancare : public ValidareComanda {
public:
	ValidareMancare() {}
	~ValidareMancare() {}
	void validareComanda(Comanda& m);
};
