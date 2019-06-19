#ifndef COREFACADE_H
#define COREFACADE_H
#include<QGraphicsView>
#include<QVector>
class QRandomGenerator;
class StructureRepresentor;
class MyFactory;
class MyDrawer;
class QElapsedTimer;
class QLineEdit;
class PropertiesDialog;
class SetOperationsDialog;
class SetAlgorithms;
class SettingsDialog;
class MyRandom;
class CoreFacade{
private:
public:
    CoreFacade();
    ~CoreFacade();
    void insertToActive(int key, int value);
    void insertRandomToActive(int amount);
    int findInActive(const int & key);
    void drawActive();
    void setOutputWindow(QGraphicsView* view, int sIndex);
    void setActive(QGraphicsView *view);
    void clearActive();
    void executeAction(const QString& iconText);
    int activeElement(){return onStructureIndex; }
    void removeFromActive(const int &key);
    PropertiesDialog* getPropertiesActive();
    QLineEdit *timeTxtBox;
    void scaleActive(int delta);
    SetOperationsDialog *getSetOperationResult(int operationType);
    SettingsDialog* getSettingsWindow();
    void saveSettingsWindow();
private:
    QString vizPath;
    int onStructureIndex;
    QVector<StructureRepresentor*> s;
    QVector<QGraphicsView*> v;
    MyDrawer *drawer;
    QRandomGenerator *random;
    MyFactory *factory;

    SettingsDialog *settingsWindow;
    QElapsedTimer* stopWatch;
    SetAlgorithms *setStrategy;
};

#endif // COREFACADE_H
