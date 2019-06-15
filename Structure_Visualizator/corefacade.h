#ifndef COREFACADE_H
#define COREFACADE_H
#include<QGraphicsView>
class StructureRepresentor;

class CoreFacade{
private:
    StructureRepresentor *getStructureFromIndex(int sIndex);
public:
    void insert(int key, int value, int sIndex);
    void draw(int sIndex, QGraphicsView* view);
private:
    StructureRepresentor *s1, *s2;
};

#endif // COREFACADE_H
