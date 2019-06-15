#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsView>
#include "corefacade.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    core = new CoreFacade();

}

MainWindow::~MainWindow()
{
    delete ui;
}
