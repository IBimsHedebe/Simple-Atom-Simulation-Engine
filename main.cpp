#include <iostream>
#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

typedef struct {
    const char *shortcut;
    const char *name;
} Tool;

Tool tools[] = {
    { "H", "Wasserstoff" },
    { "C", "Kohlenstoff" },
    { "O", "Sauerstoff" },
};
#define TOOL_COUNT (sizeof(tools) / sizeof(tools[0]))

char inputBuffer[3] = "";
const char *activeTool = "Keines";

void UpdateShortcutSystem(void) {
    int key = GetCharPressed();
    
    while (key > 0) {
        if ((key >= 'a' && key <= 'z') || (key >= 'A' && key <= 'Z')) {
            if (key >= 'a') key -= 32; // In Großbuchstaben umwandeln

            int len = strlen(inputBuffer);
            if (len < 2) {
                inputBuffer[len] = (char)key;
                inputBuffer[len + 1] = '\0'; // String-Ende setzen
            }
        }
        key = GetCharPressed();
    }

    bool matchFound = false;
    for (int i = 0; i < TOOL_COUNT; i++) {
        if (strcmp(inputBuffer, tools[i].shortcut) == 0) {
            activeTool = tools[i].name;
            matchFound = true;
            inputBuffer[0] = '\0';
            break;
        }
    }

    if (!matchFound && strlen(inputBuffer) >= 2) {
        inputBuffer[0] = '\0';
    }
}


int main() {
    InitWindow(1280, 720, "Simple Atom Simulation Engine");
    SetTargetFPS(60);

    bool dropdownEditMode = false;
    int dropdownActive = 0;



    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_F11)) ToggleFullscreen();

        UpdateShortcutSystem();

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            activeTool = "Keines"; 
        }

        int currentWidth = GetScreenWidth();
        int currentHeight = GetScreenHeight();
        
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
        if (GuiDropdownBox((Rectangle){ 210, 5, 140, 30 }, "Wasserstoff;Kohlenstoff;Sauerstoff", &dropdownActive, dropdownEditMode)) {
            dropdownEditMode = !dropdownEditMode;
        }

        DrawText(TextFormat("Aktives Werkzeug: %s", activeTool), 50, 300, 24, MAROON);

        const char *displayText = TextFormat("Eingabe: [%s]", inputBuffer);
        int textWidth = MeasureText(displayText, 20);
        
        DrawText(displayText, currentWidth - textWidth - 20, currentHeight - 40, 20, BLUE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}