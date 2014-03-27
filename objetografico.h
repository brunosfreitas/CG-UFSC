#ifndef OBJETOGRAFICO_H
#define OBJETOGRAFICO_H
#include "coordenada.h"
#include <QVector>
#include <QString>

class ObjetoGrafico
{

public:
    QString nome;
    QVector<Coordenada> pontos;

    ObjetoGrafico();
};

#endif // OBJETOGRAFICO_H
