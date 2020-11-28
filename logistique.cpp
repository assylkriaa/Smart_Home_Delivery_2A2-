#include "logistique.h"
#include "ui_logistique.h"
#include <QApplication>
#include <QMessageBox>
#include "transport.h"
#include "materiel.h"
#include <QTextDocument>
#include <QtPrintSupport/QPrinter>
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>
#include <QTextStream>
#include "qcustomplot.h"
#include <QFileDialog>
logistique::logistique(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::logistique)
{
    ui->setupUi(this);
    ui->comboBox->setModel(etmp.afficher());
    ui->comboBox_2->setModel(tmp.afficher());
}

logistique::~logistique()
{
    delete ui;
}

void logistique::on_pushButtonAJ_clicked()
{

    int matricule=ui->lineEdit->text().toInt();
    QString type=ui->lineEdit_2->text();
    QString modele=ui->lineEdit_3->text();
     transport t (modele,type,matricule);
     bool test=t.ajouter();
     if(test)
     {
         ui->tableView->setModel(etmp.afficher());

         QMessageBox::information(nullptr,QObject::tr("ok"),
                                QObject::tr("Ajout avec succès!\n"
                                           "click ok to exit"),QMessageBox::Ok);

     }
     else
     { QMessageBox::critical(nullptr,QObject::tr("Ajout"),
                                QObject::tr("Ajout echoué!\n"
                                           "click ok to exit"),QMessageBox::Ok);

     }
}

void logistique::on_pushButtonSUP_clicked()
{
    int matricule=ui->lineEdit->text().toInt();
       bool test=etmp.supprimer(matricule);
       if(test){ui->tableView->setModel(etmp.afficher());
           QMessageBox::information(nullptr,QObject::tr("Suppression"),
                                  QObject::tr("Suppression avec succès!\n"
                                             "click ok to exit"),QMessageBox::Ok);


       }
       else { QMessageBox::critical(nullptr,QObject::tr("Suppression"),
                                  QObject::tr("Suppression echoué!\n"
                                             "click ok to exit"),QMessageBox::Ok); }
}

void logistique::on_pushButtonAF_clicked()
{
     ui->tableView->setModel(etmp.afficher());
}









void logistique::on_tabWidget_currentChanged(int index)
{
    // set dark background gradient:
              QLinearGradient gradient(0, 0, 0, 400);
              gradient.setColorAt(0, QColor(50, 90, 90));
              gradient.setColorAt(0.38, QColor(160, 105, 105));
              gradient.setColorAt(1, QColor(70, 70, 70));
              ui->plot->setBackground(QBrush(gradient));


              // create empty bar chart objects:
              QCPBars *amande = new QCPBars(ui->plot->xAxis, ui->plot->yAxis);
              amande->setAntialiased(false);
              amande->setStackingGap(1);
               //set names and colors:
              amande->setName("Repartition des types selon leurs matricules ");
              amande->setPen(QPen(QColor(0, 168, 140).lighter(130)));
              amande->setBrush(QColor(0, 168, 140));
              // stack bars on top of each other:


              // prepare x axis with country labels:
              QVector<double> ticks;
              QVector<QString> labels;
              etmp.statistique(&ticks,&labels);



              QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
              textTicker->addTicks(ticks, labels);
              ui->plot->xAxis->setTicker(textTicker);
              ui->plot->xAxis->setTickLabelRotation(60);
              ui->plot->xAxis->setSubTicks(false);
              ui->plot->xAxis->setTickLength(0, 4);
              ui->plot->xAxis->setRange(0, 8);
              ui->plot->xAxis->setBasePen(QPen(Qt::white));
              ui->plot->xAxis->setTickPen(QPen(Qt::white));
              ui->plot->xAxis->grid()->setVisible(true);
              ui->plot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
              ui->plot->xAxis->setTickLabelColor(Qt::white);
              ui->plot->xAxis->setLabelColor(Qt::white);

              // prepare y axis:
              ui->plot->yAxis->setRange(0,10);
              ui->plot->yAxis->setPadding(5); // a bit more space to the left border
              ui->plot->yAxis->setLabel("Statistiques");
              ui->plot->yAxis->setBasePen(QPen(Qt::white));
              ui->plot->yAxis->setTickPen(QPen(Qt::white));
              ui->plot->yAxis->setSubTickPen(QPen(Qt::white));
              ui->plot->yAxis->grid()->setSubGridVisible(true);
              ui->plot->yAxis->setTickLabelColor(Qt::white);
              ui->plot->yAxis->setLabelColor(Qt::white);
              ui->plot->yAxis->grid()->setPen(QPen(QColor(30, 50, 50), 0, Qt::SolidLine));
              ui->plot->yAxis->grid()->setSubGridPen(QPen(QColor(100, 100, 130), 0, Qt::DotLine));

              // Add data:

              QVector<double> PlaceData;
              QSqlQuery q1("select type from transport");
              while (q1.next()) {
                            int  nbr_fautee = q1.value(0).toInt();
                            PlaceData<< nbr_fautee;
                              }
              amande->setData(ticks, PlaceData);
              // setup legend:
              ui->plot->legend->setVisible(true);
              ui->plot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
              ui->plot->legend->setBrush(QColor(255, 255, 255, 100));
              ui->plot->legend->setBorderPen(Qt::NoPen);
              QFont legendFont = font();
              legendFont.setPointSize(10);
              ui->plot->legend->setFont(legendFont);
              ui->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}

