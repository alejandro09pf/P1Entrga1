#ifndef SISTEMA_H
#define SISTEMA_H
#include <string>
#include <vector>
#include"Objeto.h"
using namespace std;

class Sistema{
    protected:
    vector<Objeto> objetos;
    public:
    Sistema();
    vector<Objeto> getObjetos();
    void setObjeto(string nom, int cantP, vector<int> coordenadas, vector<int> caras);
    // comando cargar nombre_archivo
    void CargarObjeto(string nomArchivo);
    // comando listado
    void Listado();
    // comando envolvente nombre_objeto
    void EnvolventeObjeto(string nomObj);
    // comando envolvente
    void Envolvente();
    // comando descargar
    void Descargar(string nomO);
    // comando guardar objeto en archivo
    void GuardarObjArchivo(string nomO, string nomA);

    // Metodos Auxiliares:
    // PMIN General
    vector<int> PMINGeneral(vector<Coordenada>pminCoord);
     // PMAX General
    vector<int> PMAXGeneral(vector<Coordenada>pmaxCoord);
};
#endif