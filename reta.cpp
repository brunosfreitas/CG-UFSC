#include "reta.h"

Reta::Reta(QString nome, Coordenada coord1, Coordenada coord2)
{
    this->nome = nome;
    this->coord1 = coord1;
    this->coord2 = coord2;
    pontos = QVector<Coordenada>(0);
    pontos.push_back(coord1);
    pontos.push_back(coord2);
}
