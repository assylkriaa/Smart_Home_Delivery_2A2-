#include "agent.h"
#include "ui_agent.h"
#include <QSqlQueryModel>
#include <QMediaPlayer>
#include <QPrinter>
#include <QTextDocument>
#include <QPainter>
#include <QDate>
#include <QSortFilterProxyModel>
#include <QSqlTableModel>
#include <QPrintDialog>
#include <QMessageBox>


Agent::Agent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Agent)
{
    ui->setupUi(this);

    ui->lineEdit_mdp->setEchoMode(QLineEdit::Password);
    QRegExp rx("[A-Za-z]+");
    QValidator *validator = new QRegExpValidator(rx, this);
    ui->lineEdit_nom->setValidator( validator );
}

Agent::~Agent()
{
    delete ui;
}


void Agent::setnom(QString n)
{
    ui->lineEdit_nom->setText(n);
}

void Agent::setprenom(QString n)
{
    ui->lineEdit_prenom->setText(n);
}
void Agent::setcin(QString n)
{
ui->lineEdit_cin->setText(n);
}
void Agent::setmdp(QString n)
{
ui->lineEdit_mdp->setText(n);
}
void addValues(QString cin,QString nom,QString prenom,QString mdp)
{

    QSqlQuery qry;
    qry.prepare("INSERT INTO \"CHAYMA\".\"AGENTS\" ("
                "CIN,"
                "NOM,"
                "PRENOM,"
                "MDP)"
                "VALUES(?,?,?,?);");
    qry.addBindValue(cin);
    qry.addBindValue(nom);
    qry.addBindValue(prenom);
    qry.addBindValue(mdp);
    if(!qry.exec())
    {

        QMessageBox::information(nullptr, QObject::tr(""),
                   QObject::tr("ERROR !!! "), QMessageBox::Cancel);
    }
}

void Agent::on_ajouter_Ag_clicked()
{
    QString a,b,c,d;
    a=ui->lineEdit_cin->text();
    b=ui->lineEdit_nom->text();
    c=ui->lineEdit_prenom->text();
    d=ui->lineEdit_mdp->text();
    int error=0;
    QPalette *red = new QPalette();
    QPalette *white = new QPalette();
     red->setColor(QPalette::Base,Qt::red);
      white->setColor(QPalette::Base,Qt::white);

        if(ui->lineEdit_cin->text().isEmpty())

    {
            ui->lineEdit_cin->setPalette(*red) ; error=1;}

        else {

            ui->lineEdit_cin->setPalette(*white); }

        if(ui->lineEdit_nom->text().isEmpty())
    {       ui->lineEdit_nom->setPalette(*red)  ;error=1;}
        else {  ui->lineEdit_nom->setPalette(*white); }
        if(ui->lineEdit_prenom->text().isEmpty())
    {     ui->lineEdit_prenom->setPalette(*red );error=1;}
        else {  ui->lineEdit_prenom->setPalette(*white); }


        if(ui->lineEdit_mdp->text().isEmpty())

    {
            ui->lineEdit_mdp->setPalette(*red) ; error=1;}

        else {

            ui->lineEdit_mdp->setPalette(*white); }
        if(error){
            QMessageBox::information(nullptr, QObject::tr(""),
            QObject::tr("ERROR !!! "), QMessageBox::Cancel);
        }else {
            addValues(a,b,c,d);
            QMessageBox::information(nullptr, QObject::tr(""),
            QObject::tr("Utilisateur ajoutee "), QMessageBox::Cancel);
            this->hide();
        }


}





void Agent::on_lineEdit_mdp_cursorPositionChanged(int arg1, int arg2)
{

}
