#include "partial.h"
#include "mainGUI.h"
#include <QtWidgets/QApplication>
#include "repo.h"
#include "service.h"
#include <fstream>
using std::ofstream;

void adaugactv() {
    ofstream ofs;
    ofs.open("fisier.txt", ofstream::out, ofstream::trunc);
    ofs << "1,Iphone,x,2020,albastru,3000\n";
    ofs << "2,Ipad,pro,2021,negru,5000\n";
    ofs << "3,Huawei,max11,2023,albastru,7000\n";
    ofs.close();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    adaugactv();
    RepoFile repo{ "fisier.txt" };
    FirmService srv{ repo };
    MainGUI w{srv} ;
    w.show();
    return a.exec();
}
