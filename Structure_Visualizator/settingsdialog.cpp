#include "settingsdialog.h"
#include "ui_settingsdialog.h"

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);
    connect(ui->saveBtn, &QPushButton::clicked, this, &SettingsDialog::saveSettings);
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

QString SettingsDialog::getPath() const
{
    return ui->graphVizLineEdit->text();
}

void SettingsDialog::setPath(const QString &path)
{
    ui->graphVizLineEdit->setText(path);
}
