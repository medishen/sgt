#ifndef CUSTOMIZE_SNAKE_H
#define CUSTOMIZE_SNAKE_H
#include "game_config.h"
void display_snake_customization_menu();
const char* choose_color(const char *color_name);
typedef struct {
    char *name;
    char *code;
} Color;
void clear_input_buffer();
#endif
