#include <iostream>
#include "human.h"
#include "AI.h"

using namespace std;


game playgame() {
	game g;

	int move = NO_MOVE;
	int turn = 0;

	player* p1 = new human(g, O);
	player* p2 = new AI(g, X);

	while (g.winner() == NONE && !g.tie()) {
		move = g.get_turn() == O ? p1->next(move) : p2->next(move);
		g.do_move(move);
	}

	delete p1;
	delete p2;

	return g;
}

int main() {
	while (true) {
		game g = playgame();

		cout << g << endl << "WINNER = " << piece_string(g.winner()) << endl;
	}
	cin.get();
	cin.get();


	return EXIT_SUCCESS;
}