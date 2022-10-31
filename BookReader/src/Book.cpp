#include <QFile>
#include <QXmlStreamReader>
#include <QMessageBox>

#include <QDebug>

#include "../include/Book.h"

Book::Book(QString pathToBookFile) : pathToBookFile(pathToBookFile), currentPageNumber(1)
{ }

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

        if (readedText.length() <= MAX_STRING_LENGTH)
        {
            bookText.append(readedText);
            continue;
        }

        while (readedText.length() > MAX_STRING_LENGTH)
        {
            QString textToAppend;
            for (int i = 0; i  < MAX_STRING_LENGTH; i++)
            {
                textToAppend.append(readedText[i]);
            }

            int length = textToAppend.length();
            length--;
            while (textToAppend[length] != ',' && textToAppend[length] != ';' && textToAppend[length] != ':' && textToAppend[length] != '.'
                    && textToAppend[length] != '?' && textToAppend[length] != '!' && (textToAppend[length] != ' ' && readedText[length] != ' '))
            {
                textToAppend.remove(length, 1);
                length--;
            }

            length++;
            //textToAppend.append('\n');

            readedText = readedText.remove(0, length);
            bookText.append(textToAppend);
        }

        bookText.append(readedText);
    }

    SetTotalPagesNumber();
}

void Book::SetTotalPagesNumber()
{
    if (bookText.size() % MAX_STRING_AMOUNT == 0)
    {
        totalPagesNumber = bookText.size() / MAX_STRING_AMOUNT;
    }
    else
    {
        totalPagesNumber = bookText.size() / MAX_STRING_AMOUNT + 1;
    }
}

QList<QString> Book::GetBookText() const
{
    return bookText;
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

int Book::GetMaxStringAmount() const
{
    return MAX_STRING_AMOUNT;
}
