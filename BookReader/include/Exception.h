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

class ArgumentNullException : public Exception
{
public:
    ArgumentNullException(QString);
    ~ArgumentNullException() = default;
};

class OutOfRangeException : public Exception
{
public:
    OutOfRangeException(QString);
    ~OutOfRangeException() = default;
};

#endif
