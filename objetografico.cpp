#include "objetografico.h"

ObjetoGrafico::ObjetoGrafico()
{
}

int ObjetoGrafico::quantidadeDePontos(){
    return pontos.size();
}
QVector<Coordenada> ObjetoGrafico::getPontos(){
    return pontos;
}

QString ObjetoGrafico::toString(){
    QString txt = "";
    for(int i=0;i<pontos.size();i++){
        txt += "( " + QString::number(pontos[i].getX()) + " , " + QString::number(pontos[i].getY()) + " )";
    }
    return txt;
}

void ObjetoGrafico::setRandomColor(){
    cor = QColor(rand() % 255,rand() % 255,rand() % 250,255);
}

void ObjetoGrafico::setColor(QColor color){
    cor = color;
}
