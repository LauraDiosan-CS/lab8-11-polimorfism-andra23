#include "ValidareShopping.h"
#include "MyException.h"
void ValidareShopping::validareComanda( Comanda &s) {

	Shopping& sa = dynamic_cast<Shopping&>(s);
	ValidareComanda::validareComanda(s); 
	if (sa.getListaCumparaturi().size() < 1) {

		throw MyException("Lista cumparaturi trebuie sa contina cel putin un produs.");
	}
}