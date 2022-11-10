#ifndef BOOK_H
#define BOOK_H

#include <QString>
#include <QXmlStreamReader>

class Book
{
public:
    Book() = default;
    ~Book() = default;
    void SetPathToBookFile(QString);
    void ParseBookFile();
    QList<QString> GetBookText() const;
    void SetTitleStyle(QXmlStreamReader&);
    void SetParagraphStyle(QString);
    void ResetBookText();
    int GetTotalPagesNumber() const;
    void SetCurrentPageNumber(int);
    int GetCurrentPageNumber() const;
    int GetMaxStringAmount() const;

private:
    void SetBookText(QXmlStreamReader&);
    void SetTotalPagesNumber();

    QString pathToBookFile;
    QList<QString> bookText;
    const int MAX_STRING_LENGTH = 95;
    const int MAX_STRING_AMOUNT = 29;
    int totalPagesNumber;
    int currentPageNumber;
};

#endif // BOOK_H
