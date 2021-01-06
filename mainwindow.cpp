#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"dialog.h"
#include "gestion_perso_conge.h"
#include "dialog_principale.h"
#include<QPixmap>
#include"logistique.h"
#include"facrec.h"
#include"fourni.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

son=new QSound("C:/Users/oumayma/Desktop/oxp.wav");

        animation =new QPropertyAnimation(ui->label,"geometry");
                animation->setDuration(1000);
                animation->setStartValue(ui->label->geometry());
                animation->setEndValue(QRect(500,20,81,50));

                animation2 =new QPropertyAnimation(ui->label,"geometry");
                animation2->setDuration(1000);
              //  animation2->setStartValue(ui->label->geometry());
                 animation2->setStartValue(QRect(500,20,81,50));
                animation2->setEndValue(QRect(500,550,81,50));

                 animation1 =new QPropertyAnimation(ui->label,"geometry");
                animation1->setDuration(1000);
               // animation1->setStartValue(ui->label->geometry());
                 animation1->setStartValue(QRect(500,550,81,50));
                animation1->setEndValue(QRect(40,530,81,50));


                animation3 =new QPropertyAnimation(ui->label,"geometry");
                    animation3->setDuration(1000);
               // animation3->setStartValue(ui->label->geometry());
                  animation3->setStartValue(QRect(40,530,81,50));
                animation3->setEndValue(QRect(40,20,81,50));
               animgrp= new QSequentialAnimationGroup;
               animgrp->addAnimation(animation);
                animgrp->addAnimation(animation2);
                 animgrp->addAnimation(animation1);
                  animgrp->addAnimation(animation3);
                  animgrp->setLoopCount(2);
                  animgrp->start();

QPixmap pix("C:/Users/oumayma/Desktop/test/2.jpg");

ui->label_2->setPixmap(pix.scaled(990,690,Qt::KeepAspectRatio));

ui->label_3->setTextInteractionFlags(Qt::LinksAccessibleByMouse);
ui->label_3->setOpenExternalLinks(true);
ui->label_3->setTextFormat(Qt::RichText);
ui->label_3->setText("<a href=\"https://assylkriaa.wixsite.com/website\"> www.DebugCrew.com </a>");

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

son->play();
    p = new gestion_perso_conge(this);
    p->show();

}

void MainWindow::on_pushButton_2_clicked()
{
    Dialog_principale d;
    d.exec();
}



void MainWindow::on_pushButton_3_clicked()
{
    Dialog d;

    d.exec();

}

void MainWindow::on_pushButton_4_clicked()
{
    logistique l;
    l.exec();
}

void MainWindow::on_pushButton_5_clicked()
{
    FACREC f;
    f.exec();
}

void MainWindow::on_pushButton_6_clicked()
{
    fourni o;
    o.exec();
}
