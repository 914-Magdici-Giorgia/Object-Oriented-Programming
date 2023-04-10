#include "QtWidgetsApplication1.h"
#include <QtWidgets/QApplication>


#include<fstream>
#include"Coat.h"
#include"Test.h"
#include"Repository.h"
#include"AdministratorService.h"
#include"ClientService.h"
#include "UI.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   /* QtWidgetsApplication1 w;
    w.show();*/

	Repository repo;
	vector<Coat> basket;

	AdministratorService admin{ repo };

	ifstream fin("Coats.txt");

	Coat c{};
	while (fin >> c) {
		admin.addCoatService(c);
	}
	fin.close();


	ClientService* client = new ClientService{ admin.getRepo(),basket, };

	UI ui(admin,client,"Coats.txt");
	ui.show();
    return a.exec();
}
