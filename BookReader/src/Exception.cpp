#include "../include/Exception.h"

Exception::Exception(QString _errorMessage) : errorMessage(_errorMessage)
{ }

QString Exception::GetErrorMessage() const
{
    return errorMessage;
}

ArgumentNullException::ArgumentNullException(QString _errorMessage) : Exception(_errorMessage)
{ }

OutOfRangeException::OutOfRangeException(QString _errorMessage) : Exception(_errorMessage)
{ }
