#include "ponto.h"

Ponto::Ponto(QString nome, Coordenada coord){
    this->nome = nome;
    this->coord1 = coord;
    pontos = QVector<Coordenada>();
    pontos.push_back(coord);
}

Ponto::Ponto(Coordenada coord){
    this->nome = "ponto_default";
    this->coord1 = coord;
    pontos = QVector<Coordenada>();
    pontos.push_back(coord);
}

