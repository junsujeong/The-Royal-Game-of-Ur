#include "../gameUr/Board.h"
#include "../gameUr/PieceFactory.h"
#include <assert.h>

int main()
{
   Board * b = new Board();
   PieceFactory * pf = new PieceFactory();
   Piece * p1 = new Piece();
   p1->SetPlayer(1);
   Path * tempPath = new Path();
   tempPath->AddStep(new Coordinate());
   tempPath->AddStep(new Coordinate(1, 1));
   p1->SetPath(tempPath);
   Piece * p2 = new Piece();
   p2->SetPlayer(2);
   p2->SetPath(tempPath);

   ///Check getting a removed piece when none exist yet.
   assert(b->GetRemovedPiece() == NULL);

   ///Testing removing a finished piece.
   Path * finish = new Path();
   finish->AddStep(new Coordinate(1, 1));
   Coordinate * endCoord = new Coordinate();
   endCoord = finish->GetFinalPosition();
   Piece * p3 = new Piece();
   p3->SetPlayer(1);
   p3->SetPath(finish);
   b->Place(endCoord->GetRow(), endCoord->GetCol(), p3);
   bool test = b->Remove(endCoord->GetRow(), endCoord->GetCol());
   assert(test);

   ///Test moving an empty space
   Coordinate * empty = new Coordinate();
   empty = b->Move(1, 5, 1);
   assert(empty == NULL);


   for (int i = 0; i < 3; i++)
   {
      for (int j = 0; j < 8; j++)
      {
         ///Test that the constructor creates an empty board
         assert(b->IsOccupied(i, j) == 0);
         if (j < 4)
         {
            b->Place(i, j, p1);
            ///Test that pieces can correctly be placed
            assert(b->IsOccupied(i, j) == 1);
            ///Test that pieces are owned by a player
            assert(b->PieceIsOwnedByPlayer(i, j, true));
         }
         else
         {
            b->Place(i, j, p2);
            ///Test that pieces can correctly be placed
            assert(b->IsOccupied(i, j) == 1);
            ///Test that pieces are owned by a player
            assert(b->PieceIsOwnedByPlayer(i, j, false));
         }
         ///Test that the placed pieces can be removed
         assert(b->Remove(i, j));
         ///Test that they are actually removed
         assert(b->IsOccupied(i, j) == 0);
      }
   }
   ///Set up pieces with simple paths to test movement on the board
   Path * path = new Path();
   Coordinate * c1 = new Coordinate(2, 6);
   Coordinate * c2 = new Coordinate(1, 1);
   Coordinate * c3 = new Coordinate(1, 7);
   Coordinate * c4 = new Coordinate(0, 0);
   path->AddStep(c1);
   path->AddStep(c2);
   path->AddStep(c3);
   path->AddStep(c4);
   p1->SetPath(path);
   p2->SetPath(path);

   ///This looks complex, but it just tests each case you can have when you move a piece,
   ///such as taking an oponent piece, trying to take yours, etc
   delete b;
   b = new Board();
   b->Place(1, 1, p1);
   b->Place(1, 7, p2);
   assert(b->IsDotsUp(1, 1));
   assert(!b->Remove(2, 6));
   Coordinate * c = b->Move(1, 1, 0);
   assert(b->IsOccupied(2, 6));
   c = b->Move(1, 7, 0);
   assert(b->IsOccupied(2, 6));
   assert(b->PieceWasRemoved());
   assert(b->GetRemovedPiece() == p1);
   assert(!b->ValidTurn(2,false));
   assert(!b->ValidTurn(2,true));
   b->Place(1, 7, p2);
   assert(!b->ValidPieceToMove(2, 6, 2));
   assert(!b->ValidPieceToMove(2, 6, 1));
   
   b->FlipPiece(2, 6);
   assert(!b->ValidPieceToMove(2, 6, 10));
   assert(b->ValidPieceToMove(2, 6, 1));
   assert(!b->ValidPieceToMove(1, 7, 2));
   assert(b->ValidPieceToMove(1, 7, 1));
   b->Move(1, 7, 2);
   assert(b->IsOccupied(1, 7));
   b->FlipPiece(1, 7);
   b->Move(1, 7, 1);
   assert(!b->IsOccupied(0, 0));
   assert(!b->IsOccupied(1, 7));
   assert(b->IsPieceDone());
   b->ResetIsPieceDone();
   assert(!b->IsPieceDone());

   b->Place(2, 6, p1);
   assert(b->Remove(2, 6));

   b->ApplyRule(1, 1, 1);
   assert(1 == b->DetermineRule(1, 1));

   Board b2 = *b;

   delete c1, c2, c3, c4, p1, p2, path, b, p3;
   return 1;
}