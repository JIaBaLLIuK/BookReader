/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
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
    QPushButton *findPageButton;
    QLineEdit *findPageLineEdit;
    QWidget *aboutTab;
    QLabel *aboutProgramLabel;
    QPushButton *chooseFileButton;
    QPushButton *chooseRecentOpenedFileButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1360, 800);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        imageLabel = new QLabel(centralwidget);
        imageLabel->setObjectName("imageLabel");
        imageLabel->setGeometry(QRect(0, 0, 375, 264));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(imageLabel->sizePolicy().hasHeightForWidth());
        imageLabel->setSizePolicy(sizePolicy);
        imageLabel->setScaledContents(false);
        toStartMenuButton = new QPushButton(centralwidget);
        toStartMenuButton->setObjectName("toStartMenuButton");
        toStartMenuButton->setGeometry(QRect(100, 270, 190, 30));
        aboutProgramButton = new QPushButton(centralwidget);
        aboutProgramButton->setObjectName("aboutProgramButton");
        aboutProgramButton->setGeometry(QRect(100, 390, 190, 30));
        programTab = new QTabWidget(centralwidget);
        programTab->setObjectName("programTab");
        programTab->setGeometry(QRect(400, 0, 950, 790));
        startTab = new QWidget();
        startTab->setObjectName("startTab");
        mainWindowLabel = new QLabel(startTab);
        mainWindowLabel->setObjectName("mainWindowLabel");
        mainWindowLabel->setGeometry(QRect(0, 0, 940, 281));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(mainWindowLabel->sizePolicy().hasHeightForWidth());
        mainWindowLabel->setSizePolicy(sizePolicy1);
        mainWindowLabel->setAlignment(Qt::AlignCenter);
        programTab->addTab(startTab, QString());
        bookTab = new QWidget();
        bookTab->setObjectName("bookTab");
        bookLabel = new QLabel(bookTab);
        bookLabel->setObjectName("bookLabel");
        bookLabel->setGeometry(QRect(0, 10, 940, 727));
        bookLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        previousPageButton = new QPushButton(bookTab);
        previousPageButton->setObjectName("previousPageButton");
        previousPageButton->setGeometry(QRect(5, 740, 40, 25));
        nextPageButton = new QPushButton(bookTab);
        nextPageButton->setObjectName("nextPageButton");
        nextPageButton->setGeometry(QRect(905, 740, 40, 25));
        slashLabel = new QLabel(bookTab);
        slashLabel->setObjectName("slashLabel");
        slashLabel->setGeometry(QRect(420, 730, 10, 25));
        slashLabel->setAlignment(Qt::AlignCenter);
        totalPagesNumberLabel = new QLabel(bookTab);
        totalPagesNumberLabel->setObjectName("totalPagesNumberLabel");
        totalPagesNumberLabel->setGeometry(QRect(430, 730, 50, 25));
        totalPagesNumberLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        currentPageNumberLabel = new QLabel(bookTab);
        currentPageNumberLabel->setObjectName("currentPageNumberLabel");
        currentPageNumberLabel->setGeometry(QRect(370, 730, 50, 25));
        currentPageNumberLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        findPageButton = new QPushButton(bookTab);
        findPageButton->setObjectName("findPageButton");
        findPageButton->setGeometry(QRect(375, 755, 25, 25));
        findPageLineEdit = new QLineEdit(bookTab);
        findPageLineEdit->setObjectName("findPageLineEdit");
        findPageLineEdit->setGeometry(QRect(400, 755, 70, 20));
        programTab->addTab(bookTab, QString());
        aboutTab = new QWidget();
        aboutTab->setObjectName("aboutTab");
        aboutProgramLabel = new QLabel(aboutTab);
        aboutProgramLabel->setObjectName("aboutProgramLabel");
        aboutProgramLabel->setGeometry(QRect(0, 0, 940, 741));
        aboutProgramLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        programTab->addTab(aboutTab, QString());
        chooseFileButton = new QPushButton(centralwidget);
        chooseFileButton->setObjectName("chooseFileButton");
        chooseFileButton->setGeometry(QRect(100, 310, 190, 30));
        chooseRecentOpenedFileButton = new QPushButton(centralwidget);
        chooseRecentOpenedFileButton->setObjectName("chooseRecentOpenedFileButton");
        chooseRecentOpenedFileButton->setGeometry(QRect(100, 350, 190, 30));
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
        previousPageButton->setText(QCoreApplication::translate("MainWindow", "<-", nullptr));
        nextPageButton->setText(QCoreApplication::translate("MainWindow", "->", nullptr));
        slashLabel->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        totalPagesNumberLabel->setText(QString());
        currentPageNumberLabel->setText(QString());
        findPageButton->setText(QString());
        programTab->setTabText(programTab->indexOf(bookTab), QCoreApplication::translate("MainWindow", "book", nullptr));
        aboutProgramLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        programTab->setTabText(programTab->indexOf(aboutTab), QCoreApplication::translate("MainWindow", "about", nullptr));
        chooseFileButton->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        chooseRecentOpenedFileButton->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\200\320\260\320\275\320\265\320\265 \320\276\321\202\320\272\321\200\321\213\321\202\321\213\320\271 \321\204\320\260\320\271\320\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
