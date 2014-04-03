#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>     //QMap<Key, T> is one of Qt's generic container classes. It stores (key, value) pairs and provides fast lookup of the value associated with a key.
#include <QListWidgetItem>
#include <string>
#include "ui_mainwindow.h"
#include "viewport.h"
#include "mundo.h"
#include "poligono.h"

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
void novoPonto();
void novaReta();

void zoomMinus();
void zoomPlus();

void moveUp();
void moveDown();
void moveLeft();
void moveRight();


void novoPoligono();
void addPontoPoligono();

signals:
void accepted();

private:
    Ui::MainWindow *ui;
     QTabWidget *tabWidget;
     QToolBar *menuCG;
     QAction *inserirObjeto;
     Mundo mundo;
     Poligono pol;
};

#endif // MAINWINDOW_H
