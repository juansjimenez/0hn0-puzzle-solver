#pragma once

struct cell;
typedef struct cell Cell;

struct cell 
{
    int grade;
    int seen_count;
};

Cell cell_init(int grade);