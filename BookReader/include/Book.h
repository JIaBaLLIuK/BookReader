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
    void SetTotalPagesNumber();
    QList<QString> GetBookText() const;
    int GetTotalPagesNumber() const;
    int GetCurrentPageNumber() const;
    void SetCurrentPageNumber(int);
    int GetMaxStringAmount() const;

private:
    QString pathToBookFile;
    QList<QString> bookText;
    const int MAX_STRING_LENGTH = 95;
    const int MAX_STRING_AMOUNT = 31;
    int totalPagesNumber;
    int currentPageNumber;
};

#endif // BOOK_H
