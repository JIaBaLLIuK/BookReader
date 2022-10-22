#include "../include/MainWindow.h"
#include "../include/ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    MainWindow::setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    MainWindow::setWindowTitle("Book reader");
    MainWindow::setWindowIcon(*windowIcon);
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

