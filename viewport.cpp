#include "viewport.h"


ViewPort::ViewPort(QWidget *parent) : QWidget(parent)
{
    objetos = QVector<ObjetoGrafico>();

    setBackgroundRole(QPalette::Light);
    setAutoFillBackground(true);

    vPmaxX = TAMANHO_MAX_X;
    vPminX = TAMANHO_MIN_X;

    vPmaxY = TAMANHO_MAX_Y
    vPminY = TAMANHO_MIN_Y;

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
    painter.setBrush(brush);

    //Preto
    pen.setColor(QColor(0,0,0,255));
    painter.setPen(pen);

    /** Objetos **/
    for(int n=0; n< objetos.size();n++){
        setBrushColor(objetos[n].cor);
        painter.setPen(pen);
        if(objetos[n].quantidadeDePontos()==1){
            // Ponto
            Ponto ponto1 = transformadaViewPort(Ponto(objetos[n].getPontos()[0]));
            painter.drawPoint(ponto1.coord1.getX(),ponto1.coord1.getY());
        }
        else if(objetos[n].quantidadeDePontos()==2){
            //Reta
            Ponto ponto1 = transformadaViewPort(Ponto(objetos[n].getPontos()[0]));
            Ponto ponto2 = transformadaViewPort(Ponto(objetos[n].getPontos()[1]));
            painter.drawLine(ponto1.coord1.getX(),ponto1.coord1.getY(),ponto2.coord1.getX(),ponto2.coord1.getY());//ponto1.coord1.getX(),ponto1.coord1.getY(),ponto2.coord1.getX(),ponto2.coord1.getY());

        }
        else {
            //Poligono
            for(int m = 0; m  < objetos[n].quantidadeDePontos()-1; m++){
                //Ponto a ponto
                Ponto ponto1 = transformadaViewPort(Ponto(objetos[n].getPontos()[m]));
                Ponto ponto2 = transformadaViewPort(Ponto(objetos[n].getPontos()[m+1]));
                painter.drawLine(ponto1.coord1.getX(),ponto1.coord1.getY(),ponto2.coord1.getX(),ponto2.coord1.getY());
            }
            //Ultimo ponto com o primeiro
           Ponto ponto1 = transformadaViewPort(Ponto(objetos[n].getPontos()[0]));
           Ponto ponto2 = transformadaViewPort(Ponto(objetos[n].getPontos()[objetos[n].quantidadeDePontos()-1]));
           painter.drawLine(ponto1.coord1.getX(),ponto1.coord1.getY(),ponto2.coord1.getX(),ponto2.coord1.getY());
        }
    }

    painter.end();
}

Ponto ViewPort::transformadaViewPort(Ponto ponto){
    int tempX = ( ((ponto.coord1.getX() + (this->width()/2) ) / this->width() ) *  (vPmaxX - vPminX));
    int tempY = ( (1 - ((ponto.coord1.getY() + (this->height()/2)) / this->height() )) * (vPmaxY - vPminY));
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

   vPmaxX = vPmaxX*zoom;
   vPminX = vPminX*zoom;

   vPmaxY = vPmaxY*zoom;
   vPminY = vPminY*zoom;
   update();
}

/** Movimentos **/
void ViewPort::moverTela(const int movimento){
    switch(movimento){
    case 1:
        vPmaxY = vPmaxY+50;
        vPminY = vPminY-50;
        break;

    case 2:
        vPmaxY = vPmaxY-50;
        vPminY = vPminY+50;
        break;

    case 3:
        vPmaxX = vPmaxX-50;
        vPminX = vPminX+50;
        break;
    case 4:
        vPmaxX = vPmaxX+50;
        vPminX = vPminX-50;
        break;

    }
    update();
}

void ViewPort::setBrushColor(QColor cor){
    pen.setColor(cor);
}
