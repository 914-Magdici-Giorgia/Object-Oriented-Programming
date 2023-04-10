#pragma once
#include"QWidget.h"
#include"ClientService.h"
#include"AdministratorService.h"
#include<QListWidget.h>
#include<QPushButton.h>
#include<QLineEdit.h>



class UI :public QWidget {
private:
	AdministratorService admService;
	ClientService* clService;
	std::string DataFile;

	QListWidget* coatsListWidget;
	QPushButton* addButton;
	QPushButton* deleteButton;
	QPushButton* updateButton;
	QLineEdit* sizeWidget, * colourWidget, * quantityWidget, * priceWidget, * photoWidget;
	void bindUI();
	void populate();
	void initFields();
	int getSelectedIndex();
	void connectSignalsWithSlots();
	void addCoat();
	void deleteCoat();
	void updateCoat();
public:
	UI(const AdministratorService admServ, ClientService* clServ, const std::string file) : admService(admServ), clService(clServ), DataFile(file) 
	{
		bindUI(); populate(); connectSignalsWithSlots();
	}

};