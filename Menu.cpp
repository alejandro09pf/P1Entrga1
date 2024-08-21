#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Sistema.h"

using namespace std;

int main() {
    Sistema s;
    string input, command, param, param2;

    while (true) {
        cout << "$ ";
        getline(cin, input);

        if (input.empty()) continue;  // Ignorar entradas vacías

        stringstream inputStringStream(input);
        inputStringStream >> command;
        
        if (command == "salir") {
            break;
        }

        if (command == "ayuda") {
            inputStringStream >> param;  // Extraer el parámetro después de "ayuda"
            
            if (param.empty()) {
                // Mostrar listado general de comandos si no hay parámetros
                cout << "&&&&&&&&&&&&&&&&&&&&" << endl;
                cout << "& Listado de Ayuda &" << endl;
                cout << "&&&&&&&&&&&&&&&&&&&&" << endl << endl;
                cout << "cargar" << endl;
                cout << "listado" << endl;
                cout << "envolvente (con nombre objeto)" << endl;
                cout << "envolvente" << endl;
                cout << "descargar (con nombre objeto)" << endl;
                cout << "guardar (nombre objeto) (nombre archivo)" << endl;
                cout << "v_cercano px py pz (nombre objeto)" << endl;
                cout << "v_cercano px py pz" << endl;
                cout << "v_cercanos_caja (nombre objeto)" << endl;
                cout << "ruta_corta i1 i2 (nombre objeto)" << endl;
                cout << "ruta_corta_centro i1 (nombre objeto)" << endl;
                cout << "salir" << endl;
            } else {
                // Proporcionar ayuda específica según el parámetro
                if (param == "cargar") {
                    cout << "La forma en la que se escribe el comando cargar es: cargar nombre_archivo\n";
                } else if (param == "listado") {
                    cout << "La forma en la que se escribe el comando listado es: listado\n";
                } else if (param == "envolvente") {
                    cout << "Hay dos tipos de comando envolvente:\n";
                    cout << "envolvente nombre_objeto\n";
                    cout << "envolvente\n";
                } else if (param == "descargar") {
                    cout << "La forma en la que se escribe el comando descargar es: descargar nombre_obejeto\n";
                } else if (param == "guardar") {
                    cout << "La forma en la que se escribe el comando guardar es: guardar nombre_objeto nombre_archivo\n";
                } else if (param == "v_cercano") {
                    cout << "Hay dos tipos de comando v_cercano:\n";
                    cout << "v_cercano px py pz nombre_objeto\n";
                    cout << "v_cercano px py pz\n";
                } else if (param == "v_cercanos_caja") {
                    cout << "La forma en la que se escribe el comando v_cercanos_caja es: v_cercanos_caja nombre_objeto\n";
                } else if (param == "ruta_corta") {
                    cout << "La forma en la que se escribe el comando ruta_corta es: ruta_corta i1 i2 nombre_objeto\n";
                } else if (param == "ruta_corta_centro") {
                    cout << "La forma en la que se escribe el comando ruta_corta_centro es: ruta_corta_centro i1 nombre_objeto\n";
                } else {
                    cout << "Comando de ayuda no reconocido: " << param << "\n";
                }
            }
        } 
        else if (command == "cargar") { 
            inputStringStream >> param;
            if (!param.empty()) {
                s.CargarObjeto(param);
            } else {
                cout << "Error: Falta el parámetro para 'cargar'.\n";
            }
        } 
        else if (command == "listado") { 
            s.Listado();
        } 
        else if (command == "envolvente") { 
            if (inputStringStream >> param) {
                s.EnvolventeObjeto(param);
            } else {
                s.Envolvente();
            }
        } 
        else if (command == "descargar") { 
            inputStringStream >> param;
            if (!param.empty()) {
                s.Descargar(param);
            } else {
                cout << "Error: Falta el parámetro para 'descargar'.\n";
            }
        } 
        else if (command == "guardar") { 
            inputStringStream >> param >> param2;
            if (!param.empty() && !param2.empty()) {
                s.GuardarObjArchivo(param, param2);
            } else {
                cout << "Error: Faltan parámetros para 'guardar'.\n";
            }
        } 
        else if (command == "v_cercano") { 
            string px, py, pz, nomObjeto;
            inputStringStream >> px >> py >> pz >> nomObjeto;
            if (!px.empty() && !py.empty() && !pz.empty()) {
                if (nomObjeto.empty()) {
                    // Llamada a la función correspondiente en Sistema
                    cout << "Usted ha logrado entrar a la seccion de v_cercano px py pz\n";
                } else {
                    // Llamada a la función correspondiente en Sistema
                    cout << "Usted ha logrado entrar a la seccion de v_cercano px py pz nombre objeto\n";
                }
            } else {
                cout << "Algo falló, no se pudo entrar a la seccion de v_cercano px py pz\n";
            }
        } 
        else if (command == "v_cercanos_caja") { 
            inputStringStream >> param;
            if (!param.empty()) {
                // Llamada a la función correspondiente en Sistema
                cout << "Usted ha logrado entrar a la seccion de v_cercanos_caja nombre objeto\n";
            } else {
                cout << "Error: Falta el parámetro para 'v_cercanos_caja'.\n";
            }
        } 
        else if (command == "ruta_corta") { 
            string i1, i2, nomObjeto;
            inputStringStream >> i1 >> i2 >> nomObjeto;
            if (!i1.empty() && !i2.empty() && !nomObjeto.empty()) {
                // Llamada a la función correspondiente en Sistema
                cout << "Usted ha logrado entrar a la seccion de ruta_corta i1 i2 nombre objeto\n";
            } else {
                cout << "Algo falló, no se pudo entrar a la seccion de ruta_corta i1 i2 nombre objeto\n";
            }
        } 
        else if (command == "ruta_corta_centro") { 
            string i1, nomObjeto;
            inputStringStream >> i1 >> nomObjeto;
            if (!i1.empty() && !nomObjeto.empty()) {
                // Llamada a la función correspondiente en Sistema
                cout << "Usted ha logrado entrar a la seccion de ruta_corta_centro i1 nombre objeto\n";
            } else {
                cout << "Algo falló, no se pudo entrar a la seccion de ruta_corta_centro i1 nombre objeto\n";
            }
        } 
        else {
            cout << "Comando no reconocido: " << command << "\n";
        }
    }
    cout << "Usted acaba de cerrar el programa :)\n";
    return 0;
}
