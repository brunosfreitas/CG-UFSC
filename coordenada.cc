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
}/*TESTEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
Coordenada Coordenada::operator+(const Coordenada& b){
    return Coordenada(x+b.x(),y+b.y(),z+b.z());
}
Coordenada Coordenada::operator-(const Coordenada& b){
    return Coordenada(x-b.x(),y-b.y(),z-b.z());
}
Coordenada Coordenada::operator*(double escalar){
    return Coordenada(x*escalar,y*escalar,z*escalar);
}
Coordenada Coordenada::operator==(const Coordenada& b){
    return x == b.x() && y == b.y() && z == b.z();
}
*/
