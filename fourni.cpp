#include "fourni.h"
#include "ui_fourni.h"
#include <QDebug>
#include "agent.h"
#include <QFileDialog>
#include <QPdfWriter>
#include <QPrinter>
#include <QPrintDialog>
#include <QTextDocument>
#include <QSortFilterProxyModel>
#include <QSound>
fourni::fourni(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fourni)
{
    ui->setupUi(this);
    QSqlQueryModel * model = tmpfourni.afficher();

   ui->tableView->setModel( model);
   QSortFilterProxyModel *m=new QSortFilterProxyModel(this);
       m->setDynamicSortFilter(true);
       m->setSourceModel(model);
       ui->tableView->setModel(m);
       ui->tableView->setSortingEnabled(true);




    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
}

fourni::~fourni()
{
    delete ui;
}

void fourni::on_login_3_clicked()
{
    //Agent * w= new Agent;
    Agent a;
      a.exec();
}

void fourni::on_pushButton_ajouter_clicked()
{
    QString Numero = ui->NumeroLineEdit->text();
            QString Nom= ui->nomLineEdit->text();
            QString Adresse= ui->AdresseLineEdit->text();
            QString Email= ui->eMailLineEdit->text();
            QString Type= ui->TypeComboBox->currentText();

            fournisseurs fourn(Nom,Adresse,Email,Numero,Type);

            bool test=fourn.ajouter();

            if (test){
                QSqlQueryModel * model = tmpfourni.afficher();
               ui->tableView->setModel( model);
               QSortFilterProxyModel *m=new QSortFilterProxyModel(this);
                   m->setDynamicSortFilter(true);
                   m->setSourceModel(model);
                   ui->tableView->setModel(m);
                   ui->tableView->setSortingEnabled(true);}


}

void fourni::on_pushButton_reset_clicked()
{
    ui->NumeroLineEdit->setText("");
    ui->nomLineEdit->setText("");
    ui->AdresseLineEdit->setText("");
    ui->eMailLineEdit->setText("");
}

void fourni::on_pushButton_supprimer_clicked()
{
    QItemSelectionModel *select = ui->tableView->selectionModel();

    QString num =select->selectedRows(2).value(0).data().toString();

qDebug() << num ;
    if(tmpfourni.supprimer(num))
        {
        ui->tableView->setModel(tmpfourni.afficher());
        //ui->statusbar->showMessage("Fournisseur supprimé");
         }
}

void fourni::on_tableView_activated(const QModelIndex &index)
{
    QString numero=ui->tableView->model()->data(index).toString();
          QSqlQuery query;
          query.prepare("select * from FOURNISSEURS where numero LIKE '"+numero+"%' or nom LIKE '"+numero+"%' or adresse LIKE '"+numero+"%'");
          if(query.exec())
          {
            while(query.next())
            {
                ui->NumeroLineEdit->setText(query.value(2).toString());
                ui->nomLineEdit->setText(query.value(0).toString());
                ui->AdresseLineEdit->setText(query.value(1).toString());
                ui->eMailLineEdit->setText(query.value(4).toString());

            }
          }
            else
            {

                //QMessageBox::critical(this,tr("error::"),query.lastError().text());
              QMessageBox::critical(nullptr, QObject::tr("error"),
                          QObject::tr("error.\n""Click Cancel to exit."), QMessageBox::Cancel);
          }
}

void fourni::on_pushButton_recherche_clicked()
{
    QString numero =ui->lineEdit_recherche->text();
    ui->tableView->setModel(tmpfourni.recherche(numero));
}

