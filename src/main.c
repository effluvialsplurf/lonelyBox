#include <raylib.h>
#include <math.h>
#include "common.h"
//#include "../assets/lonelyBoxColors.c"
//#include "./entitymanager.c"
//#include "./entityupdaters.c"

typedef enum Screen {TITLE, ONE, TWO, THREE, FOUR} Screen;
Screen current_screen = TITLE;

const float display_width = 1280;
const float display_height = 720;
const int fps = 60;

int main(void) {
    // initialize context
    InitWindow(display_width, display_height, "lonelyBox");
    // set the fps
    SetTargetFPS(fps);

    int player_id = create_entity();
    add_position_component(player_id, 0, 0);
    add_velocity_component(player_id, 1, 1);

    // game loop
    while (!WindowShouldClose()) {
        BeginDrawing();

        // clear background before drawing anything
        ClearBackground(DARKGRAY);
        
        // update game state every frame
        move_entities(GetFrameTime());

        // draw player entity
        draw_entities();

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

