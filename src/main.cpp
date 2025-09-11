#include <raylib.h>
#include "../assets/lonelyBoxColors.cpp"

typedef enum Screen {TITLE, ONE, TWO, THREE, FOUR} Screen;
Screen current_screen = TITLE;

const int display_width = 1280;
const int display_height = 720;
int fps = 60;

int main(void) {
    // initialize context
    InitWindow(display_width, display_height, "lonelyBox");
    // set the fps
    SetTargetFPS(fps);

    // game loop
    while (!WindowShouldClose()) {
        BeginDrawing();

        // clear background before drawing anything
        ClearBackground(DARKGRAY);

        switch (current_screen) {
            case TITLE: 
            {
                DrawText("lonelyBox", 90, 200, 100, PINK);

                if (IsKeyPressed(KEY_RIGHT)){
                    current_screen = ONE;
                }
            }break;

            case ONE:
            {
                DrawText("one", 90, 200, 100, PINK);

                if (IsKeyPressed(KEY_RIGHT)){
                    current_screen = TWO;
                }
            }break;

            case TWO:
            {
                DrawText("two", 90, 200, 100, PINK);

                if (IsKeyPressed(KEY_RIGHT)){
                    current_screen = THREE;
                }
            }break;

            case THREE:
            {
                DrawText("three", 90, 200, 100, PINK);

                if (IsKeyPressed(KEY_RIGHT)){
                    current_screen = FOUR;
                }
            }break;

            case FOUR:
            {
                DrawText("four", 90, 200, 100, PINK);

                if (IsKeyPressed(KEY_RIGHT)){
                    current_screen = TITLE;
                }
            }break;
        }

        EndDrawing();
    }


    CloseWindow();
    return 0;
}
