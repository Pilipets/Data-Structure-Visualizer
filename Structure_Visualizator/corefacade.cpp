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
#include "propertiesdialog.h"
#include "setoperationsdialog.h"
#include "setalgorithms.h"
#include "settingsdialog.h"
#include<QMessageBox>
#include <QFileDialog>
#include "myrandom.h"
CoreFacade::CoreFacade()
{
    factory = MyFactory::getInstance();
    v = QVector<QGraphicsView*>(2,nullptr);
    s = QVector<StructureRepresentor*>(2,nullptr);

    onStructureIndex = -1;

    s[0] = factory->createEssence("StlList");
    s[1] = factory->createEssence("StlList");
    drawer = new MyDrawer();
    vizPath = "E:/Programs/graphviz-2.38/release/bin/dot.exe";
    drawer->setExePath("E:/Programs/graphviz-2.38/release/bin/dot.exe");

    random = new QRandomGenerator();

    stopWatch = new QElapsedTimer;
    setStrategy = new SetAlgorithms();
    settingsWindow = new SettingsDialog();
}

CoreFacade::~CoreFacade()
{
    delete s[0];
    delete s[1];
    delete drawer;
    delete random;
    delete stopWatch;
    delete setStrategy;
    delete settingsWindow;
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
    std::generate(keys.begin(), keys.end(), [=]() { return random->bounded(-500,500);});
    std::generate(values.begin(), values.end(), [=]() { return random->bounded(-500,500);});

    while(amount --> 0){
        insertToActive(keys[amount-1],values[amount-1]);
    }
    timeTxtBox->setText(QString::number(stopWatch->nsecsElapsed()) + " nanoSeconds");
}

int CoreFacade::findInActive(const int &key)
{
    stopWatch->start();
    StructureRepresentor *Str = s[onStructureIndex];
    int res = Str->find(key);
    timeTxtBox->setText(QString::number(stopWatch->nsecsElapsed()) + " nanoSeconds");
    return res;
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
    stopWatch->start();
    StructureRepresentor *Str = s[onStructureIndex];
    Str->clear();
    timeTxtBox->setText(QString::number(stopWatch->nsecsElapsed()) + " nanoSeconds");
}

void CoreFacade::executeAction(const QString &iconText)
{
    stopWatch->start();
    delete s[onStructureIndex];
    s[onStructureIndex] = factory->createEssence(iconText);
    timeTxtBox->setText(QString::number(stopWatch->nsecsElapsed()) + " nanoSeconds");
}

void CoreFacade::removeFromActive(const int &key)
{
    stopWatch->start();
    StructureRepresentor *Str = s[onStructureIndex];
    Str->remove(key);
    timeTxtBox->setText(QString::number(stopWatch->nsecsElapsed()) + " nanoSeconds");
}

PropertiesDialog* CoreFacade::getPropertiesActive()
{
    stopWatch->start();
    StructureRepresentor *Str = s[onStructureIndex];
    GetItemsVisitor<int,int> v;
    Str->accept(v);
    PropertiesDialog *dialog = new PropertiesDialog();
    dialog->setInfo(v);
    timeTxtBox->setText(QString::number(stopWatch->nsecsElapsed()) + " nanoSeconds");
    return dialog;
}

void CoreFacade::scaleActive(int delta)
{
    QGraphicsView *view = v[onStructureIndex];
    view->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);

    double scaleFactor = 1.15;
    if(delta > 0)
        view->scale(scaleFactor,scaleFactor);
    else {
        view->scale(1.0/scaleFactor, 1.0/scaleFactor);
    }
}

SetOperationsDialog *CoreFacade::getSetOperationResult(int operationType)
{
    stopWatch->start();
    StructureRepresentor *s1 = s[onStructureIndex];
    StructureRepresentor *s2 = onStructureIndex == 0 ? s[1] : s[0];
    SetAlgorithms::OperationType option = static_cast<SetAlgorithms::OperationType>(operationType);

    StructureRepresentor *res = nullptr;
    QString title;
    switch (option) {
    case SetAlgorithms::OperationType::Union:
        res = setStrategy->getUnion(s1,s2);
        title = "Union operation result";
        break;
    case SetAlgorithms::OperationType::Intersection:
        res = setStrategy->getIntersection(s1,s2);
        title = "Intersection operation result";
        break;
    case SetAlgorithms::OperationType::Difference:
        res = setStrategy->getDifference(s1,s2);
        title = "Difference operation result";
        break;
    default:
        res = nullptr;
        title = "Unknown operation type";
        break;
    }
    SetOperationsDialog* dialog = new SetOperationsDialog;
    QImage image;
    if(res)
        image = drawer->createImage(res);
    dialog->setProperties(image,title);
    timeTxtBox->setText(QString::number(stopWatch->nsecsElapsed()) + " nanoSeconds");
    return dialog;
}

SettingsDialog* CoreFacade::getSettingsWindow()
{
    settingsWindow->setPath(vizPath);
    return settingsWindow;
}

void CoreFacade::saveSettingsWindow()
{
    vizPath = settingsWindow->getPath();
    drawer->setExePath(vizPath.toStdString().c_str());
}

