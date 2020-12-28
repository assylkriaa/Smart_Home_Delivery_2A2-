#include "notification.h"
#include <QSystemTrayIcon>
#include<QString>

notification::notification()
{

}


void notification::notificationC()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon("C:/Users/oumayma/Desktop/ard/DS18B20_Qt/notif.png"));

    notifyIcon->show();
    notifyIcon->showMessage("Activer la ventilation","Urgent! ",QSystemTrayIcon::Information,15000);
}
