/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionFile;
    QAction *actionSave;
    QAction *actionSave_2;
    QAction *actionRenderer;
    QAction *actionWindow;
    QWidget *centralWidget;
    QWidget *RenderSettings;
    QGridLayout *gridLayout;
    QMenuBar *menuBar;
    QStatusBar *statusBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1232, 694);
        actionFile = new QAction(MainWindow);
        actionFile->setObjectName(QStringLiteral("actionFile"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave_2 = new QAction(MainWindow);
        actionSave_2->setObjectName(QStringLiteral("actionSave_2"));
        actionRenderer = new QAction(MainWindow);
        actionRenderer->setObjectName(QStringLiteral("actionRenderer"));
        actionWindow = new QAction(MainWindow);
        actionWindow->setObjectName(QStringLiteral("actionWindow"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        RenderSettings = new QWidget(centralWidget);
        RenderSettings->setObjectName(QStringLiteral("RenderSettings"));
        RenderSettings->setGeometry(QRect(30, 30, 341, 441));
        gridLayout = new QGridLayout(RenderSettings);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1232, 25));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        MainWindow->insertToolBarBreak(mainToolBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionFile->setText(QApplication::translate("MainWindow", "File", 0));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0));
        actionSave_2->setText(QApplication::translate("MainWindow", "Save", 0));
        actionRenderer->setText(QApplication::translate("MainWindow", "Renderer", 0));
        actionWindow->setText(QApplication::translate("MainWindow", "Scene", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
