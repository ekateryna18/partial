#include "mainGUI.h"
#include "service.h"
#include "firma.h"
#include <string>

using std::to_string;

void MainGUI::initializeGuicomponents() {
	QHBoxLayout* lyMain = new QHBoxLayout;
	this->setLayout(lyMain);

	//stg
	QWidget* left = new QWidget;
	QVBoxLayout* lyLeft = new QVBoxLayout;
	left->setLayout(lyLeft);

	QWidget* form = new QWidget;
	QFormLayout* lyForm = new QFormLayout;
	form->setLayout(lyForm);

	editan = new QLineEdit;
	editmodel = new QLineEdit;

	lyForm->addRow(lblan, editan);
	lyForm->addRow(lblmodel, editmodel);

	lyLeft->addWidget(form);

	btnfltran = new QPushButton("Filtrare Model");
	lyLeft->addWidget(btnfltran);
	btnfltrmodel = new QPushButton("Filtrare an");
	lyLeft->addWidget(btnfltrmodel);
	reincarca = new QPushButton("Reincarca");
	lyLeft->addWidget(reincarca);

	//dr
	QWidget* right = new QWidget;
	QVBoxLayout* lyRight = new QVBoxLayout;
	right->setLayout(lyRight);

	this->firmlist = new QListWidget;
	lyRight->addWidget(firmlist);

	lyMain->addWidget(left);
	lyMain->addWidget(right);
}

void MainGUI::connectSlots() {
	QObject::connect(btnfltrmodel, &QPushButton::clicked, [&]() {
		string model = this->editmodel->text().toStdString();
		this->ReloadData(srv.filtrare_model(model[0]));
		});


}

void MainGUI::ReloadData(vector<Firma> firms) {
	this->firmlist->clear();

	for (auto& firm : firms) {
		QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(to_string(firm.getId()) + "--" + firm.getTip() + "--" + firm.getModel() + "--" + to_string(firm.getAn()) + "--" + firm.getCuloare() + "--" + to_string(firm.getPret())));
		this->firmlist->addItem(item);
	}
}