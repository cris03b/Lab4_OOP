// lab4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Repository.h"

using namespace std;

Medikament read_med() {
    
    string name;
    string konzentration;
    int menge;
    float preis;
    cout << "Name: ";
    cin >> name;
    cout << "Konzentration: ";
    cin >> konzentration;
    cout << "Menge: ";
    cin >> menge;
    cout << "Preis: ";
    cin >> preis;
    Medikament m(name, konzentration, menge, preis);
    return m;
}

int main()
{

    /*Medikament m = read_med();
    cout << m.getName() << " " << m.getKonz() << " " << m.getMenge() << " " << m.getPreis();*/
    Repo repo;
    vector<Medikament> init_med;
    init_med = repo.med;
    int opt, prev_opt;
    string option, spec;
    while (true) {
        cout << endl << \
            "1. Medikament einfugen" << endl << \
            "2. Medikament loschen" << endl << \
            "3. Medikament bearbeiten" << endl << \
            "4. Alle Medikamente anzeigen" << endl << \
            "5. Verfugbare Medikamente anzeigen" << endl << \
            "6. Knapp Medikamente anzeigen" << endl << \
            "7. Medikamente nach Preis gruppiert" << endl << \
            "8. Undo" << endl << \
            "9. Redo" << endl << \
            "10. Out" << endl;
        
        cout << endl << "Option: ";
        cin >> opt;

        if (opt == 1) {
            prev_opt = 1;
            init_med.clear();
            for (int i = 0; i < repo.med.size(); i++) {
                init_med.push_back(repo.med[i]);
            }
            Medikament m = read_med();
            repo.add_med(m);
        }

        else if (opt == 4) {
            for (auto i = repo.med.begin(); i != repo.med.end(); ++i) {
                cout << i->getName() << " " << i->getKonz() << " " << i->getMenge() << " " << i->getPreis() << endl;
            }
        }

        else if (opt == 5) {
            cout << "Alle verfugbare Medikamente anzeigen, die eine spezifische Eigenschaft haben" << \
                endl << "Hint: fur Option kann man 'Name', 'Konzentration', 'Menge' oder 'Preis' wahlen" << endl;
            cout << "Option: ";
            cin >> option;
            cout << "Bezeichnung: ";
            cin >> spec;
            vector<Medikament> vect = repo.show_med(option, spec);
            for (auto i1 = vect.begin(); i1 != vect.end(); ++i1) {
                cout << i1->getName() << " " << i1->getKonz() << " " << i1->getMenge() << " " << i1->getPreis() << endl;
            }

        }

        else if (opt == 8) {
            repo.med.clear();
            if (prev_opt == 1) {
                for (int i = 0; i < init_med.size(); i++) {
                    repo.med.push_back(init_med[i]);
                }
            }
        }

        else if (opt == 10) {
            return false;
        }

        else {
            cout << "Wahlen Sie bitte eine verfugbare Option " << endl;
        }

    }
   /* Medikament m1("a1", "40mg", 5, 20);
    Medikament m2("a2", "45mg", 6, 25);
    Medikament m3("a1", "45mg", 6, 20);
    Medikament m4("a3", "80mg", 3, 22.3);

    Repo repo;
    repo.add_med(m1);
    repo.add_med(m2);
    repo.add_med(m4);
    repo.add_med(m3);

    for (auto i = repo.med.begin(); i != repo.med.end(); ++i) {
        cout << i->getName() << " " << i->getKonz() << " " << i->getMenge() << " " << i->getPreis() << endl;
    }

    cout << "undo" << endl;
    repo.undo();
    for (auto i = repo.med.begin(); i != repo.med.end(); ++i) {
        cout << i->getName() << " " << i->getKonz() << " " << i->getMenge() << " " << i->getPreis() << endl;
    }



    cout << "preferinte" << endl;
    string opt = "Preis";
    string spec = "22.3";
    vector<Medikament> vect = repo.show_med(opt, spec);
    for (auto i1 = vect.begin(); i1 != vect.end(); ++i1) {
        cout << i1->getName() << " " << i1->getKonz() << " " << i1->getMenge() << " " << i1->getPreis() << endl;
      }

    cout << "knapp" << endl;
    int x;
    cout << "x: ";
    cin >> x;
    vector<Medikament> v = repo.show_knapp(x);
    for (auto i2 = v.begin(); i2 != v.end(); ++i2) {
        cout << i2->getName() << " " << i2->getKonz() << " " << i2->getMenge() << " " << i2->getPreis() << endl;
    }*/
}

