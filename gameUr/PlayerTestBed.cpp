#include <assert.h>
#include "../gameUr/Player.h"

int main()
{
	// Test constructors
	Player* p1 = new Player();
	assert(p1 != NULL);
	delete p1;
	p1 = new Player(1, 1);
	assert(p1 != NULL);
	delete p1;
   p1 = new Player(1);
   
   Player* p2 = new Player(2);
   PieceFactory * pf = new PieceFactory();

   //Tries to request piece when the container is empty.
   Piece * emptyTest = new Piece();
   emptyTest = pf->CreatePiece(Chariot, 1);
   assert(emptyTest != NULL);
   emptyTest = p1->RequestPiece();
   assert(emptyTest == NULL);

   //Setting the max player test.
   Piece* pce1 = pf->CreatePiece(Chariot, 1);
   Piece* pce2 = pf->CreatePiece(Chariot, 1);
   Piece* pce3 = pf->CreatePiece(Chariot, 1);
   //Also, testing add piece.
   p1->AddPiece(pce1);
   p1->AddPiece(pce2);
   p1->SetMax(2);
   p1->AddPiece(pce3);
   assert(p1->GetMaxPieces() == 2);
   Player * copy = new Player(*p1);
   assert(copy != NULL);
   delete copy;

   //Testing clear pieces.
   p1->ClearPieces();
   emptyTest = pf->CreatePiece(Chariot, 1);
   assert(emptyTest != NULL);
   emptyTest = p1->RequestPiece();
   assert(emptyTest == NULL);
   p1->ClearPieces();

   //Testing request piece with nonempty container.
   Piece * requestTest;
   Piece* pce4;
   Piece* pce5;
   pce4 = pf->CreatePiece(Chariot, 1);
   pce5 = pf->CreatePiece(Chariot, 1);
   p1->AddPiece(pce4);
   p1->AddPiece(pce5);
   //Stack, so order matters.
   requestTest = p1->RequestPiece();
   assert(pce5 == requestTest);
   requestTest = p1->RequestPiece();
   assert(pce4 == requestTest);

   //Setting score.
   p1->SetScore(3);
   assert(p1->GetScore() == 3);
   p1->SetScore(-2);
   assert(p1->GetScore() == -2);
   p1->IncreaseScore();
   assert(p1->GetScore() == -1);

   //Reset score test.
   p1->ResetScore();
   assert(p1->GetScore() == 0);

   delete pce1, pce2;
   //testing request piece with nonempty container for player 2.
   pce1 = pf->CreatePiece(Chariot, 2);
   pce2 = pf->CreatePiece(Chariot, 2);
   p1->SetMax(2);
   p1->AddPiece(pce1);
   p1->AddPiece(pce2);
   //Stack, so order matters.
   requestTest = p1->RequestPiece();
   assert(pce2 == requestTest);
   requestTest = p1->RequestPiece();
   assert(pce1 == requestTest);

   delete p1, p2, pce1, pce2, pce3, pce4, pce5, pf;
   return 0;
};

