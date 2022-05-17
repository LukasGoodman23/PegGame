#pragma once
#include <iostream>
#include <string>
#include "Peg_Board.h"
#include "Stack.h"

using namespace std;

class stack
{
public:
	move_struct *head= nullptr;

	void add_move(move_struct *new_move)
	{
		new_move->pointer= head;
		head= new_move;
	}

	void pop_move()
	{

		move_struct *temp_move= head;
		head= head->pointer;
		delete temp_move;
	}

	void print()
	{
		move_struct *temp_move= head;
		while (temp_move != nullptr)
		{
			cout << "(" << temp_move->from << ":" << temp_move->to << ")\n";
			temp_move= temp_move->pointer;
		}
		delete temp_move;
	}
};