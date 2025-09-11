#include <raylib.h>
#include "./common.h"

typedef struct CharacterBox {
    Vector2 position = {display_width / 2, display_height / 2};
    Vector2 size = {50, 50};
    Vector2 velocity = {0, 0};
    int health = 100;
} CharacterBox;

