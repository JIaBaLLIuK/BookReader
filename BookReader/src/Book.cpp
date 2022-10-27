#include <QFile>
#include <QXmlStreamReader>
#include <QMessageBox>

#include <QDebug>

#include "../include/Book.h"

Book::Book(QString pathToBookFile) : pathToBookFile(pathToBookFile), currentPageNumber(1)
{
    bookText = "";
    pageSize = MAX_STRING_LENGTH * MAX_STRING_AMOUNT;
}

void Book::SetPathToBookFile(QString pathToBookFile)
{
    this->pathToBookFile = pathToBookFile;
}

void Book::ParseBookFile()
{
    QFile bookFile(pathToBookFile);
    if (!bookFile.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::critical(nullptr, "Критическая ошибка!", "Что-то пошло не так. Файл невозможно открыть!");
    }

    QXmlStreamReader xmlFile(&bookFile);
    while (!xmlFile.atEnd())
    {
        xmlFile.readNextStartElement();
        if (xmlFile.isEndElement())
        {
            continue;
        }

        QString tag = xmlFile.name().toString();
        if (tag == "body")
        {
            SetBookText(xmlFile);
            break;
        }
    }

    bookFile.close();
}

void Book::SetBookText(QXmlStreamReader& xmlFile)
{
    QString tag;
    while (tag != "body")
    {
        xmlFile.readNextStartElement();
        tag = xmlFile.name().toString();
        if (xmlFile.isEndElement())
        {
            continue;
        }

        while (tag != "p")
        {
            xmlFile.readNextStartElement();
            tag = xmlFile.name().toString();
        }

        QString readedText = "      " + xmlFile.readElementText(QXmlStreamReader::ReadElementTextBehaviour::IncludeChildElements) + '\n';
        bookText.append(readedText);
    }

    totalPagesNumber = bookText.length() / pageSize + 1;
}

QString Book::GetBookText() const
{
    return bookText;
}

int Book::GetPageSize() const
{
    return pageSize;
}

int Book::GetTotalPagesNumber() const
{
    return totalPagesNumber;
}

int Book::GetCurrentPageNumber() const
{
    return currentPageNumber;
}

void Book::SetCurrentPageNumber(int currentPageNumber)
{
    this->currentPageNumber = currentPageNumber;
}
