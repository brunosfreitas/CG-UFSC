#ifndef MUNDO_H
#define MUNDO_H
#include <QString>
#include "objetografico.h"

class Mundo
{
public:
    Mundo();

    QVector<ObjetoGrafico> listaObjetos;
    void adicionarObjeto(ObjetoGrafico objeto);
    QVector<ObjetoGrafico> getListaDeObjetos();
};

#endif // MUNDO_H
