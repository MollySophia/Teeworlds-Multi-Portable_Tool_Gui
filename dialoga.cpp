#include "dialoga.h"
#include "ui_dialoga.h"

Dialoga::Dialoga(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialoga)
{
    ui->setupUi(this);
}

Dialoga::~Dialoga()
{
    delete ui;
}
