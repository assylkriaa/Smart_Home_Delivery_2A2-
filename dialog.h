#ifndef DIALOG_H
#define DIALOG_H
#include "commande.h"
#include <QDialog>
#include "mainwindow.h"
#include <qpropertyanimation.h>
#include "client.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:



    void on_pushButton_ajouterco_2_clicked();

    void on_pushButton_afficherco_2_clicked();

    void on_pushButton_suprimerco_2_clicked();

    void on_pushButton_ajouterct_2_clicked();

    void on_pushButton_afficherct_2_clicked();

    void on_pushButton_suprimerct_2_clicked();

    void on_pushButton_modifierco_2_clicked();

    void on_pushButton_modifierct_2_clicked();

    void on_pushButton_enregistrerco_2_clicked();

    void on_pushButton_rechercherco_2_clicked();

    void on_pushButton_trierco_2_clicked();

    void on_pushButton_enregistrerct_2_clicked();

    void on_comboBox_modifiercoma_2_currentIndexChanged(const QString &arg1);

    void on_comboBox_modifiercli_2_currentIndexChanged(const QString &arg1);

private:
    Ui::Dialog *ui;
    Commande tempCommande;
    Client tempClient;
};

#endif // DIALOG_H
