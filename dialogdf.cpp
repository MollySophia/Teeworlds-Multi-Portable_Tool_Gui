#include "dialogdf.h"
#include "ui_dialogdf.h"

Dialogdf::Dialogdf(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialogdf)
{
    ui->setupUi(this);
    this->setMaximumSize(194,71);
    this->setMinimumSize(194,71);
}

Dialogdf::~Dialogdf()
{
    delete ui;
}

void Dialogdf::on_okbutton_clicked()
{
    this->hide();
}
