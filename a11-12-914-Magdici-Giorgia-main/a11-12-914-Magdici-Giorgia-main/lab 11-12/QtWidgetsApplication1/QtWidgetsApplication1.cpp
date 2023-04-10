#include "QtWidgetsApplication1.h"
#include<vector>
#include<QPalette>
#include<QMessageBox>

using namespace std;

QtWidgetsApplication1::QtWidgetsApplication1( AdministratorService& a,ClientService* c,const std::string& f,QWidget *parent)
    : QMainWindow(parent), admService{a},clService{c},file{f}
{
    ui.setupUi(this);
	

	this->populateList();
	this->connectSignalAndSlots();

}

void QtWidgetsApplication1::connectSignalAndSlots()
{
	QObject::connect(this->ui.listWidgetCoats, &QListWidget::clicked, this, &QtWidgetsApplication1::initFields);
	QObject::connect(this->ui.pushButtonAdd, &QPushButton::clicked, this, &QtWidgetsApplication1::addCoat);
	QObject::connect(this->ui.pushButtonDelete, &QPushButton::clicked, this, &QtWidgetsApplication1::deleteCoat);
	QObject::connect(this->ui.pushButtonUpdate, &QPushButton::clicked, this, &QtWidgetsApplication1::updateCoat);
	QObject::connect(this->ui.pushButtonSearch, &QPushButton::clicked, this, &QtWidgetsApplication1::clSeeCoats);
	QObject::connect(this->ui.pushButtonNext, &QPushButton::clicked, this, &QtWidgetsApplication1::nextCoat);
	QObject::connect(this->ui.pushButtonBuy, &QPushButton::clicked, this, &QtWidgetsApplication1::addToBasket);
	QObject::connect(this->ui.pushButtonBuy, &QPushButton::clicked, this, &QtWidgetsApplication1::populateList);

}

void QtWidgetsApplication1::populateList()
{

	this->ui.listWidgetCoats->clear();
	vector<Coat> coats = admService.getCoatsService();

	for (Coat& c : coats) {
		this->ui.listWidgetCoats->addItem(QString::fromStdString(c.getColour() + " " + c.getSize() + " " + std::to_string(c.getPrice()) + " " + std::to_string(c.getQuantity()) + " " + c.getPhotograph()));
	}
}


int QtWidgetsApplication1::getSelectedIndex()
{
	auto indexes = this->ui.listWidgetCoats->selectionModel()->selectedIndexes();
	if (indexes.size() == 0) {
		this->ui.lineEditSize->clear();
		this->ui.lineEditColour->clear();
		this->ui.lineEditPrice->clear();
		this->ui.lineEditQuantity->clear();
		this->ui.lineEditLink->clear();
		return -1;
	}
	return indexes[0].row();
}


void QtWidgetsApplication1::deleteCoat()
{
	int index = getSelectedIndex();
	if (index == -1) {
		QMessageBox::critical(this, QString::fromStdString(" Error "), QString::fromStdString(" Nothing is selected "));
	}
	else {
		admService.removeCoatService(index);
		populateList();
	}
}

void QtWidgetsApplication1::addCoat()
{
	auto colour = this->ui.lineEditColour->text().toStdString();
	auto size = this->ui.lineEditSize->text().toStdString();
	auto price = this->ui.lineEditPrice->text().toStdString();
	auto quantity = this->ui.lineEditQuantity->text().toStdString();
	auto photo = this->ui.lineEditLink->text().toStdString();

	try {
		auto coat = Coat{ size,colour,stoi(quantity),stod(price),photo };
		this->admService.addCoatService(coat);
	}
	catch (ValidationException& e) {
		QMessageBox::critical(this, QString::fromStdString("stop!"), QString::fromStdString("Your  coat is invalid!\nReasons:" + e.getMessage()));
	}
	populateList();
}

void QtWidgetsApplication1::updateCoat()
{
	int index = getSelectedIndex();
	if (index == -1) {
		QMessageBox::critical(this, QString::fromStdString(" Error "), QString::fromStdString(" Nothing is selected "));
	}
	else {
		auto colour = this->ui.lineEditColour->text().toStdString();
		auto size = this->ui.lineEditSize->text().toStdString();
		auto price = this->ui.lineEditPrice->text().toStdString();
		auto quantity = this->ui.lineEditQuantity->text().toStdString();
		auto photo = this->ui.lineEditLink->text().toStdString();
		try {

			this->admService.updateCoatService(index, size, colour, stoi(quantity), stod(price), photo);
		}
		catch (ValidationException& e) {
			QMessageBox::critical(this, QString::fromStdString("stop!"), QString::fromStdString("Your  coat is invalid!\nReasons:" + e.getMessage()));
		}
		populateList();


	}

}


void QtWidgetsApplication1::initFields()
{
	int index = getSelectedIndex();
	Coat c = admService.getCoatsService()[index];

	this->ui.lineEditColour->setText(QString::fromStdString(c.getColour()));
	this->ui.lineEditSize->setText(QString::fromStdString(c.getSize()));
	this->ui.lineEditPrice->setText(QString::fromStdString(std::to_string(c.getPrice())));
	this->ui.lineEditQuantity->setText(QString::fromStdString(std::to_string(c.getQuantity())));
	this->ui.lineEditLink->setText(QString::fromStdString(c.getPhotograph()));


}



void QtWidgetsApplication1::clSeeCoats()
{
	auto size = this->ui.lineEditSizeSearch->text().toStdString();
	this->searchCoats = this->clService->getCoatsWithSize(size);
	this->it = this->searchCoats.begin();

	showCoat();

}

void QtWidgetsApplication1::showCoat()
{

	this->ui.listWidgetSearch->clear();
	Coat c = *this->it;
	this->ui.listWidgetSearch->addItem(QString::fromStdString(c.getColour() + " " + c.getSize() + " " + std::to_string(c.getPrice()) + " " + std::to_string(c.getQuantity()) + " " + c.getPhotograph()));

}

void QtWidgetsApplication1::nextCoat()
{
	if (it < this->searchCoats.end()-1)
		 this->it++;
	else
		it = this->searchCoats.begin();
	showCoat();
}

void QtWidgetsApplication1::addToBasket()
{
	Coat c = *this->it;
	this->clService->addCoatService(c);

	this->ui.listWidgetBasket->clear();
	vector<Coat> coats = this->clService->getbasket();

	for (Coat& c : coats) {
		this->ui.listWidgetBasket->addItem(QString::fromStdString(c.getColour() + " " + c.getSize() + " " + std::to_string(c.getPrice()) + " " + std::to_string(c.getQuantity()) + " " + c.getPhotograph()));
	}
	populateList();
	nextCoat();
}

