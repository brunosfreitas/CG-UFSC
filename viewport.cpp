#include "viewport.h"


ViewPort::ViewPort(QWidget *parent) : QWidget(parent)
{

    setBackgroundRole(QPalette::Dark);
    setAutoFillBackground(true);

    maxX = TAMANHO_MAX_X;
    minX = TAMANHO_MIN_X;

    maxY = TAMANHO_MAX_Y
    minY = TAMANHO_MIN_Y;

    antialiased = true;
    transformed = false;

}

void ViewPort::setMundo(Mundo _mundo){
      objetos = _mundo.getListaDeObjetos();
      //update();
}

void ViewPort::paintEvent(QPaintEvent *event){
    QPainter painter;
    painter.begin(this);
    painter.setPen(pen);
    painter.setBrush(brush);

    Ponto ponto1 = Ponto("p1",Coordenada(0,400));
    Ponto ponto2 = Ponto("p2",Coordenada(0,-400));

    ponto1 = transformadaViewPort(ponto1);
    ponto2 = transformadaViewPort(ponto2);
    painter.drawLine(ponto1.coord1.getX(), ponto1.coord1.getY(),ponto2.coord1.getX(),ponto2.coord1.getY());

    ponto1 = Ponto("p1",Coordenada(400,0));
    ponto2 = Ponto("p2",Coordenada(-400,0));

    ponto1 = transformadaViewPort(ponto1);
    ponto2 = transformadaViewPort(ponto2);
    painter.drawLine(ponto1.coord1.getX(), ponto1.coord1.getY(),ponto2.coord1.getX(),ponto2.coord1.getY());

    painter.end();
}

Ponto ViewPort::transformadaViewPort(Ponto ponto){
    int tempX = ((ponto.coord1.getX() - minX) *this->width()/ (maxX - minX));
    int tempY = 1*this->height() - ((ponto.coord1.getY() - minY)*this->height()) / (maxY - minY);
    return Ponto(ponto.nome, Coordenada(tempX, tempY));
}

/** Metodos para construção da classe, nada a modificar **/

QSize ViewPort::minimumSizeHint() const{
    return QSize(100,100);
}

QSize ViewPort::sizeHint() const{
    return QSize(400,200);
}

void ViewPort::setPen(const QPen &pen)
{
    this->pen = pen;
    update();
}

void ViewPort::setBrush(const QBrush &brush)
{
    this->brush = brush;
    update();
}

void ViewPort::setAntialiased(bool antialiased)
{
    this->antialiased = antialiased;
    update();
}

void ViewPort::setTransformed(bool transformed)
{
    this->transformed = transformed;
    update();
}
