#pragma once
#include "repo.h"
#include "firma.h"

class FirmService {
	RepoFile& repo;
public:
	FirmService(RepoFile& repo) : repo{ repo } {}
	//nu permitem copierea de obiecte FilmService
	FirmService(const FirmService& ot) = delete;

	vector<Firma>& getAll() {
		return repo.get_all();
	}
	void adauga(int i, string tip, string m, int an, string c, int pr);

	vector<Firma> filtrare_model(char litera);

	vector<Firma> filtrare_an(int an);

};