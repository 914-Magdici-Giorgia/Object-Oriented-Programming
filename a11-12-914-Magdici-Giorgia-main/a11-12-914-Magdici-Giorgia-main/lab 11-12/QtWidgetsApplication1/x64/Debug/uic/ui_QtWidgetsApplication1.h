/********************************************************************************
** Form generated from reading UI file 'QtWidgetsApplication1.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTWIDGETSAPPLICATION1_H
#define UI_QTWIDGETSAPPLICATION1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtWidgetsApplication1Class
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QListWidget *listWidgetCoats;
    QFormLayout *formLayout;
    QLabel *labelSize;
    QLineEdit *lineEditSize;
    QLineEdit *lineEditColour;
    QLabel *labelPrice;
    QLineEdit *lineEditPrice;
    QLabel *labelQuantity;
    QLineEdit *lineEditQuantity;
    QLabel *labelLink;
    QLineEdit *lineEditLink;
    QLabel *labelColour;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonAdd;
    QPushButton *pushButtonDelete;
    QPushButton *pushButtonUpdate;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QFormLayout *formLayout_2;
    QLabel *label;
    QLineEdit *lineEditSizeSearch;
    QPushButton *pushButtonSearch;
    QListWidget *listWidgetSearch;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButtonBuy;
    QPushButton *pushButtonNext;
    QLabel *label_2;
    QListWidget *listWidgetBasket;
    QLabel *labelTotalPrice;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtWidgetsApplication1Class)
    {
        if (QtWidgetsApplication1Class->objectName().isEmpty())
            QtWidgetsApplication1Class->setObjectName(QString::fromUtf8("QtWidgetsApplication1Class"));
        QtWidgetsApplication1Class->resize(492, 524);
        centralWidget = new QWidget(QtWidgetsApplication1Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_5 = new QVBoxLayout(tab);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        listWidgetCoats = new QListWidget(tab);
        listWidgetCoats->setObjectName(QString::fromUtf8("listWidgetCoats"));
        QFont font;
        font.setPointSize(12);
        listWidgetCoats->setFont(font);

        verticalLayout_4->addWidget(listWidgetCoats);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        labelSize = new QLabel(tab);
        labelSize->setObjectName(QString::fromUtf8("labelSize"));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelSize);

        lineEditSize = new QLineEdit(tab);
        lineEditSize->setObjectName(QString::fromUtf8("lineEditSize"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditSize);

        lineEditColour = new QLineEdit(tab);
        lineEditColour->setObjectName(QString::fromUtf8("lineEditColour"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEditColour);

        labelPrice = new QLabel(tab);
        labelPrice->setObjectName(QString::fromUtf8("labelPrice"));

        formLayout->setWidget(2, QFormLayout::LabelRole, labelPrice);

        lineEditPrice = new QLineEdit(tab);
        lineEditPrice->setObjectName(QString::fromUtf8("lineEditPrice"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEditPrice);

        labelQuantity = new QLabel(tab);
        labelQuantity->setObjectName(QString::fromUtf8("labelQuantity"));

        formLayout->setWidget(3, QFormLayout::LabelRole, labelQuantity);

        lineEditQuantity = new QLineEdit(tab);
        lineEditQuantity->setObjectName(QString::fromUtf8("lineEditQuantity"));

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEditQuantity);

        labelLink = new QLabel(tab);
        labelLink->setObjectName(QString::fromUtf8("labelLink"));

        formLayout->setWidget(4, QFormLayout::LabelRole, labelLink);

        lineEditLink = new QLineEdit(tab);
        lineEditLink->setObjectName(QString::fromUtf8("lineEditLink"));

        formLayout->setWidget(4, QFormLayout::FieldRole, lineEditLink);

        labelColour = new QLabel(tab);
        labelColour->setObjectName(QString::fromUtf8("labelColour"));

        formLayout->setWidget(1, QFormLayout::LabelRole, labelColour);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButtonAdd = new QPushButton(tab);
        pushButtonAdd->setObjectName(QString::fromUtf8("pushButtonAdd"));

        horizontalLayout->addWidget(pushButtonAdd);

        pushButtonDelete = new QPushButton(tab);
        pushButtonDelete->setObjectName(QString::fromUtf8("pushButtonDelete"));

        horizontalLayout->addWidget(pushButtonDelete);

        pushButtonUpdate = new QPushButton(tab);
        pushButtonUpdate->setObjectName(QString::fromUtf8("pushButtonUpdate"));

        horizontalLayout->addWidget(pushButtonUpdate);


        formLayout->setLayout(5, QFormLayout::FieldRole, horizontalLayout);


        verticalLayout_4->addLayout(formLayout);


        verticalLayout_5->addLayout(verticalLayout_4);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        horizontalLayout_3 = new QHBoxLayout(tab_2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        formLayout_2 = new QFormLayout();
        formLayout_2->setSpacing(6);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        label = new QLabel(tab_2);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label);

        lineEditSizeSearch = new QLineEdit(tab_2);
        lineEditSizeSearch->setObjectName(QString::fromUtf8("lineEditSizeSearch"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, lineEditSizeSearch);

        pushButtonSearch = new QPushButton(tab_2);
        pushButtonSearch->setObjectName(QString::fromUtf8("pushButtonSearch"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, pushButtonSearch);


        verticalLayout_2->addLayout(formLayout_2);

        listWidgetSearch = new QListWidget(tab_2);
        listWidgetSearch->setObjectName(QString::fromUtf8("listWidgetSearch"));

        verticalLayout_2->addWidget(listWidgetSearch);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButtonBuy = new QPushButton(tab_2);
        pushButtonBuy->setObjectName(QString::fromUtf8("pushButtonBuy"));

        horizontalLayout_2->addWidget(pushButtonBuy);

        pushButtonNext = new QPushButton(tab_2);
        pushButtonNext->setObjectName(QString::fromUtf8("pushButtonNext"));

        horizontalLayout_2->addWidget(pushButtonNext);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout_3->addLayout(verticalLayout_2);

        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_3->addWidget(label_2);

        listWidgetBasket = new QListWidget(tab_2);
        listWidgetBasket->setObjectName(QString::fromUtf8("listWidgetBasket"));

        verticalLayout_3->addWidget(listWidgetBasket);

        labelTotalPrice = new QLabel(tab_2);
        labelTotalPrice->setObjectName(QString::fromUtf8("labelTotalPrice"));

        verticalLayout_3->addWidget(labelTotalPrice);


        horizontalLayout_3->addLayout(verticalLayout_3);

        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

        QtWidgetsApplication1Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtWidgetsApplication1Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 492, 22));
        QtWidgetsApplication1Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtWidgetsApplication1Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QtWidgetsApplication1Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtWidgetsApplication1Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QtWidgetsApplication1Class->setStatusBar(statusBar);

        retranslateUi(QtWidgetsApplication1Class);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(QtWidgetsApplication1Class);
    } // setupUi

    void retranslateUi(QMainWindow *QtWidgetsApplication1Class)
    {
        QtWidgetsApplication1Class->setWindowTitle(QCoreApplication::translate("QtWidgetsApplication1Class", "QtWidgetsApplication1", nullptr));
        labelSize->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "Size", nullptr));
        lineEditSize->setText(QString());
        labelPrice->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "Price", nullptr));
        labelQuantity->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "Quantity", nullptr));
        labelLink->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "Link", nullptr));
        labelColour->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "Colour", nullptr));
        pushButtonAdd->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "Add", nullptr));
        pushButtonDelete->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "Delete", nullptr));
        pushButtonUpdate->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "Update", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("QtWidgetsApplication1Class", "Administrator", nullptr));
        label->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "Size:", nullptr));
        pushButtonSearch->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "Search", nullptr));
        pushButtonBuy->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "Buy", nullptr));
        pushButtonBuy->setStyleSheet("background-color: red");
        pushButtonNext->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "Next", nullptr));
        label_2->setText(QCoreApplication::translate("QtWidgetsApplication1Class", "Basket:", nullptr));
        labelTotalPrice->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("QtWidgetsApplication1Class", "Client", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtWidgetsApplication1Class: public Ui_QtWidgetsApplication1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTWIDGETSAPPLICATION1_H
