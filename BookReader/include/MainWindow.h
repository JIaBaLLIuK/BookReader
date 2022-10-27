#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>

#include "Book.h"

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void on_aboutProgramButton_clicked();
    void on_toStartMenuButton_clicked();
    void on_chooseFileButton_clicked();

    void on_nextPageButton_clicked();

private:
    void ConfigureMainWindow();
    void ConfigureTabWidget();
    void ConfigureMainWindowLabel();
    void ConfigureAboutProgramLabel();
    void ConfigurePageNumberLabels();
    void ConfigureBookTab();
    void SetBookLabelText(QString);

    Ui::MainWindow* ui;
    Book* book;
    const int WINDOW_WIDTH = 1360;
    const int WINDOW_HEIGHT = 800;
};

#endif // MAIN_WINDOW_H
