QT       += core gui sql printsupport

greaterThan(QT_MAJOR_VERSION, 4):
QT += widgets multimedia

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connexion.cpp \
    fournisseurs.cpp \
    login.cpp \
    agent.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    connexion.h \
    fournisseurs.h \
    login.h \
    agent.h \
    mainwindow.h

FORMS += \
    login.ui \
    agent.ui \
    mainwindow.ui

    QT += core gui
    QT +=sql
    QT +=core sql
    QT += widgets
    QT += printsupport
    QT += core gui  multimedia multimediawidgets
    QT += core gui widgets
    QT += multimedia

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
RESOURCES += resources.qrc
