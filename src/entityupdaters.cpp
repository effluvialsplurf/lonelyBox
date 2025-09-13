#include "./common.h"
#include <raylib.h>

// functions to update all the entities active in the game
void move_entities(float delta_time) {
    // iterate through all the entities
    for (int i=0; i<next_entity_id; i++) {
        // check for active and has position and velocity
        if (active_entities[i] && (component_masks[i] 
            & (POSITION_COMPONENT_BIT | VELOCITY_COMPONENT_BIT)) == (POSITION_COMPONENT_BIT | VELOCITY_COMPONENT_BIT)) {
            // grab the component pointers
            PositionComponent *pos = &position_components[i];
            VelocityComponent *vel = &velocity_components[i];

            // update the position
            pos->x += vel->x * delta_time;
            pos->y += vel->y * delta_time;
        }
    }
}

void draw_entities() {
    // iterate through all the entities
    for (int i=0; i<next_entity_id; i++) {
        // check for active and has position component
        if (active_entities[i] && (component_masks[i] 
            & POSITION_COMPONENT_BIT) == POSITION_COMPONENT_BIT) {
            PositionComponent *pos = &position_components[i];
            DrawRectangleV({pos->x, pos->y}, {50, 50}, SKYBLUE);
        }
    }
}

