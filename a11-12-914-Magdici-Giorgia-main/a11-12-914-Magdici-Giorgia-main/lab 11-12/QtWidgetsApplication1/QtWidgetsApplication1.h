#pragma once
#include"AdministratorService.h"
#include"ClientService.h"

#include <QtWidgets/QMainWindow>
#include "ui_QtWidgetsApplication1.h"

class QtWidgetsApplication1 : public QMainWindow
{
    Q_OBJECT

public:
    QtWidgetsApplication1( AdministratorService& a, ClientService* c,const std::string& f,QWidget* parent = 0);

private:
    Ui::QtWidgetsApplication1Class ui;
    AdministratorService& admService;
    ClientService* clService; 
    std::string file;

    vector<Coat> searchCoats;
    vector<Coat>::iterator it;

    void connectSignalAndSlots();

    void populateList();
    void initFields();
    void deleteCoat();
    void addCoat();
    void updateCoat();
    int getSelectedIndex();

    void clSeeCoats();
    void showCoat();
    void nextCoat();
    void addToBasket();

};