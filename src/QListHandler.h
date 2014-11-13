#ifndef _QFileList
#define _QFileList
#include <QObject>
#include <QStringList>

class QListHandler : public QObject
{
    Q_OBJECT
public:
    explicit QListHandler(QObject *parent = 0);
    void setListhandler(const QStringList& ListOfFiles);
    Q_INVOKABLE qint32 count () const;
    Q_INVOKABLE QString itemat(const int &i);
signals:

public slots:

private:
    QStringList m_listhandler;
};
#endif
