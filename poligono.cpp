#include "poligono.h"

Poligono::Poligono()
{
    this->pontos = QVector<Coordenada>(0);
}

Poligono::Poligono(QString vnome)
{
    this->nome = vnome;
    this->pontos = QVector<Coordenada>(0);
}

Poligono::Poligono(QString vnome, Coordenada coord)
{
    this->nome = vnome;
    this->pontos = QVector<Coordenada>(0);
    this->adicionarPonto(coord);
}

void Poligono::adicionarPonto(Coordenada vponto){
    pontos.push_back(vponto);
}

void Poligono::adicionarNome(QString vnome){
    nome = vnome;
}


