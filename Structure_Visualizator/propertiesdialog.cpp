#include "propertiesdialog.h"
#include "ui_propertiesdialog.h"
#include "structurevisitor.h"
PropertiesDialog::PropertiesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PropertiesDialog)
{
    ui->setupUi(this);
    ui->keysLineEdit->setReadOnly(true);
    ui->valuesLineEdit->setReadOnly(true);
    ui->amountLineEdit->setReadOnly(true);
}

PropertiesDialog::~PropertiesDialog()
{
    delete ui;
}

void PropertiesDialog::setInfo(const GetItemsVisitor<int,int> &v)
{
    ui->amountLineEdit->setText(QString::number(v.amount));

    auto vector_to_string = [](const QString &res, const int &num){ return QString("%1, %2").arg(res, QString::number(num));};
    QString keys = std::accumulate(v.keys.begin(),v.keys.end(),QString::number(v.keys[0]),
            vector_to_string);
    QString values = std::accumulate(v.values.begin(),v.values.end(),QString::number(v.values[0]),
            vector_to_string);
    ui->keysLineEdit->setText(keys);
    ui->valuesLineEdit->setText(values);
}
