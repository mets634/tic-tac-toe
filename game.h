#pragma once

#include <vector>
#include <string>

using namespace std;

const int NO_MOVE = -1;

enum piece {
	X=-1, O=1, NONE=0
};

string piece_string(int num);

class game {
public:
	// class ctor
	game();

	// game management functions
	void do_move(const int index);  // do a move

	vector<int> get_available_squares() const;  // get list of available places on board

	bool square_available(const int index) const;  // check if square is available

	piece winner() const;  // return the winner of the game

	bool tie() const { return turn == 9 && winner() == NONE; }

	piece get_turn() const { return turn % 2 == 0 ? O : X; }

	friend ostream& operator<<(ostream& output, const game& g) {
		for (int k = 0; k < 9; ++k) {
			if (k % 3 == 0) output << endl;

			output << piece_string(g.board[k]);
		}

		return output;
	}
	
private:
	piece board[9];  // game board
	int turn;  // turn counter, used to find out who's turn it is

	piece horizontal_winner() const;
	piece vertical_winner() const;
	piece diagonal_winner() const;
};