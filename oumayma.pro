QT       += core gui sql printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
greaterThan(QT_MAJOR_VERSION, 4):

QT += widgets multimedia



TARGET = test_son

TEMPLATE = app

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    classe_conge.cpp \
    classe_personnel.cpp \
    connexion.cpp \
    gestion_perso_conge.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    classe_conge.h \
    classe_personnel.h \
    connexion.h \
    gestion_perso_conge.h \
    mainwindow.h

FORMS += \
    gestion_perso_conge.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES +=
