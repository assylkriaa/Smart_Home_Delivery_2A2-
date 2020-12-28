#include "facrec.h"
#include "ui_facrec.h"
#include "exportexcelobjet.h"
#include "connection.h"
#include "modifier.h"
#include "facture.h"
#include "recette.h"
#include "smtp.h"

#include <QMessageBox>
#include <QIntValidator>


FACREC::FACREC(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FACREC)
{
    Connection c;
    bool test=c.createconnect();
    ui->setupUi(this);
    //for email tab
    connect(ui->sendBtn_2, SIGNAL(clicked()),this, SLOT(sendMail()));
    connect(ui->browseBtn_2, SIGNAL(clicked()), this, SLOT(browse()));


show_tables();
show_tables2();
}




FACREC::~FACREC()
{
    delete ui;

   show_tables();


}
void FACREC::show_tables(){
//creation model (masque du tableau) : permet recherche et tri
    proxy = new QSortFilterProxyModel();

 //definir la source (tableau original)
    proxy->setSourceModel(tmp_facture.afficher());

 //pour la recherche
    proxy->setFilterCaseSensitivity(Qt::CaseInsensitive); // S=s (pas de difference entre majiscule et miniscule)
    proxy->setFilterKeyColumn(-1); // chercher dans tout le tableau (-1) ou donner le numero de la colone
   //remplissage tableau avec le masque
    ui->tableView_facture->setModel(proxy);
}
void FACREC::show_tables2(){

    //creation model (masque du tableau) : permet recherche et tri
        proxy2 = new QSortFilterProxyModel();

     //definir la source (tableau original)
        proxy2->setSourceModel(tmp_recette.afficher());

     //pour la recherche
        proxy2->setFilterCaseSensitivity(Qt::CaseInsensitive); // S=s (pas de difference entre majiscule et miniscule)
        proxy2->setFilterKeyColumn(-1); // chercher dans tout le tableau (-1) ou donner le numero de la colone
       //remplissage tableau avec le masque
        ui->tableView_recette->setModel(proxy2);
}

void FACREC::on_pushButton_Ajouter_clicked()
{
    int id=ui->lineEdit_ID->text().toInt();
    QString date=ui->lineEdit_Date->text();
    QString montant=ui->lineEdit_Montant->text();
    QString source=ui->lineEdit_Source->text();
    QString mode=ui->comboBox->currentText();
    facture f(id,date,montant,source,mode);
    bool test=f.ajouter_facture();
    if (test)
    {
        ui->lineEdit_ID->clear();
        ui->lineEdit_Source->clear();
        ui->lineEdit_Montant->clear();

        show_tables();
        QMessageBox::information(nullptr,QObject::tr("ajout"),
                QObject::tr("succées.\n""click cancel to exit."),QMessageBox::Cancel);
}

    else QMessageBox::critical(nullptr,QObject::tr("ajout"),
                                  QObject::tr("échoués.\n""click cancel to exit."),QMessageBox::Cancel);
}

void FACREC::on_pushButton_Ajouter_2_clicked()
{
    int id=ui->lineEdit_ID_2->text().toInt();
    QString date=ui->lineEdit_Date_2->text();
    QString montant=ui->lineEdit_Montant_2->text();
    QString source=ui->lineEdit_Source_2->text();
    recette r(id,date,montant,source);
    bool test=r.ajouter_recette();
    if (test)
    {
        ui->lineEdit_ID_2->clear();
        ui->lineEdit_Source_2->clear();
        ui->lineEdit_Montant_2->clear();
        show_tables2();
        QMessageBox::information(nullptr,QObject::tr("ajout"),
                QObject::tr("succées.\n""click cancel to exit."),QMessageBox::Cancel);
}

    else QMessageBox::critical(nullptr,QObject::tr("ajout"),
                                  QObject::tr("échoués.\n""click cancel to exit."),QMessageBox::Cancel);
}

