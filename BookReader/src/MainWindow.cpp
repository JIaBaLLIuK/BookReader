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
    ConfigurePageNumberLabels();


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
    if (path.isEmpty())
    {
        QMessageBox::warning(this, "Ошибка!", "Вы не выбрали файл!");
    }
    else
    {
        book = new Book(path);
        book->ParseBookFile();
        QString bookText = book->GetBookText();
        ConfigureBookTab();
        SetBookLabelText(bookText);

    }
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
                                   "После открытия файла для перехода на следующую страницу необходимо нажать на кнопку \">\" в нижней части экрана, "
                                   "для перехода на предыдущую страницу — нажать на кнопку \"<\".");
}

void MainWindow::ConfigurePageNumberLabels()
{
    ui->currentPageNumberLabel->setStyleSheet(WidgetStyle::GetPageNumberLabelsStyle());
    ui->slashLabel->setStyleSheet(WidgetStyle::GetPageNumberLabelsStyle());
    ui->totalPagesNumberLabel->setStyleSheet(WidgetStyle::GetPageNumberLabelsStyle());
}

void MainWindow::ConfigureBookTab()
{
    ui->programTab->setCurrentIndex(1);
    ui->bookLabel->setStyleSheet(WidgetStyle::GetBookLabelStyle());
    ui->totalPagesNumberLabel->setText(QString::number(book->GetTotalPagesNumber()));
    ui->currentPageNumberLabel->setText(QString::number(book->GetCurrentPageNumber()));
}

void MainWindow::SetBookLabelText(QString bookText)
{
    QString pageText;
    for (int i = 0; i < book->GetPageSize(); i++)
    {
        pageText.append(bookText[(book->GetCurrentPageNumber() - 1) * book->GetPageSize() + i]);
    }

    ui->bookLabel->setText(pageText);
}

void MainWindow::on_nextPageButton_clicked()
{
    book->SetCurrentPageNumber(book->GetCurrentPageNumber() + 1);
    ui->currentPageNumberLabel->setText(QString::number(book->GetCurrentPageNumber()));
    SetBookLabelText(book->GetBookText());
}

