#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../../includes/game/game_config.h"
#include "../../includes/game/snake.h"
#include "../../includes/game/customize_snake.h"

void render_walls(Snake *snake,int terminal_rows, int terminal_cols,GameSettings *settings) {
    // Calculate the screen dimensions (adjusted for terminal size)
    int screen_height = (int)(terminal_rows * SCREEN_HEIGHT_RATIO);
    int screen_width = (int)(terminal_cols * SCREEN_WIDTH_RATIO);
    int start_row = (terminal_rows - screen_height) / 2;
    int start_col = (terminal_cols - screen_width) / 2;
     // Move cursor to the top-left without clearing the screen
    printf("\033[H");

    for (int i = 0; i < terminal_rows; i++) {
        for (int j = 0; j < terminal_cols; j++) {
            if (i >= start_row && i < start_row + screen_height && j >= start_col && j < start_col + screen_width) {
                if (i == start_row || j == start_col || 
                    i == start_row + screen_height - 1 || j == start_col + screen_width - 1) {
                    if ((i + j) % 2 == 0) {
                        printf("%s%s%s", WALL_COLOR_1, settings->wall_char, EMPTY_COLOR);  // Green Walls
                    } else {
                        printf("%s%s%s", WALL_COLOR_2, settings->wall_char, EMPTY_COLOR);  // Blue Walls
                    }
                } else {
                    int is_snake = 0;
                    // Check if the current position is part of the snake's body
                    for (int k = 0; k < snake->length; k++) {
                        if (snake->body[k * 2] == i && snake->body[k * 2 + 1] == j) {
                            if (k == 0) {
                                const char *head_color = choose_color(settings->head_color);
                                // Render snake head
                                printf("%s%s%s", head_color, settings->head_char, EMPTY_COLOR);  // Snake head
                            } else {
                                const char *body_color = choose_color(settings->body_color);
                                // Render snake body
                                printf("%s%s%s", body_color, settings->body_char, EMPTY_COLOR);  // Snake body
                            }
                            is_snake = 1;
                            break;
                        }
                    }

                    // Render background if not part of the snake
                    if (!is_snake) {
                        if ((i + j) % 2 == 0) {
                            printf("%s%c%s", BACKGROUND_COLOR, '.', EMPTY_COLOR);  // Soft dot background
                        } else {
                            printf("%s%c%s", BACKGROUND_COLOR, ' ', EMPTY_COLOR);  // Blank space for background
                        }
                    }
                }
            } else {
                // Render empty space outside the game screen bounds
                printf("%s%c%s", BACKGROUND_COLOR, ' ', EMPTY_COLOR);
            }
        }
    }
}