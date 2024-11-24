#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <sys/ioctl.h>
#include <sys/stat.h>
#include "utils.h"
#include <string.h>
#include "../includes/game/game_config.h"

void animated_text(const char* text, const char* color) {
    printf("%s", color);
    while (*text) {
        putchar(*text++);
        fflush(stdout);
        usleep(20000);
    }
    printf("%s", RESET);
}
void get_terminal_size(int *rows, int *cols) {
    struct winsize w;
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == -1) {
        perror("ioctl");
        exit(1);
    }
    *rows = w.ws_row;
    *cols = w.ws_col;
}
void create_sgt_directory() {
    const char *home_dir = getenv("HOME");
    if (home_dir == NULL) {
        fprintf(stderr, "Error: Unable to get the home directory.\n");
        exit(1);
    }
    char sgt_path[1024];
    snprintf(sgt_path, sizeof(sgt_path), "%s/%s", home_dir, SGT_DIR_NAME);
    struct stat st = {0};
    if (stat(sgt_path, &st) == -1) {
        if (mkdir(sgt_path, 0700) == -1) {
            perror("Error creating sgt directory");
            exit(1);
        }
    }
}