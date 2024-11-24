#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <sys/select.h>
#include "../../includes/game/score.h"
#include "../../includes/utils.h"
#include "../../includes/game/snake.h"
#include "../../includes/utils.h"
#include "../../includes/game/walls.h"
#include "../../includes/game/food.h"
void clear_screen() {
    printf("\033[H");
}
int score = 0;
void start_game() {
    printf("\n");
    create_sgt_directory();
    ScoreInfo scores = read_scores_from_file();
    int rows, cols;
    GameSettings settings;
    load_game_settings(&settings);
    get_terminal_size(&rows, &cols);
    Snake *snake = init_snake(rows, cols);
    int food_x, food_y;
    generate_food(snake, rows, cols, &food_x, &food_y);
    render_walls(snake, rows, cols,&settings);
    struct timeval timeout;
    int game_speed = settings.game_speed;
    timeout.tv_sec = 0;
    timeout.tv_usec = game_speed;  // 100ms delay (standard speed)
    char key;
    while (1) {
        clear_screen();
        fd_set readfds;
        FD_ZERO(&readfds);
        FD_SET(STDIN_FILENO, &readfds);
        int activity = select(STDIN_FILENO + 1, &readfds, NULL, NULL, &timeout);
        if (activity > 0) {
            key = getchar();

            if (key == '\033') {
                getchar();
                switch (getchar()) {
                    case 'A': // Up arrow
                        update_direction(snake, MOVE_UP);
                        break;
                    case 'B': // Down arrow
                        update_direction(snake, MOVE_DOWN);
                        break;
                    case 'C': // Right arrow
                        update_direction(snake, MOVE_RIGHT);
                        break;
                    case 'D': // Left arrow
                        update_direction(snake, MOVE_LEFT);
                        break;
                }
            }
        }
        move_snake(snake, food_x, food_y);
        if (check_collision(snake, rows, cols)) {
            game_over();
            snake = init_snake(rows, cols);
            render_walls(snake, rows, cols,&settings);
        }
        render_food(food_x, food_y,&settings);
        if (abs(snake->body[0] - food_x) <= 1 && abs(snake->body[1] - food_y) <= 1) {
                clear_food(food_x, food_y);
                generate_food(snake, rows, cols, &food_x, &food_y);
                score++;
        }
        render_walls(snake, rows, cols,&settings);
        usleep(game_speed);
    }
    free(snake->body);
    free(snake);
}
void game_over() {
    ScoreInfo scores = read_scores_from_file();  // Read current scores

    int last_score = scores.last_score;  // Previous game score
    int highest_score = scores.highest_score;

    // Display the scores
    printf("\n----- GAME OVER -----\n");
    printf("Your Current Score: %d\n", score);
    printf("Your Last Score: %d\n", last_score);
    printf("Your Highest Score: %d\n", highest_score);

    // Check if a new high score was achieved
    if (score > highest_score) {
        printf("\nCongratulations! You have set a new high score!\n");
        highest_score = score;  // Set the new high score
    }

    // Save the scores: Last score, Current score, Highest score
    write_scores_to_file(score, highest_score);
    const char *messages[] = {
        "You lost... What a surprise! Not like anyone expected you to win.",
        "Ha! You're weak. Do you even know what 'winning' means?",
        "That was pathetic. Even a snail would've outrun you. Try again?",
        "Burned to a crisp... Were you trying to set a record for failure?",
        "You're officially the worst player ever. Don't worry, you'll get it right... never.",
        "Oh, wow! You couldn't even get past the first level. Are you proud?",
        "Well, that was quick. Did you even try or just give up from the start?"
    };
    int random_index = rand() % (sizeof(messages) / sizeof(messages[0]));
    animated_text(messages[random_index], CYAN);
    // Give player option to try again or quit
    animated_text("\nPress 'r' to try again, if you're brave enough... or 'q' to quit and spare yourself further humiliation.\n", YELLOW);

    char choice;
    while (1) {
        choice = getchar();
        if (choice == 'r' || choice == 'R') {
            return;
        } else if (choice == 'q' || choice == 'Q') {
            printf("\033[2J\033[H");
            exit(0);
        }
    }
}
