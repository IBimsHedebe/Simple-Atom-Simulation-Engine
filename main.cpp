#include <iostream>
#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

int main() {
    InitWindow(800, 600, "Raygui Beispiel");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Button zeichnet sich selbst und gibt true zurück, wenn geklickt
        if (GuiButton((Rectangle){ 350, 250, 100, 40 }, "Klick mich!")) {
            // Aktion bei Klick
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}