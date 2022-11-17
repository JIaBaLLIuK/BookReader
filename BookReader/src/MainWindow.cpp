#include <QFileDialog>
#include <QMessageBox>
#include <QFile>

#include "../include/MainWindow.h"
#include "../include/RecentOpenedFilesWindow.h"
#include "../include/WidgetStyle.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ConfigureMainWindow();
    ConfigureTabWidget();
    ConfigureMainWindowLabel();
    ConfigureAboutProgramLabel();
}

MainWindow::~MainWindow()
{
    delete ui;
    // delete book;
}

void MainWindow::on_aboutProgramButton_clicked()
{
     ui->programTab->setCurrentIndex(2);  // открыть меню с информацией
}

void MainWindow::on_toStartMenuButton_clicked()
{
    ui->programTab->setCurrentIndex(0);  // открыть стартовое меню
}

void MainWindow::on_chooseFileButton_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, "Выберите файл", "C:", "Book file (*.fb2)");  // открыть диалоговое окно для выбора fb2 файла
    if (!path.endsWith(".fb2"))
    {
       QMessageBox::warning(this, "", "Вы не выбрали файл!");  // если файл не выбран
    }
    else
    {
        book.SetPathToBookFile(path);  // задать путь до книги
        book.ResetBookText();  // обнулить текст книги
        book.ParseBookFile();  // считать текст книги
        book.SetCurrentPageNumber(1);  // задать номер текущей страницы
        ConfigureBookTab();  // настроить стили меню с книгой
        SetBookLabelText(book.GetBookText(), 1);  // отобразить текст страницы на окне
        QString bookFileName = (QFileInfo(QFile(path).fileName())).fileName();
        if (!QFile::exists("RecentOpenedFiles/" + bookFileName))
        {
            QFile::copy(path, "RecentOpenedFiles/" + bookFileName);  // создать копию файла для возможности открыть его на ранее открытой странице
        }

       AppendPageNumberToBookFile(book.GetCurrentPageNumber());  // добавить номер страницы в конец файла книги
    }
}

void MainWindow::on_nextPageButton_clicked()
{
    int currentPageNumber = book.GetCurrentPageNumber() + 1;
    if (currentPageNumber > book.GetTotalPagesNumber())
    {
        QMessageBox::information(this, "", "Вы дочитали до конца!");  // если последняя страница открыта
        return;
    }

    book.SetCurrentPageNumber(currentPageNumber);  // задать новый номер страницы
    ui->currentPageNumberLabel->setText(QString::number(currentPageNumber));  // отобразить номер текущей страницы
    SetBookLabelText(book.GetBookText(), currentPageNumber);  // отобразить текст новой страницы
    AppendPageNumberToBookFile(book.GetCurrentPageNumber());  // добавить номер страницы в конец файла книги
}

void MainWindow::on_previousPageButton_clicked()
{
    int currentPageNumber = book.GetCurrentPageNumber() - 1;
    if (currentPageNumber == 0)
    {
        QMessageBox::information(this, "", "Вы не можете вернуться назад!");  // если первая страницы открыта
        return;
    }

    book.SetCurrentPageNumber(currentPageNumber);  // задать новый номер страницы
    ui->currentPageNumberLabel->setText(QString::number(currentPageNumber));  // отобразить номер текущей страницы
    SetBookLabelText(book.GetBookText(), currentPageNumber);  // отобразить текст новой страницы
    AppendPageNumberToBookFile(book.GetCurrentPageNumber());  // добавить номер страницы в конец файла книги
}

void MainWindow::on_findPageButton_clicked()
{
    int pageNumber = ui->findPageLineEdit->text().toInt();
    if (pageNumber < 1 || pageNumber > book.GetTotalPagesNumber())
    {
        QMessageBox::warning(this, "", "Вы ввели неверное значение!");  // если введено неверное значение для поиска
        ui->findPageLineEdit->setText("");
        return;
    }

    ui->findPageLineEdit->setText("");  // обнулить текст после ввода
    book.SetCurrentPageNumber(pageNumber);  // задать новый номер страницы
    ui->currentPageNumberLabel->setText(QString::number(pageNumber));  // отобразить номер текущей страницы
    SetBookLabelText(book.GetBookText(), pageNumber);  // отобразить текст новой страницы
    AppendPageNumberToBookFile(pageNumber);  // добавить номер страницы в конец файла книги
}

void MainWindow::on_chooseRecentOpenedFileButton_clicked()
{
    ui->programTab->setCurrentIndex(0);
    QDir recentOpenedFilesDirectory("RecentOpenedFiles/");
    if (recentOpenedFilesDirectory.isEmpty())
    {
        QMessageBox::warning(this, "", "Ранее открытые файлы отсутсвуют!");  // если ранее не был открыт ни один файл
        return;
    }

    RecentOpenedFilesWindow window(this);
    window.show();
    window.exec();

    book = window.GetBook();
    if ((book.GetPathToBookFile()).isEmpty())
    {
        QMessageBox::warning(this, "", "Вы не выбрали файл!");  // если файл не выбран
        return;
    }

    book.ResetBookText();  // обнулить текст книги
    book.ParseBookFile();  // считать текст книги
    ConfigureBookTab();  // настроить стили меню с книгой
    SetBookLabelText(book.GetBookText(), book.GetCurrentPageNumber());  // отобразить текст новой страницы
}

