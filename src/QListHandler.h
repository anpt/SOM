#ifndef _QFileList
#define _QFileList
#include <QObject>
#include <QStringList>

class QListHandler : public QObject
{
    Q_OBJECT
public:
    explicit QListHandler(QObject *parent = 0);
    void setListhandler(const QList<QStringList>& ListOfFiles);
    Q_INVOKABLE qint32 count () const;
    Q_INVOKABLE QString ItemAt(const int &i, const int &j);
signals:

public slots:

private:
    QList<QStringList> m_listhandler;
};
#endif
