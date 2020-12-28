#ifndef FOURNI_H
#define FOURNI_H
#include "fournisseurs.h"
#include <QDialog>
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>
namespace Ui {
class fourni;
}

class fourni : public QDialog
{
    Q_OBJECT

public:
    explicit fourni(QWidget *parent = nullptr);
    ~fourni();



private slots:
    void on_login_3_clicked();

    void on_pushButton_ajouter_clicked();

    void on_pushButton_reset_clicked();

    void on_pushButton_supprimer_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_recherche_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::fourni *ui;
    fournisseurs tmpfourni;

};

#endif // FOURNI_H
