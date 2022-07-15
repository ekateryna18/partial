#pragma once
#include <string>
using std::string;

class Firma {
public:
	Firma() = default;
	Firma(int i, string tip, string m, int an, string c, int pr) : id{ i }, tip{ tip },model{ m }, an{ an }, culoare{ c }, pret{ pr }{}
	Firma(const Firma& ot) :id{ ot.id }, tip{ ot.tip }, model{ ot.model }, an{ ot.an }, culoare{ ot.culoare }, pret{ ot.pret }{}

	int getId() {
		return id;
	}

	string getTip() {
		return tip;
	}

	string getModel() {
		return model;
	}

	int getAn() {
		return an;
	}

	string getCuloare() {
		return culoare;
	}

	int getPret() {
		return pret;
	}
private:
	int id = -1;
	string tip;
	string model;
	int an = -1;
	string culoare;
	int pret = -1;
};