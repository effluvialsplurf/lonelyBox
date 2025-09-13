#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

// max entities and entity global
#define MAX_ENTITIES 1000
extern int active_entities[MAX_ENTITIES];
extern int next_entity_id;

// bitmask to track the components associated with an entity
typedef unsigned int ComponentMask;

// components
typedef struct {
    float x;
    float y;
} PositionComponent;

typedef struct {
    float x;
    float y;
} VelocityComponent;

// component arrays
extern PositionComponent position_components[MAX_ENTITIES];
extern VelocityComponent velocity_components[MAX_ENTITIES];
extern ComponentMask component_masks[MAX_ENTITIES];

// assign a bit for each component type
#define POSITION_COMPONENT_BIT (1<<0)
#define VELOCITY_COMPONENT_BIT (1<<1)

// functions for entity management
int create_entity(void);
void add_position_component(int entity_id, float x, float y);
void add_velocity_component(int entity_id, float x, float y);

// functions for entity updating
void move_entities(float delta_time);
void draw_entities(void);

#endif
