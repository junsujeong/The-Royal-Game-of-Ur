#include "../gameUr/AI.h"
#include <assert.h>

int main()
{
   Personality adam = ADAM;
   Board * b = new Board();

   ///Tests constructors
   AI * ai = new AI(adam, b);
   AI * ai2 = new AI(b);
   assert(ai != NULL);
   assert(ai2 != NULL);

   ///Checks AI methods method
   Coordinate * c = ai->GenerateMove(3);
   assert(c == NULL);
   Piece * p = new Piece();
   Path * path = new Path();
   path->AddStep(new Coordinate());
   path->AddStep(new Coordinate(1, 1));
   path->AddStep(new Coordinate(1, 1));
   path->AddStep(new Coordinate(1, 1));
   p->SetPath(path);
   ai->AddPiece(p);
   c = ai->GenerateMove(0);
   assert(c == NULL);
   c = ai->GenerateMove(1);
   assert(c != NULL);
   ai->ChangePersonality(DAN);
   assert(ai->GetPersonality() == DAN);
   ai->ChangePersonality(ADAM);
   assert(ai->GetPersonality() == ADAM);
   Piece * temp = ai->RequestPiece();
   assert(temp != NULL);
   ai->AddPiece(temp);
   b->Place(1, 1, ai->RequestPiece());
   c = ai->GenerateMove(1);
   assert(c == NULL);

   delete ai, ai2, p, path, b;
}