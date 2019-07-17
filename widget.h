#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    void changeMoney(int n);
    void ResetMoney();
    void ReturnMoney();
    int money {0};
    int emoney;
    int RM1, RM2, RM3, RM4;
    int LM1, LM2, LM3;

private slots:
    void on_PB10_clicked();

    void on_PB50_clicked();

    void on_PB100_clicked();

    void on_PB500_clicked();

    void on_PBCoffee_clicked();

    void on_PBTea_clicked();

    void on_PBCoke_clicked();

    void on_PBReturn_clicked();

    void on_PBReset_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
