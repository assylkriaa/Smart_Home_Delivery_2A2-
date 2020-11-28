#include "gestion_perso_conge.h"
#include "ui_gestion_perso_conge.h"
#include <QMessageBox>
#include "QString"
#include <QTextStream>
#include<QPrintDialog>
#include<QTextDocument>
#include<QPrinter>
#include<QPainter>
#include<QPdfWriter>
#include<QDebug>
gestion_perso_conge::gestion_perso_conge(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_perso_conge)
{
    ui->setupUi(this);
  //  ui->tableView->setModel(tmpemployee.afficher_employe());
    ui->lineEdit->setValidator(new QIntValidator(0000,9999,this));
    ui->comboBox_id->setModel(tmpemployee.afficher_employe());
     ui->lineEdit_5->setValidator(new QIntValidator(0000,9999,this));
      ui->comboBox_id_2->setModel(tmpemployee.afficher_employe());



}

gestion_perso_conge::~gestion_perso_conge()
{
    delete ui;

}

void gestion_perso_conge::on_pushButton_ajouter_clicked()
{
   QString idp=ui->lineEdit->text();
   QString nom=ui->lineEdit_2->text();
   QString prenom=ui->lineEdit_3->text();
   QString adress=ui->lineEdit_4->text();
   classe_personnel p(idp,nom,prenom,adress);
   bool test=p.ajouter_employe();

   if(test)
   {

        ui->tableView->setModel(tmpemployee.afficher_employe());
        ui->comboBox_id->setModel(tmpemployee.afficher_employe());
        ui->comboBox_id_2->setModel(tmpemployee.afficher_employe());
       QMessageBox::information(nullptr, QObject::tr("ajouter un employee"),
                   QObject::tr("employee ajouté.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
   }
   ui->lineEdit->clear();
   ui->lineEdit_2->clear();
   ui->lineEdit_3->clear();
   ui->lineEdit_4->clear();
}

void gestion_perso_conge::on_pushButton_afficher_clicked()
{


     ui->tableView->setModel(tmpemployee.afficher_employe());
      ui->comboBox_id->setModel(tmpemployee.afficher_employe());
}

void gestion_perso_conge::on_pushButton_supprimer_clicked()
{
     QString idp=ui->lineEdit->text();
   // QString idp=ui->comboBox_id->currentText();
    bool test=tmpemployee.supprimer_employe(idp);
    if(test)
    {
         ui->tableView->setModel(tmpemployee.afficher_employe());
         ui->comboBox_id->setModel(tmpemployee.afficher_employe());
         ui->comboBox_id_2->setModel(tmpemployee.afficher_employe());
        QMessageBox::information(nullptr, QObject::tr("supprimer un employee"),
                    QObject::tr("employee a ete supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    ui->lineEdit->clear();
}

void gestion_perso_conge::on_pushButton_modifier_clicked()
{
     QString idp=ui->lineEdit->text();
   // QString idp=ui->comboBox_id->currentText();
    QString nom=ui->lineEdit_2->text();
    QString prenom=ui->lineEdit_3->text();
    QString adress=ui->lineEdit_4->text();
    classe_personnel p(idp,nom,prenom,adress);
    bool test=p.modifier_employe(idp);
    if(test)
    {
        ui->comboBox_id->setModel(tmpemployee.afficher_employe());
         ui->tableView->setModel(tmpemployee.afficher_employe());
        QMessageBox::information(nullptr, QObject::tr("modifier un employee"),
                    QObject::tr("employee modifié.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
}


void gestion_perso_conge::on_pushButton_tri_clicked()
{


       if(ui->radioButton->isChecked())
        ui->tableView->setModel(tmpemployee.tri_id_employe());
        else if(ui->radioButton_2->isChecked())
            ui->tableView->setModel(tmpemployee.tri_nom_employe());
        else if(ui->radioButton_3->isChecked())
            ui->tableView->setModel(tmpemployee.tri_prenom_employe());


}



void gestion_perso_conge::on_pushButton_chercher_clicked()
{

    int idp=ui->lineEdit->text().toInt();
        QString nom=ui->lineEdit_2->text();
        QString prenom=ui->lineEdit_3->text();
       if(nom==""&&prenom==""){
       QString txt=ui->lineEdit->text();
      ui->tableView->setModel(tmpemployee.recherche_id_employe(txt));
       }
       else    if(idp==0&&prenom==""){
           QString txt=ui->lineEdit_2->text();
          ui->tableView->setModel(tmpemployee.recherche_nom_employe(txt));}
       else    if(idp==0&&nom==""){
           QString txt=ui->lineEdit_3->text();
          ui->tableView->setModel(tmpemployee.recherche_prenom_employe(txt));}
       ui->lineEdit->clear();
       ui->lineEdit_2->clear();
       ui->lineEdit_3->clear();
}

void gestion_perso_conge::on_pushButton_pdf_clicked()
{

                 QString strStream;
                 QTextStream out(&strStream);
                 const int rowCount1 = ui->tableView->model()->rowCount();
                 const int columnCoun1t =  ui->tableView->model()->columnCount();
                 const QString strTitle ="Document";
                 out <<  "<html>\n"
                          "   <img src='C:/Users/oumayma/oumayma/img/logo.jpg' height='526' width='526'/>"
                     "<head>\n"
                         "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                      "<img src='img.png'>"
                     <<  QString("<title>%1</title>\n").arg(strTitle)
                     <<  "</head>\n"
                     "<body bgcolor=#ffffff link=#5000A0>\n"
                    << QString("<h3 style=\"  font-size=96px, font-family: Arial , Helvetica, sans-serif; color: #FF9933; font-weight: bold; text-align: left;\">%1</h3>\n").arg("Liste des employées :")
                    <<"<br>"
                     <<"<table border=1 cellspacing=0 cellpadding=40>\n";

                 out << "<thead><tr bgcolor=#f0f0f0>";
                 for (int column = 0; column < columnCoun1t; column++)
                     if (!ui->tableView->isColumnHidden(column))
                         out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
                 out << "</tr></thead>\n";

                 for (int row = 0; row < rowCount1; row++) {
                     out << "<tr>";
                     for (int column = 0; column < columnCoun1t; column++) {
                         if (!ui->tableView->isColumnHidden(column)) {
                             QString data =ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
                             out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                         }
                     }
                     out << "</tr>\n";
                 }
                 out <<  "</table>\n"
                         "<br><br>"
                         <<"<br>"
                         <<"<table border=1 cellspacing=0 cellpadding=2>\n";


                     out << "<thead><tr bgcolor=#f0f0f0>";

                         out <<  "</table>\n"
                     "</body>\n"

                     "</html>\n";

                 QTextDocument *document = new QTextDocument();
                 document->setHtml(strStream);

                 QPrinter printer;
                 QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                 if (dialog->exec() == QDialog::Accepted) {

                     //QPrinter printer(QPrinter::PrinterResolution);


                     document->print(&printer);
                 }

                 printer.setOutputFormat(QPrinter::PdfFormat);
                 printer.setPaperSize(QPrinter::A4);
                 printer.setOutputFileName("/tmp/employee.pdf");
                 printer.setPageMargins(QMarginsF(15, 15, 15, 15));
                 delete document;

}



void gestion_perso_conge::on_pushButton_ajouter_conge_clicked()
{
    QString idc=ui->lineEdit_5->text();
    QString nom=ui->lineEdit_6->text();
    QString date_debut=ui->dateEdit->text();
    QString duree=ui->lineEdit_7->text();
    classe_conge p(idc,nom,date_debut,duree);
    bool test=p.ajouter_conge();

    if(test)
    {

         ui->tableView_2->setModel(tmpconge.afficher_conge());
         ui->comboBox_id_2->setModel(tmpconge.afficher_conge());
        QMessageBox::information(nullptr, QObject::tr("ajouter un employee"),
                    QObject::tr("employee ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
    ui->lineEdit_7->clear();
}

void gestion_perso_conge::on_pushButton_supprimer_conge_clicked()
{

    QString idc=ui->comboBox_id_2->currentText();
    bool test=tmpconge.supprimer_conge(idc);
    if(test)
    {
         ui->tableView_2->setModel(tmpconge.afficher_conge());
        // ui->comboBox_id_2->setModel(tmpconge.afficher_conge());
        QMessageBox::information(nullptr, QObject::tr("supprimer un employee"),
                    QObject::tr("employee a ete supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    ui->lineEdit_5->clear();
}

void gestion_perso_conge::on_pushButton_modifier_conge_clicked()
{
     QString idc=ui->comboBox_id_2->currentText();

    QString nom=ui->lineEdit_6->text();
    QString date_debut=ui->dateEdit->text();
    QString duree=ui->lineEdit_7->text();
    classe_conge p(idc,nom,date_debut,duree);
    bool test=p.modifier_conge(idc);
    if(test)
    {
       // ui->comboBox_id_2->setModel(tmpconge.afficher_conge());
         ui->tableView_2->setModel(tmpconge.afficher_conge());
        QMessageBox::information(nullptr, QObject::tr("modifier un employee"),
                    QObject::tr("employee modifié.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();

    ui->lineEdit_7->clear();
}

void gestion_perso_conge::on_pushButton_afficher_conge_clicked()
{
    ui->tableView_2->setModel(tmpconge.afficher_conge());

}

void gestion_perso_conge::on_pushButton_chercher_conge_clicked()
{
    int idc=ui->lineEdit_5->text().toInt();
        QString nom=ui->lineEdit_6->text();
        QString date_debut=ui->dateEdit->text();
       if(idc!=0){
       QString txt=ui->lineEdit_5->text();
      ui->tableView_2->setModel(tmpconge.recherche_id_conge(txt));
       }
       else    if(nom!=""){
           QString txt=ui->lineEdit_6->text();
          ui->tableView_2->setModel(tmpconge.recherche_nom_conge(txt));}
       else    if(idc==0&&nom==""){
           QString txt=ui->dateEdit->text();
          ui->tableView_2->setModel(tmpconge.recherche_date_conge(txt));}
       ui->lineEdit_5->clear();
       ui->lineEdit_6->clear();

}

void gestion_perso_conge::on_pushButton_imprimer_conge_clicked()
{
    QString strStream;
    QTextStream out(&strStream);
    const int rowCount1 = ui->tableView_2->model()->rowCount();
    const int columnCoun1t =  ui->tableView_2->model()->columnCount();
    const QString strTitle ="Document";
    out <<  "<html>\n"
             "   <img src='C:/Users/oumayma/oumayma/img/logo.jpg' height='526' width='526'/>"
        "<head>\n"
            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
         "<img src='img.png'>"
        <<  QString("<title>%1</title>\n").arg(strTitle)
        <<  "</head>\n"
        "<body bgcolor=#ffffff link=#5000A0>\n"
       << QString("<h3 style=\"  font-size=96px, font-family: Arial , Helvetica, sans-serif; color: #FF9933; font-weight: bold; text-align: left;\">%1</h3>\n").arg("Liste des congés :")
       <<"<br>"
        <<"<table border=1 cellspacing=0 cellpadding=40>\n";

    out << "<thead><tr bgcolor=#f0f0f0>";
    for (int column = 0; column < columnCoun1t; column++)
        if (!ui->tableView_2->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->tableView_2->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    for (int row = 0; row < rowCount1; row++) {
        out << "<tr>";
        for (int column = 0; column < columnCoun1t; column++) {
            if (!ui->tableView_2->isColumnHidden(column)) {
                QString data =ui->tableView_2->model()->data(ui->tableView_2->model()->index(row, column)).toString().simplified();
                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
            }
        }
        out << "</tr>\n";
    }
    out <<  "</table>\n"
            "<br><br>"
            <<"<br>"
            <<"<table border=1 cellspacing=0 cellpadding=2>\n";


        out << "<thead><tr bgcolor=#f0f0f0>";

            out <<  "</table>\n"
        "</body>\n"

        "</html>\n";

    QTextDocument *document = new QTextDocument();
    document->setHtml(strStream);

    QPrinter printer;
    QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
    if (dialog->exec() == QDialog::Accepted) {

        QPrinter printer(QPrinter::PrinterResolution);


        document->print(&printer);
    }

    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName("/tmp/congé.pdf");
    printer.setPageMargins(QMarginsF(15, 15, 15, 15));
    delete document;
}



void gestion_perso_conge::on_comboBox_id_2_currentTextChanged(const QString &arg1)
{

    QString txt=arg1;
  ui->lineEdit_5->setText(txt);
  qDebug()<<txt;
          ui->comboBox_id_3->setModel( tmpemployee.afficher_employe_1(txt));
 ui->lineEdit_6->setText(ui->comboBox_id_3->currentText());
}

void gestion_perso_conge::on_comboBox_id_currentTextChanged(const QString &arg1)
{
    QString txt=arg1;
  ui->lineEdit->setText(txt);
  qDebug()<<txt;
}
