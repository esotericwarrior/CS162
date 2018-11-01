/*********************************************************************  
** Program name:  Langton's Ant
** Author:  Tristan Santiago
** Date:  January 20, 2018
** Description: This is the header file for the ant class. Here we
** initialize the class members.
*********************************************************************/
    #ifndef ANT_HPP
    #define ANT_HPP

    // Used for tracking direction in which ant is facing
    enum Direction { NORTH, EAST, SOUTH, WEST };

    class Ant
    {
    private:
        Direction dir;
        char color;
        int antRow, antCol, cRow, cCol;

    public:
        Ant();
        Ant(int r, int c);
        void setDirection(Direction d);
        Direction getDirection();
        void setColor(char c2);
        char getColor();
        void setAntRow(int ar);
        int getAntRow();
        void setAntCol(int ac);
        int getAntCol();
        void setCRow(int cr);
        int getCRow();
        void setCCol(int cc);
        int getCCol();
    };

    #endif