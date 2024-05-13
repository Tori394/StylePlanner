#include "StylePlanner.h"
#include "qmessagebox.h"

StylePlanner::StylePlanner(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

StylePlanner::~StylePlanner()
{}

void StylePlanner::on_Pbut_clicked()
{
    tops.upInx();
}

void StylePlanner::on_Lbut_clicked()
{
    tops.downInx();
}

void StylePlanner::on_Click_clicked()
{
    QMessageBox::information(this, "Test", tops.give_top());
}
