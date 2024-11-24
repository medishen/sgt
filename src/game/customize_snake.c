#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../includes/game/game_config.h"
#include "../../includes/game/customize_snake.h"
#include "../../includes/game/snake.h"
#include "../../includes/utils.h"
void display_snake_customization_menu() {
    system("clear");
    printf("\033[1;32mCustomize Snake Settings\033[0m\n\n");
    printf("1. Customize Snake Head Color\n");
    printf("2. Customize Snake Body Color\n");
    printf("3. Set Snake Head Character\n");
    printf("4. Set Snake Body Character\n");
    printf("5. Set Maximum Snake Length\n");
    printf("6. Customize Food Character\n");
    printf("7. Customize Wall Character\n");
    printf("8. Save & Return to Main Menu\n");
    printf("9. Cancel Changes and Return to Main Menu\n");
    printf("\n");
}

Color colors[] = {
    {"green", GREEN},
    {"light_green", LIGHT_GREEN},
    {"cyan", CYAN},
    {"light_cyan", LIGHT_CYAN},
    {"yellow", YELLOW},
    {"light_yellow", LIGHT_YELLOW},
    {"red", RED},
    {"light_red", LIGHT_RED},
    {"blue", BLUE},
    {"light_blue", LIGHT_BLUE},
    {"purple", PURPLE},
    {"light_purple", LIGHT_PURPLE},
    {"orange", ORANGE},
    {"grey", GREY},
    {"light_grey", LIGHT_GREY},
    {NULL, NULL}
};
const char* choose_color(const char *color_name) {
    for (int i = 0; colors[i].name != NULL; i++) {
        if (strcmp(color_name, colors[i].name) == 0) {
            return colors[i].code;
        }
    }
    return RESET;
}
void customize_snake() {
    system("clear");
    char head_color[MAX_HEAD_COLOR_LEN], body_color[MAX_BODY_COLOR_LEN];
    char head_char[MAX_CHAR_LEN], body_char[MAX_CHAR_LEN];
    char food_char[MAX_CHAR_LEN], wall_char[MAX_CHAR_LEN];
    int max_length = MAX_SNAKE_LENGTH;
    GameSettings settings;

    load_game_settings(&settings);
    while (1) {
        display_snake_customization_menu(); // Show menu options
        
        char choice;
        printf("Enter your choice: ");
        choice = getchar(); // Read the user's choice
        
        // Process the user's choice
        switch (choice) {
            case '1': {
                // Change Snake Head Color
                printf("Enter the new Snake Head Color (e.g., green, cyan, red): ");
                scanf("%s", head_color);
                strcpy(settings.head_color, choose_color(head_color));
                break;
            }
            case '2': {
                // Change Snake Body Color
                printf("Enter the new Snake Body Color (e.g., blue, yellow, purple): ");
                scanf("%s", body_color);
                strcpy(settings.body_color, choose_color(body_color));
                break;
            }
            case '3': {
                // Change Snake Head Character
                printf("Enter the new Snake Head Character (e.g., O, @, X): ");
                scanf("%s", head_char);
                strcpy(settings.head_char, head_char);
                break;
            }
            case '4': {
                // Change Snake Body Character
                printf("Enter the new Snake Body Character (e.g., *, #, .): ");
                scanf("%s", body_char);
                strcpy(settings.body_char, body_char);
                break;
            }
            case '5': {
                // Set Maximum Snake Length
                printf("Enter the Maximum Snake Length (e.g., 50, 100): ");
                scanf("%d", &max_length);
                settings.max_length = max_length;
                break;
            }
            case '6': {
                // Change Food Character
                printf("Enter the new Food Character (e.g., @, $, %, +): ");
                scanf("%s", food_char);
                strcpy(settings.food_char, food_char);
                break;
            }
            case '7': {
                // Change Wall Character
                printf("Enter the new Wall Character (e.g., #, $, %): ");
                scanf("%s", wall_char);
                strcpy(settings.wall_char, wall_char);
                break;
            }
            case '8': {
                // Save changes and return to main menu
                printf("\nAre you sure you want to save the changes? (y/n): ");
                char confirm = getchar();
                if (confirm == 'y' || confirm == 'Y') {
                    save_game_settings(&settings); // Save the settings
                    printf("Settings have been saved successfully!\n");
                } else {
                    printf("Changes were not saved.\n");
                }
                return; // Exit the function and return to the main menu
            }
            case '9': {
                // Cancel changes and return to main menu
                printf("Changes have been discarded.\n");
                return; // Exit without saving changes
            }
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
}