#pragma once
#include "player.h"


class AI : public player {
public:
	AI(game g, piece p) : player(g, p) {}

	virtual int next(int move) {
		if (move != NO_MOVE)
			_g.do_move(move);

		move = minimax(_g, _p, NO_MOVE).first;
		_g.do_move(move);  // update board
		return move;
	}

private:
	// construct sub - tree
	static pair<int, int> minimax(game g, piece p, int move) {
		if (move != NO_MOVE)
			g.do_move(move);  // update game

		// game over, nothing to do
		if (g.winner() != NONE || g.tie()) 
			return pair<int, int>(NO_MOVE, g.winner());

		vector<int> poss = g.get_available_squares();

		pair<int, int> res = minimax(g, (piece)(-p), poss[0]);  // get result of first move
		res.first = poss[0];  // substitute son's move with current move

		for (vector<int>::iterator it = ++poss.begin(); it != poss.end(); ++it) {
			if (res.second == p)  // best move possible, (alpha-beta pruning)
				return res;

			// try new son
			pair<int, int> temp = minimax(g, (piece)(-p), *it);
			temp.first = *it;  // substitue son's move for current move

			// got better move
			if (temp.second > res.second && p == O || temp.second < res.second && p == X)
				res = temp;
		}

		return res;
	}
};

