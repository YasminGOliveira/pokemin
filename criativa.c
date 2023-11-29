#include "raylib.h"
#include <stdio.h>
#include <string.h>

#define MAX_POKEMONS 6

enum Screen {
        WELCOME_SCREEN,
        POKEMON_SELECTION_SCREEN,
        MENU_SCREEN,
        COLLECTION_SCREEN,
        BACKPACK_SCREEN
    };
    
// Estrutura para representar um Pokémon
typedef struct {
    const char* name;
} Pokemon;

void DrawTextBox(const char* text, int posX, int posY, int width, int height, Color textColor, Color boxColor) {
    DrawRectangle(posX, posY, width, height, boxColor);
    DrawText(text, posX + 10, posY + 10, 20, textColor);
}

int main() {
    const int screenWidth = 1900;
    const int screenHeight = 950;
    bool showMessage = false;
    float messageTimer = 0.0f;
    const float messageDuration = 3.0f;

    InitWindow(screenWidth, screenHeight, "Jornada Pokémon");
    
    // Carregar uma imagem como plano de fundo
    Texture2D background = LoadTexture("C:/pokemon.png");

    SetTargetFPS(60);

    int currentScreen = WELCOME_SCREEN;
    Pokemon playerCollection[MAX_POKEMONS];
    int collectionCount = 0;
    Pokemon pokemons[MAX_POKEMONS] = {{"Bulbasaur"}, {"Charmander"}, {"Squirtle"}};
    int selectedPokemon = -1;
    int pokeballs = 50;

    Rectangle startButton = { screenWidth / 2 - 100, screenHeight / 2 - 25, 200, 50 };
    Rectangle pokemonButtons[MAX_POKEMONS] = {
        { screenWidth / 4 - 100, screenHeight / 2, 200, 50 },
        { screenWidth / 2 - 100, screenHeight / 2, 200, 50 },
        { screenWidth * 3 / 4 - 100, screenHeight / 2, 200, 50 }
    };
    
    Rectangle mapaButton = { screenWidth / 2 - 100, screenHeight / 2 - 80, 200, 100 };
    Rectangle collectionButton = { screenWidth / 2 - 100, screenHeight / 2 - 30, 200, 50 };
    Rectangle backpackButton = { screenWidth / 2 - 100, screenHeight / 2, 200, 50 };

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        if (currentScreen == WELCOME_SCREEN) {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), startButton)) {
                currentScreen = POKEMON_SELECTION_SCREEN;
            }

            BeginDrawing();
            ClearBackground(RAYWHITE);

            DrawTexture(background, 0, 0, WHITE);
            
            DrawText("Bem-vindo!", screenWidth / 2 - MeasureText("Bem-vindo!", 40) / 1, screenHeight / 4, 80, WHITE);

            // Desenha o botão de começar
            DrawRectangleRec(startButton, DARKGREEN);
            DrawText("Começar", startButton.x + 40, startButton.y + 10, 30, WHITE);

            EndDrawing();
        } else if (currentScreen == POKEMON_SELECTION_SCREEN) {
            BeginDrawing();
            ClearBackground(RAYWHITE);
            
            DrawTexture(background, 0, 0, WHITE);

            DrawText("Comece sua jornada!\nEscolha um Pokémon inicial:", screenWidth / 4, screenHeight / 4, 40, BLACK);

            for (int i = 0; i < MAX_POKEMONS; ++i) {
                Color buttonColor = GRAY;

                if (i == 0) buttonColor = GREEN; // Bulbasaur
                else if (i == 1) buttonColor = RED; // Charmander
                else if (i == 2) buttonColor = BLUE; // Squirtle

                DrawRectangleRec(pokemonButtons[i], buttonColor);
                DrawText(pokemons[i].name, pokemonButtons[i].x + 25, pokemonButtons[i].y + 10, 25, WHITE);

                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), pokemonButtons[i])) {
                    selectedPokemon = i;
                    break;
                }
            }

            if (selectedPokemon != -1) {
                showMessage = true;
                messageTimer = 0.0f; // Reseta o temporizador quando a mensagem é exibida
                currentScreen = MENU_SCREEN;
            }
            EndDrawing();
        } else if (currentScreen == MENU_SCREEN) {
            BeginDrawing();
            ClearBackground(RAYWHITE);
            
            //CARREGAR FUNDO
            DrawTexture(background, 0, 0, WHITE);

            DrawText("Menu", screenWidth / 2 - MeasureText("Menu", 40) / 2, screenHeight / 4, 80, WHITE);

            DrawRectangleRec(mapaButton, DARKGREEN);
            DrawText("Mapa", mapaButton.x + 35, mapaButton.y + -5, 30, WHITE);
            
            DrawRectangleRec(collectionButton, DARKGREEN);
            DrawText("Coleção", collectionButton.x + 35, collectionButton.y + 10, 30, WHITE);

            DrawRectangleRec(backpackButton, DARKGREEN);
            DrawText("Mochila", backpackButton.x + 35, backpackButton.y + 30, 30, WHITE);
           
           if (showMessage) {
                DrawTextBox("POKEMON ESCOLHIDO", 10, 10, 250, 50, WHITE, BLACK);
                if (messageTimer < messageDuration) {
                    messageTimer += GetFrameTime();
                } else {
                    showMessage = false;
                }
            }
            EndDrawing();
        } else if (currentScreen == COLLECTION_SCREEN) {
            BeginDrawing();
            ClearBackground(RAYWHITE);

            DrawText("Coleção de Pokémon:", 10, 10, 20, BLACK);
            for (int i = 0; i < collectionCount; ++i) {
                DrawText(TextFormat("%d. %s", i + 1, playerCollection[i].name), 10, 40 + i * 20, 20, BLACK);
            }

            EndDrawing();
            
        } else if (currentScreen == BACKPACK_SCREEN) {
            BeginDrawing();
            ClearBackground(RAYWHITE);

            DrawText("Mochila de Pokémon", screenWidth / 4, screenHeight / 4, 20, BLACK);

            DrawText("Insira o nome do Pokémon:", screenWidth / 4, screenHeight / 4 + 30, 20, BLACK);
            DrawText(TextFormat("Pokébolas disponíveis: %d", pokeballs), screenWidth / 4, screenHeight / 4 + 60, 20, BLACK);

            EndDrawing();
        }
    }
    UnloadTexture(background);


    CloseWindow();
    return 0;
}
