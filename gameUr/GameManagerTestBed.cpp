#include "../gameUr/GameManager.h"
#include "../gameUr/Cell.h"
#include <assert.h>
#include <iostream>
using namespace std;

int main()
{
	GameManager* manager = new GameManager();
   ///We will need a section of code like this for each game mode.
   manager->SetGame(Chariot);
   Player * player1 = manager->GetPlayerOne();
   Player * player2 = manager->GetPlayerTwo();
   Coordinate * p1Coord = new Coordinate(0, 3);
   Coordinate * p2Coord = new Coordinate(2, 3);

   //Checks to make sure first coord is empty for player 1 and player 2.
   assert(!manager->ContainsPiece(p1Coord->GetRow(), p1Coord->GetCol()));
   assert(!manager->ContainsPiece(p2Coord->GetRow(), p2Coord->GetCol()));

   //Checks to make sure it does not move/place piece unless rolled.
   manager->SetTurnToP1();
   manager->MovePiece(-1, -1);
   assert(!manager->ContainsPiece(p1Coord->GetRow(), p1Coord->GetCol()));
   Coordinate * notRolledCheck = manager->MovePiece(p1Coord->GetRow(), p1Coord->GetCol());
   assert(notRolledCheck == NULL);
   
   //Check to make sure roll works.
   assert(!manager->GetHasRolled());
   manager->Roll();
   int rollVal = manager->GetRoll();
   if (rollVal == 0)
   {
      manager->SetTurnToP1();
      manager->SetRoll(1);
      rollVal = 1;
   }
   assert(manager->GetHasRolled() && rollVal >= 0 && rollVal <= 4);
   //Confirm it does not roll again until move is made. (Chance of false positive.)
   assert(manager->GetRoll() == rollVal);

   //Places a piece for player1 so that movement can be tested.
   manager->SetRoll(1);
   manager->MovePiece(-1, -1);
   assert(manager->ContainsPiece(p1Coord->GetRow(), p1Coord->GetCol()));

   //Places a piece for player2 so that movement can be tested.
   manager->SetRoll(1);
   manager->MovePiece(-1, -1);
   assert(manager->ContainsPiece(p2Coord->GetRow(), p2Coord->GetCol()));

   manager->SetRoll(2);
   //Confirm it is player 1's turn.
   assert(manager->IsPlayer1Turn());
   //Check moving after a roll for player 1.
   Coordinate * afterRollP1 = manager->MovePiece(p1Coord->GetRow(), p1Coord->GetCol());
   assert(!manager->ContainsPiece(p1Coord->GetRow(), p1Coord->GetCol()));
   assert(manager->ContainsPiece(afterRollP1->GetRow(), afterRollP1->GetCol()));
   //Makes sure the piece was removed.
   assert(!manager->ContainsPiece(p1Coord->GetRow(), p1Coord->GetCol()));
   //Confirm is no longer player 1's turn.
   assert(!manager->IsPlayer1Turn());

   //Check moving does not work unless rolled.
   assert(!manager->IsPlayer1Turn());
   //Makes sure the piece was not moved.
   assert(manager->ContainsPiece(p2Coord->GetRow(), p2Coord->GetCol()));
   assert(!manager->IsPlayer1Turn());

	delete player1, player2, manager, afterRollP1, p1Coord, p2Coord;
	return 0;
}