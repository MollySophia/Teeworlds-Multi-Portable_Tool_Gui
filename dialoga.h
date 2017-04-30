#ifndef DIALOGA_H
#define DIALOGA_H

#include <QDialog>

namespace Ui {
class Dialoga;
}

class Dialoga : public QDialog
{
    Q_OBJECT

public:
    explicit Dialoga(QWidget *parent = 0);
    ~Dialoga();

private:
    Ui::Dialoga *ui;
};

#endif // DIALOGA_H
