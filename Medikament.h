#pragma once
#include <string>

using namespace std;

class Medikament
{
private:
	string name, konz;
	int menge;
	float preis;

public:
	Medikament(string name, string konzentration, int menge, float preis);
	//~Medikament();

	// getters
	string getName() { return name; }
	string getKonz() { return konz; }
	int getMenge() { return menge; }
	float getPreis() { return preis; }

	//setters
	void setName(string name) { this->name = name; }
	void setKonz(string konzentration) { this->konz = konzentration; }
	void setMenge(int menge) { this->menge = menge; }
	void setPreis(float preis) { this->preis = preis; }


};

