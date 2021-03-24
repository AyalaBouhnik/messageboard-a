#include "doctest.h"
#include <iostream>
#include <string>
#include "Board.hpp"
#include "Direction.hpp"
using ariel::Direction;
#include <stdexcept>
using namespace std;



TEST_CASE("negative numbers -> we suppose to get exeption."){

	ariel::Board board;
	board.post( 100, 200, Direction::Horizontal, "abcd");
	board.post(99, 202, Direction::Vertical, "xyz");

	board.show(); // shows the board in a reasonable way. For example:
		//    98:  _________
		//    99:  ____x____
		//    100: __abyd___
		//    101: ____z____
		//    102: _________


//FOR POST FUNCTION:
//row egative:
CHECK_THROWS(board.post(-3,2,Direction::Horizontal,"somthing"));
CHECK_THROWS(board.post(-1,5,Direction::Horizontal,"somthing"));
CHECK_THROWS(board.post(-80,5,Direction::Vertical,"somthing"));
CHECK_THROWS(board.post(-11,5,Direction::Vertical,"somthing"));

//col negative:
CHECK_THROWS(board.post(3,-2,Direction::Horizontal,"somthing"));
CHECK_THROWS(board.post(1,-5,Direction::Horizontal,"somthing"));
CHECK_THROWS(board.post(80,-55,Direction::Vertical,"somthing"));
CHECK_THROWS(board.post(1,-41,Direction::Vertical,"somthing"));

//both negative:
CHECK_THROWS(board.post(-23,-2,Direction::Horizontal,"somthing"));
CHECK_THROWS(board.post(-71,-5,Direction::Horizontal,"somthing"));
CHECK_THROWS(board.post(-80,-55,Direction::Vertical,"somthing"));
CHECK_THROWS(board.post(-1,-41,Direction::Vertical,"somthing"));

//FOR READ FUNCTION:
//row negative:
CHECK_THROWS(board.read(-3,2,Direction::Horizontal,5));
CHECK_THROWS(board.read(-1,5,Direction::Horizontal,5));
CHECK_THROWS(board.read(-80,5,Direction::Vertical,3));
CHECK_THROWS(board.read(-11,5,Direction::Vertical,78));

//col negative:
CHECK_THROWS(board.read(3,-2,Direction::Horizontal,71));
CHECK_THROWS(board.read(1,-5,Direction::Horizontal,1));
CHECK_THROWS(board.read(80,-55,Direction::Vertical,2));
CHECK_THROWS(board.read(1,-41,Direction::Vertical,8));

//both negative:
CHECK_THROWS(board.read(-23,-2,Direction::Horizontal,7));
CHECK_THROWS(board.read(-71,-5,Direction::Horizontal,8));
CHECK_THROWS(board.read(-80,-55,Direction::Vertical,4));
CHECK_THROWS(board.read(-1,-41,Direction::Vertical,5));

//The numbers of chars to read is negative:
CHECK_THROWS(board.read(-23,-2,Direction::Horizontal,-7));
CHECK_THROWS(board.read(-71,-5,Direction::Horizontal,-8));
CHECK_THROWS(board.read(-80,-55,Direction::Vertical,-4));
CHECK_THROWS(board.read(-1,-41,Direction::Vertical,-5));

}


TEST_CASE("legal valuse- Lest chaeck if we got the right output :)!!"){

	ariel::Board board;
	board.post(100, 200, Direction::Horizontal, "abcd");
	board.post(99, 202, Direction::Vertical, "xyz");

	board.show(); 
		//    98:  _________
		//    99:  ____x____
		//    100: __abyd___
		//    101: ____z____
		//    102: _________

CHECK(board.read(100,200,Direction::Horizontal,4) == "abyd");
CHECK(board.read(100,200,Direction::Horizontal,5) == "abyd_");
CHECK(board.read(100,200,Direction::Horizontal,3) == "aby");
CHECK(board.read(100,200,Direction::Horizontal,1) == "a");
CHECK(board.read(100,200,Direction::Horizontal,0) != "abyd_");
CHECK(board.read(100,200,Direction::Horizontal,4) != "abcd");
CHECK(board.read(99,201,Direction::Vertical,3) == "xyz");
CHECK(board.read(100,100,Direction::Vertical,1) != "a");

}
