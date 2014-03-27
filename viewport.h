#ifndef VIEWPORT_H
#define VIEWPORT_H
#include <QWidget>
#include <QBrush>
#include <QPen>
#include <QPixmap>
#include <QtGui>
#include "mundo.h"
#include "ponto.h"


#define TAMANHO_MAX_X  256;
#define TAMANHO_MIN_X  -255;

#define TAMANHO_MAX_Y  196;
#define TAMANHO_MIN_Y  -195;


class ViewPort : public QWidget
{
    Q_OBJECT

public:
    ViewPort();
    ViewPort(QWidget *parent);
    void setMundo(Mundo _mundo);

    QSize minimumSizeHint() const;
    QSize sizeHint() const;

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

    int maxX;
    int minX;
    int maxY;
    int minY;

    bool antialiased;
    bool transformed;

};

#endif // VIEWPORT_H