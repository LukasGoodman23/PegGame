#pragma once

using namespace std;

struct move_struct
{
	int from= 0;
	int jumped= 0;
	int to= 0;
	move_struct *pointer= nullptr;
};