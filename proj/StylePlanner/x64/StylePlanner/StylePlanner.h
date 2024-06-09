#pragma once

#include "Top.h"
#include "Bottom.h"
#include "ui_StylePlanner.h"
#include <QtWidgets/QMainWindow>
#include <qhash.h>
#include <qlayout.h>
#include <qmessagebox.h>
#include <qpair.h>

class StylePlanner : public QMainWindow
{
    Q_OBJECT

public:
    StylePlanner(QWidget *parent = nullptr);
    ~StylePlanner();

    void load();
    void save();

private:
    Ui::StylePlannerClass ui;
    Top tops;
    Bottom bots;
    std::vector<QPair<QString, QString>> favourities;

    QMessageBox err;
    QHash<QPushButton*, QHBoxLayout*>button_to_layout;

private slots:
    void displayPixT();
    void on_Pbut_clicked();
    void on_Lbut_clicked();
    void on_addTop_clicked();
    void on_delTop_clicked();

    void displayPixB();
    void on_PbutB_clicked();
    void on_LbutB_clicked();
    void on_addBot_clicked();
    void on_delBot_clicked();

    void on_flagFav_clicked();
    void on_unflagFav();
};
