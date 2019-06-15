#include "corefacade.h"
#include "structurerepresentor.h"

StructureRepresentor *CoreFacade::getStructureFromIndex(int sIndex)
{
    StructureRepresentor *res = nullptr;
    switch (sIndex) {
    case 1:
        res = s1;
        break;
    case 2:
        res = s2;
        break;
    }
    return res;
}

void CoreFacade::insert(int key, int value, int sIndex)
{
    StructureRepresentor *s = getStructureFromIndex(sIndex);
    s->insert(key, value);
}

void CoreFacade::draw(int sIndex, QGraphicsView *view)
{

}
