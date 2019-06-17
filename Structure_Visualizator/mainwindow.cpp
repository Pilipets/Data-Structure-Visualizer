#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsView>
#include "corefacade.h"
#include <QPushButton>
#include <QInputDialog>
#include "insertonedialog.h"
#include <QDebug>
#include<QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView_0->setScene(new QGraphicsScene());
    ui->graphicsView_1->setScene(new QGraphicsScene());

    connect(ui->insertBtn, &QPushButton::clicked, this, &MainWindow::insertBtn_clicked);
    connect(ui->randomInsertBtn, &QPushButton::clicked, this, &MainWindow::randomInsertBtn_clicked);
    connect(ui->clearBtn, &QPushButton::clicked, this, &MainWindow::clearBtn_clicked);
    connect(ui->findBtn, &QPushButton::clicked, this, &MainWindow::findBtn_clicked);
    connect(ui->removeBtn, &QPushButton::clicked, this, &MainWindow::removeBtn_clicked);

    ui->graphicsView_0->installEventFilter(this);
    ui->graphicsView_1->installEventFilter(this);

    core = new CoreFacade();
    core->setOutputWindow(ui->graphicsView_0, 0);
    core->setOutputWindow(ui->graphicsView_1, 1);

    core->timeTxtBox = ui->opTimeLineEdit;
    ui->opTimeLineEdit->setReadOnly(true);

    ui->lineEdit_0->setReadOnly(true);
    ui->lineEdit_1->setReadOnly(true);
    ui->lineEdit_0->setText("StlList");
    ui->lineEdit_1->setText("StlList");
    connect(ui->actionStlList, &QAction::triggered, this, &MainWindow::actionCreateStructure_clicked);
    connect(ui->actionStlMap, &QAction::triggered, this, &MainWindow::actionCreateStructure_clicked);
    connect(ui->actionSplayTree, &QAction::triggered, this, &MainWindow::actionCreateStructure_clicked);
    connect(ui->actionRBTree, &QAction::triggered, this, &MainWindow::actionCreateStructure_clicked);

    insertWindow = new InsertOneDialog(this);
}

MainWindow::~MainWindow()
{

    delete ui->graphicsView_0->scene();
    delete ui->graphicsView_1->scene();
    delete ui;

    delete insertWindow;
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

void MainWindow::InsertDraw(const QString &key, const QString &value)
{
    core->insertToActive(key.toInt(),value.toInt());
    core->drawActive();
}


void MainWindow::insertBtn_clicked()
{
    insertWindow->open();

    //int key = QInputDialog::getInt(this,"Enter Key","Enter Key");
    //core->insertToActive(key,key);
    //core->drawActive();
}

void MainWindow::randomInsertBtn_clicked()
{
    int amount = QInputDialog::getInt(this,"Random Insertion","Enter amount");
    if(amount == 0)
        return;
    core->insertRandomToActive(amount);
    core->drawActive();
}

void MainWindow::clearBtn_clicked()
{
    core->clearActive();
    core->drawActive();
}

void MainWindow::actionCreateStructure_clicked()
{
    QObject *object = sender();
    QAction *action = qobject_cast<QAction*>(object);
    core->executeAction(action->iconText());
    core->drawActive();

    int index = core->activeElement();
    if(index == 0)
        ui->lineEdit_0->setText(action->iconText());
    else if(index == 1)
        ui->lineEdit_1->setText(action->iconText());
}

void MainWindow::findBtn_clicked()
{
    int key = QInputDialog::getInt(this,"Find by key","Enter Key");
    int res = core->findInActive(key);
    QMessageBox *output = new QMessageBox();
    output->setText(QString::number(res));
    output->exec();
    delete output;
    core->drawActive();
}

void MainWindow::removeBtn_clicked()
{
    int key = QInputDialog::getInt(this,"Remove by key","Enter Key");
    core->removeFromActive(key);
    core->drawActive();
}
