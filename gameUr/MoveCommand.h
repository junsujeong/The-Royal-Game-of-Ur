//---------------------------------------------------------------------------
// Name:    David Feldman, Edward VanDerJagt, Alex Bisbach, 
//				Junsu Jeong, Adam Larson
// Team:    C--
// Project: Play a game of Ur
// Purpose: Executes the moves for an AI player, which is based on the users 
//          selection of several Personality options. Is derived from Player.
//----------------------------------------------------------------------------
#pragma once
#ifndef  __MOVECOMMAND_H
#define __MOVECOMMAND_H

#include "Command.h"
#include "Piece.h"
#include "Board.h"
#include "Player.h"

class MoveCommand : public Command
{
public:
   //----------------------------------------------------------------------------
   // Constructor
   //----------------------------------------------------------------------------
   MoveCommand();

   //----------------------------------------------------------------------------
   // Function that execute the  state
   //----------------------------------------------------------------------------
   Coordinate * execute(State * & s, int roll, Coordinate * c);

   //----------------------------------------------------------------------------
   // Function that returns the old state
   //----------------------------------------------------------------------------
   State * unexecute();

   //----------------------------------------------------------------------------
   // Destructor
   //----------------------------------------------------------------------------
   ~MoveCommand() { delete newState; }
private:
   State * oldState;
   State * newState;

   //----------------------------------------------------------------------------
   // Helper method to simulate placing a piece if not moving
   //----------------------------------------------------------------------------
   Coordinate * PlacePiece(Player *& pl, Board *& b);
   
};

#endif