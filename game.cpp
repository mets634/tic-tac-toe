#include "game.h"

using namespace std;


string piece_string(int num) {
	if (num == -1)
		return "X";
	if (num == 1)
		return "O";
	return "-";
}

game::game() {
	turn = 0;

	for (int k = 0; k < 9; ++k)
		board[k] = NONE;
}

vector<int> game::get_available_squares() const {
	vector<int> res;

	// find each square that
	// doesn't have NONE
	for (int k = 0; k < 9; ++k) 
			if (board[k] == NONE)
				res.push_back(k);

	return res;
}

bool game::square_available(const int index) const {
	if (index < 0 || index > 8)
		throw out_of_range("INDEX OUT OF RANGE - MUST BE IN [0, 9]");

	return board[index] == NONE;
}

void game::do_move(const int index) {
	if (!square_available(index))
		throw invalid_argument("SQUARE UNAVAILABLE");

	board[index] = (piece) (turn++ % 2 == 0 ? O : X);
}

piece game::winner() const {
	piece w = horizontal_winner();
	if (w != NONE)
		return w;

	w = vertical_winner();
	if (w != NONE)
		return w;

	w = diagonal_winner();
	if (w != NONE)
		return w;

	return NONE;
}

piece game::horizontal_winner() const {
	// check indexes 0, 1, 2
	if (board[0] == board[1] && board[0] == board[2] && board[0] != NONE)
		return board[0];

	// check indexes 3, 4, 5
	if (board[3] == board[4] && board[3] == board[5] && board[3] != NONE)
		return board[3];

	// check indexes 6, 7, 8
	if (board[6] == board[7] && board[6] == board[8] && board[6] != NONE)
		return board[6];

	return NONE;
}

piece game::vertical_winner() const {
	// check indexes 0, 3, 6
	if (board[0] == board[3] && board[0] == board[6] && board[0] != NONE)
		return board[0];

	// check indexes 1, 4, 7
	if (board[1] == board[4] && board[1] == board[7] && board[0] != NONE)
		return board[1];

	// check indexes 2, 5, 8
	if (board[2] == board[5] && board[2] == board[8] && board[2] != NONE)
		return board[2];

	return NONE;
}

piece game::diagonal_winner() const {
	// check indexes 0, 4, 8
	if (board[0] == board[4] && board[0] == board[8] && board[0] != NONE)
		return board[0];

	// check indexes 2, 4, 6
	if (board[2] == board[4] && board[2] == board[6] && board[2] != NONE)
		return board[2];

	return NONE;
}