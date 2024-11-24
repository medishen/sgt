#include <stdlib.h>
#include "../includes/display.h"
#include "../includes/terminal_mode.h"
#include "../includes/utils.h"
#include "../includes/game/game_config.h"
#include "../includes/navigation.h"
/**
 * Entry point of the program.
 * Initializes the game, handles menu navigation, and executes actions based on user input.
 */
int main() {
    enable_raw_mode();
    atexit(disable_raw_mode);
    int selected_index = 0;  // Initial selected index for the menu
    display_menu(selected_index);
    // Handle menu navigation in a separate function
    handle_navigation(&selected_index);
    return 0;
}