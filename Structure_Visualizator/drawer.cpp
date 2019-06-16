#include "drawer.h"
#include "structurerepresentor.h"
#include <QDir>
MyDrawer::MyDrawer()
{
    typedef StructureRepresentor::Type Type;
    outputPath = {{(int)Type::StlList, "Output/StlList"},{(int)Type::StlVector, "Output/StlVector"},
                  {(int)Type::SplayTree, "Output/SplayTree"}, {(int)Type::RBTree, "Output/RBTree"}};

    dir = QDir::current();
    if(!dir.exists("Output"))
        dir.mkdir("Output");

    for(const auto&elem : outputPath){
        if(!dir.exists(elem.second))
            dir.mkdir(elem.second);
    }
}

QImage MyDrawer::createImage(StructureRepresentor *s)
{
    const char * relativePath = outputPath[s->getType()];
    s->writeToFile(QString("%1/tmp.dot").arg(relativePath).toStdString().c_str());

    QString cmdCommand = QString("%1 -Tpng %2/tmp.dot -o %2/tmp.png").arg(graphVizPath,relativePath);
    system(cmdCommand.toStdString().c_str());

    QImage image(QString(relativePath) + "/tmp.png");
    //QImage image("E:/Programming/C++/2 course/Data Structures/Veres_Algorithmics_2semester/BPlusTree/output_data/output.png");
    return image;
}

void MyDrawer::setExePath(const char *graphVizPath)
{
    this->graphVizPath = graphVizPath;
}
