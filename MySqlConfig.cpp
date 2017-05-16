#include "MySqlConfig.h"

MySqlConfig::MySqlConfig(QString hostName, int port, QString dataBaseName, QString userName, QString passwd)
{
    m_hostName = hostName;
    m_port = port;
    m_dataBaseName = dataBaseName;
    m_userName = userName;
    m_passwd = passwd;
}


QString MySqlConfig::hostName()
{
    return m_hostName;
}

int MySqlConfig::port()
{
    return m_port;
}

QString MySqlConfig::dataBaseName()
{
    return m_dataBaseName;
}

QString MySqlConfig::userName()
{
    return m_userName;
}

QString MySqlConfig::passwd()
{
    return m_passwd;
}
