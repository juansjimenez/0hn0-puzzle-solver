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
* Each assigned variable can have a blue or red color. 

</br> 

The considered restrictions were the following: 
* All cells must have a color assigned.
* All blue cells must be able to see a number of blue cells equal to their `grade`.

## Input

The input must be structured as follows:
* A line that describes the height and width `n` of the board.
* `n` lines that describe the initial state of each row of the board, where -1 indicates that a cell red and 0 indicates that a cell is empty. Any other positive value `β` represents a blue cell with `grade` `β`. 

</br>

The input for the example board shown in the pictures would be the following: </br>
<pre>
4 
0  0  1  0 
0  4  0  3 
2  0  2  0 </pre>

## Output

Represents the final state of the board (meeting all restrictions). A valid output for the previous example input would be: </br>
<pre>
-1  -1   1  -1 
-1   4   3   3 
-1   2  -1   1 
 4   4   2  -1  </pre>

## Execution

The execution depends on a binary called `0hn0` which needs to be compiled by running
```
make
```
The binary can be then executed by running
```
./0hn0 input ouput

```
* `input` corresponds to the `.txt` file which contains the previously mentioned input format.
* `output` corresponds to the `.txt` file in which the output will be printed.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