void logistique::on_pushButtonAJJ_clicked()
{
    int reference =ui->lineEdit_7->text().toInt();
    QString type=ui->lineEdit_8->text();
    int code =ui->lineEdit_9->text().toInt();

     materiel m (reference,type,code);
     bool test=m.ajouter();
     if(test)
     {
         ui->tableView_3->setModel(tmp.afficher());

         QMessageBox::information(nullptr,QObject::tr("ok"),
                                QObject::tr("Ajout avec succès!\n"
                                           "click ok to exit"),QMessageBox::Ok);

     }
     else
     { QMessageBox::critical(nullptr,QObject::tr("Ajout"),
                                QObject::tr("Ajout echoué!\n"
                                           "click ok to exit"),QMessageBox::Ok);

     }
}
void logistique::on_pushButtonAFF_clicked()
{
     ui->tableView_3->setModel(tmp.afficher());
}
void logistique::on_pushButtonSUPP_clicked()
{
    int reference=ui->lineEdit_7->text().toInt();
       bool test=tmp.supprimer(reference);
       if(test){ui->tableView_3->setModel(tmp.afficher());
           QMessageBox::information(nullptr,QObject::tr("Suppression"),
                                  QObject::tr("Suppression avec succès!\n"
                                             "click ok to exit"),QMessageBox::Ok);


       }
       else { QMessageBox::critical(nullptr,QObject::tr("Suppression"),
                                  QObject::tr("Suppression echoué!\n"
                                             "click ok to exit"),QMessageBox::Ok); }

}


void logistique::on_pushButtonMO_clicked()
{
    QString matricule=ui->comboBox->currentText();
    etmp.settype(ui->lineEdit_4->text());
        etmp.setmodele(ui->lineEdit_5->text());
        bool test=etmp.modifier(matricule);
        if(test)
        {
            ui->comboBox->setModel(etmp.afficher());
            ui->tableView->setModel(etmp.afficher());
                    QMessageBox::information(nullptr,QObject::tr("modification"),QObject::tr("modification avec succés \n click ok to exit")
                            ,QMessageBox::Ok);
                                           }
                else
                    QMessageBox::critical(nullptr,QObject::tr("modification"),QObject::tr("modification failed \n click cancel to exit")
                            ,QMessageBox::Ok);
}
void logistique::on_pushButtonMOO_clicked()
{
    QString reference=ui->comboBox_2->currentText();
    tmp.settype(ui->lineEdit_6->text());
        //tmp.setcode(ui->lineEdit_10->text());
        bool test=etmp.modifier(reference);
        if(test)
        {
            ui->comboBox_2->setModel(tmp.afficher());
            ui->tableView_3->setModel(tmp.afficher());
                    QMessageBox::information(nullptr,QObject::tr("modification"),QObject::tr("modification avec succés \n click ok to exit")
                            ,QMessageBox::Ok);
                                           }
                else
                    QMessageBox::critical(nullptr,QObject::tr("modification"),QObject::tr("modification failed \n click cancel to exit")
                            ,QMessageBox::Ok);
}

