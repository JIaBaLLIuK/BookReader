#include <QFile>
#include <QXmlStreamReader>

#include <QDebug>

#include "../include/Book.h"

void Book::SetPathToBookFile(QString pathToBookFile)
{
    this->pathToBookFile = pathToBookFile;
}

QString Book::GetBookText()
{
    QFile bookFile(pathToBookFile);
    if (!bookFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "dqdqdq";
    }

    QXmlStreamReader xmlFile(&bookFile);
    while (true)
    {
        xmlFile.readNextStartElement();

        QString text = xmlFile.name().toString();

        if (text != "body")
            {
                continue;
            }
            else
            {
                qDebug() << xmlFile.name().toString();
            }
//            QString text = xmlFile.name().toString();
//            if (text == "book-title")
//            {
//                qDebug() << xmlFile.readElementText();
//            }
    }

    return bookText;
}
