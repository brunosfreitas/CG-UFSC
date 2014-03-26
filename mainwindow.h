#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>     //QMap<Key, T> is one of Qt's generic container classes. It stores (key, value) pairs and provides fast lookup of the value associated with a key.
#include <QListWidgetItem>
#include <string>
#include "ui_mainwindow.h"

using std::string;
class PontoTab : public QWidget
{
    Q_OBJECT

public:
    explicit PontoTab(char a, QWidget *parent = 0);
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
void on_pushButton_up_clicked();
void adicionarObjeto();

private:
    Ui::MainWindow *ui;
     QTabWidget *tabWidget;
     void createToolBars();
     void createActions();
     QToolBar *menuCG;
     QAction *inserirObjeto;
};

#endif // MAINWINDOW_H
