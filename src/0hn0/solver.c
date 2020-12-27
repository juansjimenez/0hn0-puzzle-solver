#include "cell.h"
#include "solver.h"


int solve0hn0(Cell** board, int board_dim, int row, int col, int pos_count)
{
    if (pos_count >= board_dim * board_dim)
    {
        return 1;
    }

    if (board[row][col].grade != -2)
    {
        pos_count += 1;
        row = pos_count / board_dim;
        col = pos_count % board_dim;
        return solve0hn0(board, board_dim, row, col, pos_count);
    }

    int color;
    for (int i = 0; i < 2; i++)
    {
        if (i == 0)
        {
            color = 0;
        } else
        {
            color = -1;
        }

        board[row][col].grade = color;

        if (is_valid(board, board_dim, row, col, pos_count, color))
        {
            int next_pos_count = pos_count + 1;
            int next_row = next_pos_count / board_dim;
            int next_col = next_pos_count % board_dim;

            if (solve0hn0(board, board_dim, next_row, next_col, next_pos_count))
            {
                return 1;
            }

            board[row][col].grade = -2;
        }

        board[row][col].grade = -2;
    }
    return 0;
}


int is_valid(Cell** board, int board_dim, int row, int col, int pos_count, char color)
{
    if (color == 0)
    {
        int temp_col_left = col - 1;
        while (temp_col_left >= 0 && board[row][temp_col_left].grade > -1)
        {
            if (board[row][temp_col_left].grade > 0)
            {
                if (!blue_valid(board, board_dim, row, temp_col_left))
                {
                    return 0;
                }
            }
            temp_col_left -= 1;
        }

        int temp_col_right = col + 1;
        while (temp_col_right < board_dim && board[row][temp_col_right].grade > -1)
        {
            if (board[row][temp_col_right].grade > 0)
            {
                if (!blue_valid(board, board_dim, row, temp_col_right))
                {
                    return 0;
                }
            }
            temp_col_right += 1;
        }

        int temp_row_up = row - 1;
        while (temp_row_up >= 0 && board[temp_row_up][col].grade > -1)
        {
            if (board[temp_row_up][col].grade > 0)
            {
                if (!blue_valid(board, board_dim, temp_row_up, col))
                {
                    return 0;
                }
            }
            temp_row_up -= 1;
        }
        
        int temp_row_down = row + 1;
        while (temp_row_down < board_dim && board[temp_row_down][col].grade > -1)
        {
            if (board[temp_row_down][col].grade > 0)
            {
                if (!blue_valid(board, board_dim, temp_row_down, col))
                {
                    return 0;
                }
            }
            temp_row_down += 1;
        }
        return 1;
    } else
    {
        int temp_col_left = col - 1;
        while (temp_col_left >= 0 && board[row][temp_col_left].grade != -1)
        {
            if (board[row][temp_col_left].grade > 0)
            {
                if (!red_valid(board, board_dim, row, temp_col_left))
                {
                    return 0;
                }
            }
            temp_col_left -= 1;
        }

        int temp_col_right = col + 1;
        while (temp_col_right < board_dim && board[row][temp_col_right].grade != -1)
        {
            if (board[row][temp_col_right].grade > 0)
            {
                if (!red_valid(board, board_dim, row, temp_col_right))
                {
                    return 0;
                }
            }
            temp_col_right += 1;
        }

        int temp_row_up = row - 1;
        while (temp_row_up >= 0 && board[temp_row_up][col].grade != -1)
        {
            if (board[temp_row_up][col].grade > 0)
            {
                if (!red_valid(board, board_dim, temp_row_up, col))
                {
                    return 0;
                }
            }
            temp_row_up -= 1;
        }
        
        int temp_row_down = row + 1;
        while (temp_row_down < board_dim && board[temp_row_down][col].grade != -1)
        {
            if (board[temp_row_down][col].grade > 0)
            {
                if (!red_valid(board, board_dim, temp_row_down, col))
                {
                    return 0;
                }
            }
            temp_row_down += 1;
        }
        return 1;    
    }
}

int blue_valid(Cell** board, int board_dim, int row, int col)
{
    int seen_count = 0;
    int max_seen = board[row][col].grade;

    int temp_col_left = col - 1;
    while (temp_col_left >= 0 && board[row][temp_col_left].grade > -1)
    {
        seen_count += 1;
        temp_col_left -= 1;

        if (seen_count > max_seen)
        {
            return 0;
        }
    }

    int temp_col_right = col + 1;
    while (temp_col_right < board_dim && board[row][temp_col_right].grade > -1)
    {
        seen_count += 1;
        temp_col_right += 1;

        if (seen_count > max_seen)
        {
            return 0;
        }
    }

    int temp_row_up = row - 1;
    while (temp_row_up >= 0 && board[temp_row_up][col].grade > -1)
    {
        seen_count += 1;
        temp_row_up -= 1;

        if (seen_count > max_seen)
        {
            return 0;
        }
    }

    int temp_row_down = row + 1;
    while (temp_row_down < board_dim && board[temp_row_down][col].grade > -1)
    {
        seen_count += 1;
        temp_row_down += 1;

        if (seen_count > max_seen)
        {
            return 0;
        }
    }

    return 1;
}

int red_valid(Cell** board, int board_dim, int row, int col)
{
    int max_to_see = 0;
    int needed_seen = board[row][col].grade;

    int temp_col_left = col - 1;
    while (temp_col_left >= 0 && board[row][temp_col_left].grade != -1)
    {
        max_to_see += 1;
        temp_col_left -= 1;

        if (max_to_see >= needed_seen)
        {
            return 1;
        }
    }

    int temp_col_right = col + 1;
    while (temp_col_right < board_dim && board[row][temp_col_right].grade != -1)
    {
        max_to_see += 1;
        temp_col_right += 1;

        if (max_to_see >= needed_seen)
        {
            return 1;
        }
    }

    int temp_row_up = row - 1;
    while (temp_row_up >= 0 && board[temp_row_up][col].grade != -1)
    {
        max_to_see += 1;
        temp_row_up -= 1;

        if (max_to_see >= needed_seen)
        {
            return 1;
        }
    }

    int temp_row_down = row + 1;
    while (temp_row_down < board_dim && board[temp_row_down][col].grade != -1)
    {
        max_to_see += 1;
        temp_row_down += 1;

        if (max_to_see >= needed_seen)
        {
            return 1;
        }
    }

    return 0;
}

int counter(Cell** board, int board_dim, int row, int col)
{   
    if (board[row][col].grade == -1)
    {
        return -1;
    }

    int seen_count = 0;

    int temp_col_left = col - 1;
    while (temp_col_left >= 0 && board[row][temp_col_left].grade != -1)
    {
        seen_count += 1;
        temp_col_left -= 1;
    }

    int temp_col_right = col + 1;
    while (temp_col_right < board_dim && board[row][temp_col_right].grade != -1)
    {
        seen_count += 1;
        temp_col_right += 1;
    }

    int temp_row_up = row - 1;
    while (temp_row_up >= 0 && board[temp_row_up][col].grade != -1)
    {
        seen_count += 1;
        temp_row_up -= 1;
    }

    int temp_row_down = row + 1;
    while (temp_row_down < board_dim && board[temp_row_down][col].grade != -1)
    {
        seen_count += 1;
        temp_row_down += 1;
    }

    if (seen_count == 0)
    {
        return -1;
    }

    return seen_count;
}