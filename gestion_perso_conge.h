#ifndef GESTION_PERSO_CONGE_H
#define GESTION_PERSO_CONGE_H
#include "classe_personnel.h"
#include"classe_conge.h"
#include <QString>
#include <QDialog>
#include<QSqlQuery>
#include<QSqlQueryModel>
namespace Ui {
class gestion_perso_conge;
}

class gestion_perso_conge : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_perso_conge(QWidget *parent = nullptr);
    ~gestion_perso_conge();

private slots:
    void on_pushButton_ajouter_clicked();

    void on_pushButton_afficher_clicked();

    void on_pushButton_supprimer_clicked();

    void on_pushButton_modifier_clicked();

    void on_pushButton_tri_clicked();



    void on_pushButton_chercher_clicked();


    void on_pushButton_pdf_clicked();



    void on_pushButton_ajouter_conge_clicked();

    void on_pushButton_supprimer_conge_clicked();

    void on_pushButton_modifier_conge_clicked();

    void on_pushButton_afficher_conge_clicked();

    void on_pushButton_chercher_conge_clicked();

    void on_pushButton_imprimer_conge_clicked();









    void on_comboBox_id_2_currentTextChanged(const QString &arg1);

    void on_comboBox_id_currentTextChanged(const QString &arg1);



private:
    Ui::gestion_perso_conge *ui;
    classe_personnel tmpemployee;
    classe_conge tmpconge;
};

#endif // GESTION_PERSO_CONGE_H
