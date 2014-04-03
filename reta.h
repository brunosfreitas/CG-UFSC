#ifndef RETA_H
#define RETA_H
#include "coordenada.h"
#include "objetografico.h"

class Reta: public ObjetoGrafico{

public:
    Coordenada coord1;
    Coordenada coord2;

    Reta();
    Reta(QString nome, Coordenada coord1, Coordenada coord2);


};

#endif // RETA_H
