#include <QFileDialog>
#include <QMessageBox>

#include "../include/MainWindow.h"
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
}

void MainWindow::on_aboutProgramButton_clicked()
{
     ui->programTab->setCurrentIndex(2);
}

void MainWindow::on_toStartMenuButton_clicked()
{
    ui->programTab->setCurrentIndex(0);
}

void MainWindow::on_chooseFileButton_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, "Выберите файл", "C:", "Book file (*.fb2)");
    if (!path.endsWith(".fb2"))
    {
        QMessageBox::warning(this, "", "Вы не выбрали .fb2 файл!");
    }
    else
    {
        book = new Book(path);
        book->ParseBookFile();
        ConfigureBookTab();
        SetBookLabelText(book->GetBookText(), 1);
    }
}

void MainWindow::on_nextPageButton_clicked()
{
    int currentPageNumber = book->GetCurrentPageNumber() + 1;
    if (currentPageNumber > book->GetTotalPagesNumber())
    {
        QMessageBox::information(this, "", "Вы дочитали до конца!");
        return;
    }

    book->SetCurrentPageNumber(currentPageNumber);
    ui->currentPageNumberLabel->setText(QString::number(currentPageNumber));
    SetBookLabelText(book->GetBookText(), currentPageNumber);
}

void MainWindow::on_previousPageButton_clicked()
{
    int currentPageNumber = book->GetCurrentPageNumber() - 1;
    if (currentPageNumber <= 0)
    {
        QMessageBox::information(this, "", "Вы не можете вернуться назад!");
        return;
    }

    book->SetCurrentPageNumber(currentPageNumber);
    ui->currentPageNumberLabel->setText(QString::number(currentPageNumber));
    SetBookLabelText(book->GetBookText(), currentPageNumber);
}

void MainWindow::ConfigureMainWindow()
{
    this->setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    this->setWindowTitle("Book Reader");
    this->setWindowIcon(QIcon(":/img/program_icon.png"));
    QPixmap labelPicture(":/img/book_image.jpg");
    labelPicture = labelPicture.scaled(labelPicture.width() * 0.8f, labelPicture.height() * 0.8f);
    ui->imageLabel->setFixedSize(labelPicture.size());
    ui->imageLabel->setPixmap(labelPicture);
}

void MainWindow::ConfigureTabWidget()
{
    ui->programTab->setStyleSheet(WidgetStyle::GetTabStyle());
    ui->programTab->setCurrentIndex(0);
}

void MainWindow::ConfigureMainWindowLabel()
{
    ui->mainWindowLabel->setStyleSheet(WidgetStyle::GetMainWindowLabelStyle());
    ui->mainWindowLabel->setText("Book   Reader");
}

void MainWindow::ConfigureAboutProgramLabel()
{
    ui->aboutProgramLabel->setStyleSheet(WidgetStyle::GetAboutPogramLabelStyle());
    ui->aboutProgramLabel->setText("    Эта программа предназначена для чтения электронных книг, имеющих расширение .fb2. "
                                   "Для того, чтобы начать читать, необходимо:\n"
                                   "1) нажать на кнопку \"Выбрать файл\" в левой части окна;\n"
                                   "2) в открывшемся диалоговом окне выбрать файл, имеющий расширений .fb2;\n"
                                   "3) выбрав нужный файл, нажать кнопку \"Открыть\".\n"
                                   "После открытия файла для перехода на следующую страницу необходимо нажать на кнопку \"->\" в нижней части экрана, "
                                   "для перехода на предыдущую страницу — нажать на кнопку \"<-\".");
}

void MainWindow::ConfigureBookTab()
{
    ui->programTab->setCurrentIndex(1);
    ui->bookLabel->setStyleSheet(WidgetStyle::GetBookLabelStyle());
    ui->totalPagesNumberLabel->setStyleSheet(WidgetStyle::GetPageNumberLabelsStyle());
    ui->totalPagesNumberLabel->setText(QString::number(book->GetTotalPagesNumber()));
    ui->currentPageNumberLabel->setStyleSheet(WidgetStyle::GetPageNumberLabelsStyle());
    ui->currentPageNumberLabel->setText(QString::number(book->GetCurrentPageNumber()));   
    ui->slashLabel->setStyleSheet("font-size: 18px;");
}

void MainWindow::SetBookLabelText(QList<QString> bookText, int currentPageNumber)
{
    QString pageText;
    int maxStringAmount = book->GetMaxStringAmount();
    for (int i = 0; i < maxStringAmount; i++)
    {
        pageText.append(bookText[(currentPageNumber - 1) * maxStringAmount + i]);
    }

    ui->bookLabel->setText(pageText);
}