void fourni::on_pushButton_3_clicked()
{
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
     if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

     QPrinter printer(QPrinter::PrinterResolution);
     printer.setOutputFormat(QPrinter::PdfFormat);
     printer.setPaperSize(QPrinter::A4);
     printer.setOutputFileName(fileName);

     QTextDocument doc;
     QSqlQuery q;
     q.prepare("SELECT * FROM FOURNISSEURS ");
     q.exec();
     QString pdf="<br><br> <img src='C:/Users/LEGION/Desktop/logo.png' height='42' align='left' width='144'/>  <h1 align='middle' style='color:blue;   style='display: block;margin: auto;max-width: 600px;padding:5px;width: 100%;'>LISTE DES FOURNISSEURS  <br></h1>\n <br> <table  style='border: 1px solid black;background: white; border-radius:3px; border-collapse: collapse; margin: auto;  padding:5px; width: 100%; box-shadow: 0 5px 10px rgba(0, 0, 0, 0.1);'>  <tr>  <th style='border: 1px solid black;color:#D5DDE5;background:#1b1e24;border-bottom:4px solid #9ea7af;border-right: 1px solid #343a45;font-size:12px;font-weight: 100;padding:24px;text-align:left;text-shadow: 0 1px 1px rgba(0, 0, 0, 0.1);vertical-align:middle;'>NUMERO </th> <th style='border: 1px solid black;color:#D5DDE5;background:#1b1e24;border-bottom:4px solid #9ea7af;border-right: 1px solid #343a45;font-size:12px;font-weight: 100;padding:24px;text-align:left;text-shadow: 0 1px 1px rgba(0, 0, 0, 0.1);vertical-align:middle;'>NOM </th> <th style='border: 1px solid black;color:#D5DDE5;background:#1b1e24;border-bottom:4px solid #9ea7af;border-right: 1px solid #343a45;font-size:12px;font-weight: 100;padding:24px;text-align:left;text-shadow: 0 1px 1px rgba(0, 0, 0, 0.1);vertical-align:middle;'>ADRESSE </th> <th style='border: 1px solid black;color:#D5DDE5;background:#1b1e24;border-bottom:4px solid #9ea7af;border-right: 1px solid #343a45;font-size:12px;font-weight: 100;padding:12px;text-align:left;text-shadow: 0 1px 1px rgba(0, 0, 0, 0.1);vertical-align:middle;'> EMAIL </th> <th style='border: 1px solid black;color:#D5DDE5;background:#1b1e24;border-bottom:4px solid #9ea7af;border-right: 1px solid #343a45;font-size:12px;font-weight: 100;padding:12px;text-align:left;text-shadow: 0 1px 1px rgba(0, 0, 0, 0.1);vertical-align:middle;border: 1px solid black;'>TYPE </th>  </tr>" ;


     while ( q.next()) {

         pdf= pdf+ " <br> <tr style='border-top: 1px solid #C1C3D1; border-bottom-: 1px solid #C1C3D1; color:#666B85;padding-bottom:5px; font-size:16px; font-weight:normal; text-shadow: 0 1px 1px rgba(256, 256, 256, 0.1);'> <td style='border: 1px solid black;border: 1px solid black;background:#FFFFFF; padding:20px; text-align:left; vertical-align:middle; font-weight:300; font-size:8px; text-shadow: -1px -1px 1px rgba(0, 0, 0, 0.1); border-right: 1px solid #C1C3D1;'>"+ q.value(2).toString()+"</td>  <td style='border: 1px solid black;border: 1px solid black;background:#FFFFFF; padding:20px; text-align:left; vertical-align:middle; font-weight:300; font-size:8px; text-shadow: -1px -1px 1px rgba(0, 0, 0, 0.1); border-right: 1px solid #C1C3D1;'> " + q.value(0).toString() +"</td>   <td style='border: 1px solid black;background:#FFFFFF; padding:20px; text-align:left; vertical-align:middle; font-weight:300; font-size:8px; text-shadow: -1px -1px 1px rgba(0, 0, 0, 0.1); border-right: 1px solid #C1C3D1;'>" +q.value(1).toString() +"  "" " "</td>   <td style='border: 1px solid black;background:#FFFFFF; padding:20px; text-align:left; vertical-align:middle; font-weight:300; font-size:8px; text-shadow: -1px -1px 1px rgba(0, 0, 0, 0.1); border-right: 1px solid #C1C3D1;'>"+q.value(4).toString()+"</td>   <td style='border: 1px solid black;background:#FFFFFF; padding:20px; text-align:left; vertical-align:middle; font-weight:300; font-size:8px; text-shadow: -1px -1px 1px rgba(0, 0, 0, 0.1); border-right: 1px solid #C1C3D1;'>"+q.value(3).toString()+" "  " " "</td> </td>" ;

     }
     doc.setHtml(pdf);
     doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
     doc.print(&printer);
}

void fourni::on_pushButton_2_clicked()
{
    QPrinter rd;
        QPrintDialog d(&rd,this);
        d.setWindowTitle("Print Livre");
        d.addEnabledOption(QAbstractPrintDialog::PrintSelection);
        if (d.exec() != QDialog::Accepted)
            return ;
}

void fourni::on_pushButton_4_clicked()
{
    // int cin =ui->lineEdit_40->text().toInt();
     //    int telephone=ui->lineEdit_34->text().toInt();
     QString Numero = ui->NumeroLineEdit->text();
     QString Nom= ui->nomLineEdit->text();
     QString Adresse= ui->AdresseLineEdit->text();
     QString Email= ui->eMailLineEdit->text();
     QString Type= ui->TypeComboBox->currentText();

     fournisseurs fourn(Nom,Adresse,Numero,Type,Email);

     bool test=fourn.modifier(Nom,Adresse,Numero,Type,Email);
           if(test)
         {


                               QSqlQueryModel * model = tmpfourni.afficher();
                              ui->tableView->setModel( model);
                              QSortFilterProxyModel *m=new QSortFilterProxyModel(this);
                                  m->setDynamicSortFilter(true);
                                  m->setSourceModel(model);
                                  ui->tableView->setModel(m);
                                  ui->tableView->setSortingEnabled(true);
                                  QMessageBox::information(nullptr, QObject::tr("Modifier"),
                           QObject::tr("Modification avec succees.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);

         }
           else
               QMessageBox::critical(nullptr, QObject::tr("Modifier"),
                           QObject::tr("Erreur !.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
}
