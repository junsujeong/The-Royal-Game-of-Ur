//----------------------------------------------------------------------------
// Name:    David Feldman, Edward VanDerJagt, Alex Bisbach, 
//			   Junsu Jeong, Adam Larson
// Team:    C--
// Project: Play a game of Ur
// Purpose: This class is a player with its own score, player number, and
//          number of pieces.
//----------------------------------------------------------------------------
#ifndef  __PLAYER_H
#define __PLAYER_H

#include <stack>
#include "PieceFactory.h"
#include "Piece.h"
#include "Path.h"

//----------------------------------------------------------------------------
// Player is accessed and used through GameManager 
// (even when communicating with board)
//----------------------------------------------------------------------------
class Player
{


public:

   //----------------------------------------------------------------------------
   // Default constructor.
   //----------------------------------------------------------------------------
   Player();

   //----------------------------------------------------------------------------
   // Constructor given a player number.
   //----------------------------------------------------------------------------
   Player(int num);

   //----------------------------------------------------------------------------
   // Constructor given a player and max number of pieces.
   //----------------------------------------------------------------------------
   Player(int pNum, int max);

   //----------------------------------------------------------------------------
   // Gets the player number.
   //----------------------------------------------------------------------------
   int GetPlayerNum() { return playerNum; }

   //----------------------------------------------------------------------------
   // Gets the player score.
   //----------------------------------------------------------------------------
   int GetScore() { return score; }

   //----------------------------------------------------------------------------
   // Gets the number of pieces.
   //----------------------------------------------------------------------------
   int GetPieceNum() { return (int)pieces.size(); }

   //----------------------------------------------------------------------------
   // Get the maximum number of pieces.
   //----------------------------------------------------------------------------
   int GetMaxPieces() { return finalMaxPieceCount; }

   //----------------------------------------------------------------------------
   // Adds a piece to the starting container.
   //----------------------------------------------------------------------------
   virtual void AddPiece(Piece * pc);

   //----------------------------------------------------------------------------
   // Sets the score (used to create a handicap).
   //----------------------------------------------------------------------------
   void SetScore(int newScore) { score = newScore; }

   //----------------------------------------------------------------------------
   // Resets the score to zero.
   //----------------------------------------------------------------------------
   void ResetScore() { score = 0; }

   //----------------------------------------------------------------------------
   // Sets the max number of pieces.
   //----------------------------------------------------------------------------
   void SetMax(int max) { finalMaxPieceCount = currMaxPieceCount = max; }

   //----------------------------------------------------------------------------
   // Sends a piece back to be put on the board (removes from container).
   // If the bowl is empty this will return NULL. To deal with this we make the 
   // button unclickable in the GUI.
   //----------------------------------------------------------------------------
   Piece * RequestPiece();

   //----------------------------------------------------------------------------
   // Incredments the score by 1.
   //----------------------------------------------------------------------------
   void IncreaseScore() { ++score; --currMaxPieceCount; }

   //----------------------------------------------------------------------------
   // Deletes all the piece pointers. Used by the destructor.
   //----------------------------------------------------------------------------
   void ClearPieces();

   //----------------------------------------------------------------------------
   // Desctructor.
   //----------------------------------------------------------------------------
   ~Player();

   //----------------------------------------------------------------------------
   // Operator Overloading
   //----------------------------------------------------------------------------
   virtual Player& operator=(Player& player);

   //----------------------------------------------------------------------------
   // Copy Constructor
   //----------------------------------------------------------------------------
   Player(Player& player);

protected:

   int playerNum;
   int score;
   int currMaxPieceCount;
   int finalMaxPieceCount;
   stack<Piece*> pieces;
};



#endif // !1
