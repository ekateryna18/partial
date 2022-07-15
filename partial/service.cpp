#include "service.h"
#include "firma.h"

void FirmService::adauga(int i, string tip, string m, int an, string c, int pr) {
	Firma f{ i,tip,m,an,c,pr };
	repo.add(f);
}

vector<Firma> FirmService::filtrare_model(char l) {
	vector<Firma> filtered;
	for (auto& firm : repo.get_all()) {
		if (firm.getModel()[0] == l)
			filtered.push_back(firm);
	}
	return filtered;
}

vector<Firma> FirmService::filtrare_an(int an) {
	vector<Firma> filtered;
	for (auto& firm : repo.get_all()) {
		if (firm.getAn() == an)
			filtered.push_back(firm);
	}
	return filtered;
}