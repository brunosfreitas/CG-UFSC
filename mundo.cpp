#include "mundo.h"
#include "objetografico.h"

Mundo::Mundo()
{
    listaObjetos = QVector<ObjetoGrafico>(0);
}

void Mundo::adicionarObjeto(ObjetoGrafico objeto){
    listaObjetos.push_back(objeto);
}

QVector<ObjetoGrafico> Mundo::getListaDeObjetos(){
    return listaObjetos;
}
