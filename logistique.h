#ifndef LOGISTIQUE_H
#define LOGISTIQUE_H

#include <QDialog>
#include "transport.h"
#include "materiel.h"
namespace Ui {
class logistique;
}

class logistique : public QDialog
{
    Q_OBJECT

public:
    explicit logistique(QWidget *parent = nullptr);
    ~logistique();

private slots:
    void on_pushButtonAJ_clicked();

    void on_pushButtonSUP_clicked();

    void on_pushButtonAF_clicked();

   void on_pushButton_pdf_clicked();

    void on_pushButtonAJJ_clicked();

    void on_pushButtonAFF_clicked();

    void on_pushButtonSUPP_clicked();

    void on_tabWidget_currentChanged(int index);


    void on_pushButtonMO_clicked();

    void on_pushButtonMOO_clicked();

    void on_pushButtonRE_clicked();

    void on_pushButtonREE_clicked();

private:
    Ui::logistique *ui;
    transport etmp;
    materiel tmp;

};

#endif // LOGISTIQUE_H
