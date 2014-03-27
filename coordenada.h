#ifndef COORDENADA_H
#define COORDENADA_H


#define COORDENADA_WIDTH 4;

class Coordenada{
private:
    double x;
    double y;
    double z;
 public:
    Coordenada(double nx, double ny, double nz=0.0);
    Coordenada():x(0),y(0),z(0){}

    double getX();
    double getY();
    double getZ();

    void setX(double newX);
    void setY(double newY);
    void setZ(double newZ);

    Coordenada operator+(Coordenada& b);
    Coordenada operator-(Coordenada& b);
    Coordenada operator*(double);
    bool operator==(Coordenada& b);
};

#endif // COORDENADA_H
