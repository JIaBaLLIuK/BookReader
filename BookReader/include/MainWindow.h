#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>

#include "Book.h"

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void on_aboutProgramButton_clicked();
    void on_toStartMenuButton_clicked();
    void on_chooseFileButton_clicked();
    void on_nextPageButton_clicked();
    void on_previousPageButton_clicked();
    void on_findPageButton_clicked();
    void on_chooseRecentOpenedFileButton_clicked();

private:
    void ConfigureMainWindow();
    void ConfigureTabWidget();
    void ConfigureMainWindowLabel();
    void ConfigureAboutProgramLabel();
    void ConfigureBookTab();
    void ConfigurePageButtons();
    void SetBookLabelText(QList<QString>, int);
    void FindPage();

    Ui::MainWindow* ui;
    Book* book;
    const int WINDOW_WIDTH = 1360;
    const int WINDOW_HEIGHT = 800;
};

#endif // MAIN_WINDOW_H
