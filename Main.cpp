#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Sistema.h"

using namespace std;

int main(){
    Sistema s;
    s.CargarObjeto("ejemplo1.txt");
    s.CargarObjeto("ejemplo2.txt");
    s.Listado();
    s.EnvolventeObjeto("Mesh_0");
    s.EnvolventeObjeto("Mesh_1");
    s.Envolvente();
    s.Listado();
    s.GuardarObjArchivo("env_Mesh_0","salida1.txt");
    s.GuardarObjArchivo("env_Mesh_1","salida2.txt");
    s.GuardarObjArchivo("env_global","salida3.txt");
    return 0;
}