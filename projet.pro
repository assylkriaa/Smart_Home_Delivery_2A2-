QT       += core gui sql printsupport  serialport charts network

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
    ../i-Food/agent.cpp \
    ../i-Food/client.cpp \
    ../i-Food/commande.cpp \
    ../i-Food/dialog.cpp \
    ../i-Food/dialog_principale.cpp \
    ../i-Food/emplacement.cpp \
    ../i-Food/exportexcelobjet.cpp \
    ../i-Food/facrec.cpp \
    ../i-Food/facture.cpp \
    ../i-Food/fourni.cpp \
    ../i-Food/fournisseurs.cpp \
    ../i-Food/login.cpp \
    ../i-Food/logistique.cpp \
    ../i-Food/materiel.cpp \
    ../i-Food/modifier.cpp \
    ../i-Food/qcustomplot.cpp \
    ../i-Food/recette.cpp \
    ../i-Food/reclamation.cpp \
    ../i-Food/smtp.cpp \
    ../i-Food/stat_combo.cpp \
    ../i-Food/transport.cpp \
    classe_conge.cpp \
    classe_personnel.cpp \
    connexion.cpp \
    gestion_perso_conge.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    ../i-Food/agent.h \
    ../i-Food/client.h \
    ../i-Food/commande.h \
    ../i-Food/dialog.h \
    ../i-Food/dialog_principale.h \
    ../i-Food/emplacement.h \
    ../i-Food/exportexcelobjet.h \
    ../i-Food/facrec.h \
    ../i-Food/facture.h \
    ../i-Food/fourni.h \
    ../i-Food/fournisseurs.h \
    ../i-Food/login.h \
    ../i-Food/logistique.h \
    ../i-Food/materiel.h \
    ../i-Food/modifier.h \
    ../i-Food/qcustomplot.h \
    ../i-Food/recette.h \
    ../i-Food/reclamation.h \
    ../i-Food/smtp.h \
    ../i-Food/stat_combo.h \
    ../i-Food/transport.h \
    classe_conge.h \
    classe_personnel.h \
    connexion.h \
    gestion_perso_conge.h \
    mainwindow.h

FORMS += \
    ../i-Food/agent.ui \
    ../i-Food/dialog.ui \
    ../i-Food/dialog_principale.ui \
    ../i-Food/facrec.ui \
    ../i-Food/fourni.ui \
    ../i-Food/login.ui \
    ../i-Food/logistique.ui \
    ../i-Food/modifier.ui \
    ../i-Food/stat_combo.ui \
    gestion_perso_conge.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    translation.qrc

DISTFILES +=
