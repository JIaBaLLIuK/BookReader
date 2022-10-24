/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *imageLabel;
    QPushButton *chooseBookButton;
    QPushButton *aboutProgramButton;
    QTabWidget *programTab;
    QWidget *bookTab;
    QWidget *aboutTab;
    QLabel *aboutProgramLabel;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1360, 800);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        imageLabel = new QLabel(centralwidget);
        imageLabel->setObjectName(QString::fromUtf8("imageLabel"));
        imageLabel->setGeometry(QRect(0, 0, 375, 264));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(imageLabel->sizePolicy().hasHeightForWidth());
        imageLabel->setSizePolicy(sizePolicy);
        imageLabel->setScaledContents(false);
        chooseBookButton = new QPushButton(centralwidget);
        chooseBookButton->setObjectName(QString::fromUtf8("chooseBookButton"));
        chooseBookButton->setGeometry(QRect(120, 270, 140, 30));
        aboutProgramButton = new QPushButton(centralwidget);
        aboutProgramButton->setObjectName(QString::fromUtf8("aboutProgramButton"));
        aboutProgramButton->setGeometry(QRect(120, 310, 140, 30));
        programTab = new QTabWidget(centralwidget);
        programTab->setObjectName(QString::fromUtf8("programTab"));
        programTab->setGeometry(QRect(400, 10, 951, 771));
        bookTab = new QWidget();
        bookTab->setObjectName(QString::fromUtf8("bookTab"));
        programTab->addTab(bookTab, QString());
        aboutTab = new QWidget();
        aboutTab->setObjectName(QString::fromUtf8("aboutTab"));
        aboutProgramLabel = new QLabel(aboutTab);
        aboutProgramLabel->setObjectName(QString::fromUtf8("aboutProgramLabel"));
        aboutProgramLabel->setGeometry(QRect(0, 0, 930, 745));
        aboutProgramLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        programTab->addTab(aboutTab, QString());
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        programTab->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        imageLabel->setText(QString());
        chooseBookButton->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        aboutProgramButton->setText(QCoreApplication::translate("MainWindow", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", nullptr));
        programTab->setTabText(programTab->indexOf(bookTab), QCoreApplication::translate("MainWindow", "Tab 1", nullptr));
        aboutProgramLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        programTab->setTabText(programTab->indexOf(aboutTab), QCoreApplication::translate("MainWindow", "Tab 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
