#ifndef BOOK_H
#define BOOK_H

#include <QString>
#include <QXmlStreamReader>

class Book
{
public:
    Book(QString);
    ~Book() = default;
    void SetPathToBookFile(QString);
    void ParseBookFile();
    void SetBookText(QXmlStreamReader&);
    QString GetBookText() const;

private:
    QString pathToBookFile;
    QString bookText;
};

#endif // BOOK_H
