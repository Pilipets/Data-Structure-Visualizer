#include "corefacade.h"
#include "structurerepresentor.h"
#include "drawer.h"
#include <QDir>
#include <QDebug>
#include "stllist.h"
#include <QGraphicsPixmapItem>
#include <QRandomGenerator>
#include<vector>
#include "stlmap.h"
#include "myfactory.h"
#include <QElapsedTimer>
#include <QLineEdit>
CoreFacade::CoreFacade()
{
    v = QVector<QGraphicsView*>(2,nullptr);
    s = QVector<StructureRepresentor*>(2);

    onStructureIndex = -1;

    s[0] = new StlList();
    s[1] = new StlList();
    drawer = new MyDrawer();

    drawer->setExePath("E:/Programs/graphviz-2.38/release/bin/dot.exe");

    random = new QRandomGenerator();
    factory = MyFactory::getInstance();

    stopWatch = new QElapsedTimer;
}

CoreFacade::~CoreFacade()
{
    delete s[0];
    delete s[1];
    delete drawer;
    delete random;
}

void CoreFacade::insertToActive(int key, int value)
{
    stopWatch->start();
    StructureRepresentor *Str = s[onStructureIndex];
    Str->insert(key, value);
    timeTxtBox->setText(QString::number(stopWatch->nsecsElapsed()) + " nanoSeconds");
}

void CoreFacade::insertRandomToActive(int amount)
{
    stopWatch->start();
    std::vector<int> keys(amount),values(amount);
    random->generate(keys.begin(), keys.end());
    random->generate(values.begin(), values.end());

    while(amount --> 0){
        insertToActive(keys[amount-1],values[amount-1]);
    }
    timeTxtBox->setText(QString::number(stopWatch->nsecsElapsed()) + " nanoSeconds");
}

int CoreFacade::findInActive(const int &key)
{
    StructureRepresentor *Str = s[onStructureIndex];
    return Str->find(key);
}

void CoreFacade::drawActive()
{
    StructureRepresentor *Str = s[onStructureIndex];
    QGraphicsView *view = v[onStructureIndex];
    QImage image = drawer->createImage(Str);

    QGraphicsScene *scene = view->scene();
    scene->clear();
    QGraphicsItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
    scene->addItem(item);
    item->setPos(0,0);
    view->fitInView(image.rect(),Qt::KeepAspectRatio);

}

void CoreFacade::setOutputWindow(QGraphicsView *view, int sIndex)
{
    v[sIndex] = view;
    if(onStructureIndex == -1)
        this->setActive(view);
}

void CoreFacade::setActive(QGraphicsView *view)
{
    int index = v.indexOf(view);
    if(onStructureIndex == -1){
        onStructureIndex = index;
        v[onStructureIndex]->setStyleSheet("QGraphicsView { border: 2px solid red }");
    }
    else if(index != onStructureIndex){
        v[onStructureIndex]->setStyleSheet("QGraphicsView { border: none }");
        v[index]->setStyleSheet("QGraphicsView { border: 2px solid red }");
        onStructureIndex = index;
    }
}

void CoreFacade::clearActive()
{
    StructureRepresentor *Str = s[onStructureIndex];
    Str->clear();
}

void CoreFacade::executeAction(const QString &iconText)
{
    delete s[onStructureIndex];
    s[onStructureIndex] = factory->createEssence(iconText);
}

void CoreFacade::removeFromActive(const int &key)
{
    StructureRepresentor *Str = s[onStructureIndex];
    Str->remove(key);
}

