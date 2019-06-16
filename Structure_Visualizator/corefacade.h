#ifndef COREFACADE_H
#define COREFACADE_H
#include<QGraphicsView>
#include<QVector>
class StructureRepresentor;
class MyDrawer;

class CoreFacade{
private:
public:
    CoreFacade();
    ~CoreFacade();
    void insertToActive(int key, int value);
    void drawActive();
    void setOutputWindow(QGraphicsView* view, int sIndex);
    void setActive(QGraphicsView *view);
private:
    int onStructureIndex;
    QVector<StructureRepresentor*> s;
    QVector<QGraphicsView*> v;
    MyDrawer *drawer;
};

#endif // COREFACADE_H
