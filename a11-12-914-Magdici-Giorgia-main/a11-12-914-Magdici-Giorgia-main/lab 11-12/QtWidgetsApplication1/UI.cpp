#include "UI.h"
#include<QVBoxLayout>
#include<QFormlayout>
#include<QGridLayout>
#include<QMessageBox>
#include"Coat.h"
#include<vector>

using namespace std;

void UI::bindUI()
{
	sizeWidget = new QLineEdit();
	colourWidget = new QLineEdit();
	photoWidget = new QLineEdit();
	quantityWidget = new QLineEdit();
	priceWidget = new QLineEdit();

	coatsListWidget = new QListWidget();

	addButton = new QPushButton("Add");
	deleteButton = new QPushButton("Delete");
	updateButton = new QPushButton("Update");

	QVBoxLayout* mainLayout = new QVBoxLayout(this);
	mainLayout->addWidget(coatsListWidget);

	QFormLayout* formLayout = new QFormLayout();
	formLayout->addRow("Size",sizeWidget);
	formLayout->addRow("Colour", colourWidget);
	formLayout->addRow("Price", priceWidget);
	formLayout->addRow("Quantity", quantityWidget);
	formLayout->addRow("Photo", photoWidget);
	mainLayout->addLayout(formLayout);

	QGridLayout* gridLayout = new QGridLayout();
	gridLayout->addWidget(addButton, 0, 0);
	gridLayout->addWidget(deleteButton, 0, 1);
	gridLayout->addWidget(updateButton, 0, 2);
	mainLayout->addLayout(gridLayout);



}

void UI::populate()
{
	vector<Coat> coats = admService.getCoatsService();

	coatsListWidget->clear();
	for (Coat& c : coats) {
		coatsListWidget->addItem(QString::fromStdString(c.getColour() +" "+ c.getSize() +" "+ std::to_string(c.getPrice()) +" "+ std::to_string(c.getQuantity())+" " + c.getPhotograph()));
	}

}

void UI::initFields()
{
	int index = getSelectedIndex();
	Coat c = admService.getCoatsService()[index];

	colourWidget->setText(QString::fromStdString(c.getColour()));
	sizeWidget->setText(QString::fromStdString(c.getSize()));
	priceWidget->setText(QString::fromStdString(std::to_string(c.getPrice())));
	quantityWidget->setText(QString::fromStdString(std::to_string(c.getQuantity())));
	photoWidget->setText(QString::fromStdString(c.getPhotograph()));


}

int UI::getSelectedIndex()
{
	auto indexes = coatsListWidget->selectionModel()->selectedIndexes();
	if (indexes.size() == 0) {
		return -1;
	}
	return indexes[0].row();
}

void UI::connectSignalsWithSlots()
{
	QObject::connect(coatsListWidget, &QListWidget::clicked, this, &UI::initFields);
	QObject::connect(deleteButton, &QPushButton::clicked, this, &UI::deleteCoat);
	QObject::connect(addButton, &QPushButton::clicked, this, &UI::addCoat);
	QObject::connect(updateButton, &QPushButton::clicked, this, &UI::updateCoat);
}

void UI::addCoat()
{
	auto colour = this->colourWidget->text().toStdString();
	auto size = this->sizeWidget->text().toStdString();
	auto price = this->priceWidget->text().toStdString();
	auto quantity = this->quantityWidget->text().toStdString();
	auto photo = this->photoWidget->text().toStdString();

	try {
		auto coat = Coat{ size,colour,stoi(quantity),stod(price),photo };
		this->admService.addCoatService(coat);
	}
	catch (ValidationException& e) {
		QMessageBox::critical(this, QString::fromStdString("stop!"), QString::fromStdString("Your  coat is invalid!\nReasons:" + e.getMessage()));
	}
	populate();
}

void UI::deleteCoat()
{
	int index = getSelectedIndex();
	if (index == -1) {
		QMessageBox::critical(this, QString::fromStdString(" Error "), QString::fromStdString(" Nothing is selected "));
	}
	else {
		admService.removeCoatService(index);
		populate();
	}
}

void UI::updateCoat()
{
	int index = getSelectedIndex();
	if (index == -1) {
		QMessageBox::critical(this, QString::fromStdString(" Error "), QString::fromStdString(" Nothing is selected "));
	}
	else {
		auto colour = this->colourWidget->text().toStdString();
		auto size = this->sizeWidget->text().toStdString();
		auto price = this->priceWidget->text().toStdString();
		auto quantity = this->quantityWidget->text().toStdString();
		auto photo = this->photoWidget->text().toStdString();
		try {

			this->admService.updateCoatService(index, size, colour, stoi(quantity), stod(price), photo);
		}
		catch (ValidationException& e) {
			QMessageBox::critical(this, QString::fromStdString("stop!"), QString::fromStdString("Your  coat is invalid!\nReasons:" + e.getMessage()));
		}
		populate();


	}

}
