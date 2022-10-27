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
    QPushButton *toStartMenuButton;
    QPushButton *aboutProgramButton;
    QTabWidget *programTab;
    QWidget *startTab;
    QLabel *mainWindowLabel;
    QWidget *bookTab;
    QLabel *bookLabel;
    QPushButton *previousPageButton;
    QPushButton *nextPageButton;
    QLabel *slashLabel;
    QLabel *totalPagesNumberLabel;
    QLabel *currentPageNumberLabel;
    QWidget *aboutTab;
    QLabel *aboutProgramLabel;
    QPushButton *chooseFileButton;

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
        toStartMenuButton = new QPushButton(centralwidget);
        toStartMenuButton->setObjectName(QString::fromUtf8("toStartMenuButton"));
        toStartMenuButton->setGeometry(QRect(120, 270, 140, 30));
        aboutProgramButton = new QPushButton(centralwidget);
        aboutProgramButton->setObjectName(QString::fromUtf8("aboutProgramButton"));
        aboutProgramButton->setGeometry(QRect(120, 350, 140, 30));
        programTab = new QTabWidget(centralwidget);
        programTab->setObjectName(QString::fromUtf8("programTab"));
        programTab->setGeometry(QRect(400, 0, 950, 790));
        startTab = new QWidget();
        startTab->setObjectName(QString::fromUtf8("startTab"));
        mainWindowLabel = new QLabel(startTab);
        mainWindowLabel->setObjectName(QString::fromUtf8("mainWindowLabel"));
        mainWindowLabel->setGeometry(QRect(0, 0, 940, 281));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(mainWindowLabel->sizePolicy().hasHeightForWidth());
        mainWindowLabel->setSizePolicy(sizePolicy1);
        mainWindowLabel->setAlignment(Qt::AlignCenter);
        programTab->addTab(startTab, QString());
        bookTab = new QWidget();
        bookTab->setObjectName(QString::fromUtf8("bookTab"));
        bookLabel = new QLabel(bookTab);
        bookLabel->setObjectName(QString::fromUtf8("bookLabel"));
        bookLabel->setGeometry(QRect(0, 0, 940, 717));
        bookLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        previousPageButton = new QPushButton(bookTab);
        previousPageButton->setObjectName(QString::fromUtf8("previousPageButton"));
        previousPageButton->setGeometry(QRect(10, 740, 40, 25));
        nextPageButton = new QPushButton(bookTab);
        nextPageButton->setObjectName(QString::fromUtf8("nextPageButton"));
        nextPageButton->setGeometry(QRect(900, 740, 40, 25));
        slashLabel = new QLabel(bookTab);
        slashLabel->setObjectName(QString::fromUtf8("slashLabel"));
        slashLabel->setGeometry(QRect(420, 740, 10, 25));
        slashLabel->setAlignment(Qt::AlignCenter);
        totalPagesNumberLabel = new QLabel(bookTab);
        totalPagesNumberLabel->setObjectName(QString::fromUtf8("totalPagesNumberLabel"));
        totalPagesNumberLabel->setGeometry(QRect(430, 740, 50, 25));
        totalPagesNumberLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        currentPageNumberLabel = new QLabel(bookTab);
        currentPageNumberLabel->setObjectName(QString::fromUtf8("currentPageNumberLabel"));
        currentPageNumberLabel->setGeometry(QRect(370, 740, 50, 25));
        currentPageNumberLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        programTab->addTab(bookTab, QString());
        aboutTab = new QWidget();
        aboutTab->setObjectName(QString::fromUtf8("aboutTab"));
        aboutProgramLabel = new QLabel(aboutTab);
        aboutProgramLabel->setObjectName(QString::fromUtf8("aboutProgramLabel"));
        aboutProgramLabel->setGeometry(QRect(0, 0, 940, 741));
        aboutProgramLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        programTab->addTab(aboutTab, QString());
        chooseFileButton = new QPushButton(centralwidget);
        chooseFileButton->setObjectName(QString::fromUtf8("chooseFileButton"));
        chooseFileButton->setGeometry(QRect(120, 310, 140, 30));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        programTab->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        imageLabel->setText(QString());
        toStartMenuButton->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260 \320\263\320\273\320\260\320\262\320\275\321\203\321\216", nullptr));
        aboutProgramButton->setText(QCoreApplication::translate("MainWindow", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", nullptr));
        mainWindowLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        programTab->setTabText(programTab->indexOf(startTab), QCoreApplication::translate("MainWindow", "start", nullptr));
        bookLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        previousPageButton->setText(QCoreApplication::translate("MainWindow", "<", nullptr));
        nextPageButton->setText(QCoreApplication::translate("MainWindow", ">", nullptr));
        slashLabel->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        totalPagesNumberLabel->setText(QString());
        currentPageNumberLabel->setText(QString());
        programTab->setTabText(programTab->indexOf(bookTab), QCoreApplication::translate("MainWindow", "book", nullptr));
        aboutProgramLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        programTab->setTabText(programTab->indexOf(aboutTab), QCoreApplication::translate("MainWindow", "about", nullptr));
        chooseFileButton->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
