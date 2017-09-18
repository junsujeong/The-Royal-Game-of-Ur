//---------------------------------------------------------------------------
// Name:    Team C--: David Feldman, Edward VanDerJagt, Alex Bisbach, 
//				Junsu Jeong, Adam Larson
// Project: Play a game of Ur
// Purpose: This manages the game logic. Works as a policy.
//----------------------------------------------------------------------------
#include "GameManager.h"

GameManager::GameManager()
{
   gameBoard = new Board();
   dice = new RollDice();
   roll = -1;
   hasRolled = false;
   player1 = new Player(PLAYER_1_NUM);
   player2= new Player(PLAYER_2_NUM);
   pf = new PieceFactory();
   srand(time(NULL));
   ai = NULL;
}

Coordinate* GameManager::MovePiece(int row, int col)
{

   Coordinate * result = NULL;
   if (hasRolled)
   {
      Command * c = new MoveCommand();
      Coordinate * cr = new Coordinate(row, col);
      
      result = c->execute(currState, roll, cr);
      if (result != NULL)
      {
         doStack.push(c);
         hasRolled = !hasRolled;
         SetToState(currState);
      }
      delete cr;
   }
   
   if (result != NULL)
      ClearRedo();
   return result;

}

/*bool GameManager::RemovePiece(int row, int col)
{
   return gameBoard->Remove(row, col);
}*/

void GameManager::Roll()
{
   if (!hasRolled)
   {
      dice->rollAllDice();
      roll = dice->getTotalValue();
      hasRolled = true;
   }
}

int GameManager::GetNumPieces()
{
   if (player1Turn)
      return player1->GetPieceNum();
   if(player2 != NULL)
      return player2->GetPieceNum();
   return ai->GetPieceNum();
}

int GameManager::GetNumPieces(int player)
{
	if (player == PLAYER_1_NUM)
		return player1->GetPieceNum();
	else if (player == PLAYER_2_NUM && player2 != NULL)
		return player2->GetPieceNum();
   else if (player == PLAYER_2_NUM && player2 == NULL)
      return ai->GetPieceNum();
	else
		return 0;
}

bool GameManager::IsPieceDone()
{
   if (gameBoard->IsPieceDone())
   {
      gameBoard->ResetIsPieceDone();
      return true;
   }
   return false;
}

int GameManager::GetPlayerScore(bool IsPlayer1)
{
   if (IsPlayer1)
      return player1->GetScore();
   if (ai == NULL)
      return player2->GetScore();
   else
      return ai->GetScore();
}

bool GameManager::IsThereMove()
{
   bool valid;
   if (hasRolled)
   {
      if (roll != 0)
      {
         valid = gameBoard->ValidTurn(roll, player1Turn);
         if (!valid)
         {
            Player * temp;
            if (player1Turn)
               temp = player1;
            else
            {
               if (player2 == NULL)
                  temp = ai;
               else
                  temp = player2;
            }
            if (temp->GetPieceNum() > 0)
            {
               Piece * tempP = temp->RequestPiece();
               Coordinate * tempC = tempP->PeakPath(1);
               temp->AddPiece(tempP);

               if (!gameBoard->PieceIsOwnedByPlayer(tempC->GetRow(), tempC->GetCol(), player1Turn))
                  valid = true;
            }
         }
      }
	  else
	  {
		  valid = false;
		  //MovePiece(-1, -1); // Runs a roll 0 scenario to add to stack
	  }    
   }
   else
      valid = false;
   if (!valid) // Check to see if roll 0 scenario was already processed
   {
      player1Turn = !player1Turn;
      currState->SetPlayerTurn(player1Turn);
      hasRolled = false;
   }
   return valid;
}

bool GameManager::AreAllPiecesDown(bool isPlayer1)
{
   for (int i = 0; i < NUM_ROWS; i++)
   {
      for (int j = 0; j < NUM_COLS; j++) // loop through all slots on the board
      {
         if (gameBoard->IsOccupied(i, j)) // find a piece from either player
         {
            if (gameBoard->PieceIsOwnedByPlayer(i, j, isPlayer1)) // check for ownership
            {
               if (gameBoard->IsDotsUp(i, j))
                  return false; // if a single piece is up they are not all down.
            }
         }
      }
   }
   return true;
}

forward_list<Coordinate> * GameManager::FlipAllPiecesUp(bool isPlayer1)
{
   forward_list<Coordinate> * list = new forward_list<Coordinate>;
   for (int i = 0; i < NUM_ROWS; i++)
   {
      for (int j = 0; j < NUM_COLS; j++) // loop through all slots on the board
      {
         if (gameBoard->IsOccupied(i, j)) // find a piece from either player
         {
            if (gameBoard->PieceIsOwnedByPlayer(i, j, isPlayer1)) // check for ownership
            {
               gameBoard->FlipPiece(i, j); // flip the piece
               list->push_front(Coordinate(i, j));
            }
         }
      }
   }
   return list;
}

void GameManager::ChangeAIPersonality(string personality)
{
   Personality p = GetPersonalityFromString(personality);
   ai->ChangePersonality(p);
}

