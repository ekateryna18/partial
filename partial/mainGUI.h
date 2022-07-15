#pragma once
#include "service.h"
#include <QtWidgets/QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QListWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QFormLayout>
#include <vector>
#include <QObject>

class MainGUI : public QWidget {
	
private:
	FirmService& srv;
	QLabel* lblmodel = new QLabel("model:");
	QLabel* lblan = new QLabel("an:");

	QLineEdit* editmodel;
	QLineEdit* editan;

	QPushButton* btnfltrmodel;
	QPushButton* btnfltran;
	QPushButton* reincarca;

	QListWidget* firmlist;
	
	void initializeGuicomponents();
	void connectSlots();
	void ReloadData(vector<Firma> firms);

public:
	MainGUI(FirmService& srv) : srv{ srv } {
		initializeGuicomponents();
		connectSlots();
		ReloadData(srv.getAll());
	}
};