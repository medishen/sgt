#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include "../../includes/game/game_config.h"
#include "../../includes/game/walls.h"
#include "../../includes/utils.h"
#include "../../includes/game/snake.h"
#include "../../includes/game/food.h"
// Function to initialize the snake
Snake *init_snake(int terminal_rows, int terminal_cols) {
    Snake *snake = (Snake *)malloc(sizeof(Snake));
    if (!snake) {
        perror("Failed to allocate memory for snake");
        exit(1);
    }
    
    // Random position for the snake head, ensuring it's within bounds
    snake->x = rand() % (terminal_rows - INITIAL_SNAKE_LENGTH - 2) + 1;
    snake->y = rand() % (terminal_cols - 2) + 1; 
    snake->length = INITIAL_SNAKE_LENGTH;
    snake->direction = MOVE_RIGHT;

    // Allocate memory for the snake's body segments
    snake->body = (int*)malloc(sizeof(int) * 2 * snake->length);
    if (!snake->body) {
        perror("Failed to allocate memory for snake body");
        free(snake);
        exit(1);
    }
    for (int i = 0; i < snake->length; i++) {
        snake->body[i * 2] = snake->x - i;
        snake->body[i * 2 + 1] = snake->y;
    }
    return snake; 
}
void move_snake(Snake *snake, int food_x, int food_y) {
    static int last_direction = MOVE_RIGHT;
    if ((last_direction == MOVE_UP && snake->direction == MOVE_DOWN) ||
        (last_direction == MOVE_DOWN && snake->direction == MOVE_UP) ||
        (last_direction == MOVE_LEFT && snake->direction == MOVE_RIGHT) ||
        (last_direction == MOVE_RIGHT && snake->direction == MOVE_LEFT)) {
        snake->direction = last_direction;
    }
    last_direction = snake->direction;
    int new_x = snake->body[0];
    int new_y = snake->body[1];

    switch (snake->direction) {
        case MOVE_UP:
            new_x--;
            break;
        case MOVE_DOWN:
            new_x++;
            break;
        case MOVE_LEFT:
            new_y--;
            break;
        case MOVE_RIGHT:
            new_y++;
            break;
    }
     int proximity = 1;
    if (abs(new_x - food_x) <= proximity && abs(new_y - food_y) <= proximity) {
        // Snake eats the food
        snake->length++; // Increase snake length

        // Reallocate memory for new body segment
        int *new_body = realloc(snake->body, sizeof(int) * 2 * snake->length);
        if (!new_body) {
            perror("Failed to allocate memory for snake body");
            exit(1);
        }
        snake->body = new_body;

        // Shift body to make room for new head
        for (int i = snake->length - 1; i > 0; i--) {
            snake->body[i * 2] = snake->body[(i - 1) * 2];
            snake->body[i * 2 + 1] = snake->body[(i - 1) * 2 + 1];
        }

        // Place new head at food's location
        snake->body[0] = new_x;
        snake->body[1] = new_y;
    } else {
        // Snake hasn't eaten food, just move the body
        for (int i = snake->length - 1; i > 0; i--) {
            snake->body[i * 2] = snake->body[(i - 1) * 2];
            snake->body[i * 2 + 1] = snake->body[(i - 1) * 2 + 1];
        }

        // Update the head position without eating food
        snake->body[0] = new_x;
        snake->body[1] = new_y;
    }
}

int check_collision(Snake *snake, int rows, int cols) {
    if (snake->body[0] <= 0 || snake->body[0] >= rows - 1 ||
        snake->body[1] <= 0 || snake->body[1] >= cols - 1) {
        return 1; // Collision with wall
    }

    // Check collision with itself
    for (int i = 1; i < snake->length; i++) {
        if (snake->body[0] == snake->body[i * 2] && snake->body[1] == snake->body[i * 2 + 1]) {
            return 1; // Collision with self
        }
    }

    return 0; // No collision
}
void update_direction(Snake *snake, int new_direction) {
    if ((snake->direction == MOVE_UP && new_direction == MOVE_DOWN) ||
        (snake->direction == MOVE_DOWN && new_direction == MOVE_UP) ||
        (snake->direction == MOVE_LEFT && new_direction == MOVE_RIGHT) ||
        (snake->direction == MOVE_RIGHT && new_direction == MOVE_LEFT)) {
        return;
    }
    snake->direction = new_direction;
}