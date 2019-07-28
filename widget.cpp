#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

int money = 0;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int n){
    money += n;
    ui->lcdNumber->display(money);
    if(money >= 100 && money < 150){
        ui->pbcoffee->setEnabled(true);
        ui->pbtea->setEnabled(false);
        ui->pbcola->setEnabled(false);
    }
    else if( money >= 150 && money < 200){
        ui->pbcoffee->setEnabled(true);
        ui->pbtea->setEnabled(true);
        ui->pbcola->setEnabled(false);
    }
    else if( money >= 200){
        ui->pbcoffee->setEnabled(true);
        ui->pbtea->setEnabled(true);
        ui->pbcola->setEnabled(true);
    }
    else{
        ui->pbcoffee->setEnabled(false);
        ui->pbtea->setEnabled(false);
        ui->pbcola->setEnabled(false);
    }
}


void Widget::on_pb10_clicked()
{
    changeMoney(10);
}

void Widget::on_pb50_clicked()
{
    changeMoney(50);
}

void Widget::on_pb100_clicked()
{
    changeMoney(100);
}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
}

void Widget::on_pbcoffee_clicked()
{
    changeMoney(-100);
}

void Widget::on_pbtea_clicked()
{
    changeMoney(-150);
}

void Widget::on_pbcola_clicked()
{
    changeMoney(-200);
}

void Widget::on_reset_clicked()
{
    int c_money = money;
    int ab = c_money / 500;
    int bb = ( c_money % 500) / 100;
    int cb = ( c_money % 500 % 100 ) / 50;
    int db = ( c_money % 500 % 100 % 50) / 10;
    ui->a->display(db);
    ui->b->display(cb);
    ui->c->display(bb);
    ui->d->display(ab);
    changeMoney(-(money));
}
