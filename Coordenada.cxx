#include "Coordenada.h"
#include <string>
#include <vector>
using namespace std;

Coordenada::Coordenada(){

}
//
int Coordenada::getX(){
    return(x);
}
//
int Coordenada::getY(){
    return(y);
}
//
int Coordenada::getZ(){
    return(z);
}
//
void Coordenada::setX(int x){
    this->x=x;
}
//
void Coordenada::setY(int y){
    this->y=y;
}
//
void Coordenada::setZ(int z){
    this->z=z;
}
