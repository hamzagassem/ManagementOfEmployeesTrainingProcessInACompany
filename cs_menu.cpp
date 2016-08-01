#include "cs_menu.h"
#include "mainwindow.h"
#include "ui_cs_menu.h"
#include <QMessageBox>

cs_menu::cs_menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::cs_menu)
{
    ui->setupUi(this);

    QSqlQuery qry;
    qry.prepare("SELECT * FROM `connected`");
    if (qry.exec())
    {

        if (qry.next())
        {
            ui->nom_e->setText(qry.value(1).toString());
            ui->img->setPixmap(qry.value(8).toString());
        }
    }

    QSqlQuery qry1;
    qry1.prepare("SELECT * FROM `demande` WHERE etat_for='no'");
    if (qry1.exec())
    {

        while(qry1.next())
        {
            ui->cb->addItem(qry1.value(1).toString()+" "+qry1.value(2).toString());
        }
    }
}

cs_menu::~cs_menu()
{
    delete ui;
}

void cs_menu::on_Accept_clicked()
{
    QSqlQuery qry2;
    QString nom11,nom1,prn1;
    int test=0;
    nom11=ui->cb->currentText();
    for(int i=0;i<nom11.length();i++)
    {
        if(test==1)
            prn1+=nom11[i];
        if(nom11[i]==' ')
        {
            test=1;
        }
        if(test==0)
            nom1+=nom11[i];
    }
    qry2.prepare("update demande set etat_for = 'accepter' where nom = '"+nom1+"' AND prenom='"+prn1+"'");
    if(qry2.exec())
        QMessageBox::information(0,qApp->tr("Information"),qApp->tr("Employe Accepter Avec Succes"),QMessageBox::Close);
    }

void cs_menu::on_Refus_clicked()
{
    QSqlQuery qry2;
    QString nom11,nom1,prn1;
    int test=0;
    nom11=ui->cb->currentText();
    for(int i=0;i<nom11.length();i++)
    {
        if(test==1)
            prn1+=nom11[i];
        if(nom11[i]==' ')
        {
            test=1;
        }
        if(test==0)
            nom1+=nom11[i];
    }
    qry2.prepare("update demande set etat_for ='refuser' where nom = '"+nom1+"' AND prenom='"+prn1+"'");
    QMessageBox::information(0,qApp->tr("Information"),qApp->tr("Employe Refuser Avec Succes"),QMessageBox::Close);
    if(qry2.exec())
        QMessageBox::information(0,qApp->tr("Information"),qApp->tr("Employe Refuser"),QMessageBox::Close);
}

void cs_menu::on_pb_clicked()
{
    MainWindow *menu = new MainWindow;
    setCentralWidget(menu);
}
