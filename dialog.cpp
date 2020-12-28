#include "dialog.h"
#include "ui_dialog.h"
#include"mainwindow.h"
#include <QPrinter>
#include"QFileDialog"
#include <QPrintDialog>
#include <QPainter>
#include <QTextStream>
#include <QTextDocument>
#include <QDateTime>
#include <QMessageBox>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->comboBox_client->addItem("ID et nom");
            ui->comboBox_client->addItem("ID et prenom");
            ui->comboBox_client->addItem("ID et adresse");
            ui->comboBox_client->addItem("nom et prenom");
            ui->comboBox_client->addItem("nom et adresse");
            ui->comboBox_client->addItem("prenom et adresse");
            ui->comboBox_commande->addItem("ID");
            ui->comboBox_commande->addItem("nom_commande");
            ui->comboBox_commande->addItem("nbc");
            ui->comboBox_choix->addItem("croissant");
            ui->comboBox_choix->addItem("decroissant");



   /* ui->tableView->setModel(tempCommande.afficher());*/
}

Dialog::~Dialog()
{
    delete ui;
}
void Dialog::on_pushButton_ajouterco_clicked()
{



    int nb=ui->spinBox->text().toInt();
    int id=ui->lineEdit_IDCOMMANDES->text().toInt();
    QString nom_commande=ui->lineEdit_commande->text();

    Commande c(nom_commande,nb,id);
    bool test=c.ajouter();

    if(test)
    {
        /*ui->tableView->setModel(tempCommande.afficher());*/
        QMessageBox::information(nullptr, QObject::tr("Ajout"),
                    QObject::tr("ajout avec succes.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("ajout "),
                    QObject::tr("ajout echoue.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void Dialog ::on_pushButton_afficherco_clicked()
{
    QSqlQueryModel * Modal=new  QSqlQueryModel();

    QSqlQuery qry;
     qry.prepare("SELECT ID FROM Commandes ");
     qry.exec();
     Modal->setQuery(qry);
     ui->comboBox_modifiercoma->setModel(Modal);
    ui->tableView->setModel(tempCommande.afficher());
}

void Dialog::on_pushButton_suprimerco_clicked()
{
    int id=ui->lineEdit_IDCOMMANDES->text().toInt();
    bool test=tempCommande.supprimer(id);
    if(test)
    {

        QMessageBox::information(nullptr, QObject::tr("supprimer"),
                    QObject::tr("supression avec succes.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

 }
    else
        QMessageBox::critical(nullptr, QObject::tr("supprimer"),
                    QObject::tr("surppresion echoue.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void Dialog::on_pushButton_ajouterct_clicked()
{


    int ID=ui->lineEdit_ID->text().toInt();
    QString nom=ui->lineEdit_nom->text();
    QString prenom=ui->lineEdit_prenom->text();
    QString adresse=ui->lineEdit_adresse->text();

    Client c(ID,nom,prenom,adresse);
    bool test=c.ajouter();
    if(test)
    {

        QMessageBox::information(nullptr, QObject::tr("Ajout"),
                    QObject::tr("ajout avec succes.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("ajout "),
                    QObject::tr("ajout echoue.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void Dialog::on_pushButton_afficherct_clicked()
{
    QSqlQueryModel * Modal=new  QSqlQueryModel();

    QSqlQuery qry;
     qry.prepare("SELECT ID FROM Clients ");
     qry.exec();
     Modal->setQuery(qry);
     ui->comboBox_modifiercli->setModel(Modal);
    ui->tableView_client->setModel(tempClient.afficher());

}

void Dialog::on_pushButton_suprimerct_clicked()
{
    int id=ui->lineEdit_ID->text().toInt();
    bool test=tempClient.supprimer(id);
    if(test)
    {

        QMessageBox::information(nullptr, QObject::tr("supprimer"),
                    QObject::tr("supression avec succes.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

 }
    else
        QMessageBox::critical(nullptr, QObject::tr("supprimer "),
                    QObject::tr("surppresion echoue.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void Dialog::on_pushButton_modifierco_clicked()
{
    int nb=ui->spinBox->text().toInt();
    int id=ui->lineEdit_IDCOMMANDES->text().toInt();
    QString nom_commande=ui->lineEdit_commande->text();

    Commande c(nom_commande,nb,id);
    bool test=c.modifier();
    if(test)
    {

        QMessageBox::information(nullptr, QObject::tr("Modifier"),
                    QObject::tr("Modification avec succes.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("Modifier "),
                    QObject::tr("Modification echoue.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void Dialog::on_pushButton_modifierct_clicked()
{
    int ID=ui->lineEdit_ID->text().toInt();
    QString nom=ui->lineEdit_nom->text();
    QString prenom=ui->lineEdit_prenom->text();
    QString adresse=ui->lineEdit_adresse->text();

    Client c(ID,nom,prenom,adresse);
    bool test=c.modifier();
    if(test)
    {

        QMessageBox::information(nullptr, QObject::tr("Modifier"),
                    QObject::tr("Modification avec succes.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("Modifier "),
                    QObject::tr("Modification echoue.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void Dialog::on_pushButton_rechercherco_clicked()
{

    QString a=ui->lineEdit_recherche->text();
    QString b=ui->lineEdit_reee->text();
    QString choice=ui->comboBox_client->currentText();
     ui->tableView_client->setModel(tempClient.rechercher(choice,a,b));
}

void Dialog::on_pushButton_trierco_clicked()
{
QString a=ui->comboBox_choix->currentText();
    QString choice=ui->comboBox_commande->currentText();
     ui->tableView->setModel(tempCommande.trier(choice,a));
}




void Dialog::on_pushButton_enregistrerco_clicked()
{

    QSqlDatabase db;
                  QTableView tableView;

                   tableView.setModel(tempCommande.enregistrer());
                   db.close();


                   QString strStream;
                   QTextStream out(&strStream);

                   const int rowCount = tableView.model()->rowCount();
                   const int columnCount =  tableView.model()->columnCount();

                   QString date = QDateTime::currentDateTime().toString();
out<<date;

                   const QString strTitle ="Document";


                   out <<  "<html>\n"
                       "<head>\n"
                           "<meta Content=\"Text/html; charset=Windows-1251\">\n"

                       <<  QString("<title>%1</title>\n").arg(strTitle)
                       <<  "</head>\n"
                       "<body bgcolor=#ffffff link=#5000A0>\n"
                      << QString("<h3 style=\" font-size: 40px; font-family: Arial, Helvetica, sans-serif; color: #0894FD; font-weight: lighter; text-align: center;\">%1</h3>\n").arg("Liste des Commandes")
                      <<"<br>"
                       <<"<table border=1 cellspacing=0 cellpadding=2 width=\"100%\">\n";

                   out << "<thead><tr bgcolor=#f0f0f0>";
                   for (int column = 0; column < columnCount; column++)
                       if (!tableView.isColumnHidden(column))
                           out << QString("<th>%1</th>").arg(tableView.model()->headerData(column, Qt::Horizontal).toString());
                   out << "</tr></thead>\n";

                   for (int row = 0; row < rowCount; row++) {
                       out << "<tr>";
                       for (int column = 0; column < columnCount; column++) {
                           if (!tableView.isColumnHidden(column)) {
                               QString data = tableView.model()->data(tableView.model()->index(row, column)).toString().simplified();
                               out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                           }
                       }
                       out << "</tr>\n";
                   }
                   out <<  "</table>\n"
                           "<br><br>"

                           "<p align='center'> <img src='/C:/Users/pc/Desktop/Nouveau dossier/naoto.png' alt='naoto.png'></p>"

                        <<"<br>"
                           <<"<table border=1 cellspacing=0 cellpadding=2 >\n";


                       out << "<thead><tr bgcolor=#f0f0f0>";

                           out <<  "</table >\n"

                       "</body>\n"

                       "</html>\n";

                   QTextDocument *document = new QTextDocument();
                   document->setHtml(strStream);

                   QPrinter printer;
                   QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                   if (dialog->exec() == QDialog::Accepted) {

                      /* QLabel lab;
                        QPixmap pixmap("D:/care++.png");
                       lab.setPixmap(pixmap);
                       QPainter painter(&lab);
                       QPrinter printer(QPrinter::PrinterResolution);
  */
                       document->print(&printer);

                   }

                   printer.setOutputFormat(QPrinter::PdfFormat);
                   printer.setPaperSize(QPrinter::A4);
                   printer.setOutputFileName("C:/Users/pc/Desktop/projet c++/PDF/commande.pdf");
                   printer.setPageMargins(QMarginsF(15, 15, 15, 15));



                   delete document;
}

void Dialog::on_pushButton_enregistrerct_clicked()
{
    QSqlDatabase db;
                  QTableView tableView;

                   tableView.setModel(tempClient.enregistrer());



                   db.close();


                   QString strStream;
                   QTextStream out(&strStream);

                   const int rowCount = tableView.model()->rowCount();
                   const int columnCount =  tableView.model()->columnCount();


                   QString date = QDateTime::currentDateTime().toString();
out<<date;
                   const QString strTitle ="Document";


                   out <<  "<html>\n"
                       "<head>\n"
                           "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                       <<  QString("<title>%1</title>\n").arg(strTitle)
                       <<  "</head>\n"
                       "<body bgcolor=#ffffff link=#5000A0>\n"
                      << QString("<h3 style=\" font-size: 40px; font-family: Arial, Helvetica, sans-serif; color: #0894FD; font-weight: lighter; text-align: center;\">%1</h3>\n").arg("Liste des Comptes Clients")
                      <<"<br>"
                       <<"<table border=1 cellspacing=0 cellpadding=2 width=\"100%\">\n";

                   out << "<thead><tr bgcolor=#f0f0f0>";
                   for (int column = 0; column < columnCount; column++)
                       if (!tableView.isColumnHidden(column))
                           out << QString("<th>%1</th>").arg(tableView.model()->headerData(column, Qt::Horizontal).toString());
                   out << "</tr></thead>\n";

                   for (int row = 0; row < rowCount; row++) {
                       out << "<tr>";
                       for (int column = 0; column < columnCount; column++) {
                           if (!tableView.isColumnHidden(column)) {
                               QString data = tableView.model()->data(tableView.model()->index(row, column)).toString().simplified();
                               out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                           }
                       }
                       out << "</tr>\n";
                   }
                   out <<  "</table>\n"
                           "<br><br>"

                           "<p align='center'> <img src='/C:/Users/pc/Desktop/Nouveau dossier/naoto.png' alt='naoto.png'></p>"

                        <<"<br>"
                           <<"<table border=1 cellspacing=0 cellpadding=2 >\n";


                       out << "<thead><tr bgcolor=#f0f0f0>";

                           out <<  "</table >\n"

                       "</body>\n"

                       "</html>\n";

                   QTextDocument *document = new QTextDocument();
                   document->setHtml(strStream);

                   QPrinter printer;
                   QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                   if (dialog->exec() == QDialog::Accepted) {

                      /* QLabel lab;
                        QPixmap pixmap("D:/care++.png");
                       lab.setPixmap(pixmap);
                       QPainter painter(&lab);
                       QPrinter printer(QPrinter::PrinterResolution);
  */
                       document->print(&printer);

                   }

                   printer.setOutputFormat(QPrinter::PdfFormat);
                   printer.setPaperSize(QPrinter::A4);
                   printer.setOutputFileName("C:/Users/pc/Desktop/projet c++/PDF/compte_client.pdf");
                   printer.setPageMargins(QMarginsF(15, 15, 15, 15));



                   delete document;
}

void Dialog::on_comboBox_modifiercoma_currentIndexChanged(const QString &arg1)
{
    QString name =ui->comboBox_modifiercoma->currentText();
    name=arg1;
    QSqlQuery qry;
     qry.prepare("SELECT * FROM Commandes where ID LIKE '"+name+"%' ");
     if(qry.exec())
     {
         while(qry.next())
         {
             ui->lineEdit_IDCOMMANDES->setText(qry.value(0).toString());
         ui->lineEdit_commande->setText(qry.value(1).toString());
         ui->spinBox->setValue(qry.value(2).toInt());

}

     }
}

void Dialog::on_comboBox_modifiercli_currentIndexChanged(const QString &arg1)
{
    QString name =ui->comboBox_modifiercli->currentText();
    name=arg1;
    QSqlQuery qry;
     qry.prepare("SELECT * FROM Clients where ID LIKE '"+name+"%' ");
     if(qry.exec())
     {
         while(qry.next())
         {
             ui->lineEdit_ID->setText(qry.value(0).toString());
         ui->lineEdit_nom->setText(qry.value(1).toString());
         ui->lineEdit_prenom->setText(qry.value(2).toString());
         ui->lineEdit_adresse->setText(qry.value(3).toString());
}
     }
}

