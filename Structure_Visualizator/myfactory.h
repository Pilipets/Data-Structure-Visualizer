#ifndef MYFACTORY_H
#define MYFACTORY_H
#include <QString>
#include<memory>
class StructureRepresentor;
class MyFactory{
private:
    MyFactory() = default;
public:
    static MyFactory *getInstance();
    StructureRepresentor *createEssence(const QString& name);
};

#endif // MYFACTORY_H
