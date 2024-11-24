#ifndef SNAKE_H
#define SNAKE_H
#include "game_config.h"
Snake *init_snake(int terminal_rows, int terminal_cols);
void move_snake(Snake *snake, int food_x, int food_y);
int check_collision(Snake *snake, int rows, int cols);
void update_direction(Snake *snake, int new_direction);
void game_over();
#endif
