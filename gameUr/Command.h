//---------------------------------------------------------------------------
// Name:    David Feldman, Edward VanDerJagt, Alex Bisbach, 
//				Junsu Jeong, Adam Larson
// Team:    C--
// Project: Play a game of Ur
// Purpose: Executes the moves for an AI player, which is based on the users 
//          selection of several Personality options. Is derived from Player.
//----------------------------------------------------------------------------
#pragma once
#ifndef  __COMMAND_H
#define __COMMAND_H

#include "Coordinate.h"
#include "State.h"

class Command
{
public:
   //----------------------------------------------------------------------------
   // command pattern to execute the move
   //----------------------------------------------------------------------------
   virtual Coordinate * execute(State * & s, int roll, Coordinate * c) = 0;
   
   //----------------------------------------------------------------------------
   // command pattern to unexecute the move
   //----------------------------------------------------------------------------
   virtual State * unexecute() = 0;
private:
};

#endif