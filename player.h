#pragma once
#include "game.h"

class player {
public:
	player(game g, piece p) : _g(g), _p(p) {}

	// a function to determine the next move
	virtual int next(int move) = 0;

protected:
	game _g;  // the game being played
	piece _p;  // what piece is this player
};