#ifndef INSERTONEDIALOG_H
#define INSERTONEDIALOG_H

#include <QDialog>

namespace Ui {
class InsertOneDialog;
}

class InsertOneDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InsertOneDialog(QWidget *parent = nullptr);
    ~InsertOneDialog();
private slots:
    void insertBtn_clicked();
private:
    Ui::InsertOneDialog *ui;
};

#endif // INSERTONEDIALOG_H
