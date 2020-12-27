#pragma once
#include "cell.h"


int solve0hn0(Cell** board, int board_dim, int row, int col, int pos_count);
int is_valid(Cell** board, int board_dim, int row, int col, int pos_count, char color);
int blue_valid(Cell** board, int board_dim, int row, int col);
int red_valid(Cell** board, int board_dim, int row, int col);
int counter(Cell** board, int board_dim, int row, int col);