#include "coordenada.h"
#include <limits>


Coordenada::Coordenada(double nx, double ny, double nz){
    x = nx;
    y = ny;
    z = nz;

}

double Coordenada::getX(){
    return x;
}
double Coordenada::getY(){
    return y;
}
double Coordenada::getZ(){
    return z;
}
void Coordenada::setX(double newX){
    x = newX;
}
void Coordenada::setY(double newY){
    y = newY;
}
void Coordenada::setZ(double newZ){
    z = newZ;
}
Coordenada Coordenada::operator+(Coordenada& b){
    return Coordenada(x + b.getX(),y + b.getY(),z + b.getZ());
}
Coordenada Coordenada::operator-(Coordenada& b){
    return Coordenada(x-b.getX(),y-b.getY(),z-b.getZ());
}
Coordenada Coordenada::operator*(double escalar){
    return Coordenada(x*escalar,y*escalar,z*escalar);
}
bool Coordenada::operator==(Coordenada& b){
    return x == b.getX() && y == b.getY() && z == b.getZ();
}