void FACREC::on_tableView_facture_clicked(const QModelIndex &index)
{
     selected=ui->tableView_facture->model()->data(index).toInt();
}


void FACREC::on_pushButton_Supprimer_clicked()
{
    facture fs;
    fs.supprimer_facture(selected);
   show_tables();
}




void FACREC::on_tableView_facture_doubleClicked(const QModelIndex &index)
{

    modifier ac(this);
    ac.fill_form(selected);
  int res=ac.exec();
  if (res == QDialog::Rejected )
    return;

  QString s1=ac.date();
  QString s2=ac.montant();
  QString s3=ac.source();
  QString s4=ac.mode();
  facture mc(selected,s1,s2,s3,s4);
  mc.modifier(selected);








  //refresh du tableau (affichage)
     show_tables();


}
void FACREC::on_tableView_recette_clicked(const QModelIndex &index)
{
    selected2=ui->tableView_recette->model()->data(index).toInt();
}

void FACREC::on_pushButton_Supprimer_2_clicked()
{
    recette r;
    r.supprimer_recette(selected2);
   show_tables2();
}





void FACREC::on_tableView_recette_doubleClicked(const QModelIndex &index)
{
    modifier ac(this);
    ac.fill_form_recette(selected2);
  int res=ac.exec();
  if (res == QDialog::Rejected )
    return;

  QString s1=ac.date();
  QString s2=ac.montant();
  QString s3=ac.source();
  recette mc(selected2,s1,s2,s3);
  mc.modifier_recette(selected2);








  //refresh du tableau (affichage)
     show_tables2();
}

void FACREC::on_recherche_2_textChanged(const QString &arg2)
{
    proxy2->setFilterFixedString(arg2);

}

void FACREC::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                    tr("Excel Files (*.xls)"));
    if (fileName.isEmpty())
        return;

    ExportExcelObject obj(fileName, "mydata", ui->tableView_facture);

    //colums to export
    obj.addField(0, "entier", "char(20)");
    obj.addField(1, "reel", "char(20)");
    obj.addField(2, "combobox", "char(20)");
    obj.addField(3, "lineedit", "char(20)");
    obj.addField(4, "textedit", "char(20)");
    obj.addField(5, "dateedit", "char(20)");
    obj.addField(5, "timeedit", "char(20)");


    int retVal = obj.export2Excel();
    if( retVal > 0)
    {
        QMessageBox::information(this, tr("Done"),
                                 QString(tr("%1 records exported!")).arg(retVal)
                                 );
    }
}








void FACREC::on_pushButton_stat_clicked()

    {
        s = new stat_combo();

      s->setWindowTitle("statistique ComboBox");
      s->choix_pie();
      s->show();


    }
//mail

void FACREC::browse()
{
    {
        files.clear();

        QFileDialog dialog(this);
        dialog.setDirectory(QDir::homePath());
        dialog.setFileMode(QFileDialog::ExistingFiles);

        if (dialog.exec())
            files = dialog.selectedFiles();

        QString fileListString;
        foreach(QString file, files)
            fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

        ui->file_2->setText( fileListString );

    }
}

void   FACREC::sendMail()
{
    Smtp* smtp = new Smtp("oumaimakarmandi1@gmail.com",ui->mail_pass_2->text(), "smtp.gmail.com");
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail("oumaimakarmandi1@gmail.com", ui->rcpt_2->text() , ui->subject_2->text(),ui->msg_2->toPlainText(), files );
    else
        smtp->sendMail("oumaimakarmandi1@gmail.com", ui->rcpt_2->text() , ui->subject_2->text(),ui->msg_2->toPlainText());
}
void   FACREC::mailSent(QString status)
{

    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple stmp client" ), tr( "Message sent!\n\n" ) );
    ui->rcpt_2->clear();
    ui->subject_2->clear();
    ui->file_2->clear();
    ui->msg_2->clear();
    ui->mail_pass_2->clear();
}

