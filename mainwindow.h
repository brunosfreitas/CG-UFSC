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
void novoPonto();
void novaReta();
void novoPoligono();
void addPontoPoligono();

void zoomMinus();
void zoomPlus();

void moveUp();
void moveDown();
void moveLeft();
void moveRight();

void zerarCampos();
void ocultarCamposPoligono(bool ocultar);

private:
    Ui::MainWindow *ui;
     QTabWidget *tabWidget;
     QToolBar *menuCG;
     QAction *inserirObjeto;
     Mundo mundo;
     Poligono pol;
};

#endif // MAINWINDOW_H
