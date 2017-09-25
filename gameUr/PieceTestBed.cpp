#include "../gameUr/Piece.h"
#include <assert.h>

int main()
{
   ///Tests flipping functionality
   Piece * p = new Piece();
   assert(!p->IsFaceDown()); 
   p->Flip();
   assert(p->IsFaceDown()); 

   ///Sets up a path to test piece with
   Path * path = new Path();
   Coordinate * c1 = new Coordinate(-1, -1);
   Coordinate * c2 = new Coordinate(1, 1);
   Coordinate * c3 = new Coordinate(7, 5);
   Coordinate * c4 = new Coordinate(0, 0);
   path->AddStep(c1);
   path->AddStep(c2);
   path->AddStep(c3);
   path->AddStep(c4);
   p->SetPath(path);

   ///Tests PeakPath function
   Coordinate * c = p->PeakPath(0);
   assert(c == NULL);
   c = p->PeakPath(4);
   assert(c == NULL);
   c = p->PeakPath(3);
   assert(c == c4);

   ///Tests Movement functionality
   c = p->MoveFront(0);
   assert(c == c1);
   c = p->MoveFront(4);
   assert(c == NULL);
   c = p->MoveFront(3);
   assert(c == c4);
   assert(p->Finished());
   c = p->MoveBack(2);
   assert(c == c2);
   c = p->MoveFront(1);
   assert(c == c3);
   c = p->MoveBack(3);
   assert(c == NULL);
   p->Restart();
   c = p->MoveFront(0);
   assert(c == c1);

   ///Tests player num getter and setter
   p->SetPlayer(0);
   assert(0 == p->GetPlayerNum());
   p->SetPlayer(50);
   assert(50 == p->GetPlayerNum());
   p->SetPlayer(-1);
   assert(-1 == p->GetPlayerNum());

   ///Test operator=
   Path * path2 = new Path();
   path2->AddStep(c1);
   path2->AddStep(c2);
   Piece * p1 = new Piece();
   Piece * p2 = new Piece();
   p1->SetPath(path2);
   p2 = p1;
   assert(p1 == p2);


   delete p, path, c1, c2, c3, c4, path2, p1, p2;
   return 1;
}