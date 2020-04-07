#include "Medikament.h"

using namespace std;

Medikament::Medikament(string name, string konzentration, int menge, float preis) {
	this->name = name;
	this->konz = konzentration;
	this->menge = menge;
	this->preis = preis;

}
