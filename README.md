# 0hn0-puzzle-solver

## The Problem

The problem consists of finding a valid solution to the [0h n0 puzzle](https://0hn0.com/). An *n x n* board game with blue and red cells.

At the beginning of the game, some cells are already painted. Blue cells contain a number called `grade`. Each blue cell must be able to see a number of blue cells equal to their `grade`. A cell is visible by another cell if they are on the same row or column and there are no red cells between them. A blue cell can't see itself.

The puzzle's objective is to paint all empty cells with the correct color without violating any of the previously mentioned restrictions. All initially painted cells are fixed in place and can't change their color or `grade`.

<p align="center">
  <img width="80%" src=https://github.com/juansjimenez/0hn0-puzzle-solver/blob/main/img/0hn0_example.PNG>
</p> </br>

## Solution

The solution to this problem was implemented using *Backtracking*. The following considerations were taken for the variables and their domains: 
* The color of each cell of the board is a variable.
* Each assigned variable can have a blue or red color. </br> </br>
The restrictions considered were the following: 
* All cells must have a color assigned.
* All blue cells must be able to see a number of blue cells equal to their `grade`.

## Input

## Output

## Execution

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
