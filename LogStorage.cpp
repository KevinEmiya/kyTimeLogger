#include "LogStorage.h"

LogStorage::LogStorage(MySqlConfig* config)
{
    m_db = QSqlDatabase::addDatabase("QMYSQL");
    m_db.setHostName(config->hostName());
    m_db.setDatabaseName(config->dataBaseName());
    m_db.setUserName(config->userName());
    m_db.setPassword(config->passwd());
    m_db.setConnectOptions();
    m_initOk = m_db.open();
}

void LogStorage::writeToStorage(QString desc, QDateTime startTime, QDateTime finTime, QString finType, QString reason)
{
    if(m_initOk)
    {
        QSqlQuery query;
        query.prepare("INSERT INTO ky_log_info (task_desc, start_time, end_time, fin_type, interrupt_reason) "
                      "VALUES (:task_desc, :start_time, :end_time, :fin_type, :interrupt_reason)");
        query.bindValue(":task_desc", desc.toUtf8());
        query.bindValue(":start_time", startTime);
        query.bindValue(":end_time", finTime);
        query.bindValue(":fin_type", finType.toUtf8());
        query.bindValue(":interrupt_reason", (reason != NULL) ? reason.toUtf8() : QString("").toUtf8());
        bool ret = query.exec();
        if(!ret)
        {
            qDebug() << m_db.lastError();
        }
    }
    else
    {
        qDebug() << "数据库未连接！略过持久化...";
    }
}
