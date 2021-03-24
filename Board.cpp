
#include "Board.hpp"
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include "Direction.hpp"

namespace ariel
{

    Board::Board(): minrow_(UINT32_MAX), maxrow_(0), mincol_(UINT32_MAX), maxcol_(0) {}

//The "&" denotes a reference instead of a pointer to an object.
    void Board::post(int row, int column, Direction direction, const std::string &message)
    {
        
    }

    std::string Board::read(int row, int column, Direction direction, int length)
    {
        return "t";
    }

    void Board::show()
    {
        
    }
} //-closing namespace ariel
