#pragma once

#include <QtWidgets/QMainWindow>
#include "Top.h"
#include "ui_StylePlanner.h"

class StylePlanner : public QMainWindow
{
    Q_OBJECT

public:
    StylePlanner(QWidget *parent = nullptr);
    ~StylePlanner();

private:
    Ui::StylePlannerClass ui;
    Top tops;

private slots:
    void on_Pbut_clicked();
    void on_Lbut_clicked();
    void on_Click_clicked();
};
