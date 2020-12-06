#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "facture.h"
#include "recette.h"
#include "smtp.h"
#include "stat_combo.h"
#include <QMainWindow>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QDialog>
#include <QDialog>
#include <QFileDialog>
//#ifndef MYLIBSHARED_EXPORT Q_DECL_EXPORT
//#define MYLIBSHARED_EXPORT Q_DECL_EXPORT
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
      void fill_form(int);
      QSortFilterProxyModel *proxy;
      QSortFilterProxyModel *proxy2;
      void show_tables();
      void show_tables2();


private slots:
    void on_pushButton_Ajouter_clicked();

    void on_pushButton_Ajouter_2_clicked();

    void on_pushButton_Supprimer_clicked();

    void on_tableView_facture_clicked(const QModelIndex &index);

    void on_tableView_facture_doubleClicked(const QModelIndex &index);

    void on_pushButton_Supprimer_2_clicked();

    void on_tableView_recette_clicked(const QModelIndex &index);

    void on_tableView_recette_doubleClicked(const QModelIndex &index);

    void on_recherche_2_textChanged(const QString &arg2);

    void on_pushButton_clicked();


    void on_pushButton_stat_clicked();


  void sendMail();
  void mailSent(QString);
  void browse();


private:
    Ui::MainWindow *ui;
    facture tmp_facture;
    recette tmp_recette;
    int selected=0;
    int selected2=0;
    QStringList files;
    stat_combo *s;

};

#endif // MAINWINDOW_H
