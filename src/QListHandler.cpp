#include <src/QListHandler.h>

QListHandler::QListHandler(QObject *parent) : QObject(parent)
{

}

void QListHandler::setListhandler(const QStringList &listhandler){
    m_listhandler = listhandler;
}
qint32 QListHandler::count() const
{
    return m_listhandler.count();
}

QString QListHandler::itemat(const int &i)
{
    QString value;
    if(i>=0 && i<m_listhandler.count())
    {
        value = m_listhandler.at(i);
    }
    return value;
}

