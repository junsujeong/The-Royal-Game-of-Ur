#include "../gameUr/MoveCommand.h"
#include <assert.h>
#include <iostream>

using namespace std;

int main()
{
	MoveCommand * mc = new MoveCommand();
	Board * b = new Board();
	Player * p1 = new Player(1);
	Player * p2 = new Player(2);
	GameType gt = GameType::Chariot;
	Piece * pc1;
	Piece * pc2;

	bool turn = true;
	PieceFactory * pf = new PieceFactory();
	Coordinate * p1Start = new Coordinate(0, 3);
	Coordinate * p2Start = new Coordinate(2, 3);
	Coordinate * cont = new Coordinate(-1, -1);
	pc1 = pf->CreatePiece(GameType::Chariot, 1);
	p1->AddPiece(pc1);

	pc2 = new Piece();
	pc2 = pf->CreatePiece(GameType::Chariot, 2);
	p2->AddPiece(pc2);

	p1->SetMax(1);
	p2->SetMax(1);
	State * st = new State(b, p1, p2, gt, turn);


	//Creating a piece and move for player1

	assert(!b->IsOccupied(0, 3));
	mc->execute(st, 1, cont);
	b = st->GetCurrBoard();
	assert(b->IsOccupied(0, 3));
	assert(!st->GetPlayer1Turn());


	assert(!b->IsOccupied(2, 3));
	mc = new MoveCommand();
	mc->execute(st, 1, cont);
	b = st->GetCurrBoard();
	assert(b->IsOccupied(2, 3));
	assert(st->GetPlayer1Turn());

	mc = new MoveCommand();
	mc->execute(st, 1, p1Start);
	b = st->GetCurrBoard();
	assert(b->IsOccupied(0, 2));

	return 0;
}