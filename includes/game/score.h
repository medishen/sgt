#ifndef SCORE_H
#define SCORE_H
#include "game_config.h"
ScoreInfo read_scores_from_file();
void write_scores_to_file(int last_score, int highest_score);
void update_highest_score(int *highest_score, int last_score);
void view_scores();
#endif
