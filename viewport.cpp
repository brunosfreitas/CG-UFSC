#include "viewport.h"


ViewPort::ViewPort(QWidget *parent) : QWidget(parent)
{
    objetos = QVector<ObjetoGrafico>();

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
    pen.setColor(QColor(0,255,0,255));
    painter.setPen(pen);
    painter.setBrush(brush);

    /** Eixos X e Y **/
    Ponto ponto1 = Ponto("p1",Coordenada(0,4000));
    Ponto ponto2 = Ponto("p2",Coordenada(0,-4000));

    ponto1 = transformadaViewPort(ponto1);
    ponto2 = transformadaViewPort(ponto2);
    painter.drawLine(ponto1.coord1.getX(), ponto1.coord1.getY(),ponto2.coord1.getX(),ponto2.coord1.getY());

    ponto1 = Ponto("p1",Coordenada(4000,0));
    ponto2 = Ponto("p2",Coordenada(-4000,0));

    ponto1 = transformadaViewPort(ponto1);
    ponto2 = transformadaViewPort(ponto2);
    painter.drawLine(ponto1.coord1.getX(), ponto1.coord1.getY(),ponto2.coord1.getX(),ponto2.coord1.getY());

    //Preto
    pen.setColor(QColor(0,0,0,255));
    painter.setPen(pen);

    /** Objetos **/
    for(int n=0; n< objetos.size();n++){
        if(objetos[n].quantidadeDePontos()==1){
            // Ponto
            ponto1 = transformadaViewPort(Ponto(objetos[n].getPontos()[0]));
            painter.drawPoint(ponto1.coord1.getX(),ponto1.coord1.getY());
        }
        else if(objetos[n].quantidadeDePontos()==2){
            //Reta
            ponto1 = transformadaViewPort(Ponto(objetos[n].getPontos()[0]));
            ponto2 = transformadaViewPort(Ponto(objetos[n].getPontos()[1]));
            painter.drawLine(ponto1.coord1.getX(),ponto1.coord1.getY(),ponto2.coord1.getX(),ponto2.coord1.getY());//ponto1.coord1.getX(),ponto1.coord1.getY(),ponto2.coord1.getX(),ponto2.coord1.getY());

        }
        else {
            //Poligono
            for(int m = 0; m  < objetos[n].quantidadeDePontos()-1 ; m++){
                //Ponto a ponto
                ponto1 = transformadaViewPort(Ponto(objetos[n].getPontos()[m]));
                ponto2 = transformadaViewPort(Ponto(objetos[n].getPontos()[m+1]));
                painter.drawLine(ponto1.coord1.getX(),ponto1.coord1.getY(),ponto2.coord1.getX(),ponto2.coord1.getY());
            }
            //Ultimo ponto com o primeiro
           ponto1 = transformadaViewPort(Ponto(objetos[n].getPontos()[0]));
           ponto2 = transformadaViewPort(Ponto(objetos[n].getPontos()[objetos[n].quantidadeDePontos()-1]));
           painter.drawLine(ponto1.coord1.getX(),ponto1.coord1.getY(),ponto2.coord1.getX(),ponto2.coord1.getY());
        }
    }

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
    return QSize(200,200);
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

/** Zoom **/
void ViewPort::zoom(bool positivo){
   double zoom = 0.9;
   if(!positivo)
       zoom = 1.1;

   maxX = maxX*zoom;
   minX = minX*zoom;

   maxY = maxY*zoom;
   minY = minY*zoom;
   update();
}

/** Movimentos **/
void ViewPort::moverTela(int movimento){
    switch(movimento){
    case 1:
        maxY = maxY*1.1;
        minY = minY*0.9;
        break;

    case 2:
        maxY = maxY*0.9;
        minY = minY*1.1;
        break;

    case 3:
        maxX = maxX*0.9;
        minX = minX*1.1;
        break;
    case 4:
        maxX = maxX*1.1;
        minX = minX*0.9;
        break;

    }
    update();
}
