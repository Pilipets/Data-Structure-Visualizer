#ifndef STRUCTUREDRAWER_H
#define STRUCTUREDRAWER_H
#include<string>
#include<map>
#include<QImage>
#include<QDir>
using std::map;

class StructureRepresentor;
class MyDrawer{
public:
    MyDrawer();
    QImage createImage(StructureRepresentor *s);
    void setExePath(const char* graphVizPath);
private:
    std::map<int, const char *> outputPath;
    const char* graphVizPath;
    QDir dir;
};

#endif // STRUCTUREDRAWER_H
