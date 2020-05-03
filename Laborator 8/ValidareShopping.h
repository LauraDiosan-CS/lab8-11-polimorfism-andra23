#pragma once
#include "Shopping.h"
#include "ValidareComanda.h"
class ValidareShopping :public ValidareComanda {
public:
	ValidareShopping() {}
	~ValidareShopping() {}
	void validareComanda(Comanda& s);
};

