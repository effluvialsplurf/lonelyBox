#include "scenes.h"
#include <raylib.h>

static Scene current_scene = TITLE;

void UpdateDrawScene(void) {
    switch (current_scene) {
        case TITLE: 
        {
            DrawText("lonelyBox", 90, 200, 100, PINK);

            if (IsKeyPressed(KEY_RIGHT)){
                current_scene = ONE;
            }
        }break;

        case ONE:
        {
            DrawText("one", 90, 200, 100, PINK);

            if (IsKeyPressed(KEY_RIGHT)){
                current_scene = TWO;
            }
        }break;

        case TWO:
        {
            DrawText("two", 90, 200, 100, PINK);

            if (IsKeyPressed(KEY_RIGHT)){
                current_scene = THREE;
            }
        }break;

        case THREE:
        {
            DrawText("three", 90, 200, 100, PINK);

            if (IsKeyPressed(KEY_RIGHT)){
                current_scene = FOUR;
            }
        }break;

        case FOUR:
        {
            DrawText("four", 90, 200, 100, PINK);

            if (IsKeyPressed(KEY_RIGHT)){
                current_scene = TITLE;
            }
        }break;
    }
}

