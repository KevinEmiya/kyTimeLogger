#ifndef LOGSTORAGE_H
#define LOGSTORAGE_H

#include <QString>
#include <QDateTime>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QTextCodec>
#include "MySqlConfig.h"

class LogStorage
{
public:
    LogStorage(MySqlConfig* config);

public:
    void writeToStorage(QString desc, QDateTime startTime, QDateTime finTime, QString finType = "Finish", QString reason = NULL);

private:
    bool m_initOk;
    QSqlDatabase m_db;
};

#endif // LOGSTORAGE_H
