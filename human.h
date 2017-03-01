#pragma once
#include <iostream>
#include "player.h"

using namespace std;

class human : public player {
public:
	human(game g, piece p) : player(g, p) {}

	virtual int next(int move) {
		if (move != NO_MOVE)
			_g.do_move(move); // execute next move

		cout << _g << endl << endl;
		bool good = true;

		while (true) {
			cout << piece_string(_p) << " ENTER MOVE: ";
			cin >> move;
			try {
				_g.do_move(move);
				return move;
			}
			catch (...) {
				cout << "ILLEGAL MOVE\n";
			}
		} 
	}
};