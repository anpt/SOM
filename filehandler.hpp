#ifndef _filehandler
#define _filehandler
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <QObject>
#include <QStringList>
#include <QList>
#include <src/todoHeader.h>
#include <QStandardPaths>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QAbstractListModel>
class filehandler : public QAbstractListModel
{
    Q_OBJECT
public:
    enum todoRoles{
        todorole = Qt::UserRole + 1
    };

    explicit filehandler(QObject *parnet = 0);

    Q_INVOKABLE void newTodo(QString text, QString file, QString date);
    Q_INVOKABLE void clockin(QString header, QString file);
    Q_INVOKABLE void clockout(QString header, QString fileName);
    Q_INVOKABLE void listHeaders(QString file);
    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
protected:
    QHash<int, QByteArray> roleNames() const;
private:
    QString cTime();
    QList<todoHeader*> headerList;
};
#endif