void GameManager::SetupAI(string selectedPersonality, GameType type)
{
   Personality p = GetPersonalityFromString(selectedPersonality);
   if (ai != NULL)
      delete ai;
   ai = new AI(p, gameBoard);
   if (type == Chariot)
   {
      ai->SetMax(CHARIOT_PIECE_NUM);
      for (int i = 0; i < CHARIOT_PIECE_NUM; i++)
      {
         ai->AddPiece(pf->CreatePiece(type, 2));
      }
      
   }
   ai->ResetScore();
   delete player2;
   player2 = NULL;
}

bool GameManager::Undo()
{
   if (!doStack.empty())
   {
      Command * tempC = doStack.top();
      doStack.pop();
      currState = tempC->unexecute();
      SetToState(currState);
      hasRolled = false;
      undoStack.push(tempC);
      return true;
   }
   return false;
}

bool GameManager::Redo()
{
   if (!undoStack.empty())
   {
      Command * tempC = undoStack.top();
      undoStack.pop();
      tempC->execute(currState, 0, NULL);
      SetToState(currState);
      hasRolled = false;
      doStack.push(tempC);
      return true;
   }
   return false;
}

bool GameManager::IsAITurn()
{
   return !player1Turn;
}

Coordinate * GameManager::GetAIPieceToMove()
{
   return ai->GenerateMove(roll);
}

bool GameManager::IsPieceOwnedByPlayer(int row, int col, bool isPlayer1)
{
	return gameBoard->PieceIsOwnedByPlayer(row, col, isPlayer1);
}

void GameManager::KillEmAll()
{
   for (int row = 0; row < NUM_ROWS; row++)
   {
      for (int col = 0; col < NUM_COLS; col++)
         gameBoard->Remove(row, col);
   }
   ClearRedo();
   ClearDo();
   player1->ClearPieces();
   if (player2 == NULL)
      ai->ClearPieces();
   else
      player2->ClearPieces();
}

bool GameManager::IsPieceDotsDown(int row, int col)
{
	return !gameBoard->IsDotsUp(row, col);
}

void GameManager::SetToState(State * s)
{
   gameBoard = s->GetCurrBoard();
   player1 = s->GetPlayer(true);
   player2 = s->GetPlayer(false);
   gameT = s->GetGameType();
   if (s->GetGameMode())
   {
      ai = s->GetAI();
	   ai->ChangePersonality(s->GetAIPersonality());
	   ai->UpdateBoard(gameBoard);
   }
      
      
   player1Turn = s->GetPlayer1Turn();
}

void GameManager::ClearRedo()
{
   if (!undoStack.empty())
   {
      Command * p;
      int max = undoStack.size();
      for (int i = 0; i < max; i++)
      {
         p = undoStack.top();
         undoStack.pop();
         delete p;
      }
   }
}

void GameManager::ClearDo()
{
   if (!doStack.empty())
   {
      Command * p;
      int max = doStack.size();
      for (int i = 0; i < max; i++)
      {
         p = doStack.top();
         doStack.pop();
         delete p;
      }
   }
}


void GameManager::GenerateGame(GameType type)
{
   if (player1 != NULL)
      player1->ClearPieces();
   if (player2 != NULL)
      player2->ClearPieces();
   if (type == Chariot)
   {
      if (player1 != NULL)
         player1->SetMax(CHARIOT_PIECE_NUM);
      if (player2 != NULL)
         player2->SetMax(CHARIOT_PIECE_NUM);
      for (int i = 0; i < CHARIOT_PIECE_NUM; i++)
      {
         if (player1 != NULL)
            player1->AddPiece(pf->CreatePiece(type, PLAYER_1_NUM));
         if (player2 != NULL)
            player2->AddPiece(pf->CreatePiece(type, PLAYER_2_NUM));
      }
   }
   if (player1 != NULL)
      player1->ResetScore();
   if (player2 != NULL)
      player2->ResetScore();
   player1Turn = (int) rand() % 2; 
   if(player2 != NULL)
      currState = new State(gameBoard, player1, player2, gameT, player1Turn);
   else
      currState = new State(gameBoard, player1, ai, gameT, ai->GetPersonality(), player1Turn);
}

Personality GameManager::GetPersonalityFromString(string personality)
{
   Personality p;
   if (personality == "Adam")
      p = ADAM;
   else if (personality == "Alex")
      p = ALEX;
   else if (personality == "Animal")
      p = ANIMAL;
   else if (personality == "Bailey")
      p = BAILEY;
   else if (personality == "Dan")
      p = DAN;
   else if (personality == "Edward")
      p = EDWARD;
   else if (personality == "Eve")
      p = EVE;
   else if (personality == "Jun")
      p = JUN;
   else if (personality == "Storm")
      p = STORM;

   return p;
}


GameManager::~GameManager()
{
   if (!doStack.empty())
   {
      Command * p;
      int max = doStack.size();
      for (int i = 0; i < max; i++)
      {
         p = doStack.top();
         doStack.pop();
         delete p;
      }
   }
   delete gameBoard, dice, player1, player2, ai, currState, pf;
}
