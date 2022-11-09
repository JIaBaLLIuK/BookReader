#include <QFile>
#include <QMessageBox>

#include "../include/Book.h"

void Book::SetPathToBookFile(QString _pathToBookFile)
{
    pathToBookFile = _pathToBookFile;
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
        QString readText;
        xmlFile.readNextStartElement();
        tag = xmlFile.name().toString();
        if (xmlFile.isEndElement())
        {
            continue;
        }

        while (tag != "p" && tag != "title")
        {
            xmlFile.readNextStartElement();
            tag = xmlFile.name().toString();
        }

        if (tag == "p")
        {
            SetParagraphStyle(xmlFile.readElementText(QXmlStreamReader::ReadElementTextBehaviour::IncludeChildElements));
        }
        else
        {
             SetTitleStyle(xmlFile);
        }
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

void Book::SetTitleStyle(QXmlStreamReader& xmlFile)
{
    QString tag;
    while (tag != "title")
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

        bookText.append("<p align = 'center'><b>" +
                        xmlFile.readElementText(QXmlStreamReader::ReadElementTextBehaviour::IncludeChildElements) +
                        "</p></b>");
    }
}

void Book::SetParagraphStyle(QString paragraphText)
{
    if (paragraphText.length() <= MAX_STRING_LENGTH)
    {
        bookText.append("<p style = \"margin-left: 30; margin-right: 0; margin-top: 0; margin-bottom: 0\">" + paragraphText + "</p>");
        return;
    }

    bool isFirstLineOfParagraph = true;
    while (paragraphText.length() > MAX_STRING_LENGTH)
    {
        QString textToAppend;
        for (int i = 0; i  < MAX_STRING_LENGTH; i++)
        {
            textToAppend.append(paragraphText[i]);
        }

        int length = textToAppend.length();
        length--;
        while (textToAppend[length] != ',' && textToAppend[length] != ';' && textToAppend[length] != ':' && textToAppend[length] != '.'
                && textToAppend[length] != '?' && textToAppend[length] != '!' && (textToAppend[length] != ' ' && paragraphText[length] != ' '))
        {
            textToAppend.remove(length, 1);
            length--;
        }

        length++;
        paragraphText = paragraphText.remove(0, length);
        if (isFirstLineOfParagraph)
        {
            bookText.append("<p style = \"margin-left: 30; margin-right: 0; margin-top: 0; margin-bottom: 0\">" + textToAppend + "</p>");
            isFirstLineOfParagraph = false;
        }
        else
        {
            bookText.append("<p style = \"margin: 0\">" + textToAppend + "</p>");
        }
    }

    bookText.append("<p style = \"margin: 0\">" + paragraphText + "</p>");
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
