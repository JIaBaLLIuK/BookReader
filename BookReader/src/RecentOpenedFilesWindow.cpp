#include <QDir>

#include "../include/RecentOpenedFilesWindow.h"
#include "../include/WidgetStyle.h"
#include "ui_recentopenedfileswindow.h"

RecentOpenedFilesWindow::RecentOpenedFilesWindow(QWidget* parent) : QDialog(parent), ui(new Ui::RecentOpenedFilesWindow)
{
    ui->setupUi(this);
    ConfigureDialogWindow();
    SetRecentOpenedFiles();
    CreateRecentOpenedFilesButtons();
    CreateDeleteRecentOpenedFilesButtons();
}

RecentOpenedFilesWindow::~RecentOpenedFilesWindow()
{
    delete ui;
}

Book RecentOpenedFilesWindow::GetBook() const
{
    return book;
}

void RecentOpenedFilesWindow::RecentOpenedFileButtonClicked()
{
    QPushButton* btn = (QPushButton*)sender();
    book.SetPathToBookFile("RecentOpenedFiles/" + (btn->text()).append(".fb2"));  // получить имя выбранной книги
    SetLastOpenedPageNumber((btn->text()).append(".fb2"));  // получить последнюю страницы выбранной книги
}

void RecentOpenedFilesWindow::DeleteRecentOpenedFileButtonClicked()
{
    QPushButton* btn = (QPushButton*)sender();
    int deleteButtonY = btn->y();  // получить y координату выбранной кнопки удалить (она равна y координате кнопки с книгой)
    for (int i = 0; i < recentOpenedFilesButtons.size(); i++)
    {
        if (deleteButtonY == recentOpenedFilesButtons[i]->y())
        {
            ChangeRecentOpenedFilesButtonsPosition(i);  // если найден номер кнопки с названием книги, который необходимо удалить
            break;
        }
    }
}

void RecentOpenedFilesWindow::ConfigureDialogWindow()
{
    setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    setWindowTitle("Ранее открытые файлы");
    setWindowIcon(QIcon(":/img/program_icon.png"));
    setWindowModality(Qt::ApplicationModal);
}

void RecentOpenedFilesWindow::SetRecentOpenedFiles()
{
    QDir recentOpenedFilesDirectory("RecentOpenedFiles/");

    recentOpenedFiles = recentOpenedFilesDirectory.entryList(QDir::NoDotAndDotDot | QDir::AllEntries);  // получить список всех ранее открытых файлов из директории
}

void RecentOpenedFilesWindow::CreateRecentOpenedFilesButtons()
{
    const int BUTTON_WIDTH = WINDOW_WIDTH;  // длина кнопки с названием книги
    const int BUTTON_HEIGHT = 30;  // высота кнопки с названием книги
    for (int i = 0; i < recentOpenedFiles.size(); i++)  // цикл по всем ранее открытым книгам
    {
        recentOpenedFilesButtons.append(new QPushButton(this));  // добавление кнопки в список
        recentOpenedFilesButtons[i]->setText(recentOpenedFiles[i].remove(recentOpenedFiles[i].size() - 4, 4));  // текст кнопки - имя файла без расширения
        recentOpenedFilesButtons[i]->setFixedSize(BUTTON_WIDTH, BUTTON_HEIGHT);  // установить размеры кнопки
        recentOpenedFilesButtons[i]->move(0, i * BUTTON_HEIGHT);  // задать координаты кнопки
        recentOpenedFilesButtons[i]->setStyleSheet(WidgetStyle::GetRecentOpenedFilesButtonsStyle());  // установка стилей для кнопки
        // обработка нажатия кнопки
        connect(recentOpenedFilesButtons[i], SIGNAL(clicked()), this, SLOT(RecentOpenedFileButtonClicked()));
        connect(recentOpenedFilesButtons[i], SIGNAL(clicked()), this, SLOT(close()));
    }
}

void RecentOpenedFilesWindow::CreateDeleteRecentOpenedFilesButtons()
{
    const int BUTTON_WIDTH = 50;  // длина кнопки удаления
    const int BUTTON_HEIGHT = 30;  // высота кнопки удаления
    for (int i = 0; i < recentOpenedFiles.size(); i++)  // цикл по всем ранее открытым книгам
    {
        deleteRecentOpenedFilesButtons.append(new QPushButton(this));  // добавление кнопки в список
        deleteRecentOpenedFilesButtons[i]->setFixedSize(BUTTON_WIDTH, BUTTON_HEIGHT);  // установить размеры кнопки
        deleteRecentOpenedFilesButtons[i]->move(WINDOW_WIDTH - 50, i * BUTTON_HEIGHT);  // задать координаты кнопки
        deleteRecentOpenedFilesButtons[i]->setStyleSheet(WidgetStyle::GetDeleteRecentOpenedFilesButtonsStyle());  // установка стилей для кнопки
        // создание иконки кнопки
        QIcon deleteRecentOpenedFileButtonIcon(":/img/delete_file_icon.png");
        deleteRecentOpenedFilesButtons[i]->setIcon(deleteRecentOpenedFileButtonIcon);
        deleteRecentOpenedFilesButtons[i]->setIconSize(deleteRecentOpenedFilesButtons[i]->size());
        // обработка нажатия кнопки
        connect(deleteRecentOpenedFilesButtons[i], SIGNAL(clicked()), this, SLOT(DeleteRecentOpenedFileButtonClicked()));
    }
}

void RecentOpenedFilesWindow::SetLastOpenedPageNumber(QString fileName)
{
    QFile bookFile("RecentOpenedFiles/" + fileName);
    bookFile.open(QIODevice::Text | QIODevice::ReadOnly);  // открытие выбранного файла
    QTextStream bookFileStream(&bookFile);
    QString bookFileText = bookFileStream.readAll();  // получить весь текст файла
    QString lastOpenedPage;
    for (int i = bookFileText.length() - 1; bookFileText[i] != '\n'; i--)  // цикл до конца последней строки файла
    {
        lastOpenedPage.append(bookFileText[i]);  // добавить символ с конца файла (в конец файла добавлялись номера страниц)
    }

    std::reverse(lastOpenedPage.begin(), lastOpenedPage.end());  // реверс строки
    book.SetCurrentPageNumber(lastOpenedPage.toInt());  // перевод номера последней открытой страницы в int
}

void RecentOpenedFilesWindow::ChangeRecentOpenedFilesButtonsPosition(int i)
{
    QFile::remove("RecentOpenedFiles/" + (recentOpenedFilesButtons[i]->text()).append(".fb2"));  // удаление выбранного файла из директории
    // закрытие кнопок, соответствующих выбранному файлу
    recentOpenedFilesButtons[i]->close();
    deleteRecentOpenedFilesButtons[i]->close();
    // смещение кнопок, если нажатая кнопка не последняя
    if (i < recentOpenedFilesButtons.size() - 1)
    {
        for (int j = i + 1; j < recentOpenedFilesButtons.size(); j++)
        {
            recentOpenedFilesButtons[j]->move(0, 30 * (j - 1)); // сместить вверх все кнопки ниже той, которая была удалена
            deleteRecentOpenedFilesButtons[j]->move(WINDOW_WIDTH - 50, 30 * (j - 1));
        }
    }
    // удаление выбранного файла и кнопок из списков
    recentOpenedFiles.removeAt(i);
    recentOpenedFilesButtons.removeAt(i);
    deleteRecentOpenedFilesButtons.removeAt(i);
}
