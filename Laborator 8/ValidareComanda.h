#pragma once
#include"Comanda.h"
#include "Mancare.h"
#include"Shopping.h"
class ValidareComanda
{
public:
	ValidareComanda() {}
	~ValidareComanda() {}
	virtual void validareComanda(Comanda& c);
};

