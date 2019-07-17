#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->PBCoffee->setEnabled(false);
    ui->PBTea->setEnabled(false);
    ui->PBCoke->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::changeMoney(int n){
    money += n;
    if(money>=500){
        ui->PBCoke->setEnabled(true);
        ui->PBTea->setEnabled(true);
        ui->PBCoffee->setEnabled(true);
    }else if(money>=150){
        ui->PBTea->setEnabled(true);
        ui->PBCoffee->setEnabled(true);
    }else if(money>=100){
        ui->PBCoffee->setEnabled(true);
    }else{
        if(money<100){
            ui->PBCoffee->setEnabled(false);
            ui->PBTea->setEnabled(false);
            ui->PBCoke->setEnabled(false);
        }else if(money<150){
            ui->PBTea->setEnabled(false);
            ui->PBCoke->setEnabled(false);
        }else if(money<500){
            ui->PBCoke->setEnabled(false);
        }
     }
    ui->lcdNumber->display(money);
}

void Widget::ResetMoney(){
    money = 0;
    ui->PBCoffee->setEnabled(false);
    ui->PBTea->setEnabled(false);
    ui->PBCoke->setEnabled(false);
    ui->lcdNumber->display(money);
}

void Widget::ReturnMoney(){
    RM1=0;RM2=0;RM3=0;RM4=0;
    if(money<10){
        QMessageBox msg;
        msg.information(nullptr, "Error","Empty! XD");
    }else if(money>=500){
        RM1 = money/500;
        LM1 = money%500;
        RM2 = LM1/100;
        LM2 = LM1%100;
        RM3 = LM2/50;
        LM3 = LM2%50;
        RM4 = LM3/10;
        QMessageBox msg;
        msg.information(nullptr, "Return",QString("Money Return\n$500 : %1\n$100 : %2\n$50 : %3\n$10 : %4").arg(RM1).arg(RM2).arg(RM3).arg(RM4));
    }else if(money>=100){
        RM1 = money/100;
        LM1 = money%100;
        RM2 = LM1/50;
        LM2 = LM1%50;
        RM3 = LM2/10;
        QMessageBox msg;
        msg.information(nullptr, "Return",QString("Money Return\n$100 : %1\n$50 : %2\n$10 : %3\n").arg(RM1).arg(RM2).arg(RM3));
    }else if(money>=50){
        RM1 = money/50;
        LM1 = money%50;
        RM2 = LM1/10;
        QMessageBox msg;
        msg.information(nullptr, "Return",QString("Money Return\n$50 : %1\n$10 : %2\n").arg(RM1).arg(RM2));
    }else{
        RM1 = money/10;
        QMessageBox msg;
        msg.information(nullptr, "Return",QString("Money Return\n$10 : %1\n").arg(RM1));
    }

}

void Widget::on_PB10_clicked()
{
    changeMoney(10);
}

void Widget::on_PB50_clicked()
{
    changeMoney(50);
}

void Widget::on_PB100_clicked()
{
    changeMoney(100);
}

void Widget::on_PB500_clicked()
{
    changeMoney(500);
}

void Widget::on_PBCoffee_clicked()
{
    changeMoney(-100);
}

void Widget::on_PBTea_clicked()
{
    changeMoney(-150);
}

void Widget::on_PBCoke_clicked()
{
    changeMoney(-500);
}

void Widget::on_PBReset_clicked()
{
    ResetMoney();
}

void Widget::on_PBReturn_clicked()
{
    ReturnMoney();
    ResetMoney();
    //ui->PBCoke->setEnabled(false);

}