void logistique::on_pushButton_pdf_clicked()
{
    QSqlDatabase db;
                QTableView TableView;
                QSqlQueryModel * Modal=new  QSqlQueryModel();

                QSqlQuery qry;
                 qry.prepare("SELECT * FROM transport ");
                 qry.exec();
                 Modal->setQuery(qry);
                 TableView.setModel(Modal);



                 db.close();


                 QString strStream;
                 QTextStream out(&strStream);

                 const int rowCount = TableView.model()->rowCount();
                 const int columnCount =  TableView.model()->columnCount();


                 const QString strTitle ="Document";


                 out <<  "<html>\n"
                     "<head>\n"
                         "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                     <<  QString("<title>%1</title>\n").arg(strTitle)
                     <<  "</head>\n"
                     "<body bgcolor=#ffffff link=#5000A0>\n"
                    << QString("<h3 style=\" font-size: 32px; font-family: Arial, Helvetica, sans-serif; color: #FF9933; font-weight: lighter; text-align: center;\">%1</h3>\n").arg("Liste des vehicules")
                    <<"<br>"
                     <<"<table border=1 cellspacing=0 cellpadding=2>\n";

                 out << "<thead><tr bgcolor=#f0f0f0>";
                 for (int column = 0; column < columnCount; column++)
                     if (!TableView.isColumnHidden(column))
                         out << QString("<th>%1</th>").arg(TableView.model()->headerData(column, Qt::Horizontal).toString());
                 out << "</tr></thead>\n";

                 for (int row = 0; row < rowCount; row++) {
                     out << "<tr>";
                     for (int column = 0; column < columnCount; column++) {
                         if (!TableView.isColumnHidden(column)) {
                             QString data = TableView.model()->data(TableView.model()->index(row, column)).toString().simplified();
                             out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                         }
                     }
                     out << "</tr>\n";
                 }
                 out <<  "</table>\n"
                         "<br><br>"
                         //<< QString("<p><img src=":/img/aze.png"; width="200"; height="200";\">%1</p>\n")
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

                     QLabel lab;
                      QPixmap pixmap(":/img/aze.png");
                     lab.setPixmap(pixmap);
                     QPainter painter(&lab);
                     //QPrinter printer(QPrinter::PrinterResolution);

                     //pixmap.load("aze.png");
                     //painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
                     //painter.drawPixmap(10,10,50,50, pixmap);

                     document->print(&printer);
                 }

                 printer.setOutputFormat(QPrinter::PdfFormat);
                 printer.setPaperSize(QPrinter::A4);
                 printer.setOutputFileName("/tmp/logistique.pdf");
                 printer.setPageMargins(QMarginsF(15, 15, 15, 15));



                 delete document;

}



void logistique::on_pushButtonREE_clicked()
{
    int matricule = ui->lineEdit_13->text().toInt();
            QString type = ui->lineEdit_14->text();
            QString modele = ui->lineEdit_15->text();


                QString txt=ui->lineEdit_13->text();
                 QString txt1=ui->lineEdit_14->text();
                  QString txt2=ui->lineEdit_15->text();
                ui->tableView->setModel(etmp.chercher(txt));
                 ui->tableView->setModel(etmp.chercher2(txt1));
                      ui->tableView->setModel(etmp.chercher1(txt2));

                      if(matricule==0&&type==""){
                           ui->tableView->setModel(etmp.chercher(txt));
                      }
               else    if(modele==""&&type==""){
                    QString txt1=ui->lineEdit_14->text();
                   ui->tableView->setModel(etmp.chercher2(txt1));}

                else    if(modele==""&&matricule==0){
                    QString txt2=ui->lineEdit_14->text();
                  ui->tableView->setModel(etmp.chercher1(txt2));}

                      else    if(modele==""){

                           QString txt2=ui->lineEdit_6->text();
                           QString txt1=ui->lineEdit_15->text();
                          ui->tableView->setModel(etmp.chercher2(txt1));
                        ui->tableView->setModel(etmp.chercher1(txt2));}
                      else    if(matricule==0){
                          QString txt=ui->lineEdit_13->text();
                           QString txt1=ui->lineEdit_14->text();
                          ui->tableView->setModel(etmp.chercher(txt));
                           ui->tableView->setModel(etmp.chercher1(txt1));

                          }

}
