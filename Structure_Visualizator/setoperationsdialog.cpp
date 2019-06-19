#include "setoperationsdialog.h"
#include "ui_setoperationsdialog.h"
#include "structurerepresentor.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
SetOperationsDialog::SetOperationsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetOperationsDialog)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(new QGraphicsScene);
}

SetOperationsDialog::~SetOperationsDialog()
{
    delete ui->graphicsView->scene();
    ui->graphicsView->setScene(nullptr);
    delete ui;
}

void SetOperationsDialog::setProperties(const QImage &img, const QString &title)
{
    this->setWindowTitle(title);
    QGraphicsScene *scene = ui->graphicsView->scene();
    scene->clear();
    QGraphicsItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(img));
    scene->addItem(item);
    item->setPos(0,0);
    //ui->graphicsView->fitInView(img.rect(),Qt::KeepAspectRatio);
}