void MainWindow::ConfigureMainWindow()
{
    setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);  //  задать размер окна
    setWindowTitle("Book Reader");  // задать заголовок окна
    setWindowIcon(QIcon(":/img/program_icon.png"));  // задать икноку окна
    QPixmap labelPicture(":/img/book_image.jpg");  // отобразить картинку на окне
    labelPicture = labelPicture.scaled(labelPicture.width() * 0.8f, labelPicture.height() * 0.8f);
    ui->imageLabel->setFixedSize(labelPicture.size());
    ui->imageLabel->setPixmap(labelPicture);
    ui->toStartMenuButton->setStyleSheet(WidgetStyle::GetMainWindowButtonsStyle());
    ui->chooseFileButton->setStyleSheet(WidgetStyle::GetMainWindowButtonsStyle());
    ui->chooseRecentOpenedFileButton->setStyleSheet(WidgetStyle::GetMainWindowButtonsStyle());
    ui->aboutProgramButton->setStyleSheet(WidgetStyle::GetMainWindowButtonsStyle());
}

void MainWindow::ConfigureTabWidget()
{
    ui->programTab->setStyleSheet(WidgetStyle::GetTabStyle());  // задать стили для QTabWidget
    ui->programTab->setCurrentIndex(0);
}

void MainWindow::ConfigureMainWindowLabel()
{
    ui->mainWindowLabel->setStyleSheet(WidgetStyle::GetMainWindowLabelStyle());  // задать стили для стартового окна
    ui->mainWindowLabel->setText("Book   Reader");  // задать текст на стартовом окне
}

void MainWindow::ConfigureAboutProgramLabel()
{
    ui->aboutProgramLabel->setStyleSheet(WidgetStyle::GetAboutPogramLabelStyle());  // задать стили для меню с информацией
    ui->aboutProgramLabel->setText("    Эта программа предназначена для чтения электронных книг, имеющих расширение .fb2."  // устноавить текст информации
                                   " Для того, чтобы начать читать, необходимо:\n"
                                   "1) нажать на кнопку \"Выбрать файл\" в левой части окна;\n"
                                   "2) в открывшемся диалоговом окне выбрать файл, имеющий расширение .fb2;\n"
                                   "3) выбрав нужный файл, нажать кнопку \"Открыть\".\n"
                                   "После открытия файла для перехода на следующую страницу необходимо нажать на кнопку \"->\" в нижней части экрана, "
                                   "для перехода на предыдущую страницу — нажать на кнопку \"<-\".\n"
                                   "    Если необходимо перейти на конкретную страницу, то необходимо в поле снизу ввести номер страницы и "
                                   "нажать на кнопку с изображенной на ней лупой.\n"
                                   "    При нажатии на кнопку \"Выбрать ранее открытый файл\" можно открыть один из ранее открытых файлов на"
                                   "последней открытой странице либо удалить этот файл.");
}

void MainWindow::ConfigureBookTab()
{   // задать стили для меню с книгой
    ui->programTab->setCurrentIndex(1);
    ui->bookLabel->setStyleSheet(WidgetStyle::GetBookLabelStyle());
    // задать стили для части окна с номерами текущего и обшего числа страниц
    ui->totalPagesNumberLabel->setStyleSheet(WidgetStyle::GetPageNumberLabelsStyle());
    ui->totalPagesNumberLabel->setText(QString::number(book.GetTotalPagesNumber()));
    ui->currentPageNumberLabel->setStyleSheet(WidgetStyle::GetPageNumberLabelsStyle());
    ui->currentPageNumberLabel->setText(QString::number(book.GetCurrentPageNumber()));
    ui->slashLabel->setStyleSheet("font-size: 18px;");
    // задать стили для меню поиска страницы
    QIcon findPageButtonIcon(":/img/magnifier_icon.png");
    ui->findPageButton->setIcon(findPageButtonIcon);
    ui->findPageButton->setIconSize(ui->findPageButton->size());
    ui->findPageButton->setStyleSheet(WidgetStyle::GetFindPageButtonStyle());
    ui->findPageLineEdit->setStyleSheet(WidgetStyle::GetFindPageLineEditStyle());
}

void MainWindow::SetBookLabelText(QList<QString> bookText, int currentPageNumber)
{
    QString pageText;
    int maxStringAmount = book.GetMaxStringAmount();
    for (int i = 0; i < maxStringAmount; i++)  // пока не будет добавлено максимальное число строк к тексту страницы
    {
        int index = (currentPageNumber - 1) * maxStringAmount + i;
        if (index > bookText.size() - 1)  // если на последней странице строк меньше, чем из максимальное количество
        {
            break;
        }

        pageText.append(bookText[index]);  // добавить строку к тексту страницы
    }

    ui->bookLabel->setText(pageText);  // отобразить текст страницы
}

void MainWindow::AppendPageNumberToBookFile(int pageNumber)
{
    QString bookFileName = (QFileInfo(QFile(book.GetPathToBookFile()).fileName())).fileName();  // получить имя файла
    QFile bookFile("RecentOpenedFiles/" + bookFileName);
    bookFile.open(QIODevice::Text | QIODevice::Append);  // открыть файл
    QTextStream bookFileStream(&bookFile);
    bookFileStream << '\n' << pageNumber;  // добавить номер страницы в файл
}
