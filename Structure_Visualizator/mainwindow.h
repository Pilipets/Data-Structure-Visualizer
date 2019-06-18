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

    void InsertDraw(const QString &key, const QString &value);
private slots:
    void insertBtn_clicked();
    void randomInsertBtn_clicked();
    void clearBtn_clicked();
    void actionCreateStructure_clicked();
    void findBtn_clicked();
    void removeBtn_clicked();
    void intersectBtn_clicked();
    void unionBtn_clicked();
    void propertiesBtn_clicked();
private:
    Ui::MainWindow *ui;

    CoreFacade *core;
    QDialog *insertWindow;
};

#endif // MAINWINDOW_H
