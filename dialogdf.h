#ifndef DIALOGDF_H
#define DIALOGDF_H

#include <QDialog>

namespace Ui {
class Dialogdf;
}

class Dialogdf : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogdf(QWidget *parent = 0);
    ~Dialogdf();

private slots:
    void on_okbutton_clicked();

private:
    Ui::Dialogdf *ui;
};

#endif // DIALOGDF_H
