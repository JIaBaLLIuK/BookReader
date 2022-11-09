#include "../include/RecentOpenedFilesWindow.h"
#include "ui_recentopenedfileswindow.h"

RecentOpenedFilesWindow::RecentOpenedFilesWindow(QWidget *parent) : QDialog(parent), ui(new Ui::RecentOpenedFilesWindow)
{
    ui->setupUi(this);
    this->setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    this->setWindowTitle("Выберите файл");
    this->setWindowIcon(QIcon(":/img/program_icon.png"));
}

RecentOpenedFilesWindow::~RecentOpenedFilesWindow()
{
    delete ui;
}
