#include "Repository.h"
#include <vector>
#include <sstream>
using namespace std;


void Repo::add_med(Medikament m) {
	med_undo = med;
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
			// daca de ex details = 22.3 lei => dupa conversie price = 22.3
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
	return med;
	
}

vector<Medikament> Repo::show_knapp(int x) {
	vector<Medikament> show_v;
	for (auto i = med.begin(); i != med.end(); ++i) {
		if (i->getMenge() <= x) {
			Medikament m1(i->getName(), i->getKonz(), i->getMenge(), i->getPreis());
			show_v.push_back(m1);
		}
 	}
	return show_v;
}

vector<Medikament> Repo::undo() {
	med = med_undo;
	return med;
}
