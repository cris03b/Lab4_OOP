#include "Controller.h"
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>
using namespace std;


void Repo::add_med(Medikament m) {
	//adauga un element in vectorul med
	//daca gaseste elementul care are aceeasi concentratie, ii schima doar cantitatea si pretul
	//cantitatea se adauga la cantitatea anterioara
	bool found_name = false;
	for (auto i = med.begin(); i != med.end(); ++i) {
		if (i->getName() == m.getName() && i->getKonz() == m.getKonz()) {
			found_name = true;
			int new_menge = m.getMenge() + i->getMenge();
			i->setMenge(new_menge);
			i->setPreis(m.getPreis());
			break;
		}		
	}
	//daca nu se gaseste elementul, sau daca concentratia este diferita, se adauga elementul in lista de medicamente
	if (found_name == false || med.empty()) {
		med.push_back(m);		
	}
}

vector<Medikament> Repo::show_med(string option, string details) {
	/* 
		option = categoria dupa care vor fi afisate medicamentele (Name, Konz, Menge si Preis)
	    details = caracteristica dupa care vor fi afisate med. din categoria aleasa 
	    show_v = vectorul in care vor fi puse elm gasite
	 */

	vector<Medikament> show_v;
	if (option == "Name") {
		for (auto i = med.begin(); i != med.end(); ++i) {
			// se parcurge vectorul, daca s-a gasit string-ul la un elm din vectorul cu med, se creeaza un med care se adauga la vectorul show_v
			if (i->getName() == details) {
				Medikament m1(i->getName(), i->getKonz(), i->getMenge(), i->getPreis());
				show_v.push_back(m1);
			}
		}
		return show_v;
	}

	else if (option == "Konzentration") {
		for (auto i = med.begin(); i != med.end(); ++i) {
			// analog
			if (i->getKonz() == details) {
				Medikament m1(i->getName(), i->getKonz(), i->getMenge(), i->getPreis());
				show_v.push_back(m1);
			}
		}
		return show_v;
	}

	else if (option == "Menge") {
		// daca optiunea aleasa este 'Menge', se va converti str details intr-un int, pt a putea fi comparat cu 'Menge' de la fiecare obiect din vector
		int nr;
		istringstream(details) >> nr;
		for (auto i = med.begin(); i != med.end(); ++i) {
			if (i->getMenge() == nr) {
				Medikament m1(i->getName(), i->getKonz(), i->getMenge(), i->getPreis());
				show_v.push_back(m1);
			}
		}
		return show_v;
	}

	else if (option == "Preis") {
		for (auto i = med.begin(); i != med.end(); ++i) {
			// convert string to float
			// daca details e doar string (fara numere) => price = 0
			float price = i->getPreis();
			stringstream ss;
			ss << details;
			ss >> price;
			if (i->getPreis() == price) {
				Medikament m1(i->getName(), i->getKonz(), i->getMenge(), i->getPreis());
				show_v.push_back(m1);
			}
		}
		return show_v;

	}
	else if (option == "" && details == ""){
		// sortare crescatoare lexicografica
		sort(med.begin(), med.end(), [](Medikament& lhs, Medikament& rhs) {return lhs.getName() < rhs.getName(); });
		return med;
	}
	
	else {
		// altfel => return vector cu toate elementele
		cout << "Es gibt nicht solche Eigenschaften..." << endl;
		return med;
	}
	
}

vector<Medikament> Repo::show_knapp(int x) {
	/*
		x = numarul de pastile (Menge) introdus de user
		show_v = vectorul in care vor fi puse elm gasite
	*/
	vector<Medikament> show_v;
	for (auto i = med.begin(); i != med.end(); ++i) {
		// daca se gaseste elm cu menge < x => se creeaza obiectul si se adauga la show_v
		if (i->getMenge() < x) {
			Medikament m1(i->getName(), i->getKonz(), i->getMenge(), i->getPreis());
			show_v.push_back(m1);
		}
 	}
	return show_v;
}

void Repo::delete_med(Medikament m) {
	//sterge un element din vecorul med (lista de medicamente)
	//cauta daca elementul pe care vrei sa il stergi exista si daca exista, 
	//se adauga toate celelalte elemente din vector intr-unul nou
	bool ok = false;
	vector<Medikament> vect;
	for (auto i = med.begin(); i != med.end(); ++i) {
		if (i->getName() != m.getName() || i->getKonz() != m.getKonz() || i->getMenge() != m.getMenge() || i->getPreis() != m.getPreis()) {
			Medikament m1(i->getName(), i->getKonz(), i->getMenge(), i->getPreis());
			vect.push_back(m1);
		}
		else {
			ok = true;
		}
	}
	if (ok == true) {
		med.clear();
		for (int i = 0; i < vect.size(); i++) {
			med.push_back(vect[i]);
		}
	}
	else {
		cout << "Es gibt kein Medikament mit dieser Beschreibung!" << endl;
	}
}

void Repo::edit_med(Medikament& m, string option) {
	//editeaza un medicament dupa criteriul ales (option)
	//cauta in vector medicamentul care trebuie editat si daca l-a gasit, ii modifica atributul in cel citit
	bool opt = false;
	for (auto i = med.begin(); i != med.end(); ++i) {
		if (i->getName() == m.getName() && i->getKonz() == m.getKonz() && i->getMenge() == m.getMenge() && i->getPreis() == m.getPreis()) {
			if (option == "Name") {
				string name;
				cout << "Sie wollen den Namen " << i->getName() << " verandern, mit dem Namen: ";
				cin >> name;
				i->setName(name);
				opt = true;
				break;
			}
			else if (option == "Menge") {
				int menge;
				cout << "Sie wollen die Menge " << i->getMenge() << " verandern, mit der Menge: ";
				cin >> menge;
				i->setMenge(menge);
				opt = true;
				break;
			}
			else if (option == "Konzentration") {
				string konz;
				cout << "Sie wollen die Konzentration " << i->getMenge() << " verandern, mit der Konzentration: ";
				cin >> konz;
				i->setKonz(konz);
				opt = true;
				break;
			}
			else if (option == "Preis") {
				float preis;
				cout << "Sie wollen den Preis " << i->getMenge() << " verandern, mit dem Preis: ";
				cin >> preis;
				i->setPreis(preis);
				opt = true;
				break;
			}
		}
	}

	if (!opt) {
		cout << "Es gibt kein Medikament mit dieser Beschreibung!\n";
	}
}

void Repo::gruppiert_nach_preis(string s_od_f) {
	//grupeaza medicamentele dupa pret
	//pot fi grupate crescator sau descrescator in functie de preferinta utilizatorului
	//steigend oder fallend
	if (s_od_f == "steigend") {
		sort(med.begin(), med.end(), [](Medikament& lhs, Medikament& rhs) {
			return lhs.getPreis() < rhs.getPreis();
			});
		//lambda expression fur Sortieren von Objekten vom Typ Medikament
	}
	else if (s_od_f == "fallend") {
		sort(med.begin(), med.end(), [](Medikament& lhs, Medikament& rhs) {
			return lhs.getPreis() > rhs.getPreis();
			});
		//lambda expression fur Sortieren von Objekten vom Typ Medikament
	}
	else {
		cout << "Sie mussen steigend oder fallend wahlen\n";
	}
}
