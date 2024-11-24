#include <termios.h>
#include <unistd.h>
#include "../../includes/terminal_mode.h"
/**
 * In terminal-based applications, especially games or real-time interactive programs, we need more control over user input. 
 * The functions `enable_raw_mode()` and `disable_raw_mode()` are used to modify the terminal's behavior so that input can be read immediately, without waiting for the user to press Enter or deal with input buffering. 
 */
static struct termios original_terminal_settings;

/**
 * This function prepares the terminal to handle real-time input more efficiently by enabling "raw mode". In raw mode, input from the user is processed immediately without any buffering or special handling (like waiting for the Enter key).
 */
void enable_raw_mode() {
    struct termios raw;

    tcgetattr(STDIN_FILENO, &original_terminal_settings); 
    raw = original_terminal_settings;

    raw.c_lflag &= ~(ICANON | ECHO); // Disable canonical mode and echoing
    tcsetattr(STDIN_FILENO, TCSANOW, &raw); // Apply raw mode settings
}

/**
 * This function restores the terminal to its original settings after raw mode has been enabled. It’s important to restore the terminal to its default behavior when the program finishes, to ensure that the terminal works normally again.
 */
void disable_raw_mode() {
    tcsetattr(STDIN_FILENO, TCSANOW, &original_terminal_settings);
}
