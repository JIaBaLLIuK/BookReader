#include "../include/Exception.h"

Exception::Exception(QString _errorMessage) : errorMessage(_errorMessage)
{ }

QString Exception::GetErrorMessage() const
{
    return errorMessage;
}

ArgumentEmptyException::ArgumentEmptyException(QString _errorMessage) : Exception(_errorMessage)
{ }

PageButtonException::PageButtonException(QString _errorMessage) : Exception(_errorMessage)
{ }
