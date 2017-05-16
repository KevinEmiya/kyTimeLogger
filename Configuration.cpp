#include "Configuration.h"

#include <QFile>
#include <QDir>
#include <QSettings>
#include <QDebug>

Configuration::Configuration()
{
    m_confPath = QDir::currentPath() + "/timelogger.conf";
    _initParams();
    _parseConfFile();
}

Configuration::~Configuration()
{
    if(m_mysqlConf != NULL)
    {
        delete m_mysqlConf;
        m_mysqlConf = NULL;
    }
}

MySqlConfig* Configuration::mysqlConf()
{
    return m_mysqlConf;
}

void Configuration::_initParams()
{
    m_mysqlConf = new MySqlConfig("127.0.0.1",3306,"ky_time_log","root","root");
}

void Configuration::_parseConfFile()
{
    if(!QFile(m_confPath).exists())
    {
        qWarning() << "[Configuration]Config file not found!";
        return;
    }

    QSettings settings(m_confPath, QSettings::IniFormat);

    QString hostName = settings.value("hostName").toString();
    int port = settings.value("port").toInt();
    QString dbName = settings.value("dbName").toString();
    QString userName = settings.value("userName").toString();
    QString passwd = settings.value("passwd").toString();
    if(!hostName.isEmpty() && port > 0 && !dbName.isEmpty() && !userName.isEmpty() && !passwd.isEmpty())
    {
        m_mysqlConf = new MySqlConfig(hostName, port, dbName, userName, passwd);
    }
}
