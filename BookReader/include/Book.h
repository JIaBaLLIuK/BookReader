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
    int GetPageSize() const;
    int GetTotalPagesNumber() const;
    int GetCurrentPageNumber() const;
    void SetCurrentPageNumber(int);

private:
    QString pathToBookFile;
    QString bookText;
    const int MAX_STRING_LENGTH = 95;
    const int MAX_STRING_AMOUNT = 31;
    int pageSize;
    int totalPagesNumber;
    int currentPageNumber;
};

#endif // BOOK_H
