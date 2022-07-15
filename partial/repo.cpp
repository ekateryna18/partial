#include "repo.h"
#include "firma.h"
#include <fstream>
#include<sstream>
#include <iostream>

using std::ifstream;
using std::ofstream;
using std::stringstream;
using std::endl;

void RepoFile::loadfromfile() {
	
	ifstream firmFile(this->filename);
	if (!firmFile.is_open()) {
		return;
	}
	string line;
	while(getline(firmFile, line))
	{
		string tip, model, culoare;
		int id, an,pret;

		stringstream linestream(line);
		string current_item;
		int item_no = 0;
		while (getline(linestream, current_item, ','))
		{
			if (item_no == 0) id = stoi(current_item);
			if (item_no == 1) tip = current_item;
			if (item_no == 2) model = current_item;
			if (item_no == 3) an = stoi(current_item);
			if (item_no == 4) culoare = current_item;
			if (item_no == 5) pret = stoi(current_item);
			item_no++;
		}
		Firma f{ id,tip,model,an,culoare,pret};
		RepoFile::add(f);
	}
	firmFile.close();
}

void RepoFile::savetofile() {
	ofstream firmOutput(this->filename);
	if (!firmOutput.is_open())
		return;
	for (auto& firm : get_all()) {
		firmOutput << firm.getId() << "," << firm.getTip() << "," << firm.getModel() << "," << firm.getAn() << "," << firm.getCuloare() << ","<<firm.getPret()<<endl;
	}
	firmOutput.close();
}

vector<Firma>& RepoFile::get_all() {
	return allFirms;
}

void RepoFile::add(const Firma& firm) {
	allFirms.push_back(firm);
}