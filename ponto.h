#ifndef PONTO_H
#define PONTO_H
#include "coordenada.h"
#include "objetografico.h"


class Ponto : public ObjetoGrafico{

public:
    Coordenada coord1;

    Ponto(QString nome, Coordenada coord);
    Ponto(Coordenada coord);
};

#endif // PONTO_H
