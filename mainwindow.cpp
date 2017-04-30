#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include "dialoga.h"
#include "dialogset.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setMaximumSize(271,233);
    this->setMinimumSize(271,233);
    this->move(100,100);
    this->setWindowFlags(Qt::WindowCloseButtonHint);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_about_clicked()
{
    Dialoga *dlg = new Dialoga(this);
    dlg->show();
}

void MainWindow::on_settings_clicked()
{
    Dialogset *dlg = new Dialogset(this);
    dlg->show();
}

void MainWindow::list_selected()
{

}
