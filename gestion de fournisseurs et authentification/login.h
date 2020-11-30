#ifndef LOGIN_H
#define LOGIN_H
#include "mainwindow.h"
#include <QWidget>
#include <QSound>
namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:

    void on_login_2_clicked();
    void on_login_3_clicked();
private:
      QSound *son;
    Ui::login *ui;
};

#endif // LOGIN_H
