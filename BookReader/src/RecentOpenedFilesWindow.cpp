#include <QDir>

#include "../include/RecentOpenedFilesWindow.h"
#include "ui_recentopenedfileswindow.h"

RecentOpenedFilesWindow::RecentOpenedFilesWindow(QWidget* parent) : QDialog(parent), ui(new Ui::RecentOpenedFilesWindow)
{
    ui->setupUi(this);
    setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    setWindowTitle("Выберите файл");
    setWindowIcon(QIcon(":/img/program_icon.png"));
    SetRecentOpenedFiles();
    CreateRecentOpenedFilesButtons();
    CreateDeleteRecentOpenedFilesButtons();
}

RecentOpenedFilesWindow::~RecentOpenedFilesWindow()
{
    delete ui;
}

void RecentOpenedFilesWindow::RecentOpenedFileButtonClicked()
{
    QPushButton* btn = (QPushButton*)sender();
    bookFileName = btn->text();
    SetLastOpenedPageNumber(btn->text());
}

void RecentOpenedFilesWindow::DeleteRecentOpenedFileButtonClicked()
{
    QPushButton* btn = (QPushButton*)sender();
    int deleteButtonY = btn->y();
    for (int i = 0; i < recentOpenedFilesButtons.size(); i++)
    {
        if (deleteButtonY == recentOpenedFilesButtons[i]->y())
        {
            ChangeRecentOpenedFilesButtonsPosition(i);
            break;
        }
    }
}

void RecentOpenedFilesWindow::SetRecentOpenedFiles()
{
    QDir recentOpenedFilesDirectory("RecentOpenedFiles/");
    recentOpenedFiles = recentOpenedFilesDirectory.entryList();
    for (int i = 0; i < 2; i++)
    {
        recentOpenedFiles.removeAt(0);
    }
}

void RecentOpenedFilesWindow::CreateRecentOpenedFilesButtons()
{
    const int BUTTON_WIDTH = WINDOW_WIDTH - 50;
    const int BUTTON_HEIGHT = 30;
    for (int i = 0; i < recentOpenedFiles.size(); i++)
    {
        recentOpenedFilesButtons.append(new QPushButton(this));
        recentOpenedFilesButtons[i]->setText(recentOpenedFiles[i]);
        recentOpenedFilesButtons[i]->setFixedSize(BUTTON_WIDTH, BUTTON_HEIGHT);
        recentOpenedFilesButtons[i]->move(0, i * BUTTON_HEIGHT);
        connect(recentOpenedFilesButtons[i], SIGNAL(clicked()), this, SLOT(RecentOpenedFileButtonClicked()));
        connect(recentOpenedFilesButtons[i], SIGNAL(clicked()), this, SLOT(close()));
    }
}

void RecentOpenedFilesWindow::CreateDeleteRecentOpenedFilesButtons()
{
    const int BUTTON_WIDTH = 50;
    const int BUTTON_HEIGHT = 30;
    for (int i = 0; i < recentOpenedFiles.size(); i++)
    {
        deleteRecentOpenedFilesButtons.append(new QPushButton(this));
        deleteRecentOpenedFilesButtons[i]->setFixedSize(BUTTON_WIDTH, BUTTON_HEIGHT);
        deleteRecentOpenedFilesButtons[i]->move(WINDOW_WIDTH - 50, i * BUTTON_HEIGHT);

        QIcon deleteRecentOpenedFileButtonIcon(":/img/delete_file_icon.png");
        deleteRecentOpenedFilesButtons[i]->setIcon(deleteRecentOpenedFileButtonIcon);
        deleteRecentOpenedFilesButtons[i]->setIconSize(deleteRecentOpenedFilesButtons[i]->size());

        connect(deleteRecentOpenedFilesButtons[i], SIGNAL(clicked()), this, SLOT(DeleteRecentOpenedFileButtonClicked()));
    }
}

void RecentOpenedFilesWindow::SetLastOpenedPageNumber(QString fileName)
{
    QFile bookFile("RecentOpenedFiles/" + fileName);
    bookFile.open(QIODevice::Text | QIODevice::ReadOnly);
    QTextStream bookFileStream(&bookFile);
    QString bookFileText = bookFileStream.readAll();
    QString lastOpenedPage;
    for (int i = bookFileText.length() - 1; bookFileText[i] != '\n'; i--)
    {
        lastOpenedPage.append(bookFileText[i]);
    }

    std::reverse(lastOpenedPage.begin(), lastOpenedPage.end());
    lastOpenedPageNumber = lastOpenedPage.toInt();
}

void RecentOpenedFilesWindow::ChangeRecentOpenedFilesButtonsPosition(int i)
{
    QFile::remove("RecentOpenedFiles/" + recentOpenedFilesButtons[i]->text());

    recentOpenedFilesButtons[i]->close();
    deleteRecentOpenedFilesButtons[i]->close();

    if (i < recentOpenedFilesButtons.size() - 1)
    {
        for (int j = i + 1; j < recentOpenedFilesButtons.size(); j++)
        {
            recentOpenedFilesButtons[j]->move(0, 30 * (j - 1));
            deleteRecentOpenedFilesButtons[j]->move(WINDOW_WIDTH - 50, 30 * (j - 1));
        }
    }

    recentOpenedFiles.removeAt(i);
    recentOpenedFilesButtons.removeAt(i);
    deleteRecentOpenedFilesButtons.removeAt(i);
}

int RecentOpenedFilesWindow::GetLastOpenedPageNumber() const
{
    return lastOpenedPageNumber;
}

QString RecentOpenedFilesWindow::GetBookFileName() const
{
    return bookFileName;
}
