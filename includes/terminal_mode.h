#ifndef TERMINAL_MODE_H
#define TERMINAL_MODE_H

/**
 * Enables raw terminal mode for real-time input handling.
 */
void enable_raw_mode();

/**
 * Restores the terminal to its original settings.
 */
void disable_raw_mode();

#endif // TERMINAL_MODE_H
