#include <iostream>
#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

int main() {
    InitWindow(1280, 720, "Simple Atom Simulation Engine");
    SetTargetFPS(60);

    bool dropdownEditMode = false;
    int dropdownActive = 0;



    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_F11)) ToggleFullscreen();

        int currentWidth = GetScreenWidth();
        
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawRectangle(0,0, currentWidth, 40, LIGHTGRAY);
        DrawLine(0, 40, currentWidth, 40, GRAY);

        // Button 1 Dateien importieren
        if (GuiButton((Rectangle){10, 5, 80, 30}, "#01# Datei")) {
            TraceLog(LOG_INFO, "Imporitieren");
        }

        // Button 2 Speichern
        if (GuiButton((Rectangle){100, 5, 100, 30}, "#02# Speichern")) {
            TraceLog(LOG_INFO, "Exportieren");
        }

        // Button 3 Tools
        if (GuiDropdownBox((Rectangle){ 210, 5, 140, 30 }, "Stift;Radiergummi;Auswählen;Zoom", &dropdownActive, dropdownEditMode)) {
            dropdownEditMode = !dropdownEditMode;
        }
        


        EndDrawing();
    }

    CloseWindow();
    return 0;
}