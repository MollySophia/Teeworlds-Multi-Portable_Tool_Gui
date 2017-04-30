#ifndef DIALOGSET_H
#define DIALOGSET_H

#include <QDialog>

namespace Ui {
class Dialogset;
}

class Dialogset : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogset(QWidget *parent = 0);
    ~Dialogset();

private slots:
    void on_toolButton_clicked();

private:
    Ui::Dialogset *ui;
};

#endif // DIALOGSET_H
