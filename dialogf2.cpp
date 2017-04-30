#include "dialogf2.h"
#include "ui_dialogf2.h"

Dialogf2::Dialogf2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialogf2)
{
    ui->setupUi(this);
    this->setMaximumSize(151,85);
    this->setMinimumSize(151,85);
}

Dialogf2::~Dialogf2()
{
    delete ui;
}

void Dialogf2::on_pushButton_clicked()
{
    this->hide();
}
