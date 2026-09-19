#include "raylib.h"
#include <iostream>
#include <string>

class Atom
{
public:
    Vector2 position;
    float vel = 0;
    float dir = 0; 
    int radius = 1;
    std::string name;
    int element;


    // Texture
    Texture2D elementSheet = LoadTexture("Elements.png");

    float spriteWidth = 32.0f;
    float spriteHeight = 32.0f;

    int column = 0;
    int row = 0;

    Rectangle sourceRec;

    Atom(std::string iName, int iElement, Vector2 iPos, int iColumn, int iRow){
        name = iName;
        element = iElement;
        position = iPos;
        column = iColumn;
        row = iRow;
        std::cout << "Objekt initialisiert" << std::endl;

        // Texture loading
        sourceRec = {
            column * spriteWidth,
            row * spriteHeight,
            spriteWidth,
            spriteHeight
        };



    }

    void Info(){
        std::cout << name << " " << element << std::endl;
    }

    void Move();

    void Draw(){
        DrawTextureRec(elementSheet, sourceRec, position, WHITE);
    }

};