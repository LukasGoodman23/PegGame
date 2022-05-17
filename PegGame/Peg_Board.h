#pragma once
#include <iostream>
#include <string>
#include "Move_Struct.h"
#include "Stack.h"

using namespace std;

class peg_board
{
public:
	bool board[15]={ 0,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
	int score= 14;
	stack game_stack;
	int moves[36][3]={ {0,1,3},{0,2,5},{1,3,6},{1,4,8},{2,4,7},{2,5,9},{3,1,0},{3,4,5},{3,6,10},{3,7,12},{4,7,11},{4,8,13},{5,2,0},{5,4,3},{5,8,12},{5,9,14},{6,3,1},{6,7,8},{7,4,2},{7,8,9},{8,4,1},{8,7,6},{9,5,2},{9,8,7},{10,6,3},{10,11,12},{11,7,4},{11,12,13},{12,7,3},{12,8,5},{12,11,10},{12,13,14},{13,8,4},{13,12,11},{14,9,5},{14,13,12} };

	void document_move(move_struct *new_move)
	{
		game_stack.add_move(new_move);
	}

	void undo_move()
	{
		board[game_stack.head->from]= true;
		//cout << game_stack.head->from;
		board[game_stack.head->jumped]= true;
		//cout << game_stack.head->jumped;
		board[game_stack.head->to]= false;
		//cout << game_stack.head->to << "\n";
		game_stack.pop_move();
		score++;
	}

	void print()
	{
		cout << board[10] << "," << board[11] << "," << board[12] << "," << board[13] << "," << board[14] << "\n";
		cout << " " << board[6] << "," << board[7] << "," << board[8] << "," << board[9] << "\n";
		cout << "  " << board[3] << "," << board[4] << "," << board[5] << "\n";
		cout << "   " << board[1] << "," << board[2] << "\n";
		cout << "    " << board[0] << "\n";
	}

	bool valid_move(int move[4])
	{
		bool return_bool= false;
		if (board[move[0]] == true && board[move[1]] == true && board[move[2]] == false)
		{
			return_bool= true;
			board[move[0]]= false;
			board[move[1]]= false;
			board[move[2]]= true;
			move_struct *temp_move= new move_struct;
			temp_move->from= move[0];
			temp_move->jumped= move[1];
			temp_move->to= move[2];
			temp_move->pointer= nullptr;
			document_move(temp_move);
			score--;
		}
		return return_bool;
	}

	int play_check= 0;
	bool play_game()
	{
		
		for (int i = 0; i < 36; i++)
		{
			if (valid_move(moves[i]))
			{
				//print();
				play_game();
			}
		}
		if (score != 1)
		{
			//cout << "Undo \n";
			undo_move();
			//print();
		}
		
		return true;
	}
};