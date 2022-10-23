#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
    Ui::MainWindow* ui;
    const int WINDOW_WIDTH = 1360;
    const int WINDOW_HEIGHT = 800;
};

#endif // MAINWINDOW_H
