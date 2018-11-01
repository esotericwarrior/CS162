/*********************************************************************  
** Program name:  Langton's Ant
** Author:  Tristan Santiago
** Date:  January 20, 2018
** Description: The members of the Ant class store critical information
** required during the simulation: the ant's current direction, it's
** current board position, and space coloring information.
*********************************************************************/
    #include "antConstruct.hpp"
    #include <iostream>
    using namespace std;

    Ant::Ant()
    {
    }
    
    // Default constructors
    Ant::Ant(int r, int c)
    {
        // Defaults ant to face North
        setDirection(NORTH);
        // Defaults board to white spaces
        setColor(' ');
        // Sets rows and columns below to whatever user inputs as ant/current starting location
        setAntRow(r);
        setAntCol(c);
        setCRow(r);
        setCCol(c);
    }
    
    // ENUM direction set here. This is updated as ant moves.
    void Ant::setDirection(Direction d)
    {
        dir = d;
    }
    
    // ENUM direction is stored here. This is where we check current direction
    Direction Ant::getDirection()
    {
        return dir;
    }
    
    // This is where board space color is set ('#' or ' '. Updated as ant moves.
    void Ant::setColor(char c2)
    {
        color = c2;
    }
    
    // This is where color is stored. This is where we check if board space
    // is white or black.
    char Ant::getColor()
    {
        return color;
    }
    
    // This is where ant's location is set. (Only for rows in array)
    void Ant::setAntRow(int ar)
    {
        antRow = ar;
    }
    
    // This is where ant's location is stored. (Only for rows in array)
    int Ant::getAntRow()
    {
        return antRow;
    }
    
    // This is where ant's location is set. (Only for columns in array)
    void Ant::setAntCol(int ac)
    {
        antCol = ac;
    }
    
    // This is where ant's location is stored. (Only for columns in array)
    int Ant::getAntCol()
    {
        return antCol;
    }
    
    // This is where user's current location is set. Updated after turning left or right. (rows only)
    void Ant::setCRow(int cr)
    {
        cRow = cr;
    }
    
    // This is where user's current location is stored. Checked before moving left or right,
    // and also when moving to other side of board. (rows only)
    int Ant::getCRow()
    {
        return cRow;
    }
    
    // This is where user's current location is set. Updated after turning left or right. (columns only)
    void Ant::setCCol(int cc)
    {
        cCol = cc;
    }

    // This is where user's current location is stored. Checked before moving left or right,
    // and also when moving to other side of board. (columns only)
    int Ant::getCCol()
    {
        return cCol;
    }