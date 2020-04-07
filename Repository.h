#pragma once
#include "Medikament.h"
#include <vector>

using namespace std;
class Repo {
public:
	vector<Medikament> med;
	vector<Medikament> med_undo;
	void add_med(Medikament m);
	vector<Medikament> show_med(string option, string details); //ex2
	vector<Medikament> show_knapp(int x);
	void delete_med(Medikament m);
	void edit_med(Medikament& m, string option);
	void gruppiert_nach_preis(string s_od_f);
};