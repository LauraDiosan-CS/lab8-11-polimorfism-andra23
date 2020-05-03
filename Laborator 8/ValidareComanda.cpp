#include "ValidareComanda.h"
#include "MyException.h"
void ValidareComanda::validareComanda(Comanda& c) {

	if (strlen(c.getNumeClient()) > 10 || strlen(c.getNumeClient()) <= 2) {

		throw MyException("Nume client nu se incadreaza in intervalul [2,10] caractere.");
	}

	if (c.getAdresaClient().length() > 25) {

		throw MyException("Adresa client depaseste 25 de caractere.");
	}
	if (c.getPretTotal() <= 0) {

		throw MyException("Pretul total trebuie sa fie strict pozitiv.");
	}

}

