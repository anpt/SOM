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
class filehandler : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QObject*> list READ list)
public:
    explicit filehandler(QObject *parnet = 0);
    Q_INVOKABLE void newTodo(QString text, QString file, QString date);
    Q_INVOKABLE void clockin(QString header, QString file);
    Q_INVOKABLE void clockout(QString header, QString fileName);
    Q_INVOKABLE void listHeaders(QString file);
    QList<QObject*> list();
private:
    QString cTime();
    QList<QObject*> headerList;
};
#endif
