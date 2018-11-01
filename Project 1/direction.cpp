/*********************************************************************
** Program name: Langton's Ant
** Author: Tristan Santiago
** Date: January 20, 2018
** Description: direction.cpp is responsible for the majority of the 
** simulation. The direction function tracks the ant's location, which
** direction it's currently facing, and which direction it's going next.
** Works closely with the Ant class.
*********************************************************************/
#include <iostream>
#include "direction.hpp"
#include "antConstruct.cpp"

int directionFunction(int numRows, int numCols, int steps, int row, int col)
    {
        Ant antGame(row, col); //create an Ant object

        // Dynamically allocates the gameboard
        char **board = new char*[numRows];
        {
            for (int i = 0; i < numRows; i++)
            {
                board[i] = new char[numCols];
            }
        }
        // Initializes the board to blank spaces
        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j < numCols; j++)
            {
                board[i][j] = ' ';
            }
        }
        // Creates the ant symbol on board at starting location.
        board[row][col] = '*';

        // Prints out board to screen
        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j < numCols; j++)
            {
                cout << board[i][j];
            }
            cout << endl;
        }

        // Loops for the duration of the number of steps that was inputted by user
        for (int i = steps; i > 0; i--)
        {
// ** if statement - if current color = white then change direction, row and col changes to #, row or col gets incremented, row and col now changes to '*' ** //
            // If space's color is currentyl 'white,'
            if (antGame.getColor() == ' ')
            {   
                // ...then update color to 'black'
                board[antGame.getAntRow()][antGame.getAntCol()] = '#';
                // If the ant is facing North,
                if(antGame.getDirection() == NORTH)
                {   
                    // Set direction to East, since ant is to turn right on white spaces.
                    antGame.setDirection(EAST);
                    col = antGame.getCCol();
                    // Increase column by 1 since now facing east and moving 'right', row not changed since staying in same row
                    col = col + 1;
                    // Edge Logic. If either column is greater than user inputted column (or default of 10), restart col at 0 (opposite side of board)
                    if (col >= numCols)
                        col = 0;
                    // Update class with this information
                    antGame.setCCol(col);
                    // Restart the initial logic of whether or not the space you landed on is white or black
                    if (board[antGame.getCRow()][antGame.getCCol()] == ' ')
                    {
                        antGame.setColor(' ');
                    }
                    else
                    {
                        antGame.setColor('#');
                    }
                    // Output current ant's position with asterisk
                    board[antGame.getCRow()][antGame.getCCol()] = '*';
                }
                // Check if direction is facing East, and follow similar logic as above.
                else if(antGame.getDirection() == EAST)
                {
                    antGame.setDirection(SOUTH);
                    row = antGame.getCRow();
                    // Since moving to face south, and space is assumed to be white, turn right, increasing the row by one.
                    row = row + 1;
                    // Same logic to appear on other side of board if past the board game size
                    if (row >= numRows)
                        row = 0;
                    antGame.setCRow(row);
                    if (board[antGame.getCRow()][antGame.getCCol()] == ' ')
                    {
                        antGame.setColor(' ');
                    }
                    else
                    {
                        antGame.setColor('#');
                    }
                    board[antGame.getCRow()][antGame.getCCol()] = '*';
                }
                // Check if ant is facing South
                else if(antGame.getDirection() == SOUTH)
                {
                    antGame.setDirection(WEST);
                    col = antGame.getCCol();
                    // To turn right on white, subtract from columns
                    col = col - 1;
                    if (col < 0)
                        col = numCols - 1;
                    antGame.setCCol(col);
                    if (board[antGame.getCRow()][antGame.getCCol()] == ' ')
                    {
                        antGame.setColor(' ');
                    }
                    else
                    {
                        antGame.setColor('#');
                    }
                    board[antGame.getCRow()][antGame.getCCol()] = '*';
                }
                // Check if facing west
                else if(antGame.getDirection() == WEST)
                {
                    antGame.setDirection(NORTH);
                    row = antGame.getCRow();
                    // To turn white on right, subtract from rows.
                    row = row - 1;
                    if (row < 0)
                        row = numRows - 1;
                    antGame.setCRow(row);
                    if (board[antGame.getCRow()][antGame.getCCol()] == ' ')
                    {
                        antGame.setColor(' ');
                    }
                    else
                    {
                        antGame.setColor('#');
                    }
                    board[row][col] = '*';
                }
            }
            // This is the invert of white spaces, so black spaces. Ants are to turn left on black spaces.
            else if(antGame.getColor() == '#')
            {
                board[row][col] = ' ';
                // Check if ant is facing north
                if(antGame.getDirection() == NORTH)
                {
                    antGame.setDirection(WEST);
                    col = antGame.getCCol();
                    // Ant is to turn left on blacks, so subtract 1 from columns, update direction to facing West
                    col = col - 1;
                    if (col < 0)
                        col = numCols - 1;
                    antGame.setCCol(col);
                    if (board[antGame.getCRow()][antGame.getCCol()] == ' ')
                    {
                        antGame.setColor(' ');
                    }
                    else
                    {
                        antGame.setColor('#');
                    }
                    board[antGame.getCRow()][antGame.getCCol()] = '*';
                }
                // Check if ant is facing East
                else if(antGame.getDirection() == EAST)
                {
                    antGame.setDirection(NORTH);
                    row = antGame.getCRow();
                    // Left on blacks, so subtract one from rows, to face north
                    row = row - 1;
                    if (row < 0)
                        row = numRows - 1;
                    antGame.setCRow(row);
                    if (board[antGame.getCRow()][antGame.getCCol()] == ' ')
                    {
                        antGame.setColor(' ');
                    }
                    else
                    {
                        antGame.setColor('#');
                    }
                    board[row][col] = '*';
                }
                // Check if ant is facing South
                else if(antGame.getDirection() == SOUTH)
                {
                    antGame.setDirection(EAST);
                    col = antGame.getCCol();
                    // Left on blacks, so add 1 to columns, update to East
                    col = col + 1;
                    if (col >= numCols)
                        col = 0;
                    antGame.setCCol(col);
                    if (board[antGame.getCRow()][antGame.getCCol()] == ' ')
                    {
                        antGame.setColor(' ');
                    }
                    else
                    {
                        antGame.setColor('#');
                    }
                    board[antGame.getCRow()][antGame.getCCol()] = '*';
                }
                // Check if ant is facing West
                else if(antGame.getDirection() == WEST)
                {
                    antGame.setDirection(SOUTH);
                    row = antGame.getCRow();
                    // Left on blacks, add 1 to rows, update direction to South
                    row = row + 1;
                    if (row >= numRows)
                        row = 0;
                    antGame.setCRow(row);
                    if (board[antGame.getCRow()][antGame.getCCol()] == ' ')
                    {
                        antGame.setColor(' ');
                    }
                    else
                    {
                        antGame.setColor('#');
                    }
                    board[antGame.getCRow()][antGame.getCCol()] = '*';
                }
            }

            // Printing out current board to screen
            cout << "--------------------------------\n";
            for (int i=0; i<numRows; i++)
            {
                for (int j=0; j<numCols; j++)
                {
                    cout << board[i][j];
                }
                cout << endl;
            }
            cout << "--------------------------------\n";
            // Updates where ant is
            antGame.setAntRow(row);
            antGame.setAntCol(col);
        }
                // Free dynamically allocated board space
        for (int i=0; i<numRows; i++)
            delete [] board[i];
        delete [] board;
        
        
    }

