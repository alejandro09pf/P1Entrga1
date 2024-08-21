#include "Sistema.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>  
using namespace std;

Sistema::Sistema(){

};
//
vector<Objeto>Sistema::getObjetos(){
    return(objetos);
}
//
void Sistema::setObjeto(string nom, int cantP, vector<int> coordenadas, vector<int> caras){
    Objeto aux;
    vector<int> aux2;
    aux.setNombre(nom);
    aux.setCantidadPuntos(cantP);
    for(int c : coordenadas){
        aux.setCoordenadas(c,c+1,c+2);
        c+=2;
    }
    
    for(int c : caras){
        int aux3=caras[c];
        for(int i=0;i<aux3;i++){
            aux2.push_back(caras[c+1]);
            c+=1;
        }
    }
    aux.setCaras(aux2);
}
// Cargar Archivo con Objeto
// Cargar Archivo con Objeto
void Sistema::CargarObjeto(string nomArchivo){
    Objeto o;
    ifstream lectura;
    string aux;
    int aux2;
    string nomObjeto;
    int cantPuntos;
    int x,y,z;
    // Abrimos Archivo
    lectura.open(nomArchivo);
    // Evaluamos Error Apertura
    if(lectura.fail()){
        cout << "El archivo " <<nomArchivo<<" no existe o es ilegible"<<endl;
        return;
    }
    // Ingresamos primeros valores
    getline(lectura,nomObjeto);
    getline(lectura,aux);
    /*if(aux.find(' ')!=string::npos){ // Verificar si el archivo si esta en el formato que es
        cout << "El archivo " <<nomArchivo<<" no contiene un objeto 3D valido"<<endl;
        return;
    }*/
    cantPuntos=stoi(aux);// Convierto en int la cant de puntos y la guardo en la variable
    // Guardamos Nombre y CantPuntos
    o.setNombre(nomObjeto);// Guardo Nombre
    o.setCantidadPuntos(cantPuntos);// Guardo Cantidad Puntos
    // Leer Coordenadas
    for(int i=0;i<cantPuntos;i++){
        getline(lectura,aux);
        istringstream stream(aux);
        stream >> x >> y >> z;
        o.setCoordenadas(x,y,z);
    }
    // Leer Caras
    int punto;
    while (getline(lectura, aux) && aux != "-1") {
        istringstream stream(aux);
        int cantidadVertices;
        stream >> cantidadVertices;
        // Crear un vector para almacenar los índices de los puntos que forman una cara
        vector<int> caraPuntos;
        for (int i = 0; i < cantidadVertices; i++) {
            if (stream >> punto) {
                caraPuntos.push_back(punto);
            }
        }
        // Crear un objeto Cara y agregarlo al objeto o
        o.setCaras(caraPuntos);
    }
    objetos.push_back(o);
    lectura.close();
}
// listado
void Sistema::Listado(){
    vector<Objeto>::iterator it;
    Objeto o;
    if(objetos.size()==0){
        cout<<"Ningun objeto ha sido cargado en memoria"<<endl;
    }
    else{
        cout<<"Hay "<< objetos.size()<<" en memoria"<<endl;
        for(it=objetos.begin();it!=objetos.end();it++){
            o=*it;
            cout<<o.getNombre()<<" contiene "<< o.getCantPuntos()<<" vertices, "<<o.getCantPuntos()-o.getCaras().size()-2<< " aristas, "<<"y "<< o.getCaras().size()<<" caras."<<endl;
        }
    }
}
// // envolvente nombre_objeto
void Sistema::EnvolventeObjeto(string nomObj){
    Objeto o;
    Objeto envolventeO;
    string nomEnvO;
    vector<Objeto>::iterator it;
    bool confirmo=false;
    for(it=objetos.begin();it!=objetos.end();it++){
        if(it->getNombre()==nomObj){
            o=*it;
            confirmo=true;
            break;
        }
    }
    if(confirmo==false){
        cout << "El Objeto " <<nomObj<<" no ha sido cargado en memoria"<<endl;
        return;
    }
    vector<int>pMin=o.PMIN();
    vector<int>pMax=o.PMAX();
    nomEnvO="env_"+nomObj;
    envolventeO.setNombre(nomEnvO);
    envolventeO.setCantidadPuntos(8);
    // Guardar coordenadas
    //Punto 1
    envolventeO.setCoordenadas(pMin[0],pMin[1],pMin[2]);
    //Punto 2
    envolventeO.setCoordenadas(pMin[0],pMin[1],pMax[2]);
    //Punto 3
    envolventeO.setCoordenadas(pMax[0],pMin[1],pMax[2]);
    //Punto 4
    envolventeO.setCoordenadas(pMax[0],pMin[1],pMin[2]);
    //Punto 5
    envolventeO.setCoordenadas(pMax[0],pMax[1],pMin[2]);
    // Punto 6
    envolventeO.setCoordenadas(pMin[0],pMax[1],pMin[2]);
    //Punto 7
    envolventeO.setCoordenadas(pMin[0],pMax[1],pMax[2]);
    //Punto 8
    envolventeO.setCoordenadas(pMax[0],pMax[1],pMax[2]);

    // Guardar Caras
    vector<int>pxp;
    // Cara 1
    pxp.push_back(1);
    pxp.push_back(2);
    pxp.push_back(3);
    pxp.push_back(4);
    envolventeO.setCaras(pxp);
    //
    pxp.clear();
    // Cara 2
    pxp.push_back(2);
    pxp.push_back(3);
    pxp.push_back(8);
    pxp.push_back(7);
    envolventeO.setCaras(pxp);
    //
    pxp.clear();
    // Cara 3
    pxp.push_back(2);
    pxp.push_back(1);
    pxp.push_back(6);
    pxp.push_back(7);
    envolventeO.setCaras(pxp);
    //
    pxp.clear();
    // Cara 4
    pxp.push_back(7);
    pxp.push_back(8);
    pxp.push_back(5);
    pxp.push_back(6);
    envolventeO.setCaras(pxp);
    //
    pxp.clear();
    // Cara 5
    pxp.push_back(3);
    pxp.push_back(4);
    pxp.push_back(5);
    pxp.push_back(8);
    envolventeO.setCaras(pxp);
    //
    pxp.clear();
    // Cara 6
    pxp.push_back(4);
    pxp.push_back(5);
    pxp.push_back(6);
    pxp.push_back(1);
    envolventeO.setCaras(pxp);
    //
    pxp.clear();
    // Guardar en lista Objetos en Memoria
    objetos.push_back(envolventeO); 
}
// comando envolvente
void Sistema::Envolvente(){
    Objeto o;
    Coordenada c;
    vector<Objeto>::iterator it;
    vector<Coordenada>coordPMax;
    vector<Coordenada>coordPMin;
    vector<int> aux;
    if(objetos.empty()){
        cout<<"No hay objetos en Memoria"<<endl;
        return;
    }
    // Guardo todos los PMAX de Cada objeto en cada casilla del vector coordPMAX
    for(it=objetos.begin();it!=objetos.end();it++){
        o=*it;
        aux=o.PMAX();
        c.setX(aux[0]);
        c.setY(aux[1]);
        c.setZ(aux[2]);
        coordPMax.push_back(c);
    }
    aux.clear();
    // Guardo todos los PMIN de Cada objeto en cada casilla del vector coordPMAX
    for(it=objetos.begin();it!=objetos.end();it++){
        o=*it;
        aux=o.PMIN();
        c.setX(aux[0]);
        c.setY(aux[1]);
        c.setZ(aux[2]);
        coordPMin.push_back(c);
    }
    // Obtengo el PMAX Y PMIN de todos los Objetos
    vector<int>pMin=PMINGeneral(coordPMin);
    vector<int>pMax=PMAXGeneral(coordPMax);
    // Guardo valores en Memoria
    Objeto envGlobal;
    envGlobal.setNombre("env_global");
    envGlobal.setCantidadPuntos(8);
    // Guardar coordenadas
    //Punto 1
    envGlobal.setCoordenadas(pMin[0],pMin[1],pMin[2]);
    //Punto 2
    envGlobal.setCoordenadas(pMin[0],pMin[1],pMax[2]);
    //Punto 3
    envGlobal.setCoordenadas(pMax[0],pMin[1],pMax[2]);
    //Punto 4
    envGlobal.setCoordenadas(pMax[0],pMin[1],pMin[2]);
    //Punto 5
    envGlobal.setCoordenadas(pMax[0],pMax[1],pMin[2]);
    // Punto 6
    envGlobal.setCoordenadas(pMin[0],pMax[1],pMin[2]);
    //Punto 7
    envGlobal.setCoordenadas(pMin[0],pMax[1],pMax[2]);
    //Punto 8
    envGlobal.setCoordenadas(pMax[0],pMax[1],pMax[2]);

    // Guardar Caras
    vector<int>pxp;
    // Cara 1
    pxp.push_back(1);
    pxp.push_back(2);
    pxp.push_back(3);
    pxp.push_back(4);
    envGlobal.setCaras(pxp);
    //
    pxp.clear();
    // Cara 2
    pxp.push_back(2);
    pxp.push_back(3);
    pxp.push_back(8);
    pxp.push_back(7);
    envGlobal.setCaras(pxp);
    //
    pxp.clear();
    // Cara 3
    pxp.push_back(2);
    pxp.push_back(1);
    pxp.push_back(6);
    pxp.push_back(7);
    envGlobal.setCaras(pxp);
    //
    pxp.clear();
    // Cara 4
    pxp.push_back(7);
    pxp.push_back(8);
    pxp.push_back(5);
    pxp.push_back(6);
    envGlobal.setCaras(pxp);
    //
    pxp.clear();
    // Cara 5
    pxp.push_back(3);
    pxp.push_back(4);
    pxp.push_back(5);
    pxp.push_back(8);
    envGlobal.setCaras(pxp);
    //
    pxp.clear();
    // Cara 6
    pxp.push_back(4);
    pxp.push_back(5);
    pxp.push_back(6);
    pxp.push_back(1);
    envGlobal.setCaras(pxp);
    //
    pxp.clear();

    // Guardar en lista Objetos en Memoria
    objetos.push_back(envGlobal); 
}

