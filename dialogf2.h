#ifndef DIALOGF2_H
#define DIALOGF2_H

#include <QDialog>

namespace Ui {
class Dialogf2;
}

class Dialogf2 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogf2(QWidget *parent = 0);
    ~Dialogf2();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialogf2 *ui;
};

#endif // DIALOGF2_H
