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

private:
    Ui::MainWindow* ui;
    const int WINDOW_WIDTH = 1366;
    const int WINDOW_HEIGHT = 768;
    const QIcon* windowIcon = new QIcon(":/img/book_icon.png");
};

#endif // MAINWINDOW_H
