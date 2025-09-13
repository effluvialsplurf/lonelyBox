#include <raylib.h>
#include "common.h"
#include "entities.h"
#include "scenes.h"

const float display_width = 1280;
const float display_height = 800;
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

        UpdateDrawScene();

        // update game state every frame
        move_entities(GetFrameTime());

        // draw player entity
        draw_entities();

        EndDrawing();
    }


    CloseWindow();
    return 0;
}

