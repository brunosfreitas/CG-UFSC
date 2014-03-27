#include "mainwindow.h"
#include "mundo.h"
#include "ponto.h"
#include "coordenada.h"
#include "reta.h"

#include <string>
using namespace std;
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Mundo mundo = Mundo();
    Ponto ponto1 = Ponto("ponto1", Coordenada(3,4));
    Reta reta1 = Reta("reta1", Coordenada(10,10), Coordenada(5,7));

    mundo.adicionarObjeto(ponto1);
    mundo.adicionarObjeto(reta1);


    MainWindow w;
    w.show();

    return a.exec();
}
