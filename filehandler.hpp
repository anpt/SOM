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
#include <src/QListHandler.h>
#include <QStandardPaths>
#include <QFile>
#include <QTextStream>
#include <QDebug>
class filehandler : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QObject *list READ list)
public:
    explicit filehandler(QObject *parnet = 0);
    void newTodo(QString text, QString file, QString date);
    void clockin(QString header, QString file);
    void clockout(QString header, QString fileName);
    void listHeaders(QString file);
    QObject *list();
private:
    QString cTime();
    QListHandler m_list;
};
#endif
