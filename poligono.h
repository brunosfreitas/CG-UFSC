#ifndef POLIGONO_H
#define POLIGONO_H
#include "objetografico.h"

class Poligono : public ObjetoGrafico
{
public:
    Poligono();
    Poligono(QString nome);
    Poligono(QString nome, Coordenada coord);


    void adicionarPonto(Coordenada ponto);
    void adicionarNome(QString nome);
};

#endif // POLIGONO_H
