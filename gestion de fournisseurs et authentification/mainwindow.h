#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QRegularExpression>
#include <QTableWidgetItem>
#include <QItemSelectionModel>
#include <QDebug>
#include <QSqlTableModel>
#include "fournisseurs.h"



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


    void on_pushButton_ajouter_clicked();

    void on_pushButton_reset_clicked();

    void on_pushButton_details_clicked();



    void on_pushButton_supprimer_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_recherche_clicked();

    void on_pushButton_envoyer_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    fournisseurs tmpfournisseurs;
};
#endif // MAINWINDOW_H