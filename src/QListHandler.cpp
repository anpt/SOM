#include <src/QListHandler.h>

QListHandler::QListHandler(QObject *parent) : QObject(parent)
{

}

void QListHandler::setListhandler(const QList<QStringList> &listhandler){
    m_listhandler = listhandler;
}
qint32 QListHandler::count() const
{
    return m_listhandler.count();
}

QString QListHandler::ItemAt(const int &i, const int &j)
{
    QString value;
    if(i>=0 && i<m_listhandler.count())
    {
        if(j>=0 && j<m_listhandler.at(i).count())
        {
            value = m_listhandler.at(i).at(j);
        }
    }
    return value;
}

bb
