#ifndef OBJETO_H 
#define OBJETO_H
#include <string>
#include <vector>
#include"Cara.h"
#include"Coordenada.h"
using namespace std;

class Objeto{
    protected:
    string nombreObjeto;
    int cantPuntos;
    vector<Coordenada>coordenadas;
    vector<Cara>caras;
    public:
    Objeto();
    string getNombre();
    void setNombre(string nom);
    int getCantPuntos();
    void setCantidadPuntos(int cantP);
    vector<Coordenada> getCoordenadas();
    void setCoordenadas(int x, int y, int z);
    vector<Cara> getCaras();
    void setCaras(vector<int>PXC);
    vector<int> PMIN();
    vector<int> PMAX();
};
#endif