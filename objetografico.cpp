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
