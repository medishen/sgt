#include <stdio.h>
#include <stdlib.h>
#include "../../includes/game/game_config.h"
#include "../../includes/utils.h"
ScoreInfo read_scores_from_file() {
    const char *home_dir = getenv("HOME");
    if (home_dir == NULL) {
        fprintf(stderr, "Error: Unable to get the home directory.\n");
        exit(1);
    }
    char score_file_path[1024];
    snprintf(score_file_path, sizeof(score_file_path), "%s/%s/%s", home_dir, SGT_DIR_NAME, SCORE_FILE_NAME);

    FILE *file = fopen(score_file_path, "r");
    ScoreInfo scores = {0, 0};
    
     if (file != NULL) {
        if (fscanf(file, "Last score = %d\nHighest score = %d\n", 
                    &scores.last_score, &scores.highest_score) != 2) {
            fprintf(stderr, "Error: Failed to read the scores from the file.\n");
        }
        fclose(file);
    }
    
    return scores;
}
void write_scores_to_file(int last_score, int highest_score) {
    const char *home_dir = getenv("HOME");
    if (!home_dir) return;

    char score_file_path[1024];
    snprintf(score_file_path, sizeof(score_file_path), "%s/%s/%s", home_dir, SGT_DIR_NAME, SCORE_FILE_NAME);

    FILE *file = fopen(score_file_path, "w");
    if (file) {
        fprintf(file, "Last score = %d\n", last_score);
        fprintf(file, "Highest score = %d\n", highest_score);
        fclose(file);
    }
    printf("Saving scores to: %s\n", score_file_path);
}
void update_highest_score(int *highest_score, int last_score) {
    if (last_score > *highest_score) {
        *highest_score = last_score;
    }
}
void view_scores() {
    system("clear");
    ScoreInfo scores = read_scores_from_file();
    int last_score = scores.last_score;
    int highest_score = scores.highest_score;

    // Cool formatting and display
    printf("\n");
    animated_text("====================================\n", CYAN);
    animated_text("        🏆 SCOREBOARD 🏆\n", YELLOW);
    animated_text("====================================\n", CYAN);
    
    // Last score
    animated_text("Your Last Score: ", CYAN);
    printf("%d\n", last_score);

    // Highest score
    animated_text("Your Highest Score: ", GREEN);
    printf("%d\n", highest_score);

    // Beautiful ending message
    animated_text("\n====================================\n", CYAN);
    animated_text(" Keep going and beat your own record!\n", GREEN);
    animated_text("====================================\n\n", CYAN);
    printf("\n");
    animated_text("\033[1;33mPress any key to return to the main menu.\033[0m\n", YELLOW);
    getchar();
}