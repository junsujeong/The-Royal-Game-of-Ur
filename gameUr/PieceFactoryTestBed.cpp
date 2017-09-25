#include "../gameUr/PieceFactory.h"
#include <assert.h>

int main()
{
   //PieceFactoryTestBed runs to test	
   PieceFactory* pc = new PieceFactory();
   Piece * p;
   Coordinate * c;

   //Create piece and move
   p = pc->CreatePiece(Chariot, 1);
   c = p->MoveFront(5);

   //Check the coordinates of the piece
   assert(c->GetRow() >= 0 && c->GetCol() >= 0);

   delete pc, p;
   return 1;
}