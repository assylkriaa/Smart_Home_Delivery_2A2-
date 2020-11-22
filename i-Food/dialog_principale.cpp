#include "dialog_principale.h"
#include "ui_dialog_principale.h"
#include"emplacement.h"
#include"reclamation.h"
#include"mainwindow.h"
#include"QMessageBox"
#include"QFile"
#include"QFileDialog"
#include"QPrinter"
#include"QPrintDialog"
#include"QTextDocument"
#include"QPropertyAnimation"

Dialog_principale::Dialog_principale(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_principale)
{
    ui->setupUi(this);
    QPixmap pix("D:/Esprit/2A2/projet c++/logo/EFOOD2.png");
    ui->label_9->setPixmap(pix);
    QPixmap pix1("D:/Esprit/2A2/projet c++/logo/debug2.png");
    ui->label_10->setPixmap(pix1);
    ui->label_11->setPixmap(pix);
    ui->label_12->setPixmap(pix1);



    ui->tableView_emplacement->setModel(tempEmplacement.afficherempl());
    ui->tableView_reclamation->setModel(tempReclamation.afficherecl());
}

Dialog_principale::~Dialog_principale()
{
    delete ui;
}

void Dialog_principale::on_pushButton_ajouter_empl_clicked()
{
    QString nom_secteur=ui->lineEdit_nom_secteur->text();
    QString ville=ui->lineEdit_2_ville_secteur->text();
    QString code_postal=ui->lineEdit_3_code_postal->text();
    QString date_emplacement=ui->lineEdit_4_date_emplacement->text();
    emplacement e(nom_secteur,ville,code_postal,date_emplacement);
    bool test=e.ajouterempl();
        if(test)
        {
           QMessageBox::critical(this,tr("SAVE"),tr("saved"));
           ui->tableView_emplacement->setModel(tempEmplacement.afficherempl());
        }
        else
        {
            QMessageBox::critical(this,tr("error"),tr("not saved"));
        }
}

void Dialog_principale::on_pushButton_ajouter_reclamation_clicked()
{
    QString code=ui->lineEdit_code_reclamation->text();
    QString sujet=ui->lineEdit_sujet_reclamation->text();
    QString commentaire=ui->lineEdit_commentaire_reclamation->text();
    QString date_reclamation=ui->lineEdit_date_reclamation->text();
    reclamation r(code,sujet,commentaire,date_reclamation);
    bool test=r.ajouterecl();
        if(test)
        {
           QMessageBox::critical(this,tr("SAVE"),tr("saved"));
           ui->tableView_reclamation->setModel(tempReclamation.afficherecl());
        }
        else
        {
            QMessageBox::critical(this,tr("error"),tr("not saved"));
        }
}

void Dialog_principale::on_pushButton_afficher_empl_clicked()
{
//nothing//
}

void Dialog_principale::on_pushButton_afficher_reclamation_clicked()
{
//nothing//
}

void Dialog_principale::on_pushButton_modifier_empl_clicked()
{

        QString nom_secteur,ville,code_postal,date_ajout;
        nom_secteur=ui->lineEdit_nom_secteur->text();
        ville=ui->lineEdit_2_ville_secteur->text();
        code_postal=ui->lineEdit_3_code_postal->text();
        date_ajout=ui->lineEdit_4_date_emplacement->text();
        bool test=tempEmplacement.modifierempl(nom_secteur,ville,code_postal,date_ajout);
        if(test)
        {
           QMessageBox::critical(this,tr("Edit"),tr("Updated"));
           ui->tableView_emplacement->setModel(tempEmplacement.afficherempl());
        }
        else
        {
            QMessageBox::critical(this,tr("error::"),tr("not updated"));
        }
}

void Dialog_principale::on_pushButton_modifier_reclamation_clicked()
{
    QString code,sujet,commentaire,date_reclamation;
    code=ui->lineEdit_code_reclamation->text();
    sujet=ui->lineEdit_sujet_reclamation->text();
    commentaire=ui->lineEdit_commentaire_reclamation->text();
    date_reclamation=ui->lineEdit_date_reclamation->text();
    bool test=tempReclamation.modifierecl(code,sujet,commentaire,date_reclamation);
    if(test)
    {
       QMessageBox::critical(this,tr("Edit"),tr("Updated"));
       ui->tableView_reclamation->setModel(tempReclamation.afficherecl());
    }
    else
    {
        QMessageBox::critical(this,tr("error::"),tr("not updated"));
    }
}
void Dialog_principale::on_pushButton_supp_empl_clicked()
{
    QString nom_secteur=ui->lineEdit_nom_secteur->text();
    bool test=tempEmplacement.supprimerempl(nom_secteur);
        if(test)
        {
           QMessageBox::critical(this,tr("Delete"),tr("Deleted"));
           ui->tableView_emplacement->setModel(tempEmplacement.afficherempl());
        }
        else
        {
            QMessageBox::critical(this,tr("error::"),tr("not deleted"));
        }
}

