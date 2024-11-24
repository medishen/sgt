#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../includes/game/game_config.h"
void load_game_settings(GameSettings *settings) {
    const char *home_dir = getenv("HOME");
    if (home_dir == NULL) {
        fprintf(stderr, "Error: Unable to get the home directory.\n");
        exit(1);
    }
    
    char game_config_file_path[1024];
    snprintf(game_config_file_path, sizeof(game_config_file_path), "%s/%s/%s", home_dir, SGT_DIR_NAME, CONFIG_FILE_PATH);

    FILE *file = fopen(game_config_file_path, "r");
    if (file != NULL) {
        // Read the existing settings from the file
        fscanf(file, "Game Speed: %d\n", &settings->game_speed);
        fscanf(file, "Snake Head Color: %s\n", settings->head_color);
        fscanf(file, "Snake Body Color: %s\n", settings->body_color);
        fscanf(file, "Snake Head Character: %s\n", settings->head_char);
        fscanf(file, "Snake Body Character: %s\n", settings->body_char);
        fscanf(file, "Maximum Snake Length: %d\n", &settings->max_length);
        fscanf(file, "Food Character: %s\n", settings->food_char);
        fscanf(file, "Wall Character: %s\n", settings->wall_char);
        fclose(file);
    } else {
        // Set defaults if the file doesn't exist
        settings->game_speed = DEFAULT_GAME_SPEED;
        strcpy(settings->head_color, "cyan");
        strcpy(settings->body_color, "blue");
        strcpy(settings->head_char, "O");
        strcpy(settings->body_char, "*");
        settings->max_length = 50;
        strcpy(settings->food_char, "@");
        strcpy(settings->wall_char, "#");
    }
}

void save_game_settings(GameSettings *settings) {
    const char *home_dir = getenv("HOME");
    if (home_dir == NULL) {
        fprintf(stderr, "Error: Unable to get the home directory.\n");
        exit(1);
    }
    
    char game_config_file_path[1024];
    snprintf(game_config_file_path, sizeof(game_config_file_path), "%s/%s/%s", home_dir, SGT_DIR_NAME, CONFIG_FILE_PATH);

    FILE *file = fopen(game_config_file_path, "w");  // Use "w" to overwrite the file
    if (file != NULL) {
        // Save all settings to the file
        fprintf(file, "Game Speed: %d\n", settings->game_speed);
        fprintf(file, "Snake Head Color: %s\n", settings->head_color);
        fprintf(file, "Snake Body Color: %s\n", settings->body_color);
        fprintf(file, "Snake Head Character: %s\n", settings->head_char);
        fprintf(file, "Snake Body Character: %s\n", settings->body_char);
        fprintf(file, "Maximum Snake Length: %d\n", settings->max_length);
        fprintf(file, "Food Character: %s\n", settings->food_char);
        fprintf(file, "Wall Character: %s\n", settings->wall_char);
        fclose(file);
        printf("Customizations saved successfully!\n");
    } else {
        fprintf(stderr, "Error: Unable to open the configuration file for writing.\n");
        exit(1);
    }
}