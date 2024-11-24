#include <stdio.h>
#include <stdlib.h>
#include "../../includes/utils.h"
#include "../../includes/game/game_config.h"
/**
 * Function to adjust game settings (placeholders for now).
 */
void game_settings() {
    GameSettings settings;
    load_game_settings(&settings);

    char choice;
    int new_speed;

    while (1) {
        system("clear");

       
        printf("\033[1;32mGame Settings\033[0m\n\n");
        printf("1. Adjust Game Speed (Current: %d microseconds)\n", settings.game_speed);
        printf("2. Return to Main Menu\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("\nEnter new game speed (in microseconds, e.g., 50000 for faster): ");
                if (scanf("%d", &new_speed) == 1) {
                    if (new_speed > 0) {
                        settings.game_speed = new_speed;
                        save_game_settings(&settings);
                        printf("\nGame speed updated to %d microseconds.\n", settings.game_speed);
                    } else {
                        printf("\nInvalid speed value! Please enter a positive integer.\n");
                    }
                } else {
                    printf("\nInvalid input! Please enter a valid integer.\n");
                }
                break;
            case '2':
                return;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
        printf("\nPress Enter to continue...");
        break;
    }
    getchar();
}