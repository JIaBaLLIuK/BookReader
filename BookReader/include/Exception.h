#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <QString>

class Exception
{
public:
    Exception(QString);
    Exception() = default;
    QString GetErrorMessage() const;

private:
    QString errorMessage;
};

class ArgumentEmptyException : public Exception
{
public:
    ArgumentEmptyException(QString);
    ~ArgumentEmptyException() = default;
};

class PageButtonException : public Exception
{
public:
    PageButtonException(QString);
    ~PageButtonException() = default;
};

#endif
