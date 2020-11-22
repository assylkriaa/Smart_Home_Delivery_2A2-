#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "client.h"
#include <QMainWindow>
#include "commande.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

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

private:
    Ui::MainWindow *ui;
    Commande tempCommande;
    Client tempClient;
};
#endif // MAINWINDOW_H
