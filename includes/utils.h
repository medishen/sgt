#ifndef UTILS_H
#define UTILS_H
// ANSI Color Codes
#define RESET        "\033[0m"
#define GREEN        "\033[32m"
#define LIGHT_GREEN  "\033[92m"
#define CYAN         "\033[36m"
#define LIGHT_CYAN   "\033[96m"
#define YELLOW       "\033[33m"
#define LIGHT_YELLOW "\033[93m"
#define RED          "\033[31m"
#define LIGHT_RED    "\033[91m"
#define BLUE         "\033[34m"
#define LIGHT_BLUE   "\033[94m"
#define PURPLE       "\033[35m"
#define LIGHT_PURPLE "\033[95m"
#define ORANGE       "\033[38;5;208m"
#define GREY         "\033[90m"
#define LIGHT_GREY   "\033[37m"
void animated_text(const char* text, const char* color);
void get_terminal_size(int *rows, int *cols);
void create_sgt_directory();
void game_over_screen();
#endif 
