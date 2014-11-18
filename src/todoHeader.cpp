#include "todoHeader.h"


todoHeader::todoHeader(QObject *parent) : QObject(parent)
{

}

todoHeader::todoHeader(const QString &header , QObject *parent) : QObject(parent)
{
    m_header = header;
}

QString todoHeader::header() const
{
    return m_header;
}
void todoHeader::setHeader(const QString &header)
{
    m_header = header;
}
