
#include "Direction.hpp"

#include <string>
#include <map>
#include <unordered_map>

namespace ariel
{

  class Board
  {
  public:
    Board();
    ~Board() = default; //-destructor

//decleration for the 3 required functions:
    void post( int row, int column, Direction direction, const std::string &message);

    std::string read( int row,  int column, Direction direction,  int length);

    void show();

//The programung is runnig using unordered_map.
  private:
    std::unordered_map<unsigned int, std::unordered_map<unsigned int, char>> board_;

    // The board boundaries.
    unsigned int minrow_, maxrow_, mincol_, maxcol_;
  };

} // -closing namespace ariel