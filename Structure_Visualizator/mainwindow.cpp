#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsView>
#include "corefacade.h"
#include <QPushButton>
#include <QInputDialog>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView_0->setScene(new QGraphicsScene());
    ui->graphicsView_1->setScene(new QGraphicsScene());


    connect(ui->insertBtn, &QPushButton::clicked, this, &MainWindow::insertBtn_clicked);

    ui->graphicsView_0->installEventFilter(this);
    ui->graphicsView_1->installEventFilter(this);

    core = new CoreFacade();
    core->setOutputWindow(ui->graphicsView_0, 0);
    core->setOutputWindow(ui->graphicsView_1, 1);

}

MainWindow::~MainWindow()
{
    disconnect(ui->insertBtn, &QPushButton::clicked, this, &MainWindow::insertBtn_clicked);

    delete ui->graphicsView_0->scene();
    delete ui->graphicsView_1->scene();
    delete ui;
}

bool MainWindow::eventFilter(QObject *object, QEvent *event)
{
    if (event->type() == QEvent::FocusIn){
        QGraphicsView*v = dynamic_cast<QGraphicsView*>(object);
        core->setActive(v);
        return true;
    }
    else{
        return QMainWindow::eventFilter(object, event);
    }
}

void MainWindow::insertBtn_clicked()
{
    int key = QInputDialog::getInt(this,"Enter Key","Enter Key");
    core->insertToActive(key,key);
    core->drawActive();
}
