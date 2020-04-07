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

    Repo repo;
    vector<Medikament> undo_med, redo_med;
    undo_med = redo_med = repo.med;
    int opt, prev_opt, menge;
    string option, spec;
    while (true) {
        cout << endl << \
            "1. Medikament einfugen" << endl << \
            "2. Medikament loschen" << endl << \
            "3. Medikament bearbeiten" << endl << \
            "4. Alle Medikamente anzeigen" << endl << \
            "5. Verfugbare Medikamente anzeigen" << endl << \
            "6. Knapp Medikamente anzeigen" << endl << \
            "7. Medikamente nach Preis gruppieren" << endl << \
            "8. Undo" << endl << \
            "9. Redo" << endl << \
            "10. Out" << endl;
        
        cout << endl << "Option: ";
        cin >> opt;
        cout << endl;

        if (opt == 1) {
            cout << "Ein Medikament einfugen" << endl;
            prev_opt = 1;
            undo_med.clear();
            for (int i = 0; i < repo.med.size(); i++) {
                undo_med.push_back(repo.med[i]);
            }
            Medikament m = read_med();
            repo.add_med(m);
        }

        else if (opt == 2) {
            cout << "Ein Medikament loschen" << endl;
            if (repo.med.empty()) {
                cout << "Es gibt keine Medikamente...";
            }
            else {
                prev_opt = 2;
                undo_med.clear();
                for (int i = 0; i < repo.med.size(); i++) {
                    undo_med.push_back(repo.med[i]);
                }
                Medikament m = read_med();
                repo.delete_med(m);
            }
        }

        else if (opt == 3) {
            cout << "Ein Medikament bearbeiten" << endl;  
            if (repo.med.empty()) {
                cout << "Es gibt keine Medikamente...";
            }
            else {
                prev_opt = 3;
                undo_med.clear();
                for (int i = 0; i < repo.med.size(); i++) {
                    undo_med.push_back(repo.med[i]);
                }
                Medikament m = read_med();
                cout << "Hint: fur Option kann man 'Name', 'Konzentration', 'Menge' oder 'Preis' wahlen" << endl;
                cout << "Option: ";
                cin >> option;
                repo.edit_med(m, option);
            }
        }

        else if (opt == 4) {
            cout << "Alle Medikamente anzeigen: " << endl;
            if (repo.med.empty()) {
                cout << "Es gibt keine Medikamente...";
            }
            else {
                for (auto i = repo.med.begin(); i != repo.med.end(); ++i) {
                    cout << "Name: " << i->getName() << ", Konzentration: " << i->getKonz() << ", Menge: " << i->getMenge() << ", Preis: " << i->getPreis() << endl;
                }
            }
        }

        else if (opt == 5) {
            cout << "Alle verfugbare Medikamente anzeigen, die eine spezifische Eigenschaft haben" << endl;
            if (repo.med.empty()) {
                cout << "Es gibt keine Medikamente...";
            }
            else {
                cout << "Hint: fur Option kann man 'Name', 'Konzentration', 'Menge' oder 'Preis' wahlen" << endl;
                cout << "Option: ";
                cin >> option;
                cout << "Bezeichnung: ";
                cin >> spec;
                cout << endl;
                vector<Medikament> vect = repo.show_med(option, spec);
                for (auto i = vect.begin(); i != vect.end(); ++i) {
                    cout << "Name: " << i->getName() << ", Konzentration: " << i->getKonz() << ", Menge: " << i->getMenge() << ", Preis: " << i->getPreis() << endl;
                }
            }
        }

        else if (opt == 6) {
            cout << "Alle Medikamente anzeigen, die knapp sind" << endl;
            if (repo.med.empty()) {
                cout << "Es gibt keine Medikamente...";
            }
            else {
                cout << "Hint: Es werden nur Medikamente mit einer Menge < 'Menge' angezeigt" << endl;
                cout << "Menge: ";
                cin >> menge;
                cout << endl;
                vector<Medikament> vect = repo.show_knapp(menge);
                for (auto i = vect.begin(); i != vect.end(); ++i) {
                    cout << "Name: " << i->getName() << ", Konzentration: " << i->getKonz() << ", Menge: " << i->getMenge() << ", Preis: " << i->getPreis() << endl;
                }
            }
        }

        else if (opt == 7) {
            cout << "Medikamente nach Preis gruppieren" << endl;
            if (repo.med.empty()) {
                cout << "Es gibt keine Medikamente...";
            }
            else {
                cout << "Hint: Option kann entweder 'steigend' oder 'fallend' sein" << endl;
                cout << "Option: ";
                cin >> option;
                repo.gruppiert_nach_preis(option);
                for (auto i = repo.med.begin(); i != repo.med.end(); ++i) {
                    cout << "Name: " << i->getName() << ", Konzentration: " << i->getKonz() << ", Menge: " << i->getMenge() << ", Preis: " << i->getPreis() << endl;
                }
            }
        }

        else if (opt == 8) {
            cout << "Undo" << endl;
            if (prev_opt == 1 || prev_opt == 2 || prev_opt == 3) {                
                redo_med.clear();
                for (int j = 0; j < repo.med.size(); j++) {
                    redo_med.push_back(repo.med[j]);
                }
                repo.med.clear();
                for (int i = 0; i < undo_med.size(); i++) {
                    repo.med.push_back(undo_med[i]);
                }
            }
        }

        else if (opt == 9) {
            cout << "Redo" << endl;
            if (prev_opt == 1 || prev_opt == 2 || prev_opt == 3) {
                repo.med.clear();
                for (int i = 0; i < redo_med.size(); i++) {
                    repo.med.push_back(redo_med[i]);
                }
            }
        }

        else if (opt == 10) {
            cout << "Aufwiedersehen!" << endl << "Stay safe and wash your hands! :D" << endl;
            return false;
        }

        else {
            cout << "Wahlen Sie bitte eine verfugbare Option " << endl;
        }

    }
   
}

