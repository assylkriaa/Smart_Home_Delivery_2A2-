#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "commande.h"
#include <QMessageBox>
#include "client.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBox_client->addItem("ID");
            ui->comboBox_client->addItem("nom");
            ui->comboBox_client->addItem("prenom");
            ui->comboBox_client->addItem("adresse");
            ui->comboBox->addItem("ID");
            ui->comboBox->addItem("nom_commande");
            ui->comboBox->addItem("nbc");
            ui->comboBox_2->addItem("croissant");
            ui->comboBox_2->addItem("decroissant");
   /* ui->tableView->setModel(tempCommande.afficher());*/
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_ajouterco_clicked()
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

void MainWindow::on_pushButton_afficherco_clicked()
{
    ui->tableView->setModel(tempCommande.afficher());
}

void MainWindow::on_pushButton_suprimerco_clicked()
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

void MainWindow::on_pushButton_ajouterct_clicked()
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

void MainWindow::on_pushButton_afficherct_clicked()
{
    ui->tableView_client->setModel(tempClient.afficher());

}

void MainWindow::on_pushButton_suprimerct_clicked()
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

void MainWindow::on_pushButton_modifierco_clicked()
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

void MainWindow::on_pushButton_modifierct_clicked()
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

void MainWindow::on_pushButton_rechercherco_clicked()
{

    QString a=ui->lineEdit_recherche->text();
    QString choice=ui->comboBox_client->currentText();
     ui->tableView_client->setModel(tempClient.rechercher(choice,a));
}

void MainWindow::on_pushButton_trierco_clicked()
{
QString a=ui->comboBox_2->currentText();
    QString choice=ui->comboBox->currentText();
     ui->tableView->setModel(tempCommande.trier(choice,a));
}
