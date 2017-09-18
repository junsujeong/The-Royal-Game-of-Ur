//----------------------------------------------------------------------------
// Name:    David Feldman, Edward VanDerJagt, Alex Bisbach, Junsu Jeong, Adam Larson
// Team:    C--
// Project: Play a game of Ur
// Purpose: This class has a piece with a specific path.
//----------------------------------------------------------------------------
#ifndef  __PIECE_H
#define __PIECE_H

#include "Path.h"
#include <time.h>

//---------------------------------------------------------------------
// This class has a piece with a specific path.
//---------------------------------------------------------------------
class Piece
{
public:

   //---------------------------------------------------------------------
   // Constructs a piece with an empty path.
   //---------------------------------------------------------------------
   Piece() { path = NULL; faceDown = false; }

   //---------------------------------------------------------------------
   // Resets the path of the piece.
   //---------------------------------------------------------------------
   void Restart() { path->Reset(); faceDown = false; }

   //---------------------------------------------------------------------
   // Gets the path position as if the piece had moved forward by the
   // given number of steps. Returns NULL if out of bounds.
   //---------------------------------------------------------------------
   Coordinate* MoveFront(int steps) { return path->Move(steps); }

   //---------------------------------------------------------------------
   // Checks if the piece is at the finishing cell.
   //---------------------------------------------------------------------
   bool Finished() { return path->Finished(); }

   //---------------------------------------------------------------------
   // Gets the path position as if the piece had moved backward by the
   // given number of steps. Returns NULL if out of bounds.
   //---------------------------------------------------------------------
   Coordinate* MoveBack(int steps) { return path->Move(steps * -1); }

   //---------------------------------------------------------------------
   // Destructs the piece.
   //---------------------------------------------------------------------
   ~Piece() { delete path; }

   //---------------------------------------------------------------------
   // Sets the pieces custom path.
   //---------------------------------------------------------------------
   void SetPath(Path * p) { path = p;  }

   //----------------------------------------------------------------------------
   // Sets the player number.
   //----------------------------------------------------------------------------
   void SetPlayer(int num) { playerNum = num; }

   //----------------------------------------------------------------------------
   // Gets the player number.
   //----------------------------------------------------------------------------
   int GetPlayerNum() { return playerNum; }

   //----------------------------------------------------------------------------
   // Peek at the path of the current piece, as if the piece were to 
   // move forward.
   //----------------------------------------------------------------------------
   Coordinate * PeakPath(int num) { return path->Peak(num); }

   //----------------------------------------------------------------------------
   // Checks if the piece is facedown.
   //----------------------------------------------------------------------------
   bool IsFaceDown() { return faceDown; }

   //----------------------------------------------------------------------------
   // Flips the piece rightside-up by setting facedown to not facedown.
   //----------------------------------------------------------------------------
   void Flip() { faceDown = !faceDown; }

   //----------------------------------------------------------------------------
   // Overload operator for less than by comparing paths
   //----------------------------------------------------------------------------
   bool operator<(const Piece & p);

   //----------------------------------------------------------------------------
   // Overload operator for greater than by comparing paths
   //----------------------------------------------------------------------------
   bool operator>(const Piece & p);

   //----------------------------------------------------------------------------
   // Overload operator for equals. Sets a piece equal to the given piece.
   //----------------------------------------------------------------------------
   Piece& operator=(const Piece& p);

   //----------------------------------------------------------------------------
   // returns the final position coordinate
   //----------------------------------------------------------------------------
   Coordinate * GetFinalPosition() { return path->GetFinalPosition(); }

   //----------------------------------------------------------------------------
   // Copy Constructor
   //----------------------------------------------------------------------------
   Piece(const Piece& pc) { *this = pc; }

   //----------------------------------------------------------------------------
   // Get pieces path
   //----------------------------------------------------------------------------
   Path * GetPath() { return path; }


private:

   int playerNum;
   Path * path;
   bool faceDown;

};



#endif