void Dialog_principale::on_pushButton_supp_reclamation_clicked()
{
    QString code=ui->lineEdit_code_reclamation->text();
    bool test=tempReclamation.supprimerecl(code);
        if(test)
        {
           QMessageBox::critical(this,tr("Delete"),tr("Deleted"));
           ui->tableView_reclamation->setModel(tempReclamation.afficherecl());
        }
        else
        {
            QMessageBox::critical(this,tr("error::"),tr("not deleted"));
        }
}

void Dialog_principale::on_pushButton_enregistrer_empl_clicked()
{
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
        if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append("emplacement.pdf"); }

        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPaperSize(QPrinter::A4);
        printer.setOutputFileName(fileName);

        QTextDocument doc;
        QSqlQuery q;
        q.prepare("SELECT * FROM emplacement ");
        q.exec();
        QString pdf="<br> <h1  style='color:red'>LISTE DES EMPLACEMENT  <br></h1>\n <br> <table>  <tr>  <th> NOM SECTEUR </th> <th> VILLE SECTEUR </th> <th> CODE POSTAL </th> <th> DATE AJOUT </th>  </tr>" ;


        while ( q.next()) {

            pdf= pdf+ " <br> <tr> <td>"+ q.value(0).toString()+"    </td>   <td>   " + q.value(1).toString() +"</td>   <td>" +q.value(2).toString() +"  "" " "</td>   <td>"+q.value(3).toString()+"</td>    <td>"+q.value(4).toString()+" </td>" ;

        }
        doc.setHtml(pdf);
        doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
        doc.print(&printer);
}

void Dialog_principale::on_pushButton_imprimer_empl_clicked()
{
    QPrinter rd;
       QPrintDialog d(&rd,this);
        d.setWindowTitle("Print table emplacement");
        d.addEnabledOption(QAbstractPrintDialog::PrintSelection);
        if (d.exec() != QDialog::Accepted)
            return ;
}

void Dialog_principale::on_pushButton_trier_empl_clicked()
{
    ui->tableView_emplacement->setModel(tempEmplacement.trierempl());
}

void Dialog_principale::on_pushButton_trier_reclamation_clicked()
{
    ui->tableView_reclamation->setModel(tempReclamation.trierecl());
}

void Dialog_principale::on_pushButton_3_clicked()
{


}

void Dialog_principale::on_pushButton_imprimer_reclamation_clicked()
{
    QPrinter rd;
        QPrintDialog d(&rd,this);
        d.setWindowTitle("Print table reclamation");
        d.addEnabledOption(QAbstractPrintDialog::PrintSelection);
        if (d.exec() != QDialog::Accepted)
            return ;
}

void Dialog_principale::on_pushButton_enregistrer_reclamation_clicked()
{
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
        if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append("reclamation.pdf"); }

        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPaperSize(QPrinter::A4);
        printer.setOutputFileName(fileName);

        QTextDocument doc;
        QSqlQuery q;
        q.prepare("SELECT * FROM reclamation ");
        q.exec();
        QString pdf="<br> <h1  style='color:red'>LISTE DES RECLAMATION  <br></h1>\n <br> <table>  <tr>  <th> CODE </th> <th> SUJET </th> <th> COMMENTAIRE </th> <th> DATE AJOUT </th>  </tr>" ;


        while ( q.next()) {

            pdf= pdf+ " <br> <tr> <td>"+ q.value(0).toString()+"    </td>   <td>   " + q.value(1).toString() +"</td>   <td>" +q.value(2).toString() +"  "" " "</td>   <td>"+q.value(3).toString()+"</td>    <td>"+q.value(4).toString()+" </td>" ;

        }
        doc.setHtml(pdf);
        doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
        doc.print(&printer);
}
