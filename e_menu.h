#ifndef E_MENU_H
#define E_MENU_H

#include <QMainWindow>
#include <QtSql>


namespace Ui {
class e_menu;
}

class e_menu : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit e_menu(QWidget *parent = 0);
    ~e_menu();

private slots:
    void on_pushButton_clicked();

    void on_pb_clicked();

private:
    Ui::e_menu *ui;
};

#endif // E_MENU_H
