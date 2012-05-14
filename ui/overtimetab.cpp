#include "overtimetab.h"
#include "ui_overtimetab.h"

OverTimeTab::OverTimeTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OverTimeTab)
{
    ui->setupUi(this);
}

OverTimeTab::~OverTimeTab()
{
    delete ui;
}

void OverTimeTab::setItem(int row, int column, QTableWidgetItem *item)
{
    ui->tableWidget->setItem(row,column,item);
}
