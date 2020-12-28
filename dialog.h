#ifndef DIALOG_H
#define DIALOG_H
#include <QDialog>
#include <QString>
#include <QtSql>
#include <QFileInfo>
#include "commande.h"
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

    void on_pushButton_ajouterco_clicked();

    void on_pushButton_afficherco_clicked();

    void on_pushButton_suprimerco_clicked();

    void on_pushButton_ajouterct_clicked();

    void on_pushButton_afficherct_clicked();

    void on_pushButton_suprimerct_clicked();

    void on_pushButton_modifierco_clicked();

    void on_pushButton_modifierct_clicked();

    void on_pushButton_rechercherco_clicked();

    void on_pushButton_trierco_clicked();

    void on_pushButton_enregistrerco_clicked();

    void on_pushButton_enregistrerct_clicked();


    void on_comboBox_modifiercoma_currentIndexChanged(const QString &arg1);

    void on_comboBox_modifiercli_currentIndexChanged(const QString &arg1);

private:
    Ui::Dialog *ui;
    Commande tempCommande;
    Client tempClient;
};

#endif // DIALOG_H
