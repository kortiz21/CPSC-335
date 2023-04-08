// Kevin E Ortiz
// Algorithm 1: Soccer Opponent Avoidance - Exhaustive Search
// CPSC 335 Tuesday 7:00 PM to 9:45 PM
// Submitted: 4/21/23
#include <iostream>
#include <array>

using namespace std;

// main driver
int main()
{
    // declare variables
    // 2D array of 8 rows and 9 columns
    // start of the soccer game is at grid[0][0]
    // end of the soccer game is at grid[7][8]
    // player can only move right or down by 1 space
    // player cannot move to a space that has an X
    // player cannot move to a space that is out of bounds
    // player cannot move to a space that has already been visited
    // player must move to the end of the grid
    // their are 2 teams, Blue Team and Red Team
    // Blue Team is represented by the letter X
    // Red Team is represented by the letter .
    // moving down involves (row + 1, col)
    // moving right involves (row, col + 1)
    // keep a counter of number of paths that reach the end of the grid
    // once a path reaches the end of the grid, store the path
    
    array<array<char, 9>, 8> grid{{{'.', '.', '.', '.', '.', '.', 'X', '.', 'X'},
                                   {'X', '.', '.', '.', '.', '.', '.', '.', '.'},
                                   {'.', '.', '.', 'X', '.', '.', '.', 'X', '.'},
                                   {'.', '.', 'X', '.', '.', '.', '.', 'X', '.'},
                                   {'.', 'X', '.', '.', '.', '.', 'X', '.', '.'},
                                   {'.', '.', '.', '.', 'X', '.', '.', '.', '.'},
                                   {'.', '.', 'X', '.', '.', '.', '.', '.', 'X'},
                                   {'.', '.', '.', '.', '.', '.', '.', '.', '.'}}};
    return 0;
}