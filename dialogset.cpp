#include "dialogset.h"
#include "ui_dialogset.h"
#include <QFileDialog>
#include <string>


Dialogset::Dialogset(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialogset)
{
    ui->setupUi(this);
    this->setMaximumSize(194,71);
    this->setMinimumSize(194,71);
}

Dialogset::~Dialogset()
{
    delete ui;
}



