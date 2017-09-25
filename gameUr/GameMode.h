#ifndef __GAMEMODE_H_
#define __GAMEMODE_H_
#pragma once

#include "Coordinate.h"
#include "GameType.h"

class GameMode
{
public:
   //----------------------------------------------------------------------------
   // constructor
   //----------------------------------------------------------------------------
   GameMode() {}

   //----------------------------------------------------------------------------
   // Returns the starting position of the game
   //----------------------------------------------------------------------------
   virtual Coordinate* GetStartPos() { return startPos; }
   
   //----------------------------------------------------------------------------
   // Return the end position of the game
   //----------------------------------------------------------------------------
   virtual Coordinate* GetEndPos() { return endPos; }
   
   //----------------------------------------------------------------------------
   // Return the number of pieces of the game
   //----------------------------------------------------------------------------
   virtual int GetNumPieces() { return numPieces; }
protected:
   Coordinate * startPos;
   Coordinate * endPos;
   int numPieces;
   GameType type;
};


#endif
