#include "e_menu.h"
#include "ui_e_menu.h"
#include "mainwindow.h"
#include <QMessageBox>

e_menu::e_menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::e_menu)
{
    ui->setupUi(this);
    ui->img_msg1->hide();
    ui->img_msg1_2->hide();
    ui->img_msg1_3->hide();
    ui->prn_e->hide();
    ui->msg->hide();
    QSqlQuery qry;
    QString nom1,prn1;
    qry.prepare("SELECT * FROM `connected`");
    if (qry.exec())
    {

        if (qry.next())
        {
            ui->nom_e->setText(qry.value(1).toString());
            nom1=qry.value(1).toString();
            prn1=qry.value(2).toString();
            ui->img->setPixmap(qry.value(8).toString());
            ui->prn_e->setText(qry.value(2).toString());
        }
    }
    QSqlQuery qry3;
    qry3.prepare("SELECT * FROM `formation`");
    if (qry3.exec())
    {

        while(qry3.next())
        {
            ui->cb->addItem(qry3.value(1).toString());
        }
    }
    QSqlQuery qry1;
    qry1.prepare("SELECT * FROM `demande` Where nom='"+nom1+"' AND prenom='"+prn1+"' AND etat_for='accepter' AND etat='en cours de traitement'");
    if (qry1.exec())
    {

        if (qry1.next())
        {   ui->msg->show();
                ui->msg->setText("Demande Accepter \nEn Cours De Traitement");
                ui->img_msg1->show();
        }
    }
    qry1.prepare("SELECT * FROM `demande` Where nom='"+nom1+"' AND prenom='"+prn1+"' AND etat_for='accepter' AND etat!='en cours de traitement'");
    if (qry1.exec())
    {

        if (qry1.next())
        {   ui->msg->show();
                ui->msg->setText("Demande Accepter Avec Succes");
            ui->img_msg1_2->show();
        }
    }
    qry1.prepare("SELECT * FROM `demande` Where nom='"+nom1+"' AND prenom='"+prn1+"' AND etat_for!='accepter' OR etat='refuser'");
    if (qry1.exec())
    {

        if (qry1.next())
        {   ui->msg->show();
                ui->msg->setText("Demande Refuser");
        ui->img_msg1_3->show();
        }
    }
}

e_menu::~e_menu()
{
    delete ui;
}

void e_menu::on_pushButton_clicked()
{   QString nom=ui->nom_e->text();
    QString prn=ui->prn_e->text();
    QString date=ui->date_for->text();
    QDate CurrDate = QDate::currentDate();
    QDate dte = QDate(ui->date_for->date());
        if(CurrDate>dte)
QMessageBox::information(0,qApp->tr("Information"),qApp->tr("Date Depassee"),QMessageBox::Close);
        else
        {
    QString nom_for=ui->cb->currentText();
    QSqlQuery qry1;
    qry1.prepare("SELECT * FROM `demande` Where nom='"+nom+"' AND prenom='"+prn+"' AND etat_for='no'");
    if (qry1.exec())
    {

        if (qry1.next())
        {
            QMessageBox::information(0,qApp->tr("Information"),qApp->tr("Demande En Cours De Traietement"),QMessageBox::Close);
        }
        else
        {

            QSqlQuery query;
            query.prepare("INSERT INTO demande (nom, prenom, nom_for, date) "
                           "VALUES (:nom, :prenom, :nom_for, :date)");
            query.bindValue(":nom", nom);
            query.bindValue(":prenom", prn);
            query.bindValue(":nom_for", nom_for);
            query.bindValue(":date", date);
            if(query.exec())
                QMessageBox::information(0,qApp->tr("Information"),qApp->tr("Demande Envoyer Avec Succes"),QMessageBox::Close);
        }
    }
}
}

void e_menu::on_pb_clicked()
{
    MainWindow *menu = new MainWindow;
    setCentralWidget(menu);
}
