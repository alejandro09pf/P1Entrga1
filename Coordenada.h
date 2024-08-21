#ifndef COORDENADA_H 
#define COORDENADA_H
#include <string>
#include <vector>

using namespace std;

class Coordenada{
    protected:
    int x;
    int y;
    int z;
    public:
    Coordenada();
    int getX();
    int getY();
    int getZ();
    void setX(int x);
    void setY(int y);
    void setZ(int z);
    
};
#endif