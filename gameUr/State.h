#//---------------------------------------------------------------------------
// Name:    David Feldman, Edward VanDerJagt, Alex Bisbach, 
//				Junsu Jeong, Adam Larson
// Team:    C--
// Project: Play a game of Ur
// Purpose: Executes the moves for an AI player, which is based on the users 
//          selection of several Personality options. Is derived from Player.
//----------------------------------------------------------------------------
#pragma once
#ifndef  __STATE_H
#define __STATE_H

#include "Board.h"
#include "Player.h"
#include "Personality.h"
#include "AI.h"

class State
{
public:
   //----------------------------------------------------------------------------
   // Constructor
   //----------------------------------------------------------------------------
   State(Board * b, Player * p1, Player * p2, GameType gt, bool turn);

   //----------------------------------------------------------------------------
   // Constructor: Used for singleplayer games
   //----------------------------------------------------------------------------
   State(Board * b, Player * p1, AI * a, GameType gt, Personality p, bool turn);
   
   //----------------------------------------------------------------------------
   // Returns current board state
   //----------------------------------------------------------------------------
   Board * GetCurrBoard() { return currBoard; }
   
   //----------------------------------------------------------------------------
   // Check if the player is player1 or player2
   //----------------------------------------------------------------------------
   Player * GetPlayer(bool player1);

   //----------------------------------------------------------------------------
   // returns the game type
   //----------------------------------------------------------------------------
   GameType GetGameType() { return game; }
   
   //----------------------------------------------------------------------------
   // returns the personality
   //----------------------------------------------------------------------------
   Personality GetAIPersonality() { return per; }

   //----------------------------------------------------------------------------
   // Returns if it is player 1's turn
   //----------------------------------------------------------------------------
   bool GetPlayer1Turn() { return player1Turn; }

   //----------------------------------------------------------------------------
   // Operator Overloading
   //----------------------------------------------------------------------------
   State& operator=(const State& s);
   
   //----------------------------------------------------------------------------
   // Destructor
   //----------------------------------------------------------------------------
   ~State() { delete currBoard, currP1, currP2; }

   //----------------------------------------------------------------------------
   // set the current turn
   //----------------------------------------------------------------------------
   void SetPlayerTurn(bool p1) { player1Turn = p1; }

   //----------------------------------------------------------------------------
   // Get the current state's AI
   //----------------------------------------------------------------------------
   AI * GetAI() { return ai; }

   //----------------------------------------------------------------------------
   // Returns true only if the game mode is single player
   //----------------------------------------------------------------------------
   bool GetGameMode() { return singlePlayer; }

private:
   Board * currBoard;
   Player * currP1;
   Player * currP2;
   GameType game;
   Personality per;
   bool player1Turn;
   AI * ai;
   bool singlePlayer;
};


#endif