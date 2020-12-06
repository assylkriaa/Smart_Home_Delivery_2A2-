#include "modifier.h"
#include "ui_modifier.h"

Modifier::Modifier(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Modifier)
{
    ui->setupUi(this);
}

Modifier::~Modifier()
{
    delete ui;
}

void Modifier::fill_form(int selected ) {
    QSqlQuery query;
    query.prepare("select * from facturee where id= :integer");
    query.bindValue(":integer", selected);
    query.exec();
    while(query.next()){

        ui->lineEdit_Datem->setText(query.value(1).toString());//text edit
        ui->lineEdit_Montantm->setText(query.value(2).toString()); //line edit
        ui->lineEdit_Sourcem->setText(query.value(3).toString());//text edit
        ui->comboBoxm->setCurrentText(query.value(4).toString()); //line edit

    }}
    void Modifier::fill_form_recette(int selected ) {
        QSqlQuery query;
        query.prepare("select * from recette where ID_R = :integer");
        query.bindValue(":integer", selected);
        query.exec();
        while(query.next()){

            ui->lineEdit_Datem->setText(query.value(1).toString());//text edit
            ui->lineEdit_Montantm->setText(query.value(2).toString()); //line edit
            ui->lineEdit_Sourcem->setText(query.value(3).toString());//text edit
            ui->comboBoxm->setCurrentText(query.value(4).toString()); //line edit

        }

}
QString Modifier::date() const { //date
    return ui->lineEdit_Datem->text();
}
QString Modifier::montant() const { //date
    return ui->lineEdit_Montantm->text();
}
QString Modifier::source() const { //date
    return ui->lineEdit_Sourcem->text();
}
QString Modifier::mode() const { //date
    return ui->comboBoxm->currentText();
}

void Modifier::on_pushButton_clicked()
{

accept();
}
