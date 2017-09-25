#include "../gameUr/Cell.h"
#include <assert.h>

int main()
{
   Cell * c = new Cell();
   Piece * p1 = new Piece();
   Piece * p2 = new Piece();
   Path * path = new Path();
   path->AddStep(new Coordinate(1, 1));
   p2->SetPlayer(2);
   p1->SetPlayer(1);
   p1->SetPlayer(1);
   p1->SetPlayer(2);
   p1->SetPath(path);
   p2->SetPath(path);
   

   //Testing the = operator overloading
   Cell * c2 = new Cell();
   c2->PlacePiece(p1);
   Cell * copy = new Cell(*c2);
   assert(copy->IsOccupied());
   copy = new Cell(*c);
   copy->SetTile(0);
   c->SetTile(0);
   assert(!copy->IsOccupied());

   //Testing get piece when cell is empty.
   assert(NULL == c->GetPiece());

   //Testing placing a piece.
   c->PlacePiece(p1);
   assert(c->IsOccupied());
   assert(c->GetPiece() == p1);

   //Testing placing a piece on a cell occupied.
   c->PlacePiece(p2);
   assert(c->GetPiece() == p2);

   //Testing the Tile
   c->SetTile(1);
   assert(c->GetRule() == 1);

   //Testing getting a piece from an occupied cell.
   p1 = NULL;
   p1 = c->GetPiece();
   assert(p2 == p1);

   //Test removing a piece.
   p1 = NULL;
   p1 = c->Remove();
   assert(!c->IsOccupied());
   assert(p1 == p2);

   
   

   delete c, p1, p2, copy;
   return 0;
}