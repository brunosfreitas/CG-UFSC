#ifndef VIEWPORT_H
#define VIEWPORT_H
#include <QWidget>
#include <QBrush>
#include <QPen>
#include <QPixmap>
#include <QtGui>
#include "mundo.h"
#include "ponto.h"
#include "reta.h"
#include "mundo.h"


#define TAMANHO_MAX_X  511;
#define TAMANHO_MIN_X  -511;

#define TAMANHO_MAX_Y  341;
#define TAMANHO_MIN_Y  -341;

#define MOVIMENTO_UP    1;
#define MOVIMENTO_DOWN  2;
#define MOVIMENTO_LEFT  3;
#define MOVIMENTO_RIGHT 4;


class ViewPort : public QWidget
{
    Q_OBJECT

public:
    ViewPort();
    ViewPort(QWidget *parent);
    void setMundo(Mundo _mundo);

    QSize minimumSizeHint() const;
    QSize sizeHint() const;
    void zoom(bool positivo);
    void moverTela(const int movimento);

public slots:
    void setPen(const QPen &pen);
    void setBrush(const QBrush &brush);
    void setAntialiased(bool antialiased);
    void setTransformed(bool transformed);
    void paintEvent(QPaintEvent *event);



private:
    QPen pen;
    QBrush brush;
    QPixmap pixmap;
    QVector<ObjetoGrafico> objetos;
    Ponto transformadaViewPort(Ponto ponto);
    void setBrushColor(QColor cor);

    int vPmaxX;
    int vPminX;
    int vPmaxY;
    int vPminY;

    bool antialiased;
    bool transformed;

};

#endif // VIEWPORT_H
