//---------------------------------------------------------------------------
// Name:    David Feldman, Edward VanDerJagt, Alex Bisbach, 
//				Junsu Jeong, Adam Larson
// Team:    C--
// Project: Play a game of Ur
// Purpose: Executes the moves for an AI player, which is based on the users 
//          selection of several Personality options. Is derived from Player.
//----------------------------------------------------------------------------
#pragma once
#ifndef  __AI_H
#define __AI_H

#include "Player.h"
#include "Personality.h"
#include <list>
#include "Board.h"
#include <cstdlib>


//----------------------------------------------------------------------------
// Determines the moves for an AI player, which is based on the users 
// selection of several Personality options. Is derived from Player.
//----------------------------------------------------------------------------
class AI : public Player
{
public:
   //----------------------------------------------------------------------------
   // Constructor.
   //----------------------------------------------------------------------------
   AI(Personality newDiff, Board* &currBoard);

   AI();
   //----------------------------------------------------------------------------
   // Copy constructor.
   //----------------------------------------------------------------------------
   AI(Board* &currBoard);

   //----------------------------------------------------------------------------
   // Changes the Personality of the game.
   //----------------------------------------------------------------------------
   void ChangePersonality(Personality newDiff) { diff = newDiff; }

   //----------------------------------------------------------------------------
   // Overloaded method to add a piece to AI's containers
   //----------------------------------------------------------------------------
   void AddPiece(Piece* pc);

   //----------------------------------------------------------------------------
   // Performs a move based on Personality and the current state of the board.
   //----------------------------------------------------------------------------
   Coordinate* GenerateMove(int roll);

   //----------------------------------------------------------------------------
   // Returns the personality of the game
   //----------------------------------------------------------------------------
   Personality GetPersonality() { return diff; }

   //----------------------------------------------------------------------------
   // Update the AI's reference game board to given board
   //----------------------------------------------------------------------------
   void UpdateBoard(Board * &b) { boardState = b; }

   //----------------------------------------------------------------------------
   // Assign an AI to another
   //----------------------------------------------------------------------------
   AI & operator=(const AI & ai);

   //----------------------------------------------------------------------------
   // Copy constructor: Initialize AI as a copy of another
   //----------------------------------------------------------------------------
   AI(AI & ai);

private:
   Personality diff;
   list<Piece*> currPieces;
   Board* boardState;
   bool IsPlayer1;
   static const int ROWS = 3;
   static const int COLM = 8;

   //----------------------------------------------------------------------------
   // Helper method to generate a move for the ADAM Personality.
   //----------------------------------------------------------------------------
   Coordinate * GenerateAdamMove(int roll);

   //----------------------------------------------------------------------------
   // Helper method to generate a move for the EVE Personality.
   //---------------------------------------------------------------------------
   Coordinate * GenerateEveMove(int roll);

   //----------------------------------------------------------------------------
   // Helper method to generate a move for the STORM Personality.
   //---------------------------------------------------------------------------
   Coordinate * GenerateStormMove(int roll);

   //----------------------------------------------------------------------------
   // Helper method to generate a move for the ALEX Personality.
   //---------------------------------------------------------------------------
   Coordinate * GenerateAlexMove(int roll);

   //----------------------------------------------------------------------------
   // Helper method to generate a move for the JUN Personality.
   //---------------------------------------------------------------------------
   Coordinate * GenerateJunMove(int roll);

   //----------------------------------------------------------------------------
   // Helper method to generate a move for the EDWARD Personality.
   //---------------------------------------------------------------------------
   Coordinate * GenerateEdwardMove(int roll);

   //----------------------------------------------------------------------------
   // Helper method to generate a move for the BAILEY Personality.
   //---------------------------------------------------------------------------
   Coordinate * GenerateBaileyMove(int roll);

   //----------------------------------------------------------------------------
   // Helper method to generate a move for the DAN Personality.
   //---------------------------------------------------------------------------
   Coordinate * GenerateDanMove(int roll);

   //----------------------------------------------------------------------------
   // Helper method to generate a move for the ANIMAL Personality.
   //---------------------------------------------------------------------------
   Coordinate * GenerateAnimalMove(int roll);

   //----------------------------------------------------------------------------
   // Helper method to place a piece on a starting cell.
   //----------------------------------------------------------------------------
   Coordinate * PlacePiece();

   //----------------------------------------------------------------------------
   // Helper method to decide which piece to move by selecting the back most
   // piece on the board.
   //----------------------------------------------------------------------------
   Coordinate * MoveBackPiece(int roll);

   //----------------------------------------------------------------------------
   // Starting from the piece closest to the goal this method will attempt to 
   // either take a piece or reach the goal. This will skip over many valid
   // moves. This method will tend to achieve a higher score than other
   // strategies.
   //----------------------------------------------------------------------------
   Coordinate * MoveFrontPiece(int roll);

   //----------------------------------------------------------------------------
   // Helper method to determine the back most piece on the board
   //----------------------------------------------------------------------------
   Piece * GetBackPiece(int roll);

   //----------------------------------------------------------------------------
   // Helper method to determine the front most piece on the board
   //----------------------------------------------------------------------------
   Piece * GetFrontPiece(int roll);

   //----------------------------------------------------------------------------
   // Starting from the piece closest to the start this method will attempt to 
   // either take a piece or reach the goal. This will skip over many valid 
   // moves. This method will tend to achieve a lower score than
   // other strategies.
   //----------------------------------------------------------------------------
   Coordinate * AttackFromBack(int roll);

   //----------------------------------------------------------------------------
   // Starting from the piece closest to the goal this method will attempt to
   // either take a piece or reach the goal. This will skip over many valid 
   // moves. This method will tend to achieve a higher score than other 
   // strategies.
   //----------------------------------------------------------------------------
   Coordinate * AttackFromFront(int roll);

   //----------------------------------------------------------------------------
   // Helper method that checks if the piece can legally make the selected move
   //----------------------------------------------------------------------------
   bool CanMove(Piece* p, int roll);
   //----------------------------------------------------------------------------
   // The pieces are all held in a list class except for pieces that have made 
   // it off of the board. This method picks a piece at random from the list 
   // and checks all pieces starting with that one and looping back through 
   // the end of the list.
   //----------------------------------------------------------------------------
   Coordinate * MoveRandom(int roll);

   //----------------------------------------------------------------------------
   // Helper method to find possible random move
   //----------------------------------------------------------------------------
   Piece * FindMoveRandom(int roll);

   //----------------------------------------------------------------------------
   // Helper method to check if there is piece to score
   //----------------------------------------------------------------------------
   Coordinate * Score(int roll);


};


#endif