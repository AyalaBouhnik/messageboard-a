
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
        for (size_t i = 0; i < message.size(); ++i)
        {
            unsigned int curr_col = 0, curr_row = 0;
            switch (direction)
            {
            case Direction::Horizontal:
                curr_col = static_cast<unsigned int>(column) + i;
                curr_row = static_cast<unsigned int>(row);
                break;
            case Direction::Vertical:
                curr_col = static_cast<unsigned int>(column);
                curr_row = static_cast<unsigned int>(row) + i;
                break;
            }
            board_[curr_row][curr_col] = message[i];
            this->minrow_ = std::min<unsigned int>(this->minrow_, curr_row);
            this->maxrow_ = std::max<unsigned int>(this->maxrow_, curr_row);
            this->mincol_ = std::min<unsigned int>(this->mincol_, curr_col);
            this->maxcol_ = std::max<unsigned int>(this->maxcol_, curr_col);
        }
    }

    std::string Board::read(int row, int column, Direction direction, int length)
    {
        std::string out;
        for (size_t i = 0; i < length; ++i)
        {
            unsigned int curr_col = 0, curr_row = 0;
            switch (direction)
            {
            case Direction::Horizontal:
                curr_row = static_cast<unsigned int>(row);
                curr_col = static_cast<unsigned int>(column) + i;
                break;
            case Direction::Vertical:
                curr_row = static_cast<unsigned int>(row) + i;
                curr_col = static_cast<unsigned int>(column);
                break;
            }
            out.push_back(this->board_[curr_row][curr_col]);
        }
        return out;
    }

    void Board::show()
    {
        for (size_t row = this->minrow_ - 1; row <= this->maxrow_ + 1; ++row) {
            std::cout << row << ":\t";
            for (size_t col = this->mincol_ - 1; col <= this->maxcol_; ++col) {
                const auto message_it = this->board_[row].find(col);
                if (message_it != this->board_[row].end()) {
                    // Found a note at board[row, col].
                    std::cout << message_it->second;
                } else {
                    // Did not find a note at board[row, col].
                    std::cout <<'_';
                }
            }
            std::cout << std::endl;
        }
    }
} //-closing namespace ariel
