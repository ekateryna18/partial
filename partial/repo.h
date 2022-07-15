#pragma once
#include "firma.h"
#include <string>
#include <vector>
using std::vector;
using std::string;

class RepoFile {
private:
	vector<Firma> allFirms;
	string filename;

	void loadfromfile();

	void savetofile();
public:
	RepoFile() = default;
	RepoFile(RepoFile& ot) = delete;

	RepoFile(string fname) : filename{ fname } {
		loadfromfile();
	}

	void add(const Firma& firma);

	vector<Firma>& get_all();
};