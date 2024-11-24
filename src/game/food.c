#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../includes/game/game_config.h"
void generate_food(Snake *snake, int rows, int cols, int *food_x, int *food_y) {
    int screen_height = (int)(rows * SCREEN_HEIGHT_RATIO);
    int screen_width = (int)(cols * SCREEN_WIDTH_RATIO);
    int start_row = (rows - screen_height) / 2;
    int start_col = (cols - screen_width) / 2;

    int occupied[rows][cols]; 
    memset(occupied, 0, sizeof(occupied));
    for (int i = 0; i < snake->length; i++) {
        int x = snake->body[i * 2];
        int y = snake->body[i * 2 + 1];
        if (x >= start_row && x < start_row + screen_height && y >= start_col && y < start_col + screen_width) {
            occupied[x][y] = 1;
        }
    }
    do {
        *food_x = rand() % (screen_height - 2) + start_row + 1;
        *food_y = rand() % (screen_width - 2) + start_col + 1;
    } while (occupied[*food_x][*food_y]);
}
void render_food(int food_x, int food_y, const GameSettings *settings) {
    const char* food_bg_color = "\033[43m";  // Yellow background
    const char* food_text_color = "\033[1;36m";  // Bright cyan text
    printf("\033[%d;%dH%s%s%c\033[0m", food_x, food_y, food_bg_color, food_text_color, settings->food_char[0]);
}
void clear_food(int food_x, int food_y) {
    printf("\033[%d;%dH  ", food_x, food_y); 
}
