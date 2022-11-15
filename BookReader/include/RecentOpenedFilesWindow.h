#ifndef RECENT_OPENED_FILES_WINDOW_H
#define RECENT_OPENED_FILES_WINDOW_H

#include <QDialog>
#include <QPushButton>

namespace Ui { class RecentOpenedFilesWindow; }
// класс для работы с окном со списком ранее открытых файлов
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
    void ConfigureDialogWindow();
    void SetRecentOpenedFiles();
    void SetLastOpenedPageNumber(QString);
    void CreateRecentOpenedFilesButtons();
    void CreateDeleteRecentOpenedFilesButtons();    
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

#endif
