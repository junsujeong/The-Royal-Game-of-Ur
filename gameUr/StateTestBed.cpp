#include "../gameUr/State.h"
#include <assert.h>

int main()
{
   Board * b = new Board();
   Player * p1 = new Player();
   Player * p2 = new Player();
   AI * ai = new AI();
   GameType gt = Chariot;
   Personality p = ADAM;
   bool turn = true;

   //Checks to make sure all of the values are not NULL and 
   //are returned properly for singleplayer
   State * sts = new State(b, p1, ai, gt, p, turn);
   assert(sts->GetCurrBoard() == b);
   assert(sts->GetPlayer(true) == p1);
   assert(sts->GetAI() == ai);
   assert(sts->GetGameType() == Chariot);
   assert(sts->GetAIPersonality() == ADAM);
   assert(sts->GetPlayer1Turn() == true);
   assert(sts->GetGameMode() == true);

   //Checks to make sure all of the values are not NULL and 
   //are returned properly for multiplayer
   State * stm = new State(b, p1, p2, gt, true);
   assert(stm->GetCurrBoard() == b);
   assert(stm->GetPlayer(true) == p1);
   assert(stm->GetPlayer(false) == p2);
   assert(stm->GetGameType() == Chariot);
   assert(stm->GetAIPersonality() == ADAM);
   assert(stm->GetPlayer1Turn() == true);
   assert(stm->GetGameMode() == false);

   State * copy = new State(*stm);
   assert(copy->GetAI() == stm->GetAI());

   State st = *stm;

   delete b, p1, p2, ai, gt, p, sts, stm, copy;
   return 0;
}