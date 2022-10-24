#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void on_aboutProgramButton_clicked();

private:
    void ConfigureMainWindow();
    void ConfigureTabWidget();
    void ConfigureAboutProgramLabel();

    Ui::MainWindow* ui;
    const int WINDOW_WIDTH = 1360;
    const int WINDOW_HEIGHT = 800;
};

#endif // MAIN_WINDOW_H
