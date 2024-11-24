#ifndef GAME_CONFIG_H
#define GAME_CONFIG_H
// ===============================
// General Game Configurations
// ===============================
#define NUM_BLOCKS 7               // Total number of blocks (menu options)
#define MAX_LEVELS 10              // Maximum levels the player can reach
#define INITIAL_SPEED 100          // Initial game speed (in milliseconds)
#define MAX_SCORE 10000            // Maximum score achievable
#define GAME_SCREEN_HEIGHT 20      // Height of the game screen (in blocks)
#define INITIAL_SNAKE_LENGTH 3     // Initial length of the snake
#define SGT_DIR_NAME "sgt"
#define SCORE_FILE_NAME "score.txt"
#define CONFIG_FILE_PATH "game_config.txt"
#define SCREEN_HEIGHT_RATIO 0.9
#define SCREEN_WIDTH_RATIO  0.9
// ===============================
// Default Colors for Snake and Food
// ===============================
#define BACKGROUND_COLOR  "\x1b[48;5;16m" // Dark background
#define SNAKE_COLOR "\033[1;32m"    // Default snake color (Green)
#define FOOD_COLOR "\033[1;31m"     // Default food color (Red)
#define WALL_COLOR_1 "\x1b[38;5;45m"      // Neon Green Wall
#define WALL_COLOR_2 "\x1b[38;5;81m"      // Neon Blue Wall
#define EMPTY_COLOR  "\x1b[0m"    // Default empty space color (White)
#define BORDER_COLOR "\x1b[38;5;69m"       // Cool Cyan for border
#define DEFAULT_GAME_SPEED 100000  // 100ms (standard speed)

// ===============================
// Default Snake Appearance
// ===============================
#define MAX_SNAKE_LENGTH 50 
#define MAX_COLOR_LEN 50
#define MAX_CHAR_LEN 10
#define MAX_HEAD_COLOR_LEN 50
#define MAX_BODY_COLOR_LEN 50
#define MAX_COLOR_INPUT_LEN 50
// ===============================
// Game Controls (Keys)
// ===============================

#define UP_KEY 'w'                  // Move up key
#define DOWN_KEY 's'                // Move down key
#define LEFT_KEY 'a'                // Move left key
#define RIGHT_KEY 'd'               // Move right key
#define QUIT_KEY 'q'                // Quit the game key
#define PAUSE_KEY 'p'               // Pause the game key

// ===============================
// Menu Options (Game Modes)
// ===============================

#define START_GAME 0                // Start the game
#define HOW_TO_PLAY 1               // How to play section
#define ABOUT 2                      // About section
#define CUSTOMIZE_SNAKE 3           // Customize snake section
#define SCORES 4               // scores section
#define SETTINGS 5                  // Settings section
#define EXIT_GAME 6                 // Exit the game

// ===============================
// Game Difficulty Options
// ===============================

#define EASY 1                       // Easy difficulty
#define MEDIUM 2                     // Medium difficulty
#define HARD 3                       // Hard difficulty

// ===============================
// Default Game Settings (Initial Values)
// ===============================

#define DEFAULT_DIFFICULTY EASY      // Default difficulty is Easy
#define DEFAULT_SPEED 100           // Default game speed in milliseconds
#define DEFAULT_SNAKE_COLOR SNAKE_COLOR  // Default snake color (Green)
#define DEFAULT_FOOD_COLOR FOOD_COLOR    // Default food color (Red)

// ===============================
// Score and Level Configuration
// ===============================

#define LEVEL_UP_SCORE 1000         // Points needed to level up
#define SCORE_PER_FOOD 10           // Points earned per food eaten

// ===============================
// Game State Constants
// ===============================

#define GAME_RUNNING 1              // Game state: Running
#define GAME_OVER 0                 // Game state: Game Over
#define GAME_PAUSED -1              // Game state: Paused

// ===============================
// Snake Movement Constants
// ===============================

#define MOVE_UP 0                   // Direction: Up
#define MOVE_DOWN 1                 // Direction: Down
#define MOVE_LEFT 2                 // Direction: Left
#define MOVE_RIGHT 3                // Direction: Right

// ===============================
// Boundary Settings (Game Screen)
// ===============================

#define GAME_BORDER_WIDTH 2         // Game border width for the play area
#define GAME_BORDER_HEIGHT 2        // Game border height for the play area

// ===============================
// Snake Growth Configuration
// ===============================

#define SNAKE_GROWTH_RATE 1         // Number of blocks the snake grows per food

// ===============================
// Board Dimensions
// ===============================

#define BOARD_WIDTH 30              // Board width (in blocks)
#define BOARD_HEIGHT 20             // Board height (in blocks)

// ===============================
// Snake Struct Definition
// ===============================

typedef struct {
    int x;                           // Current x-coordinate of the snake head
    int y;                           // Current y-coordinate of the snake head
    int direction;                   // Current movement direction of the snake (UP, DOWN, LEFT, RIGHT)
    int length;                      // Length of the snake
    int *body;                       // Dynamic array for storing positions of the snake's body
    int food_x;                      // x-coordinate of the food
    int food_y;                      // y-coordinate of the food
} Snake;

// ===============================
// Score Info Struct Definition
// ===============================

typedef struct {
    int last_score;
    int highest_score;
} ScoreInfo;

// ===============================
// Game Settings Info Struct Definition
// ===============================

typedef struct {
    int game_speed;
    char head_color[MAX_COLOR_LEN];  // Snake head color
    char body_color[MAX_COLOR_LEN];  // Snake body color
    char head_char[MAX_CHAR_LEN];  // Snake head character
    char body_char[MAX_CHAR_LEN];  // Snake body character
    int max_length;
    char food_char[MAX_CHAR_LEN];  // Food character
    char wall_char[MAX_CHAR_LEN];  // Wall character
} GameSettings;

void load_game_settings(GameSettings *settings);
void save_game_settings(GameSettings *settings);

#endif
