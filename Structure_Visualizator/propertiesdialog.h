#ifndef PROPERTIESDIALOG_H
#define PROPERTIESDIALOG_H

#include <QDialog>

namespace Ui {
class PropertiesDialog;
}

template<class K, class V>
class GetItemsVisitor;
class PropertiesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PropertiesDialog(QWidget *parent = nullptr);
    ~PropertiesDialog();

    void setInfo(const GetItemsVisitor<int,int> &v);
private:
    Ui::PropertiesDialog *ui;
};

#endif // PROPERTIESDIALOG_H
