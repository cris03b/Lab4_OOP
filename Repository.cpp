#include "Repository.h"
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>
using namespace std;


void Repo::add_med(Medikament m) {
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
	if (found_name == false || med.empty()) {
		med.push_back(m);		
	}
}

vector<Medikament> Repo::show_med(string option, string details) {
	vector<Medikament> show_v;
	if (option == "Name") {
		for (auto i = med.begin(); i != med.end(); ++i) {
			if (i->getName() == details) {
				Medikament m1(i->getName(), i->getKonz(), i->getMenge(), i->getPreis());
				show_v.push_back(m1);
			}
		}
		return show_v;
	}

	else if (option == "Konzentration") {
		for (auto i = med.begin(); i != med.end(); ++i) {
			if (i->getKonz() == details) {
				Medikament m1(i->getName(), i->getKonz(), i->getMenge(), i->getPreis());
				show_v.push_back(m1);
			}
		}
		return show_v;
	}

	else if (option == "Menge") {
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
			// daca details = doar string (fara numere) => price = 0
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
		sort(med.begin(), med.end(), [](Medikament& lhs, Medikament& rhs) {return lhs.getName() < rhs.getName(); });
		return med;
	}
	
	else {
		return med;
	}
	
}

vector<Medikament> Repo::show_knapp(int x) {
	vector<Medikament> show_v;
	for (auto i = med.begin(); i != med.end(); ++i) {
		if (i->getMenge() < x) {
			Medikament m1(i->getName(), i->getKonz(), i->getMenge(), i->getPreis());
			show_v.push_back(m1);
		}
 	}
	return show_v;
}

void Repo::delete_med(Medikament m) {
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
