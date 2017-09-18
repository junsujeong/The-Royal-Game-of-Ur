//----------------------------------------------------------------------------
// Name:    David Feldman, Edward VanDerJagt, Alex Bisbach, 
//			   Junsu Jeong, Adam Larson
// Team:    C--
// Project: Play a game of Ur
// Purpose: This class is a player with its own score, player number, and
//          number of pieces.
//----------------------------------------------------------------------------
#include "Player.h"

Player::Player()
{
   playerNum = 0;
   currMaxPieceCount = finalMaxPieceCount = 0;
   score = 0;
}

Player::Player(int num)
{
   playerNum = num;
   currMaxPieceCount = finalMaxPieceCount = 0;
   score = 0;
}

Player::Player(int pNum, int max)
{
   playerNum = pNum;
   currMaxPieceCount = finalMaxPieceCount = max;
   score = 0;
}

void Player::AddPiece(Piece * pc)
{
   if (currMaxPieceCount > 0)
   {
      if (pieces.size() < currMaxPieceCount && pc->PeakPath(0) == NULL)
         pieces.push(pc);
   }
   else
      pieces.push(pc);

}

Player::~Player()
{
   ClearPieces();
}

Player & Player::operator=(Player & player)
{
   if (this != &player)
   {
      /// We need to account for when player 2 is deleted and replaced by ai      
      playerNum = player.playerNum;
      score = player.score;
      currMaxPieceCount = player.currMaxPieceCount;
      finalMaxPieceCount = player.finalMaxPieceCount;
      stack<Piece*> temp;
      while (player.pieces.size() > 0)
      {
         temp.push(new Piece(*player.pieces.top())); // Test
         player.pieces.pop();
      }
      while (temp.size() > 0)
      {
         player.pieces.push(new Piece(*temp.top()));
         pieces.push(new Piece(*temp.top()));
         temp.pop();
      }
   }
   return *this;
}

Player::Player(Player & player)
{
   *this = player;
}

Piece * Player::RequestPiece()
{
   if (!pieces.empty())
   {
      Piece * p = pieces.top();
      pieces.pop();
      return p;
   }
   return NULL;
}

void Player::ClearPieces()
{
   if (!pieces.empty())
   {
      Piece * p;
      int max = pieces.size();
      for (int i = 0; i < max; i++)
      {
         p = pieces.top();
         pieces.pop();
         delete p;
      }
   }
}
