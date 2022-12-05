#ifndef BOOK_H
#define BOOK_H

#include <QString>
#include <QXmlStreamReader>

#include "List.h"
// класс, содержащий в себе информацию о книге
class Book
{
public:
    Book() = default;
    ~Book() = default;
    void SetPathToBookFile(QString);
    QString GetPathToBookFile() const;
    void ParseBookFile();
    List<QString> GetBookText() const;
    void ResetBookText();
    int GetTotalPagesNumber() const;
    void SetCurrentPageNumber(int);
    int GetCurrentPageNumber() const;
    int GetMaxStringAmount() const;
    Book& operator=(const Book&);

private:
    void SetBookText(QXmlStreamReader&);
    void SetTitleStyle(QXmlStreamReader&);
    void SetParagraphStyle(QString);
    void SetTotalPagesNumber();

    QString pathToBookFile;
    List<QString> bookText;
    const int MAX_STRING_LENGTH = 95;
    const int MAX_STRING_AMOUNT = 29;
    int totalPagesNumber;
    int currentPageNumber;
};

#endif
