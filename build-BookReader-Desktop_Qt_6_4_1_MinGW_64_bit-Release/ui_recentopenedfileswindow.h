/********************************************************************************
** Form generated from reading UI file 'recentopenedfileswindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECENTOPENEDFILESWINDOW_H
#define UI_RECENTOPENEDFILESWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_RecentOpenedFilesWindow
{
public:

    void setupUi(QDialog *RecentOpenedFilesWindow)
    {
        if (RecentOpenedFilesWindow->objectName().isEmpty())
            RecentOpenedFilesWindow->setObjectName("RecentOpenedFilesWindow");
        RecentOpenedFilesWindow->resize(800, 600);

        retranslateUi(RecentOpenedFilesWindow);

        QMetaObject::connectSlotsByName(RecentOpenedFilesWindow);
    } // setupUi

    void retranslateUi(QDialog *RecentOpenedFilesWindow)
    {
        RecentOpenedFilesWindow->setWindowTitle(QCoreApplication::translate("RecentOpenedFilesWindow", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RecentOpenedFilesWindow: public Ui_RecentOpenedFilesWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECENTOPENEDFILESWINDOW_H
