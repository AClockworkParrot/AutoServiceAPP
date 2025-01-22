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
#include <QtWidgets/QMenu>
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
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QCheckBox *checkBox;
    QPushButton *sortAscButton;
    QPushButton *sortDescButton;
    QSpacerItem *verticalSpacer;
    QMenuBar *menubar;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(557, 545);
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
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(22);
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label);

        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName("checkBox");

        verticalLayout->addWidget(checkBox);

        sortAscButton = new QPushButton(centralwidget);
        sortAscButton->setObjectName("sortAscButton");

        verticalLayout->addWidget(sortAscButton);

        sortDescButton = new QPushButton(centralwidget);
        sortDescButton->setObjectName("sortDescButton");

        verticalLayout->addWidget(sortDescButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        verticalLayout_2->addLayout(verticalLayout);


        horizontalLayout->addLayout(verticalLayout_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 557, 21));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName("menuHelp");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuHelp->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actiontools->setText(QCoreApplication::translate("MainWindow", "tools", nullptr));
        saveButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        lineSaveFilePath->setText(QCoreApplication::translate("MainWindow", "C:/Qt projects/AutoService/AutoParts2.csv", nullptr));
        loadButton->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        lineFilePath->setText(QCoreApplication::translate("MainWindow", "C:\\Users\\lemon\\OneDrive\\\320\240\320\260\320\261\320\276\321\207\320\270\320\271 \321\201\321\202\320\276\320\273\\\320\230\320\242\320\234\320\236\\\320\230\320\275\320\266\320\270\320\275\320\270\321\200\320\270\320\275\320\263 \321\203\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\321\217 \320\264\320\260\320\275\320\275\321\213\320\274\320\270\\Datasets\\\320\232\320\270\320\275\320\276\321\202\320\265\320\260\321\202\321\200\321\213\\kinoteatry.csv", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Filter", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\320\276\320\273\320\276\320\262\320\276\320\272", nullptr));
        sortAscButton->setText(QCoreApplication::translate("MainWindow", "Increase", nullptr));
        sortDescButton->setText(QCoreApplication::translate("MainWindow", "Decrease", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
