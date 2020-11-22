#ifndef DIALOG_PRINCIPALE_H
#define DIALOG_PRINCIPALE_H
#include <QDialog>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include"emplacement.h"
#include"reclamation.h"

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

private:
    Ui::Dialog_principale *ui;
    emplacement tempEmplacement;
    reclamation tempReclamation;
};

#endif // DIALOG_PRINCIPALE_H
