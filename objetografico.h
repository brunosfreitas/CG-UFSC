#ifndef OBJETOGRAFICO_H
#define OBJETOGRAFICO_H
#include "coordenada.h"
#include <QVector>
#include <QString>
#include <QColor>

class ObjetoGrafico
{

public:
    QString nome;
    QVector<Coordenada> pontos;
    QColor cor;

    ObjetoGrafico();
    QVector<Coordenada> getPontos();
    int quantidadeDePontos();
    QString toString();
    void setRandomColor();
    void setColor(QColor cor);
};

#endif // OBJETOGRAFICO_H
