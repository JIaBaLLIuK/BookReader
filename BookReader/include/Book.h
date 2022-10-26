#ifndef BOOK_H
#define BOOK_H

#include <QString>

class Book
{
public:
    Book() = default;
    ~Book() = default;
    void SetPathToBookFile(QString);
    QString GetBookText();

private:
    QString pathToBookFile;
    QString bookText;
};

#endif // BOOK_H
