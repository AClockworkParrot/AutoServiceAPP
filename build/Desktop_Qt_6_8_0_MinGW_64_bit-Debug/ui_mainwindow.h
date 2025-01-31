/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actiontools;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout_2;
    QTableWidget *tableWidget;
    QGridLayout *gridLayout_3;
    QPushButton *saveButton;
    QLineEdit *lineSaveFilePath;
    QGridLayout *gridLayout_4;
    QPushButton *loadButton;
    QLineEdit *lineFilePath;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLineEdit *lineSearch;
    QVBoxLayout *verticalLayout;
    QPushButton *searchButton;
    QLabel *label;
    QCheckBox *headingCheckBox;
    QPushButton *sortAscButton;
    QPushButton *sortDescButton;
    QLabel *label_5;
    QLineEdit *lineFilter;
    QPushButton *filterButton;
    QPushButton *resetFilterButton;
    QLabel *label_3;
    QPushButton *addColumnButton;
    QPushButton *addRowButton;
    QLabel *label_4;
    QPushButton *delColumnButton;
    QPushButton *delRowButton;
    QSpacerItem *verticalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(729, 648);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(0, 0));
        actiontools = new QAction(MainWindow);
        actiontools->setObjectName("actiontools");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        centralwidget->setMinimumSize(QSize(0, 0));
        centralwidget->setMaximumSize(QSize(1920, 1080));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setSizeConstraint(QLayout::SizeConstraint::SetMaximumSize);
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName("tableWidget");
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(tableWidget, 0, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName("gridLayout_3");
        saveButton = new QPushButton(centralwidget);
        saveButton->setObjectName("saveButton");

        gridLayout_3->addWidget(saveButton, 0, 1, 1, 1);

        lineSaveFilePath = new QLineEdit(centralwidget);
        lineSaveFilePath->setObjectName("lineSaveFilePath");

        gridLayout_3->addWidget(lineSaveFilePath, 0, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout_3, 2, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName("gridLayout_4");
        loadButton = new QPushButton(centralwidget);
        loadButton->setObjectName("loadButton");

        gridLayout_4->addWidget(loadButton, 0, 1, 1, 1);

        lineFilePath = new QLineEdit(centralwidget);
        lineFilePath->setObjectName("lineFilePath");

        gridLayout_4->addWidget(lineFilePath, 0, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout_4, 1, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        QFont font;
        font.setPointSize(22);
        label_2->setFont(font);

        verticalLayout_2->addWidget(label_2);

        lineSearch = new QLineEdit(centralwidget);
        lineSearch->setObjectName("lineSearch");

        verticalLayout_2->addWidget(lineSearch);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        searchButton = new QPushButton(centralwidget);
        searchButton->setObjectName("searchButton");

        verticalLayout->addWidget(searchButton);

        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout->addWidget(label);

        headingCheckBox = new QCheckBox(centralwidget);
        headingCheckBox->setObjectName("headingCheckBox");

        verticalLayout->addWidget(headingCheckBox);

        sortAscButton = new QPushButton(centralwidget);
        sortAscButton->setObjectName("sortAscButton");

        verticalLayout->addWidget(sortAscButton);

        sortDescButton = new QPushButton(centralwidget);
        sortDescButton->setObjectName("sortDescButton");

        verticalLayout->addWidget(sortDescButton);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setFont(font);

        verticalLayout->addWidget(label_5);

        lineFilter = new QLineEdit(centralwidget);
        lineFilter->setObjectName("lineFilter");

        verticalLayout->addWidget(lineFilter);

        filterButton = new QPushButton(centralwidget);
        filterButton->setObjectName("filterButton");

        verticalLayout->addWidget(filterButton);

        resetFilterButton = new QPushButton(centralwidget);
        resetFilterButton->setObjectName("resetFilterButton");

        verticalLayout->addWidget(resetFilterButton);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout->addWidget(label_3);

        addColumnButton = new QPushButton(centralwidget);
        addColumnButton->setObjectName("addColumnButton");

        verticalLayout->addWidget(addColumnButton);

        addRowButton = new QPushButton(centralwidget);
        addRowButton->setObjectName("addRowButton");

        verticalLayout->addWidget(addRowButton);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setFont(font);

        verticalLayout->addWidget(label_4);

        delColumnButton = new QPushButton(centralwidget);
        delColumnButton->setObjectName("delColumnButton");

        verticalLayout->addWidget(delColumnButton);

        delRowButton = new QPushButton(centralwidget);
        delRowButton->setObjectName("delRowButton");

        verticalLayout->addWidget(delRowButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        verticalLayout_2->addLayout(verticalLayout);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalLayout->setStretch(0, 7);
        horizontalLayout->setStretch(1, 1);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 729, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actiontools->setText(QCoreApplication::translate("MainWindow", "tools", nullptr));
        saveButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        lineSaveFilePath->setText(QCoreApplication::translate("MainWindow", "C:/Qt projects/AutoService/AutoParts.csv", nullptr));
        loadButton->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        lineFilePath->setText(QCoreApplication::translate("MainWindow", "C:\\Qt projects\\AutoService\\AutoParts.csv", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        searchButton->setText(QCoreApplication::translate("MainWindow", "Search next", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Sort", nullptr));
        headingCheckBox->setText(QCoreApplication::translate("MainWindow", "Heading", nullptr));
        sortAscButton->setText(QCoreApplication::translate("MainWindow", "Increase", nullptr));
        sortDescButton->setText(QCoreApplication::translate("MainWindow", "Decrease", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Filter", nullptr));
        lineFilter->setText(QCoreApplication::translate("MainWindow", ">15 && <=20", nullptr));
        filterButton->setText(QCoreApplication::translate("MainWindow", "Filter", nullptr));
        resetFilterButton->setText(QCoreApplication::translate("MainWindow", "Reset filter", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        addColumnButton->setText(QCoreApplication::translate("MainWindow", "Add column", nullptr));
        addRowButton->setText(QCoreApplication::translate("MainWindow", "Add row", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        delColumnButton->setText(QCoreApplication::translate("MainWindow", "Delete column", nullptr));
        delRowButton->setText(QCoreApplication::translate("MainWindow", "Delete row", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
