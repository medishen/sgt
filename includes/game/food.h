#ifndef FOOD_H
#define FOOD_H
#include "game_config.h"
void generate_food(Snake *snake, int rows, int cols, int *food_x, int *food_y);
void render_food(int food_x, int food_y, const GameSettings *settings);
void clear_food(int food_x, int food_y);
#endif
