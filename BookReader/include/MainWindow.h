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

private:
    void ConfigureMainWindow();
    void ConfigureTabWidget();
    void ConfigureStartLabel();
    void ConfigureAboutProgramLabel();
    void ConfigurePageNumberLabels();

    Ui::MainWindow* ui;
    const int WINDOW_WIDTH = 1360;
    const int WINDOW_HEIGHT = 800;
    Book book;
};

#endif // MAIN_WINDOW_H
