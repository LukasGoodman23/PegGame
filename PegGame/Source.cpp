#include <iostream>
#include <vector>
#include <assert.h>
#include "Move_Struct.h"
#include "Peg_Board.h"
#include "Stack.h"

using namespace std;



int main()
{
	peg_board game_board;
	game_board.play_game();
	//game_board.print();
	//cout << game_board.score << "\n";
	game_board.print();
	game_board.game_stack.print();
}