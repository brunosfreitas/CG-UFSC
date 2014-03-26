#ifndef MATRIZ_H
#define MATRIZ_H

class MatrizNuclear {
public:
    MatrizNuclear(int linhas, int colunas);
    MatrizNuclear(const MatrizNuclear& outra);
    virtual ~MatrizNuclear();
    void operator=(const MatrizNuclear& outra);
    MatrizNuclear& operator*=(const MatrizNuclear& outra);
    MatrizNuclear operator*(const MatrizNuclear& outra) const;
    double* operator[](int elemento) const;

    bool operator==(const MatrizNuclear& outra) const;

    bool operator!=(const MatrizNuclear& outra) const;
public:
    static MatrizNuclear rotacao(double anguloRoll = 0, double anguloPitch = 0, double anguloYaw = 0, MatrizNuclear centro = MatrizNuclear(1,4));
private:
    double* valores;
    int linhas, colunas;
};


template <int linhas,int colunas=linhas>
class Matriz
{
public:
    Matriz(): nucleo(linhas,colunas){}
    Matriz(const Matriz<linhas,colunas>& outra): nucleo(outra.nucleo){}
    Matriz<linhas,colunas>& operator*=(Matriz<colunas,colunas> outra){
        nucleo*= outra.nucleo;
        return *this;
    }
    double operator[](int elem){
        return nucleo[elem];
    }
    Matriz<linhas,colunas>& operator=(const Matriz<linhas,colunas>& b){
        this->nucleo = b.nucleo;
        return *this;
    }
    const double* operator[](int elem) const{
        return nucleo[elem];
    }
   bool operator==(const Matriz<linhas,colunas>& b) const{
        return nucleo == b.nucleo;
    }
   bool operator!=(const Matriz<linhas,colunas>& b) const{
        return nucleo != b.nucleo;
    }
   template <int X>
   Matriz <linhas,X> operator*(Matriz<colunas,X> b) const{
       Matriz<linhas,X> resultado;
       resultado.nucleo = nucleo*b.nucleo;
       return resultado;
   };
public:
    MatrizNuclear nucleo;
};

typedef Matriz<1,3> MatrizLinha;


#endif // MATRIZ_H
