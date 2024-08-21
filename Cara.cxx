#include "Cara.h"
#include <string>
#include <vector>
using namespace std;

Cara::Cara(){

}
//
 int Cara::getNumPuntos(){
    return(numPuntos);
 }
 //
 void Cara::setNumPuntos(){
    numPuntos=this->PuntosXCara.size();
 }
 //
 vector<int> Cara::getPuntosXCara(){
    return(PuntosXCara);
 }
 //
 void Cara::setPuntosXCara(vector<int> PXC){
    PuntosXCara=PXC;
    setNumPuntos();
 }
