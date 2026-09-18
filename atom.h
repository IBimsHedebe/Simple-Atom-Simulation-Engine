#include <iostream>
#include <string>

class Atom
{
public:
    int xPos = 0, yPos = 0;
    float vel = 0;
    float dir = 0; 
    int radius = 1;
    std::string name;
    int element;

    Atom(std::string iName, int iElement){
        name = iName;
        element = iElement;
        std::cout << "Objekt initialisiert" << std::endl;
    }

    void Info(){
        std::cout << name << " " << element << std::endl;
    }

    void Move();

};