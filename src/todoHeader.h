#ifndef TODOHEADER_H
#define TODOHEADER_H
#include <QObject>
#include <QStringList>

class todoHeader : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString header READ header WRITE setHeader NOTIFY headerChanged)
public:
    todoHeader(QObject *parent=0);
    todoHeader(const QString &header, QObject *parent=0);

    QString header() const;
    void setHeader(const QString &header);
signals:
    void headerChanged();
private:
       QString m_header;
};

#endif // TODOHEADER_H
