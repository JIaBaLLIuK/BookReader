#ifndef RECENTOPENEDFILESWINDOW_H
#define RECENTOPENEDFILESWINDOW_H

#include <QDialog>
#include <QPushButton>

namespace Ui { class RecentOpenedFilesWindow; }

class RecentOpenedFilesWindow : public QDialog
{
    Q_OBJECT

public:
    explicit RecentOpenedFilesWindow(QWidget *parent = nullptr);
    ~RecentOpenedFilesWindow();
    int GetLastOpenedPageNumber() const;
    QString GetBookFileName() const;

private slots:
    void RecentOpenedFileButtonClicked();
    void DeleteRecentOpenedFileButtonClicked();

private:
    void SetRecentOpenedFiles();
    void CreateRecentOpenedFilesButtons();
    void CreateDeleteRecentOpenedFilesButtons();
    void SetLastOpenedPageNumber(QString);
    void ChangeRecentOpenedFilesButtonsPosition(int);

    Ui::RecentOpenedFilesWindow *ui;
    const int WINDOW_WIDTH = 800;
    const int WINDOW_HEIGHT = 600;
    QList<QString> recentOpenedFiles;
    QList<QPushButton*> recentOpenedFilesButtons;
    QList<QPushButton*> deleteRecentOpenedFilesButtons;
    int lastOpenedPageNumber;
    QString bookFileName;
};

#endif // RECENTOPENEDFILESWINDOW_H
