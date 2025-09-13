#include <raylib.h>
#include "./common.h"
#include "entities.h"

int active_entities[MAX_ENTITIES];
PositionComponent position_components[MAX_ENTITIES];
VelocityComponent velocity_components[MAX_ENTITIES];
ComponentMask component_masks[MAX_ENTITIES];

// entity manager functions 
int next_entity_id = 0;

int create_entity(void) {
    // check if we are at our entity limit
    if (next_entity_id >= MAX_ENTITIES) {
        return -1;
    }

    // create the entity
    int entity_id = next_entity_id++;
    component_masks[entity_id] = 0;
    active_entities[entity_id] = 1;
    return entity_id;
}

void add_position_component(int entity_id, float x, float y) {
    if (entity_id >= 0 && entity_id < next_entity_id) {
        position_components[entity_id] = (PositionComponent){x, y};
        component_masks[entity_id] |= POSITION_COMPONENT_BIT;
    }
}

void add_velocity_component(int entity_id, float x, float y) {
    if (entity_id >= 0 && entity_id < next_entity_id) {
        velocity_components[entity_id] = (VelocityComponent){x, y};
        component_masks[entity_id] |= VELOCITY_COMPONENT_BIT;
    }
}
