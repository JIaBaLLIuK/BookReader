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
    QLabel *label;

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
        label = new QLabel(aboutTab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 0, 931, 731));
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setPointSize(14);
        label->setFont(font);
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label->setWordWrap(true);
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
        label->setText(QCoreApplication::translate("MainWindow", "\320\255\321\202\320\260 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\260 \320\277\321\200\320\265\320\264\320\275\320\260\320\267\320\275\320\260\321\207\320\265\320\275\320\260 \320\264\320\273\321\217 \321\207\321\202\320\265\320\275\320\270\321\217 \320\272\320\275\320\270\320\263 \321\201 \321\200\320\260\321\201\321\210\320\270\321\200\320\265\320\275\320\270\320\265\320\274 .fb2.  \320\224\320\273\321\217 \321\202\320\276\320\263\320\276, \321\207\321\202\320\276\320\261\321\213 \320\275\320\260\321\207\320\260\321\202\321\214 \321\207\320\270\321\202\320\260\321\202\321\214 \320\272\320\275\320\270\320\263\321\203, \320\222\320\260\320\274 \320\275\320\265\320\276\320\261\321\205\320\276\320\264\320\270\320\274\320\276:\n"
"1) \320\275\320\260\320\266\320\260\321\202\321\214 \320\272\320\275\320\276\320\277\320\272\321\203 \"\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\204\320\260\320\271\320\273\";\n"
"2) \320\262 \320\277\320\276\321\217\320\262\320\270\320\262"
                        "\321\210\320\265\320\274\321\201\321\217 \320\264\320\270\320\260\320\273\320\276\320\263\320\276\320\262\320\276\320\274 \320\276\320\272\320\275\320\265 \320\262\321\213\320\261\321\200\320\260\321\202\321\214 \320\270\320\275\321\202\320\265\321\200\320\265\321\201\321\203\321\216\321\211\321\203\321\216 \320\222\320\260\321\201 \320\272\320\275\320\270\320\263\321\203;\n"
"3) \320\275\320\260\320\266\320\260\321\202\321\214 \320\272\320\275\320\276\320\277\320\272\321\203 \"\320\276\321\202\320\272\321\200\321\213\321\202\321\214\".\n"
" \320\222 \320\277\321\200\320\260\320\262\320\276\320\271 \321\207\320\260\321\201\321\202\320\270 \321\215\320\272\321\200\320\260\320\275\320\260 \320\277\320\276\321\217\320\262\320\270\321\202\321\201\321\217 \321\202\320\265\320\272\321\201\321\202 \320\272\320\275\320\270\320\263\320\270. \320\224\320\273\321\217 \320\277\320\265\321\200\320\265\321\205\320\276\320\264\320\260 \320\275\320\260 \321\201\320\273\320\265\320\264\321\203\321\216\321\211\321\203\321\216 \321"
                        "\201\321\202\321\200\320\260\320\275\320\270\321\206\321\203 \320\275\320\265\320\276\320\261\321\205\320\276\320\264\320\270\320\274\320\276 \320\275\320\260\320\266\320\260\321\202\321\214 \320\272\320\275\320\276\320\277\320\272\321\203 \">\", \320\264\320\273\321\217 \320\277\320\265\321\200\320\265\321\205\320\276\320\264\320\260 \320\275\320\260 \320\277\321\200\320\265\320\264\321\213\320\264\321\203\321\211\321\203\321\216 \342\200\224 \320\272\320\275\320\276\320\277\320\272\321\203 \"<\". ", nullptr));
        programTab->setTabText(programTab->indexOf(aboutTab), QCoreApplication::translate("MainWindow", "Tab 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
