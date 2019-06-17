#include "insertonedialog.h"
#include "ui_insertonedialog.h"
#include "mainwindow.h"
InsertOneDialog::InsertOneDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InsertOneDialog)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &InsertOneDialog::insertBtn_clicked);
}

InsertOneDialog::~InsertOneDialog()
{
    delete ui;
}

void InsertOneDialog::insertBtn_clicked()
{
    QString key = ui->keyLine->text();
    QString value = ui->valueLine->text();

    MainWindow *w = qobject_cast<MainWindow*>(parent());
    w->InsertDraw(key,value);

    QDialog::hide();
}
