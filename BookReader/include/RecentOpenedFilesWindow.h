#ifndef RECENTOPENEDFILESWINDOW_H
#define RECENTOPENEDFILESWINDOW_H

#include <QDialog>

namespace Ui {
class RecentOpenedFilesWindow;
}

class RecentOpenedFilesWindow : public QDialog
{
    Q_OBJECT

public:
    explicit RecentOpenedFilesWindow(QWidget *parent = nullptr);
    ~RecentOpenedFilesWindow();

private:
    Ui::RecentOpenedFilesWindow *ui;
    const int WINDOW_WIDTH = 800;
    const int WINDOW_HEIGHT = 600;
};

#endif // RECENTOPENEDFILESWINDOW_H
