#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class CoreFacade;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool eventFilter(QObject *object, QEvent *event) override;


private slots:
    void insertBtn_clicked();
    void randomInsertBtn_clicked();
    void clearBtn_clicked();
    void actionCreateStructure_clicked();
private:
    Ui::MainWindow *ui;

    CoreFacade *core;
};

#endif // MAINWINDOW_H
