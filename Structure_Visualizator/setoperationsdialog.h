#ifndef SETOPERATIONSDIALOG_H
#define SETOPERATIONSDIALOG_H

#include <QDialog>
namespace Ui {
class SetOperationsDialog;
}


class StructureRepresentor;
class SetOperationsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SetOperationsDialog(QWidget *parent = nullptr);
    ~SetOperationsDialog();
    void setProperties(const QImage &s, const QString &title);
private:
    Ui::SetOperationsDialog *ui;
};

#endif // SETOPERATIONSDIALOG_H
