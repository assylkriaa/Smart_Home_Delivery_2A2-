#include "login.h"
#include "agent.h"
#include "ui_login.h"
#include "connexion.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>
#include <QFileInfo>

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
     son=new QSound(":/resources/Resources/mouse.wav");
    connexion c;
      bool test=c.createConnection();
      this->setFixedSize(608,629);
}

login::~login()
{
    delete ui;
}

void login::on_login_2_clicked()

{   son->play();
    QString username = ui ->lineEditUser->text();
    QString password = ui ->lineEditPass->text();



    QSqlQuery query;
    query.prepare("SELECT * from \"CHAYMA\".\"AGENTS\" WHERE NOM = ? AND MDP =?");
    query.addBindValue(username);
    query.addBindValue(password);

   if (query.exec() && query.next()) {
        //successful
        //QMessageBox :: information(this,"login","Welcome");
        QMessageBox::information(nullptr, QObject::tr(""),
                   QObject::tr("Welcome ").append(username), QMessageBox::Cancel);
    this->hide();
      MainWindow *w= new MainWindow;
      w->show();
   }
    else {
        // unsuccessful either no match or bad SQL
       QMessageBox::warning(nullptr, QObject::tr(""),
                   QObject::tr("Wrong  Username or Password\n"), QMessageBox::Cancel);
    }


}

void login::on_login_3_clicked()
{
    son->play();
    Agent * w= new Agent;
      w->show();
}
