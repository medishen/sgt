#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../includes/game/game_config.h"
#include "../../includes/utils.h"
void display_menu(int selected_index) {
    system("clear");
    // Open the ASCII art script and read the output
    FILE *fp = popen("bash ./script/ascii_code.sh", "r");
    if (fp == NULL) {
        perror("Failed to run script");
        exit(1);
    }
    char title[1024];
    size_t len = fread(title, 1, sizeof(title) - 1, fp);
    title[len] = '\0'; 
    fclose(fp);

    printf("\n\033[1;36m%s\033[0m\n", title);

    printf("  \033[1;33mUse \033[1;32mArrow Keys\033[0m \033[1;33mto Navigate.\033[0m\n");
    printf("  \033[1;33mPress \033[1;32mEnter\033[0m \033[1;33mto Select.\033[0m\n\n");

    const char *menu_options[] = {
        "Start Game",
        "How To Play",
        "About",
        "Customize Snake",
        "View Scores",
        "Game Settings",
        "Exit"
    };
    // Print the menu options with highlighted selected item
    for (int i = 0; i < NUM_BLOCKS; i++) {
        if (i == selected_index) {
            printf("  \033[1;37m> \033[1;32m%s\033[0m\n", menu_options[i]);
        } else {
            printf("    \033[1;36m%s\033[0m\n", menu_options[i]);
        }
    }

    // Print separator lines and menu title
    printf("\n\033[1;35m---------------------------------------------\033[0m\n");
    printf("         \033[1;34mSnake Game Menu\033[0m\n");
    printf("\033[1;35m---------------------------------------------\033[0m\n");
}

void display_how_to_play() {
    system("clear");

    // Animated Title: How to Play Snake Game
    animated_text("\033[1;32mHow To Play Snake Game\033[0m\n\n", BLUE);
    
    // Game Rules and Controls Explanation with Animated Text
    animated_text("\033[1;36m1. Use the Arrow keys\033[0m to move the snake around the screen.\n", CYAN);
    animated_text("\033[1;36m   - Up arrow\033[0m moves the snake up.\n", CYAN);
    animated_text("\033[1;36m   - Down arrow\033[0m moves the snake down.\n", CYAN);
    animated_text("\033[1;36m   - Left arrow\033[0m moves the snake left.\n", CYAN);
    animated_text("\033[1;36m   - Right arrow\033[0m moves the snake right.\n", CYAN);
    printf("\n");

    animated_text("\033[1;36m2. Eat food (represented as a special character like '*' or another symbol)\033[0m to grow your snake.\n", CYAN);
    animated_text("   The more food you eat, the longer your snake becomes, and the higher your score will be.\n", CYAN);
    printf("\n");

    animated_text("\033[1;36m3. Avoid running into the walls or your own body\033[0m. If the snake collides with either, the game ends.\n", CYAN);
    animated_text("   Be careful not to get trapped by your own body as the snake grows longer!\n", CYAN);
    printf("\n");

    animated_text("\033[1;36m4. Press 'Q' or 'Esc' to quit the game\033[0m during gameplay.\n", CYAN);
    animated_text("   This will allow you to exit the game and return to the main menu.\n", CYAN);
    printf("\n");

    animated_text("\033[1;36m5. Starting from Level 1, the game becomes progressively more challenging\033[0m.\n", CYAN);
    animated_text("   As you advance, the snake moves faster, and the difficulty of the levels increases.\n", CYAN);
    printf("\n");

    animated_text("\033[1;36m6. Points and Level System\033[0m: Each food you eat gives you points. As you score more points, your level increases.\n", CYAN);
    animated_text("   Your speed will also increase with each new level to make the game more challenging.\n", CYAN);
    printf("\n");

    // Inform the user about the snake's speed increase with difficulty
    animated_text("\033[1;36m7. The game becomes harder as you level up\033[0m. The speed of the snake increases, and more obstacles may appear.\n", CYAN);
    printf("\n");

    // Display the objective of the game
    animated_text("\033[1;33mYour objective is to eat as much food as possible without dying!\033[0m\n", YELLOW);
    animated_text("   Try to get the highest score possible before running into walls or yourself.\n", YELLOW);
    printf("\n");

    // Closing message
    animated_text("\033[1;33mPress any key to return to the main menu.\033[0m\n", YELLOW);
    getchar();  // Wait for user to press a key before returning to the main menu
}

void display_about() {
    system("clear");
    // Display Title with animation
    animated_text("\033[1;32mAbout Snake Game\033[0m\n\n", GREEN);

    // Game Description with animated text for each part
    animated_text("\033[1;36mThis game was developed as part of a terminal-based programming challenge.\033[0m\n", CYAN);
    printf("\n");
    animated_text("\033[1;36mThe objective of the game is to control a snake that grows longer with each\n\033[0m", CYAN);
    animated_text("\033[1;36mfood item it eats. The game progressively increases in difficulty as you\n\033[0m", CYAN);
    animated_text("\033[1;36madvance through the levels. The challenge was to implement dynamic gameplay,\n\033[0m", CYAN);
    animated_text("\033[1;36mhigh scores, and an interactive menu system.\033[0m\n", CYAN);
    
    // Provide project details
    printf("\n\033[1;33mProject Details:\033[0m\n");
    animated_text("  \033[1;34mRepository:\033[0m https://github.com/medishen/sgt\n", LIGHT_BLUE);
    animated_text("  \033[1;34mEmail:\033[0m bitsgeni@gmail.com\n", LIGHT_BLUE);
    animated_text("  \033[1;34mProject Name:\033[0m sgt\n", LIGHT_BLUE);
    animated_text("  \033[1;34mDocker Image:\033[0m bitsgenix/sgt\n", LIGHT_BLUE);

    // Closing message
    printf("\n");
    animated_text("\033[1;33mPress any key to return to the main menu.\033[0m\n", YELLOW);
    getchar();
}
