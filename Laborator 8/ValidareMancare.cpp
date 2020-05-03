#include"ValidareMancare.h"
#include "MyException.h"
void ValidareMancare::validareComanda(Comanda& m) {

	Mancare& ma = dynamic_cast<Mancare&>(m);
	ValidareComanda::validareComanda(m);
	if (ma.getListaPreparate().size() < 1) {

		throw MyException("Lista preparate trebuie sa contina cel putin un produs.");
	}

}
