#include "Objeto.h"
#include <string>
#include <vector>
using namespace std;

// Constructor
Objeto::Objeto(){

}
// get Nombre
string Objeto::getNombre(){
    return(nombreObjeto);
}
// Setter Nombre
void Objeto::setNombre(string nom){
    this->nombreObjeto=nom;
}
// get Cantidad Puntos
int Objeto::getCantPuntos(){
    return(cantPuntos);
}
// Setter Cantidad Puntos
void Objeto::setCantidadPuntos(int cantP){
    cantPuntos=cantP;
}
// Getter Coordenadas
vector<Coordenada> Objeto::getCoordenadas(){
    return(coordenadas);
}
// Setter Coordenadas
void Objeto::setCoordenadas(int x, int y, int z){
    Coordenada aux;
    aux.setX(x);
    aux.setY(y);
    aux.setZ(z);
    coordenadas.push_back(aux);
}
// Getter Caras
vector<Cara> Objeto::getCaras(){
    return(caras);
}
// Setter Caras
void Objeto::setCaras(vector<int>PXC){
    Cara aux;
    aux.setPuntosXCara(PXC);
    caras.push_back(aux); // Agregar la cara al vector de caras
}
// Metodo PMIN
vector<int> Objeto::PMIN() {
    vector<Coordenada>::iterator it;
    vector<Coordenada> aux = getCoordenadas();
    vector<int> pMin;

    // Inicializamos con los valores de la primera coordenada
    if (aux.size() > 0) {
        int tempX = aux[0].getX();
        int tempY = aux[0].getY();
        int tempZ = aux[0].getZ();

        // Iteramos sobre el resto de las coordenadas
        for (it = aux.begin() + 1; it != aux.end(); it++) {
            if (tempX > it->getX()) {
                tempX = it->getX();
            }
            if (tempY > it->getY()) {
                tempY = it->getY();
            }
            if (tempZ > it->getZ()) {
                tempZ = it->getZ();
            }
        }

        pMin.push_back(tempX);
        pMin.push_back(tempY);
        pMin.push_back(tempZ);
    }

    return pMin;
}

// Metodo PMAX
vector<int> Objeto::PMAX() {
    vector<Coordenada>::iterator it;
    vector<Coordenada> aux = getCoordenadas();
    vector<int> pMax;

    // Inicializamos con los valores de la primera coordenada
    if (aux.size() > 0) {
        int tempX = aux[0].getX();
        int tempY = aux[0].getY();
        int tempZ = aux[0].getZ();

        // Iteramos sobre el resto de las coordenadas
        for (it = aux.begin() + 1; it != aux.end(); it++) {
            if (tempX < it->getX()) {
                tempX = it->getX();
            }
            if (tempY < it->getY()) {
                tempY = it->getY();
            }
            if (tempZ < it->getZ()) {
                tempZ = it->getZ();
            }
        }

        pMax.push_back(tempX);
        pMax.push_back(tempY);
        pMax.push_back(tempZ);
    }
    return pMax;
}