// comando descargar
void Sistema::Descargar(string nomO){
    Objeto o;
    vector<Objeto>::iterator it;
    bool confirmo=false;
    for (int i=0; i < objetos.size(); i++){
        o=objetos[i];
        if(o.getNombre()==nomO){
            objetos.erase(objetos.begin()+i);
            confirmo=true;
            break;
        }
    }
    if(confirmo==false){
        cout<<"El objeto "<< nomO<< " no ha sido cargado en memoria"<<endl;
        return;
    }
    else{
        cout<<"El objeto "<< nomO<< " ha sido eliminado de memoria"<<endl;
    }
}
// comando guardar objeto en archivo
void Sistema::GuardarObjArchivo(string nomO, string nomA){
    ofstream escritura;
    Objeto o;
    bool confirmo=false;
    for (int i=0; i < objetos.size(); i++){
        if (objetos[i].getNombre()==nomO){
            o=objetos[i];
            confirmo=true;
            break;
        }
    }
    if(confirmo==false){
        cout<<"El objeto "<< nomO<< " no ha sido cargado en memoria"<<endl;
        return;
    }
    else{
        cout<<"La informacion del objeto "<< nomO<< " ha sido guardada exitosamente en el archivo "<<nomA<<endl;
        escritura.open(nomA);
        if(escritura.fail()){
            cout << "El archivo " <<nomA<<" no abre :("<<endl;
            return;
        }
        //Proceso Escritura
        escritura<<o.getNombre()<<endl;
        escritura<<o.getCantPuntos()<<endl;
        vector<Coordenada>coord = o.getCoordenadas();
        // Escritura de Coordenadas
        for(int i=0;i<coord.size();i++){
            escritura << coord[i].getX()<<" "<<coord[i].getY()<<" "<< coord[i].getZ()<<endl;
        }
        // Escritura de Caras
        vector<Cara>caras = o.getCaras();
        for(int i=0;i<caras.size();i++){
            escritura << caras[i].getNumPuntos()<<" ";
            for(int j=0; j<caras[i].getNumPuntos();j++){
                escritura<<caras[i].getPuntosXCara()[j]<<" ";
            }
            escritura<<endl;
        }
        escritura<<-1;
        escritura.close();
    }
}
// Metodos Auxiliares
// PMIN General
vector<int> Sistema::PMINGeneral(vector<Coordenada> pminCoord) {
    vector<Coordenada>::iterator it;
    vector<int> pMin;

    // Inicializar con los valores de la primera coordenada
    int tempX = pminCoord[0].getX();
    int tempY = pminCoord[0].getY();
    int tempZ = pminCoord[0].getZ();

    // Iterar sobre las coordenadas para encontrar las mínimas
    for (it = pminCoord.begin(); it != pminCoord.end(); it++) {
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
    return pMin;
}
// PMAX General
vector<int> Sistema::PMAXGeneral(vector<Coordenada> pmaxCoord) {
    vector<Coordenada>::iterator it;
    vector<int> pMax;

    // Inicializar con los valores de la primera coordenada
    int tempX = pmaxCoord[0].getX();
    int tempY = pmaxCoord[0].getY();
    int tempZ = pmaxCoord[0].getZ();

    // Iterar sobre las coordenadas para encontrar las máximas
    for (it = pmaxCoord.begin(); it != pmaxCoord.end(); it++) {
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
    return pMax;
}


