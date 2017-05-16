#-------------------------------------------------
#
# Project created by QtCreator 2017-05-15T08:09:44
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = kyTimeLogger
TEMPLATE = app


SOURCES += main.cpp\
        MainDlg.cpp \
    Configuration.cpp \
    MySqlConfig.cpp \
    LogStorage.cpp \
    ReasonDlg.cpp

HEADERS  += MainDlg.h \
    Configuration.h \
    MySqlConfig.h \
    LogStorage.h \
    ReasonDlg.h

FORMS    += MainDlg.ui \
    ReasonDlg.ui
