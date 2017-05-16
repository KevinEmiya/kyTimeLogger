#ifndef MYSQLCONFIG_H
#define MYSQLCONFIG_H

#include <QString>

class MySqlConfig
{
public:
    MySqlConfig(QString hostName, int port, QString dataBaseName, QString userName, QString passwd);

public:
    QString hostName();
    int port();
    QString dataBaseName();
    QString userName();
    QString passwd();

private:
    QString m_hostName;
    int m_port;
    QString m_dataBaseName;
    QString m_userName;
    QString m_passwd;
};

#endif // MYSQLCONFIG_H
