#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QListWidget>
#include <QListWidgetItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_start_clicked();
    void on_about_clicked();
    void on_settings_clicked();

    void on_brefresh_clicked();

    void on_create_clicked();

    void on_del_clicked();
    void list_selected();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
