//---------------------------------------------------------------------------
// Name:    David Feldman, Edward VanDerJagt, Alex Bisbach, 
//				Junsu Jeong, Adam Larson
// Team C--
// Project: Play a game of Ur
// Purpose: This manages the game logic. Works as a policy.
//----------------------------------------------------------------------------

#ifndef __GAMEMANAGER_H_
#define __GAMEMANAGER_H_

#include "Board.h"
#include "RollDice.h"
#include "Player.h"
#include "PieceFactory.h"
#include <time.h>
#include <forward_list>
#include "AI.h"
#include "State.h"
#include "MoveCommand.h"
#include <stack>

using namespace std;

//---------------------------------------------------------------------
// This manages the game logic. Works as a policy.
//---------------------------------------------------------------------
class GameManager
{
public:
   //---------------------------------------------------------------------
   // Constructs a default game manager.
   //---------------------------------------------------------------------
   GameManager();

   //---------------------------------------------------------------------
   // Simulates one turn for a player by moving a piece. Check if roll is
   // 0 before calling this method.
   //---------------------------------------------------------------------
   Coordinate* MovePiece(int row, int col);

   //---------------------------------------------------------------------
   // Calls to roll the dice.
   //---------------------------------------------------------------------
   void Roll();

   //---------------------------------------------------------------------
   // Gets whether a roll has taken place since the last move.
   //---------------------------------------------------------------------
   bool GetHasRolled() { return hasRolled; }

   //---------------------------------------------------------------------
   // Destructs the game manager.
   //---------------------------------------------------------------------
   ~GameManager();

   //---------------------------------------------------------------------
   // Gets the number of pieces for the current player.
   //---------------------------------------------------------------------
   int GetNumPieces();

   //---------------------------------------------------------------------
   // Gets the number of pieces for the selected player.
   //---------------------------------------------------------------------
   int GetNumPieces(int player);

   //---------------------------------------------------------------------
   // Gets the exact roll of each of the 4 dice in string form.
   //---------------------------------------------------------------------
   string GetRollNumbers() { return dice->GetString(); }

   //----------------------------------------------------------------------------
   // Sets the game type.
   //----------------------------------------------------------------------------
   void SetGame(GameType type) { gameT = type; GenerateGame(gameT); }

   //----------------------------------------------------------------------------
   // Checks if the given game board space contains a piece.
   //----------------------------------------------------------------------------
   bool ContainsPiece(int row, int col) { return gameBoard->IsOccupied(row, col); }

   //----------------------------------------------------------------------------
   // Checks if it is player 1's turn.
   //----------------------------------------------------------------------------
   bool IsPlayer1Turn() { return player1Turn; }

   //----------------------------------------------------------------------------
   // Set the turn to player 1's turn. Only used for testbed.
   //----------------------------------------------------------------------------
   void SetTurnToP1() { player1Turn = true; }

   //----------------------------------------------------------------------------
   // Checks to see if the dice has been rolled since the previous turn.
   //----------------------------------------------------------------------------
   bool DiceWasRolled() { return hasRolled; }

   //----------------------------------------------------------------------------
   // Checks to see if the piece is at the finish spot and resets it
   //----------------------------------------------------------------------------
   bool IsPieceDone();

   //----------------------------------------------------------------------------
   // Gets the score of a given player
   //----------------------------------------------------------------------------
   int GetPlayerScore(bool IsPlayer1);

   //----------------------------------------------------------------------------
   // Gets the maximum score for a game mode
   //----------------------------------------------------------------------------
   int GetMaxScore() { return player1->GetMaxPieces(); }

   //----------------------------------------------------------------------------
   // Checks if there is any legal moves to make
   //----------------------------------------------------------------------------
   bool IsThereMove();

   //----------------------------------------------------------------------------
   // If all a players pieces are flipped down, it will return true.
   //----------------------------------------------------------------------------
   bool AreAllPiecesDown(bool isPlayer1);

   //----------------------------------------------------------------------------
   // Flips all of a players pieces dots up.
   //----------------------------------------------------------------------------
   forward_list<Coordinate> * FlipAllPiecesUp(bool isPlayer1);

   //----------------------------------------------------------------------------
   // Change AI Personality setting
   //----------------------------------------------------------------------------
   void ChangeAIPersonality(string personality);

   //----------------------------------------------------------------------------
   // Initialize AI
   //----------------------------------------------------------------------------
   void SetupAI(string personality, GameType type);

   //----------------------------------------------------------------------------
   // Checks if it is AI's turn
   //----------------------------------------------------------------------------
   bool IsAITurn();

   //----------------------------------------------------------------------------
   // Call to get AI's decision for turn
   //----------------------------------------------------------------------------
   Coordinate * GetAIPieceToMove();

   //----------------------------------------------------------------------------
   // Returns true if owned by the specified player.
   // Precondition: Cell must be occupied
   //----------------------------------------------------------------------------
   bool IsPieceOwnedByPlayer(int row, int col, bool isPlayer1);

   //----------------------------------------------------------------------------
   // This method clears the board. 
   //----------------------------------------------------------------------------
   void KillEmAll();

   //----------------------------------------------------------------------------
   // Returns true if the piece is dots down.
   // Precondition: Cell must be occupied
   //----------------------------------------------------------------------------
   bool IsPieceDotsDown(int row, int col);

   //----------------------------------------------------------------------------
   // The following get functions are used for testing.
   //----------------------------------------------------------------------------

   // Start Test Functions
   Player * GetPlayerOne() { return player1; }
   Player * GetPlayerTwo() { return player2; }
   Board * GetGameBoard() { return gameBoard; }
   int GetRoll() { return roll; }
   void SetRoll(int setRoll) { roll = setRoll; hasRolled = true; }
   // End Test Functions

   //----------------------------------------------------------------------------
   // Undo a turn and add it to the stack of turns to be redone
   //----------------------------------------------------------------------------
   bool Undo();

   //----------------------------------------------------------------------------
   // Redo a turn and add it back to the stack of turns that have been executed
   //----------------------------------------------------------------------------
   bool Redo();

private:
   const int PLAYER_1_NUM = 1;
   const int PLAYER_2_NUM = 2;
   const int CHARIOT_PIECE_NUM = 5;
   const int NUM_COLS = 8;
   const int NUM_ROWS = 3;

   Board * gameBoard;
   RollDice * dice;
   int roll;
   string rollBi;
   bool hasRolled;
   bool player1Turn;
   Player* player1;
   Player* player2;
   PieceFactory * pf;
   GameType gameT;
   AI * ai;

   State * currState;

   //----------------------------------------------------------------------------
   // Generates a new game based of the given game type.
   //----------------------------------------------------------------------------
   void GenerateGame(GameType type);

   //----------------------------------------------------------------------------
   // Helper method to generate Personality from string
   //----------------------------------------------------------------------------
   Personality GetPersonalityFromString(string personality);

   stack<Command *> doStack;
   stack<Command *> undoStack;

   //----------------------------------------------------------------------------
   // Helper method to set all local variables to current state when
   // state is updated
   //----------------------------------------------------------------------------
   void SetToState(State * s);

   //----------------------------------------------------------------------------
   // Clears the stack holding all movements that have been undone
   //----------------------------------------------------------------------------
   void ClearRedo();
   //----------------------------------------------------------------------------
   // Clears the stack holding all movements that have been executed
   //----------------------------------------------------------------------------
   void ClearDo();
};



#endif