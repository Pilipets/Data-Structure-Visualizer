#include "corefacade.h"
#include "structurerepresentor.h"
#include "drawer.h"
#include <QDir>
#include <QDebug>
#include "stllist.h"
#include <QGraphicsPixmapItem>

CoreFacade::CoreFacade()
{
    v = QVector<QGraphicsView*>(2,nullptr);
    s = QVector<StructureRepresentor*>(2);

    onStructureIndex = -1;

    s[0] = new StlList();
    s[1] = new StlList();
    drawer = new MyDrawer();

    drawer->setExePath("E:/Programs/graphviz-2.38/release/bin/dot.exe");
}

CoreFacade::~CoreFacade()
{
    delete s[0];
    delete s[1];
    delete drawer;
}

void CoreFacade::insertToActive(int key, int value)
{
    StructureRepresentor *Str = s[onStructureIndex];
    Str->insert(key, value);
}

void CoreFacade::drawActive()
{
    StructureRepresentor *Str = s[onStructureIndex];
    QGraphicsView *view = v[onStructureIndex];
    QImage image = drawer->createImage(Str);

    QGraphicsScene *scene = view->scene();
    scene->clear();
    scene->addItem(new QGraphicsPixmapItem(QPixmap::fromImage(image)));
    //item->setPos( 0, 0 );
    //view->fitInView(image.rect(),Qt::KeepAspectRatio);

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
