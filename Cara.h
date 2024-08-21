#ifndef CARA_H 
#define CARA_H
#include <string>
#include <vector>

using namespace std;

class Cara{
    protected:
    int numPuntos;
    vector<int> PuntosXCara;
    public:
    Cara();
    int getNumPuntos();
    void setNumPuntos();
    vector<int> getPuntosXCara();
    void setPuntosXCara(vector<int> PXC);
};
#endif // CARA_H