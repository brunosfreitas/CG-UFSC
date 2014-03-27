#ifndef MUNDO_H
#define MUNDO_H
#include <QString>
#include "objetografico.h"

class Mundo
{

public:
    QVector<ObjetoGrafico> listaObjetos;
    Mundo();
    void adicionarObjeto(ObjetoGrafico objeto);
    QVector<ObjetoGrafico> getListaDeObjetos();
};

#endif // MUNDO_H
