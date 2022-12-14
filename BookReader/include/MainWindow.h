#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>

#include "Book.h"

namespace Ui { class MainWindow; }
// класс для работы с главным окном
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
    void SetBookLabelText(List<QString>, int);
    void AppendPageNumberToBookFile(int);

    Ui::MainWindow* ui;
    Book book;
    const int WINDOW_WIDTH = 1360;
    const int WINDOW_HEIGHT = 800;
};

#endif
