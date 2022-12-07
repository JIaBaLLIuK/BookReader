#include <QFile>
#include <QMessageBox>

#include "../include/Book.h"
#include "../include/Exception.h"

void Book::SetPathToBookFile(QString _pathToBookFile)
{
    if (_pathToBookFile.isEmpty())
    {
        throw ArgumentNullException("Файл не выбран!");
    }

    pathToBookFile = _pathToBookFile;
}

QString Book::GetPathToBookFile() const
{
    return pathToBookFile;
}

void Book::ParseBookFile()
{
    QFile bookFile(pathToBookFile);
    if (!bookFile.open(QIODevice::ReadOnly | QIODevice::Text))  // попытка открыть файл
    {
        QMessageBox::critical(nullptr, "", "Что-то пошло не так. Файл невозможно открыть!");
        return;
    }

    QXmlStreamReader xmlFile(&bookFile);
    while (!xmlFile.atEnd())
    {
        xmlFile.readNextStartElement();
        if (xmlFile.isEndElement())  // перейти на следующую итерацию, если следующий считанный элемент является закрывающим тегом
        {
            continue;
        }

        QString tag = xmlFile.name().toString();
        if (tag == "body")
        {
            SetBookText(xmlFile);  // если найден тег "body" задать текст книги
            break;
        }
    }

    bookFile.close();
}

void Book::SetBookText(QXmlStreamReader& xmlFile)
{
    QString tag;
    while (tag != "body")  // цикл до тех пор, пока не найден конец тега "body"
    {
        xmlFile.readNextStartElement();  // считать следующий тег
        tag = xmlFile.name().toString();  // считанный тег
        if (xmlFile.isEndElement())  // перейти на следующую итерацию, если следующий считанный элемент является закрывающим тегом
        {
            continue;
        }

        while (tag != "p" && tag != "title")  // цикл до тех пор, пока не найден тег "P" (абзац) или тег "title" (заголовок)
        {
            xmlFile.readNextStartElement();
            tag = xmlFile.name().toString();
        }

        if (tag == "p")
        {
            SetParagraphStyle(xmlFile.readElementText(QXmlStreamReader::ReadElementTextBehaviour::IncludeChildElements));  // если тег "p" - задать стиль текста абзаца
        }
        else
        {
             SetTitleStyle(xmlFile);  // иначе задать стиль текста заголовка
        }
    }

    SetTotalPagesNumber();  // установить общее число страниц книги
}

void Book::SetTotalPagesNumber()
{   // метод установки общего числа страниц книги
    if (bookText.GetSize() % MAX_STRING_AMOUNT == 0)
    {
        totalPagesNumber = bookText.GetSize() / MAX_STRING_AMOUNT;
    }
    else
    {
        totalPagesNumber = bookText.GetSize() / MAX_STRING_AMOUNT + 1;
    }
}

List<QString> Book::GetBookText() const
{
    return bookText;
}

void Book::SetTitleStyle(QXmlStreamReader& xmlFile)
{
    QString tag;
    while (tag != "title")  // цикл до тех пор, пока не найден конец тега "title"
    {
        xmlFile.readNextStartElement();
        tag = xmlFile.name().toString();
        if (xmlFile.isEndElement())  // перейти на следующую итерацию, если следующий считанный элемент является закрывающим тегом
        {
            continue;
        }

        while (tag != "p")  // цикл до тех пор, пока не найден текста тега "title"
        {
            xmlFile.readNextStartElement();
            tag = xmlFile.name().toString();
        }
        // задать элементу тега "title" жирный шрифт, выравненный по центру
        bookText.Append("<p align = 'center'><b>" +
                        xmlFile.readElementText(QXmlStreamReader::ReadElementTextBehaviour::IncludeChildElements) +
                        "</p></b>");
    }
}

void Book::SetParagraphStyle(QString paragraphText)
{
    if (paragraphText.length() <= MAX_STRING_LENGTH)  // если абзац меньше, чем максимальная длина одной строки
    {
        bookText.Append("<p style = \"margin-left: 30; margin-right: 0; margin-top: 0; margin-bottom: 0\">" + paragraphText + "</p>");
        return;
    }

    bool isFirstLineOfParagraph = true;
    while (paragraphText.length() > MAX_STRING_LENGTH)  // пока абзац длинне, чем максимальная длина одной строки
    {
        QString textToAppend;  // текст строки абзаца
        for (int i = 0; i  < MAX_STRING_LENGTH; i++)
        {
            textToAppend.append(paragraphText[i]);
        }

        int length = textToAppend.length() - 1;
        while (textToAppend[length] != ',' && textToAppend[length] != ';' && textToAppend[length] != ':' && textToAppend[length] != '.'
                && textToAppend[length] != '?' && textToAppend[length] != '!' && (textToAppend[length] != ' ' && paragraphText[length] != ' '))
        {   // удалять символ строки до тех пор, пока он не равен знаку препинания, пробелу или концу слова
            textToAppend.remove(length, 1);
            length--;
        }

        paragraphText = paragraphText.remove(0, length + 1);  // удалить из текста абзаца считанную строку
        if (isFirstLineOfParagraph)
        {   // задать текст строки с отступом, если первая строка абзаца
            bookText.Append("<p style = \"margin-left: 30; margin-right: 0; margin-top: 0; margin-bottom: 0\">" + textToAppend + "</p>");
            isFirstLineOfParagraph = false;
        }
        else
        {
            bookText.Append("<p style = \"margin: 0\">" + textToAppend + "</p>");  // задать текст строки
        }
    }

    bookText.Append("<p style = \"margin: 0\">" + paragraphText + "</p>");  // задать текст последней строки абзаца
}

void Book::ResetBookText()
{
    bookText.Clear();  // удалить текст книги
}

int Book::GetTotalPagesNumber() const
{
    return totalPagesNumber;
}

int Book::GetCurrentPageNumber() const
{
    return currentPageNumber;
}

void Book::SetCurrentPageNumber(int _currentPageNumber)
{
    if (_currentPageNumber > totalPagesNumber || _currentPageNumber < 1)
    {
        throw OutOfRangeException("Вы не можете открыть данную страницу!");
    }

    currentPageNumber = _currentPageNumber;
}

int Book::GetMaxStringAmount() const
{
    return MAX_STRING_AMOUNT;
}

Book& Book::operator=(const Book& book)
{
    this->currentPageNumber = book.currentPageNumber;
    this->pathToBookFile = book.pathToBookFile;
    return *this;
}
