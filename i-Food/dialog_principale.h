#ifndef DIALOG_PRINCIPALE_H
#define DIALOG_PRINCIPALE_H
#include <QDialog>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include"emplacement.h"
#include"reclamation.h"
#include<QSound>


namespace Ui {
class Dialog_principale;
}

class Dialog_principale : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_principale(QWidget *parent = nullptr);
    ~Dialog_principale();

private slots:
    void on_pushButton_3_clicked();



    void on_pushButton_ajouter_empl_clicked();

    void on_pushButton_ajouter_reclamation_clicked();

    void on_pushButton_afficher_empl_clicked();

    void on_pushButton_afficher_reclamation_clicked();

    void on_pushButton_supp_empl_clicked();

    void on_pushButton_modifier_empl_clicked();

    void on_pushButton_modifier_reclamation_clicked();

    void on_pushButton_supp_reclamation_clicked();

    void on_pushButton_enregistrer_empl_clicked();

    void on_pushButton_imprimer_empl_clicked();

    void on_pushButton_trier_empl_clicked();

    void on_pushButton_trier_reclamation_clicked();

    void on_pushButton_imprimer_reclamation_clicked();

    void on_pushButton_enregistrer_reclamation_clicked();

    void on_radioButton_clicked();

    void on_radioButton_4_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_5_clicked();

    void on_radioButton_6_clicked();

    void on_tableView_reclamation_activated(const QModelIndex &index);

    void on_tableView_emplacement_activated(const QModelIndex &index);

private:
    Ui::Dialog_principale *ui;
    emplacement tempEmplacement;
    reclamation tempReclamation;
    QSound *son;

};

#endif // DIALOG_PRINCIPALE_H
