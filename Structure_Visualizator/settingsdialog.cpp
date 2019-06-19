#include "settingsdialog.h"
#include "ui_settingsdialog.h"

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

QString SettingsDialog::graphVizPath() const
{
    return ui->graphVizLineEdit->text();
}

void SettingsDialog::on_saveBtn_clicked()
{
    emit saveSettings();
}
