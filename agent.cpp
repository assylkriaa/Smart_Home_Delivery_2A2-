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
void Agent::setno(QString n)
{
    ui->lineEdit_nom_3->setText(n);
}

void Agent::setadresse(QString n)
{
    ui->lineEdit_prenom_3->setText(n);
}
void Agent::setci(QString n)
{
ui->lineEdit_cin_3->setText(n);
}
void Agent::setdon(QString n)
{
ui->lineEdit_mdp_3->setText(n);
}
void addValues(QString cin,QString nom,QString prenom,QString mdp)
{

    QSqlQuery qry;
    qry.prepare("INSERT INTO AGENTS ("
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
    }

}
void updateValues(QString cin,QString nom,QString prenom,QString mdp)
{
    QSqlQuery qry;
    qry.prepare("update  AGENTS set NOM='"+nom+"',PRENOM='"+prenom+"',MDP='"+mdp+"' where CIN ='"+cin+"' ");
    qry.addBindValue(nom);
    qry.addBindValue(prenom);
    qry.addBindValue(mdp);
    if(!qry.exec())
    {
    }

}

void supprimeragent(QString cin)
{
    QSqlQuery qry;
    qry.prepare("DELETE FROM AGENTS where CIN='"+cin+"'");
    if(!qry.exec())
    {
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








    addValues(a,b,c,d);
}

void Agent::on_supprimeragent_clicked()
{
    QString a;
    a=ui->lineEdit_cin->text();
    supprimeragent(a);
}

void Agent::on_pushButton_clicked()
{
    QSqlQuery qry;
    QSqlQueryModel *modal=new QSqlQueryModel();
    qry.prepare("SELECT * FROM AGENTS ");
    qry.exec();
    modal->setQuery(qry);
    ui->tableagent->setModel(modal);
    qDebug() << (modal->rowCount());
    QSortFilterProxyModel *m=new QSortFilterProxyModel(this);
    m->setDynamicSortFilter(true);
    m->setSourceModel(modal);
    ui->tableagent->setModel(m);
    ui->tableagent->setSortingEnabled(true);

}

void Agent::on_pushButton_rechercher_clicked()
{
    QString a;
    a=ui->recherche->text();
    QSqlQuery qry;
    QSqlQueryModel *modal=new QSqlQueryModel();
    qry.prepare("SELECT * FROM AGENTS WHERE NOM LIKE '"+a+"' OR MDP LIKE '"+a+"' OR PRENOM LIKE '"+a+"' OR CIN LIKE '"+a+"'");
    qry.exec();
    modal->setQuery(qry);
    ui->tableagent->setModel(modal);
}

void Agent::on_pushButton_3_clicked()
{
    QSqlDatabase db1;
           QTableView table_agent;
           QSqlQueryModel * Modal=new  QSqlQueryModel();

           QSqlQuery qry;
            qry.prepare("SELECT * FROM AGENTS");
            qry.exec();
            Modal->setQuery(qry);
            table_agent.setModel(Modal);



            db1.close();


            QString strStream;
            QTextStream out(&strStream);

            const int rowCount = table_agent.model()->rowCount();
            const int columnCount =  table_agent.model()->columnCount();

            const QString strTitle ="Document";


            out <<  "<html>\n"
                "<head>\n"
                    "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                <<  QString("<title>%1</title>\n").arg(strTitle)
                <<  "</head>\n"
                "<body bgcolor=#ffffff link=#5000A0>\n"
               << QString("<h3 style=\" font-size: 32px; font-family: Arial, Helvetica, sans-serif; color: red ; font-weight: lighter; text-align: center;\">%1</h3>\n").arg("Tous les Agents")
               <<"<br>"
                <<"<table border=1 cellspacing=0 cellpadding=2>\n";

            out << "<thead><tr bgcolor=#f0f0f0>";
            for (int column = 0; column < columnCount; column++)
                if (!table_agent.isColumnHidden(column))
                    out << QString("<th>%1</th>").arg(table_agent.model()->headerData(column, Qt::Horizontal).toString());
            out << "</tr></thead>\n";
            for (int row = 0; row < rowCount; row++) {
                    out << "<tr>";
                    for (int column = 0; column < columnCount; column++) {
                        if (!table_agent.isColumnHidden(column)) {
                            QString data = table_agent.model()->data(table_agent.model()->index(row, column)).toString().simplified();
                            out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                        }
                    }
                    out << "</tr>\n";
                }
                out <<  "</table>\n"
                        "<br><br>"


                "</body>\n"
                "</html>\n";

            QTextDocument *document = new QTextDocument();
            document->setHtml(strStream);

            QPrinter printer;

            QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
            if (dialog->exec() == QDialog::Accepted) {
                document->print(&printer);
            }
    /*QPrinter printer;
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName("C:\\Users\\DELL\\Desktop\\qt\\untitled\\pdf\\test.pdf");
        QPainter painter;

        if (! painter.begin(&printer)) { // failed to open file
                qWarning("failed to open file, is it writable?");
                //return 1;
            }

        QSqlQuery   query ;
        qDebug() << query.prepare("select sysdate from dual  ");
        if ( query.exec() )
        {

            QString S= QDate::currentDate().toString();
            painter.drawText(0,0, S);
        }
        QString CIN,NOM,PRENOM,MDP;
            QSqlQuery   qry ;

            int i =10  ;
            int j=0;

            painter.drawText(j*20,i*8,"CIN");
            painter.drawText((j+1)*60,i*8,"NOM");
            painter.drawText((j+2)*70,i*8,"PRENOM");
            painter.drawText((j+3)*75,i*8,"MDP");
            qDebug() << qry.prepare("select * from AGENT ");
            if ( qry.exec() )
            {
                while(qry.next())
                {
                    int j=0;

                    CIN = qry.value(0).toString();
                    painter.drawText(j*20,i*10, CIN);
                    j++;
                    NOM=qry.value(1).toString();
                    painter.drawText(j*60,i*10, NOM);
                    j++;
                    PRENOM=qry.value(2).toString();
                    painter.drawText(j*70,i*10, PRENOM);
                    j++;
                    MDP=qry.value(3).toString();
                    painter.drawText(j*75,i*10, MDP);
                    j++;

                    i+=10;


                }
            }


            painter.end();*/
}

void Agent::on_pushButton_4_clicked()
{


  modal = new QSqlTableModel(this);
      modal->setTable("AGENTS");
    modal ->select();

    ui->tableagent->setModel(modal);
}



void Agent::on_pushButton_2_clicked()
{
    QPrinter printer;
    printer.setPrinterName("desierd printer name");
    QPrintDialog dialog(&printer,this);
    if(dialog.exec()== QDialog::Rejected) return;
}

void Agent::on_ajouter_Ag_3_clicked()
{
    QString a,b,c,d;
    a=ui->lineEdit_cin_3->text();
    b=ui->lineEdit_nom_3->text();
    c=ui->lineEdit_prenom_3->text();
    d=ui->lineEdit_mdp_3->text();
    int error=0;
    QPalette *red = new QPalette();
    QPalette *white = new QPalette();
     red->setColor(QPalette::Base,Qt::red);
      white->setColor(QPalette::Base,Qt::white);

        if(ui->lineEdit_cin_3->text().isEmpty())

    {
            ui->lineEdit_cin_3->setPalette(*red) ; error=1;}

        else {

            ui->lineEdit_cin_3->setPalette(*white); }

        if(ui->lineEdit_nom_3->text().isEmpty())
    {       ui->lineEdit_nom_3->setPalette(*red)  ;error=1;}
        else {  ui->lineEdit_nom_3->setPalette(*white); }
        if(ui->lineEdit_prenom_3->text().isEmpty())
    {     ui->lineEdit_prenom_3->setPalette(*red );error=1;}
        else {  ui->lineEdit_prenom_3->setPalette(*white); }


        if(ui->lineEdit_mdp_3->text().isEmpty())

    {
            ui->lineEdit_mdp_3->setPalette(*red) ; error=1;}

        else {

            ui->lineEdit_mdp_3->setPalette(*white); }

        QSqlQuery qry;
        qry.prepare("INSERT INTO PARTENAIRE ("
                    "CIN,"
                    "NOM,"
                    "ADRESSE,"
                    "DONS)"
                    "VALUES(?,?,?,?);");
        qry.addBindValue(a);
        qry.addBindValue(b);
        qry.addBindValue(c);
        qry.addBindValue(d);
        if(!qry.exec())
        {
        }
}

void Agent::on_pushButton_7_clicked()
{
    QSqlQuery qry;
    QSqlQueryModel *modal=new QSqlQueryModel();
    qry.prepare("SELECT * from PARTENAIRE");
    qry.exec();
    modal->setQuery(qry);
    ui->tableagent_3->setModel(modal);
    qDebug() << (modal->rowCount());
    QSortFilterProxyModel *m=new QSortFilterProxyModel(this);
    m->setDynamicSortFilter(true);
    m->setSourceModel(modal);
    ui->tableagent_3->setModel(m);
    ui->tableagent_3->setSortingEnabled(true);
}

void Agent::on_pushButton_8_clicked()
{


  modal = new QSqlTableModel(this);
      modal->setTable("\"CHAYMA\".\"PARTENAIRE\"");
    modal ->select();

    ui->tableagent_3->setModel(modal);
}

void Agent::on_supprimeragent_3_clicked()
{
    QSqlQuery qry;
    QString a;
    a=ui->lineEdit_cin_3->text();
    qry.prepare("DELETE FROM \"CHAYMA\".\"PARTENAIRE\" where CIN='"+a+"'");
    if(!qry.exec())
    {
    }
}

void Agent::on_pushButton_9_clicked()
{
    QSqlDatabase db1;
           QTableView table_agent;
           QSqlQueryModel * Modal=new  QSqlQueryModel();

           QSqlQuery qry;
            qry.prepare("SELECT * FROM \"CHAYMA\".\"PARTENAIRE\"");
            qry.exec();
            Modal->setQuery(qry);
            table_agent.setModel(Modal);



            db1.close();


            QString strStream;
            QTextStream out(&strStream);

            const int rowCount = table_agent.model()->rowCount();
            const int columnCount =  table_agent.model()->columnCount();

            const QString strTitle ="Document";


            out <<  "<html>\n"
                "<head>\n"
                    "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                <<  QString("<title>%1</title>\n").arg(strTitle)
                <<  "</head>\n"
                "<body bgcolor=#ffffff link=#5000A0>\n"
               << QString("<h3 style=\" font-size: 32px; font-family: Arial, Helvetica, sans-serif; color: red ; font-weight: lighter; text-align: center;\">%1</h3>\n").arg("Tous les Agents")
               <<"<br>"
                <<"<table border=1 cellspacing=0 cellpadding=2>\n";

            out << "<thead><tr bgcolor=#f0f0f0>";
            for (int column = 0; column < columnCount; column++)
                if (!table_agent.isColumnHidden(column))
                    out << QString("<th>%1</th>").arg(table_agent.model()->headerData(column, Qt::Horizontal).toString());
            out << "</tr></thead>\n";
            for (int row = 0; row < rowCount; row++) {
                    out << "<tr>";
                    for (int column = 0; column < columnCount; column++) {
                        if (!table_agent.isColumnHidden(column)) {
                            QString data = table_agent.model()->data(table_agent.model()->index(row, column)).toString().simplified();
                            out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                        }
                    }
                    out << "</tr>\n";
                }
                out <<  "</table>\n"
                        "<br><br>"


                "</body>\n"
                "</html>\n";

            QTextDocument *document = new QTextDocument();
            document->setHtml(strStream);

            QPrinter printer;

            QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
            if (dialog->exec() == QDialog::Accepted) {
                document->print(&printer);
            }
}

void Agent::on_pushButton_rechercher_3_clicked()
{
    QString a;
    a=ui->recherche_3->text();
    QSqlQuery qry;
    QSqlQueryModel *modal=new QSqlQueryModel();
    qry.prepare("SELECT * FROM \"CHAYMA\".\"PARTENAIRE\" WHERE NOM LIKE '"+a+"' OR DONS LIKE '"+a+"' OR ADRESSE LIKE '"+a+"' OR CIN LIKE '"+a+"'");
    qry.exec();
    modal->setQuery(qry);
    ui->tableagent_3->setModel(modal);
}

void Agent::on_pushButton_11_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void Agent::on_pushButton_10_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void Agent::on_home_5_clicked()
{
    //this->close();
}

void Agent::on_home_6_clicked()
{
    //this->close();
}
