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

    /** Mundo a ser criado **/
    Ponto ponto1 = Ponto("ponto1", Coordenada(3,4));
    Reta reta1 = Reta("reta1", Coordenada(10,10), Coordenada(100,150));

//    Ponto ponto1Mundo = transformadaViewPort(Ponto("ponto mundo",Coordenada(ponto1.coord1.getX(), ponto1.coord1.getY())));
//    painter.drawPoint(ponto1Mundo.coord1.getX(), ponto1Mundo.coord1.getY());

//    Ponto reta1MundoP1 = transformadaViewPort(Ponto("r1 mundo",Coordenada(reta1.coord1.getX(),reta1.coord1.getY())));
//    Ponto reta1MundoP2 = transformadaViewPort(Ponto("r2 mundo",Coordenada(reta1.coord2.getX(),reta1.coord2.getY())));
//    painter.drawLine(reta1MundoP1.coord1.getX(),reta1MundoP1.coord1.getY(), reta1MundoP2.coord1.getX(),reta1MundoP2.coord1.getY());



    MainWindow w;
    w.show();

    return a.exec();
}
