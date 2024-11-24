#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../includes/display.h"
#include "../includes/game/game_config.h"
#include "../includes/game/game.h"
#include "../includes/game/score.h"
#include "../includes/game/settings.h"
#include "../includes/game/customize_snake.h"
#include "../includes/utils.h"

/**
 * Function to handle the menu navigation and key press actions.
 * This will be separated from the main function.
 */
void handle_navigation(int *selected_index) {
    char key;
    while (1) {
        key = getchar();
        if (key == '\033') { 
            getchar();              
            switch (getchar()) {
                case 'A': 
                    *selected_index = (*selected_index - 1 + NUM_BLOCKS) % NUM_BLOCKS;
                    break;
                case 'B': 
                    *selected_index = (*selected_index + 1) % NUM_BLOCKS;
                    break;
            }
            display_menu(*selected_index);
        } else if (key == '\n') { 
            switch (*selected_index) {
                case START_GAME:
                    animated_text("Starting the game...", CYAN);
                    start_game();
                    break;
                case ABOUT:
                    display_about();
                    break;
                case HOW_TO_PLAY:
                    display_how_to_play();
                    break;
                case CUSTOMIZE_SNAKE:
                    customize_snake();
                    break;
                case SCORES:
                    view_scores();
                    break;
                case SETTINGS:
                    game_settings();
                    break;
                case EXIT_GAME:
                    animated_text("Exiting the game. Goodbye!\n",GREEN);
                    exit(0);
                    break;
            }
        }
    }
}