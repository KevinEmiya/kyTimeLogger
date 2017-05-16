#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <QString>
#include "MySqlConfig.h"

class Configuration
{
public:
    Configuration();
    ~Configuration();
    MySqlConfig* mysqlConf();

private:
    void _initParams();
    void _parseConfFile();

private:
    QString m_confPath;
    MySqlConfig* m_mysqlConf;
};

#endif // CONFIGURATION_H
