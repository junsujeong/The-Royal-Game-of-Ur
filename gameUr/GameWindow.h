//---------------------------------------------------------------------
// Name:    David Feldman, Edward VanDerJagt, Alex Bisbach, 
//				Junsu Jeong, Adam Larson
// Team:    C--
// Project: Play a game of Ur
// Purpose: This is the GUI for the game.
//---------------------------------------------------------------------
#pragma once

#include <fstream>
#include <sstream>

#include "GameManager.h"
#include <msclr\marshal_cppstd.h>
using namespace msclr::interop;

namespace gameUr
{

   using namespace System;
   using namespace System::ComponentModel;
   using namespace System::Collections;
   using namespace System::Windows::Forms;
   using namespace System::Data;
   using namespace System::Drawing;


   const int PLAYER1 = 1;
   const int PLAYER2 = 2;

   const int NUM_HOR_TILES = 8;
   const int NUM_VER_TILES = 3;
   const int TILE_SIZE = 100;
   const int TILE_SPACING = TILE_SIZE + 6;
   const int TILE_SIZE_OP = 60;
   const int STARTING_X_POS = 50;
   const int STARTING_Y_POS = 50;
   const int STARTING_X_POS_OP = 210;
   const int STARTING_Y_POS_OP = 170;
   const int WINDOW_WIDTH = 960;
   const int WINDOW_HEIGHT = 550;

   /// <summary>
   /// Summary for GameWindow
   /// </summary>
   public ref class GameWindow : public System::Windows::Forms::Form
   {
   public:
      GameWindow(void)
      {
         InitializeComponent();
         //
         //TODO: Add the constructor code here
         //
      }

   protected:
      /// <summary>
      /// Clean up any resources being used.
      /// </summary>
      ~GameWindow()
      {
         if (components)
         {
            delete components;
         }
      }
      // Create start menu buttons
   private: System::Windows::Forms::Button^ btnStart;
            Button^ btnOptions;
            Button^ btnInstruct;
            Button^ btnExit;

            // Create board page graphics
   private: System::Windows::Forms::Button^ btnRollDice;
   private: System::Windows::Forms::Label^ lblLogo;
   private: System::Windows::Forms::Label^ lblGameMode;
   private: System::Windows::Forms::Label^ lblPersonality;
   private: System::Windows::Forms::Label^ lblSingleOrMulti;

            // Create option page buttons
   private: System::Windows::Forms::Button^ btnOpTile1;
   private: System::Windows::Forms::Button^ btnOpTile2;
   private: System::Windows::Forms::Button^ btnOpTile3;
   private: System::Windows::Forms::Button^ btnOpTile4;
   private: System::Windows::Forms::Button^ btnOpTile5;
   private: System::Windows::Forms::Button^ btnOpTile6;

   private: System::Windows::Forms::RadioButton^ radSingle;
   private: System::Windows::Forms::RadioButton^ radMulti;
   private: System::Windows::Forms::RadioButton^ radAdam;
   private: System::Windows::Forms::RadioButton^ radEve;
   private: System::Windows::Forms::RadioButton^ radStorm;
   private: System::Windows::Forms::RadioButton^ radAlex;
   private: System::Windows::Forms::RadioButton^ radJun;
   private: System::Windows::Forms::RadioButton^ radEdward;
   private: System::Windows::Forms::RadioButton^ radBailey;
   private: System::Windows::Forms::RadioButton^ radDan;
   private: System::Windows::Forms::RadioButton^ radAnimal;
   private: System::Windows::Forms::RadioButton^ radChariot;
   private: System::Windows::Forms::RadioButton^ radRace;
   private: System::Windows::Forms::GroupBox^ boxGameMode;
   private: System::Windows::Forms::GroupBox^ boxPersonality;
   private: System::Windows::Forms::GroupBox^ boxSingleOrMulti;
            Button^ btnOptionsBack;
            Button^ btnOptionsStart;
            Button^ btnInstructionBack;
            Button^ btnInstructionStart;
            Label^ lblCurTurnImage;      // This displays the current turn via a piece image
            Label^ lblCurTurn;

            Label^ lblPlayer1ScoreImage;
            Label^ lblPlayer2ScoreImage;
            Label^ lblPlayer1ScoreBaseImage;
            Label^ lblPlayer2ScoreBaseImage;
            Label^ lblPlayer1BowlImage;
            Label^ lblPlayer2BowlImage;

            TextBox^ txtInstruction;

            Button^ btnPlacePiece;
            Button^ btnInGameOption;
            Button^ btnRedo;
            Button^ btnUndo;
            //Label^ lblPieces;

            Label^ lblPlayer1Score;
            Label^ lblPlayer2Score;
            Label^ lblVictoryDisplay;

            // Menu
            MenuStrip^  menuStrip;
            // File menu
            ToolStripMenuItem^  fileMenuStripItem;
            ToolStripMenuItem^  saveMenuStripItem;
            ToolStripMenuItem^  loadMenuStripItem;
            ToolStripMenuItem^  exitMenuStripItem;
            // Help menu
            ToolStripMenuItem^  helpMenuStripItem;
            ToolStripMenuItem^  instructionsMenuStripItem;


   private: GameManager* gm = new GameManager();

   private: cli::array<Button^, 2>^ tiles;

   private: cli::array<Button^, 2>^ opTiles;

   private:
      Image ^image;
      Graphics ^p;
      int second = 0;
      Timer^ FlipPieceDownTimer = gcnew Timer;
      Timer^ RollTimer = gcnew Timer;
      Timer^ VictoryTimer = gcnew Timer;
      Timer^ FlipPieceUpTimer = gcnew Timer;
      int timeDuration;
      Coordinate* c;
      bool animating = false;
      forward_list<Coordinate> * list;
      bool IsFlippingPlayer1 = false;
      System::String^ selectedPersonality;
      bool optionalTile2 = false;
      bool optionalTile3 = false;
      bool optionalTile4 = false;
      bool optionalTile5 = false;
      bool optionalTile6 = false;
      bool singlePlayer = true;

   private:
      /// <summary>
      /// Required designer variable.
      /// </summary>
      System::ComponentModel::Container ^components;

      void InitializeComponent(void)
      {
         this->btnStart = gcnew System::Windows::Forms::Button();
         this->tiles = gcnew cli::array<Button^, 2>(NUM_HOR_TILES, NUM_VER_TILES);
         this->opTiles = gcnew cli::array<Button^, 2>(NUM_HOR_TILES, NUM_VER_TILES);
         this->btnRollDice = (gcnew System::Windows::Forms::Button());
         this->lblLogo = gcnew System::Windows::Forms::Label();

         btnOpTile1 = gcnew Button();
         btnOpTile2 = gcnew Button();
         btnOpTile3 = gcnew Button();
         btnOpTile4 = gcnew Button();
         btnOpTile5 = gcnew Button();
         btnOpTile6 = gcnew Button();


         lblPersonality = gcnew Label();
         lblGameMode = gcnew Label();
         lblSingleOrMulti = gcnew Label();
         radChariot = gcnew RadioButton();
         radRace = gcnew RadioButton();
         radAdam = gcnew RadioButton();
         radAlex = gcnew RadioButton();
         radAnimal = gcnew RadioButton();
         radBailey = gcnew RadioButton();
         radDan = gcnew RadioButton();
         radEdward = gcnew RadioButton();
         radEve = gcnew RadioButton();
         radJun = gcnew RadioButton();
         radStorm = gcnew RadioButton();
         radMulti = gcnew RadioButton();
         radSingle = gcnew RadioButton();
         boxPersonality = gcnew GroupBox();
         boxGameMode = gcnew GroupBox();
         boxSingleOrMulti = gcnew GroupBox();

         btnExit = gcnew Button();
         btnInstruct = gcnew Button();
         btnOptions = gcnew Button();

         btnOptionsBack = gcnew Button();
         btnOptionsStart = gcnew Button();


         btnInstructionBack = gcnew Button();
         btnInstructionStart = gcnew Button();

         txtInstruction = gcnew TextBox();

         lblCurTurnImage = gcnew Label();
         lblCurTurn = gcnew Label();
         lblPlayer1ScoreImage = gcnew Label();
         lblPlayer2ScoreImage = gcnew Label();
         lblPlayer1ScoreBaseImage = gcnew Label();
         lblPlayer2ScoreBaseImage = gcnew Label();
         lblPlayer1BowlImage = gcnew Label();
         lblPlayer2BowlImage = gcnew Label();
         btnPlacePiece = gcnew Button();
         //lblPieces = gcnew Label();
         btnInGameOption = gcnew Button();
         btnRedo = gcnew Button();
         btnUndo = gcnew Button();
         lblPlayer1Score = gcnew Label();
         lblPlayer2Score = gcnew Label();

         lblVictoryDisplay = gcnew Label();

         // Menu -- Trying to add menu items at the top (see spike 2 for references)
         menuStrip = gcnew MenuStrip();
         // File menu
         fileMenuStripItem = gcnew ToolStripMenuItem();
         saveMenuStripItem = gcnew ToolStripMenuItem();
         loadMenuStripItem = gcnew ToolStripMenuItem();
         exitMenuStripItem = gcnew ToolStripMenuItem();
         // Help menu
         helpMenuStripItem = gcnew ToolStripMenuItem();
         instructionsMenuStripItem = gcnew ToolStripMenuItem();

         menuStrip->SuspendLayout();

         this->SuspendLayout();

         //
         // menuStrip
         //
         this->menuStrip->Items->AddRange(gcnew cli::array< ToolStripItem^  >(1) { this->fileMenuStripItem });
         this->menuStrip->Location = System::Drawing::Point(0, 0);
         this->menuStrip->Name = L"menuStrip";
         this->menuStrip->Size = System::Drawing::Size(this->Size.Width, 25);
         this->menuStrip->TabIndex = 0;
         this->menuStrip->Text = L"menuStrip";

         //
         // fileMenuStripItem
         //
         this->fileMenuStripItem->DropDownItems->AddRange(gcnew cli::array< ToolStripItem^  >(3) {
            this->saveMenuStripItem,
               this->loadMenuStripItem, this->exitMenuStripItem
         });
         this->fileMenuStripItem->Name = L"fileMenuStripItem";
         this->fileMenuStripItem->Size = System::Drawing::Size(35, 20);
         this->fileMenuStripItem->Text = L"File";

         //
         // lblVictoryDisplay
         // 
         this->lblVictoryDisplay->Location = System::Drawing::Point(0, 0);
         this->lblVictoryDisplay->Name = L"lblVictoryDisplay";
         this->lblVictoryDisplay->Size = System::Drawing::Size(WINDOW_WIDTH, WINDOW_HEIGHT);
         this->lblVictoryDisplay->TabIndex = 0;
         this->lblVictoryDisplay->Text = L"";

         //
         // btnPlacePiece
         // 
         this->btnPlacePiece->Location = System::Drawing::Point(300, 450);
         this->btnPlacePiece->Name = L"btnPlacePiece";
         this->btnPlacePiece->Size = System::Drawing::Size(150, 50);
         this->btnPlacePiece->TabIndex = 0;
         this->btnPlacePiece->Text = L"Place Piece";
         this->btnPlacePiece->UseVisualStyleBackColor = true;
         this->btnPlacePiece->Click += gcnew System::EventHandler(this, &GameWindow::btnPlacePiece_Click);

         //
         // btnInGameOption
         // 
         this->btnInGameOption->Location = System::Drawing::Point(300, 390);
         this->btnInGameOption->Name = L"btnInGameOption";
         this->btnInGameOption->Size = System::Drawing::Size(150, 50);
         this->btnInGameOption->TabIndex = 0;
         this->btnInGameOption->Text = L"Options";
         this->btnInGameOption->UseVisualStyleBackColor = true;
         this->btnInGameOption->Click += gcnew System::EventHandler(this, &GameWindow::btnInGameOption_Click);

         //
         // btnRedo
         // 
         this->btnRedo->Location = System::Drawing::Point(880, 390);
         this->btnRedo->Name = L"btnRedo";
         this->btnRedo->Size = System::Drawing::Size(50, 50);
         this->btnRedo->TabIndex = 0;
         this->btnRedo->Text = L"Redo";
         this->btnRedo->UseVisualStyleBackColor = true;
         this->btnRedo->Click += gcnew System::EventHandler(this, &GameWindow::btnRedo_Click);
         //
         // btnUndo
         // 
         this->btnUndo->Location = System::Drawing::Point(820, 390);
         this->btnUndo->Name = L"btnUndo";
         this->btnUndo->Size = System::Drawing::Size(50, 50);
         this->btnUndo->TabIndex = 0;
         this->btnUndo->Text = L"Undo";
         this->btnUndo->UseVisualStyleBackColor = true;
         this->btnUndo->Click += gcnew System::EventHandler(this, &GameWindow::btnUndo_Click);

         //
         // lblCurTurn
         //
         this->lblCurTurn->AutoSize = true;
         this->lblCurTurn->Location = System::Drawing::Point(520, 420);
         this->lblCurTurn->Name = L"lblCurTurn";
         this->lblCurTurn->Text = L"Current Turn:";
         this->lblCurTurn->TabIndex = 0;

         //
         // lblCurTurnImage
         //
         this->lblCurTurnImage->AutoSize = true;
         this->lblCurTurnImage->Location = System::Drawing::Point(515, 390);
         this->lblCurTurnImage->Name = L"lblCurTurnImage";
         this->lblCurTurnImage->TabIndex = 0;
         lblCurTurnImage->MinimumSize = System::Drawing::Size(80, 80);

         //
         //lblPlayer1ScoreImage;
         //
         this->lblPlayer1ScoreImage->AutoSize = true;
         this->lblPlayer1ScoreImage->Location = System::Drawing::Point(165, 390);
         this->lblPlayer1ScoreImage->Name = L"lblPlayer1ScoreImage";
         this->lblPlayer1ScoreImage->TabIndex = 0;
         lblPlayer1ScoreImage->MinimumSize = System::Drawing::Size(50, 75);

         //
         //lblPlayer2ScoreImage;
         //
         this->lblPlayer2ScoreImage->AutoSize = true;
         this->lblPlayer2ScoreImage->Location = System::Drawing::Point(215, 390);
         this->lblPlayer2ScoreImage->Name = L"lblPlayer2ScoreImage";
         this->lblPlayer2ScoreImage->TabIndex = 0;
         lblPlayer2ScoreImage->MinimumSize = System::Drawing::Size(50, 75);

         //
         //lblPlayer1ScoreBaseImage;
         //
         this->lblPlayer1ScoreBaseImage->AutoSize = true;
         this->lblPlayer1ScoreBaseImage->Location = System::Drawing::Point(165, 440);
         this->lblPlayer1ScoreBaseImage->Name = L"lblPlayer1ScoreBaseImage";
         this->lblPlayer1ScoreBaseImage->TabIndex = 0;
         lblPlayer1ScoreBaseImage->MinimumSize = System::Drawing::Size(50, 75);

         //
         //lblPlayer2ScoreBaseImage;
         //
         this->lblPlayer2ScoreBaseImage->AutoSize = true;
         this->lblPlayer2ScoreBaseImage->Location = System::Drawing::Point(215, 440);
         this->lblPlayer2ScoreBaseImage->Name = L"lblPlayer2ScoreBaseImage";
         this->lblPlayer2ScoreBaseImage->TabIndex = 0;
         lblPlayer2ScoreBaseImage->MinimumSize = System::Drawing::Size(50, 75);

         //
         //lblPlayer1BowlImage;
         //
         this->lblPlayer1BowlImage->AutoSize = true;
         this->lblPlayer1BowlImage->Location = System::Drawing::Point(55, 390);
         this->lblPlayer1BowlImage->Name = L"lblPlayer1BowlImage";
         this->lblPlayer1BowlImage->TabIndex = 0;
         lblPlayer1BowlImage->MinimumSize = System::Drawing::Size(100, 50);

         //
         //lblPlayer2BowlImage;
         //
         this->lblPlayer2BowlImage->AutoSize = true;
         this->lblPlayer2BowlImage->Location = System::Drawing::Point(55, 440);
         this->lblPlayer2BowlImage->Name = L"lblPlayer2BowlImage";
         this->lblPlayer2BowlImage->TabIndex = 0;
         lblPlayer2BowlImage->MinimumSize = System::Drawing::Size(100, 50);



         //
         // FlipPieceDownTimer
         //
         FlipPieceDownTimer->Tick += gcnew EventHandler(this, &GameWindow::FlipPieceDownTimer_Tick);
         //
         // RollTimer
         //
         RollTimer->Tick += gcnew EventHandler(this, &GameWindow::RollTimer_Tick);
         //
         // VictoryTimer
         //
         VictoryTimer->Tick += gcnew EventHandler(this, &GameWindow::VictoryTimer_Tick);
         //
         // VictoryTimer
         //
         FlipPieceUpTimer->Tick += gcnew EventHandler(this, &GameWindow::FlipPieceUpTimer_Tick);

         //
         // btnStart
         // 
         this->btnStart->Location = System::Drawing::Point(100, 400);
         this->btnStart->Name = L"btnStart";
         this->btnStart->Size = System::Drawing::Size(150, 50);
         this->btnStart->TabIndex = 0;
         this->btnStart->Font = (gcnew System::Drawing::Font(L"Poor Richard", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnStart->Text = L"New Game";
         this->btnStart->UseVisualStyleBackColor = true;
         this->btnStart->Click += gcnew System::EventHandler(this, &GameWindow::btnStart_Click);
         // 
         // btnInstruct
         // 
         this->btnInstruct->Location = System::Drawing::Point(300, 400);
         this->btnInstruct->Name = L"btnInstruct";
         this->btnInstruct->Size = System::Drawing::Size(150, 50);
         this->btnInstruct->TabIndex = 0;
         this->btnInstruct->Font = (gcnew System::Drawing::Font(L"Poor Richard", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnInstruct->Text = L"Instructions";
         this->btnInstruct->UseVisualStyleBackColor = true;
         this->btnInstruct->Click += gcnew System::EventHandler(this, &GameWindow::btnInstruct_Click);

         //
         // btnOptions
         // 
         this->btnOptions->Location = System::Drawing::Point(500, 400);
         this->btnOptions->Name = L"btnOptions";
         this->btnOptions->Size = System::Drawing::Size(150, 50);
         this->btnOptions->TabIndex = 0;
         this->btnOptions->Font = (gcnew System::Drawing::Font(L"Poor Richard", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnOptions->Text = L"Options";
         this->btnOptions->UseVisualStyleBackColor = true;
         this->btnOptions->Click += gcnew System::EventHandler(this, &GameWindow::btnOptions_Click);

         //
         // btnExit
         // 
         this->btnExit->Location = System::Drawing::Point(700, 400);
         this->btnExit->Name = L"btnExit";
         this->btnExit->Size = System::Drawing::Size(150, 50);
         this->btnExit->TabIndex = 0;
         this->btnExit->Font = (gcnew System::Drawing::Font(L"Poor Richard", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnExit->Text = L"Exit";
         this->btnExit->UseVisualStyleBackColor = true;
         this->btnExit->Click += gcnew System::EventHandler(this, &GameWindow::btnExit_Click);

         //
         // btnOptionsStart
         // 
         btnOptionsStart->Location = System::Drawing::Point(700, 400);
         btnOptionsStart->Name = L"btnOptionsStart";
         btnOptionsStart->Size = System::Drawing::Size(150, 50);
         btnOptionsStart->TabIndex = 0;
         btnOptionsStart->Text = L"Start Game";
         btnOptionsStart->UseVisualStyleBackColor = true;
         btnOptionsStart->Click += gcnew System::EventHandler(this, &GameWindow::btnOptionsStart_Click);

         //
         // btnOptionsBack
         // 
         btnOptionsBack->Location = System::Drawing::Point(700, 330);
         btnOptionsBack->Name = L"btnOptionsBack";
         btnOptionsBack->Size = System::Drawing::Size(150, 50);
         btnOptionsBack->TabIndex = 0;
         btnOptionsBack->Text = L"Back";
         btnOptionsBack->UseVisualStyleBackColor = true;
         btnOptionsBack->Click += gcnew System::EventHandler(this, &GameWindow::btnOptionsBack_Click);

         //
         // btnInstructionStart
         // 
         btnInstructionStart->Location = System::Drawing::Point(700, 400);
         btnInstructionStart->Name = L"btnInstructionStart";
         btnInstructionStart->Size = System::Drawing::Size(150, 50);
         btnInstructionStart->TabIndex = 0;
         btnInstructionStart->Text = L"Start Game";
         btnInstructionStart->UseVisualStyleBackColor = true;
         btnInstructionStart->Click += gcnew System::EventHandler(this, &GameWindow::btnInstructionStart_Click);

         //
         // btnInstructionBack
         // 
         btnInstructionBack->Location = System::Drawing::Point(700, 330);
         btnInstructionBack->Name = L"btnInstructionBack";
         btnInstructionBack->Size = System::Drawing::Size(150, 50);
         btnInstructionBack->TabIndex = 0;
         btnInstructionBack->Text = L"Back";
         btnInstructionBack->UseVisualStyleBackColor = true;
         btnInstructionBack->Click += gcnew System::EventHandler(this, &GameWindow::btnInstructionBack_Click);

         //
         // txtInstruction
         //
         txtInstruction->Location = System::Drawing::Point(100, 10);
         txtInstruction->Name = L"txtInstruction";
         txtInstruction->SetBounds(10, 10, 500, 500);
         txtInstruction->Multiline = true;
         txtInstruction->ReadOnly = true;
         txtInstruction->ScrollBars = ScrollBars::Vertical;
         

         // 
         // boxPersonality
         // 
         this->boxPersonality->Location = System::Drawing::Point(350, 10);
         this->boxPersonality->Name = L"boxPersonality";
         this->boxPersonality->Size = System::Drawing::Size(375, 150);
         this->boxPersonality->TabIndex = 1;
         this->boxPersonality->Text = L"Personality";
         this->boxPersonality->Visible = false;
         // 
         // boxGameMode
         // 
         this->boxGameMode->Location = System::Drawing::Point(50, 10);
         this->boxGameMode->Name = L"boxGameMode";
         this->boxGameMode->Size = System::Drawing::Size(125, 150);
         this->boxGameMode->TabIndex = 0;
         this->boxGameMode->Text = L"Game Mode";
         this->boxGameMode->Visible = false;
         // 
         // boxSingleOrMulti
         // 
         this->boxSingleOrMulti->Location = System::Drawing::Point(200, 10);
         this->boxSingleOrMulti->Name = L"boxSingleOrMulti";
         this->boxSingleOrMulti->Size = System::Drawing::Size(125, 150);
         this->boxSingleOrMulti->TabIndex = 0;
         this->boxSingleOrMulti->Text = L"Mode";
         this->boxSingleOrMulti->Visible = false;
         // 
         // radChariot
         // 
         this->radChariot->Location = System::Drawing::Point(25, 25);
         this->radChariot->Name = L"radChariot";
         this->radChariot->AutoSize = true;
         this->radChariot->TabIndex = 0;
         this->radChariot->Text = L"Chariot";
         radChariot->Checked = true;
         radChariot->CheckedChanged += gcnew System::EventHandler(this, &GameWindow::radMode_CheckedChanged);
         // 
         // radRace
         // 
         this->radRace->Location = System::Drawing::Point(25, 50);
         this->radRace->Name = L"radRace";
         this->radRace->AutoSize = true;
         this->radRace->TabIndex = 0;
         this->radRace->Text = L"Race";
         radRace->CheckedChanged += gcnew System::EventHandler(this, &GameWindow::radMode_CheckedChanged);
         // 
         // radAdam
         // 
         this->radAdam->Location = System::Drawing::Point(25, 25);
         this->radAdam->Name = L"radAdam";
         this->radAdam->AutoSize = true;
         this->radAdam->TabIndex = 0;
         this->radAdam->Text = L"Adam";
         this->radAdam->Visible = false;
         radAdam->Checked = true;
         radAdam->CheckedChanged += gcnew System::EventHandler(this, &GameWindow::radPersonality_CheckedChanged);
         // 
         // radAlex
         // 
         this->radAlex->Location = System::Drawing::Point(25, 50);
         this->radAlex->Name = L"radAlex";
         this->radAlex->AutoSize = true;
         this->radAlex->TabIndex = 0;
         this->radAlex->Text = L"Alex";
         radAlex->CheckedChanged += gcnew System::EventHandler(this, &GameWindow::radPersonality_CheckedChanged);
         // 
         // radAnimal
         // 
         this->radAnimal->Location = System::Drawing::Point(25, 75);
         this->radAnimal->Name = L"radAnimal";
         this->radAnimal->AutoSize = true;
         this->radAnimal->TabIndex = 0;
         this->radAnimal->Text = L"Animal";
         radAnimal->CheckedChanged += gcnew System::EventHandler(this, &GameWindow::radPersonality_CheckedChanged);
         // 
         // radBailey
         // 
         this->radBailey->Location = System::Drawing::Point(150, 25);
         this->radBailey->Name = L"radBailey";
         this->radBailey->AutoSize = true;
         this->radBailey->TabIndex = 0;
         this->radBailey->Text = L"Bailey";
         radBailey->CheckedChanged += gcnew System::EventHandler(this, &GameWindow::radPersonality_CheckedChanged);
         // 
         // radDan
         // 
         this->radDan->Location = System::Drawing::Point(150, 50);
         this->radDan->Name = L"radDan";
         this->radDan->AutoSize = true;
         this->radDan->TabIndex = 0;
         this->radDan->Text = L"Dan";
         radDan->CheckedChanged += gcnew System::EventHandler(this, &GameWindow::radPersonality_CheckedChanged);
         // 
         // radEdward
         // 
         this->radEdward->Location = System::Drawing::Point(150, 75);
         this->radEdward->Name = L"radEdward";
         this->radEdward->AutoSize = true;
         this->radEdward->TabIndex = 0;
         this->radEdward->Text = L"Edward";
         radEdward->CheckedChanged += gcnew System::EventHandler(this, &GameWindow::radPersonality_CheckedChanged);
         // 
         // radEve
         // 
         this->radEve->Location = System::Drawing::Point(275, 25);
         this->radEve->Name = L"radEve";
         this->radEve->AutoSize = true;
         this->radEve->TabIndex = 0;
         this->radEve->Text = L"Eve";
         radEve->CheckedChanged += gcnew System::EventHandler(this, &GameWindow::radPersonality_CheckedChanged);
         // 
         // radJun
         // 
         this->radJun->Location = System::Drawing::Point(275, 50);
         this->radJun->Name = L"radJun";
         this->radJun->AutoSize = true;
         this->radJun->TabIndex = 0;
         this->radJun->Text = L"Jun";
         radJun->CheckedChanged += gcnew System::EventHandler(this, &GameWindow::radPersonality_CheckedChanged);
         // 
         // radStorm
         // 
         this->radStorm->Location = System::Drawing::Point(275, 75);
         this->radStorm->Name = L"radStorm";
         this->radStorm->AutoSize = true;
         this->radStorm->TabIndex = 0;
         this->radStorm->Text = L"Storm";
         radStorm->CheckedChanged += gcnew System::EventHandler(this, &GameWindow::radPersonality_CheckedChanged);
         // 
         // radMulti
         // 
         this->radMulti->Location = System::Drawing::Point(25, 50);
         this->radMulti->Name = L"radMulti";
         this->radMulti->AutoSize = true;
         this->radMulti->TabIndex = 0;
         this->radMulti->Text = L"Multiplayer";
         radMulti->CheckedChanged += gcnew System::EventHandler(this, &GameWindow::radSingleOrMulti_CheckedChanged);
         // 
         // radSingle
         // 
         this->radSingle->Location = System::Drawing::Point(25, 25);
         this->radSingle->Name = L"radSingle";
         this->radSingle->AutoSize = true;
         this->radSingle->TabIndex = 0;
         this->radSingle->Text = L"Singleplayer";
         radSingle->Checked = true;
         radSingle->CheckedChanged += gcnew System::EventHandler(this, &GameWindow::radSingleOrMulti_CheckedChanged);
         //
         // lblPersonality
         //
         this->lblPersonality->AutoSize = true;
         this->lblPersonality->Location = System::Drawing::Point(550, 365);
         this->lblPersonality->Name = L"lblPersonality";
         this->lblPersonality->TabIndex = 0;
         //
         // lblGameMode
         //
         this->lblGameMode->AutoSize = true;
         this->lblGameMode->Location = System::Drawing::Point(550, 365);
         this->lblGameMode->Name = L"lblGameMode";
         this->lblGameMode->TabIndex = 0;
         //
         // lblSingleOrMulti
         //
         this->lblSingleOrMulti->AutoSize = true;
         this->lblSingleOrMulti->Location = System::Drawing::Point(550, 365);
         this->lblSingleOrMulti->Name = L"lblSingleOrMulti";
         this->lblSingleOrMulti->TabIndex = 0;

         //
         // btnOpTile1
         // 
         this->btnOpTile1->Location = System::Drawing::Point(50, 170);
         this->btnOpTile1->Name = L"btnOpTile1";
         this->btnOpTile1->Size = System::Drawing::Size(60, 60);
         this->btnOpTile1->TabIndex = 0;
         btnOpTile1->UseVisualStyleBackColor = true;
         this->btnOpTile1->Text = L"Clear";
         this->btnOpTile1->Click += gcnew System::EventHandler(this, &GameWindow::btnOpTile1_Click);
         this->btnOpTile1->BackgroundImage = btnOpTile1->BackgroundImage->FromFile("../Pieces/TileOptions/Button_BlankC2.png");

         //
         // btnOpTile2
         // 
         this->btnOpTile2->Location = System::Drawing::Point(50, 230);
         this->btnOpTile2->Name = L"btnOpTile2";
         this->btnOpTile2->Size = System::Drawing::Size(60, 60);
         this->btnOpTile2->TabIndex = 0;
         btnOpTile2->UseVisualStyleBackColor = true;
         //this->btnOpTile2->Text = L"Tile 1";
         this->btnOpTile2->Click += gcnew System::EventHandler(this, &GameWindow::btnOpTile2_Click);
         this->btnOpTile2->BackgroundImage = btnOpTile2->BackgroundImage->FromFile("../Pieces/TileOptions/DotsC.png");

         //
         // btnOpTile3
         // 
         this->btnOpTile3->Location = System::Drawing::Point(50, 290);
         this->btnOpTile3->Name = L"btnOpTile3";
         this->btnOpTile3->Size = System::Drawing::Size(60, 60);
         this->btnOpTile3->TabIndex = 0;
         btnOpTile3->UseVisualStyleBackColor = true;
         //this->btnOpTile3->Text = L"Tile 1";
         this->btnOpTile3->Click += gcnew System::EventHandler(this, &GameWindow::btnOpTile3_Click);
         this->btnOpTile3->BackgroundImage = btnOpTile3->BackgroundImage->FromFile("../Pieces/TileOptions/FourDotsC.png");


         //
         // btnOpTile4
         // 
         this->btnOpTile4->Location = System::Drawing::Point(110, 170);
         this->btnOpTile4->Name = L"btnOpTile4";
         this->btnOpTile4->Size = System::Drawing::Size(60, 60);
         this->btnOpTile4->TabIndex = 0;
         btnOpTile4->UseVisualStyleBackColor = true;
         //this->btnOpTile4->Text = L"Tile 1";
         this->btnOpTile4->Click += gcnew System::EventHandler(this, &GameWindow::btnOpTile4_Click);
         this->btnOpTile4->BackgroundImage = btnOpTile4->BackgroundImage->FromFile("../Pieces/TileOptions/GuardC.png");

         //
         // btnOpTile5
         // 
         this->btnOpTile5->Location = System::Drawing::Point(110, 230);
         this->btnOpTile5->Name = L"btnOpTile5";
         this->btnOpTile5->Size = System::Drawing::Size(60, 60);
         this->btnOpTile5->TabIndex = 0;
         btnOpTile5->UseVisualStyleBackColor = true;
         //this->btnOpTile5->Text = L"Tile 1";
         this->btnOpTile5->Click += gcnew System::EventHandler(this, &GameWindow::btnOpTile5_Click);
         this->btnOpTile5->BackgroundImage = btnOpTile5->BackgroundImage->FromFile("../Pieces/TileOptions/DotsV2C.png");

         //
         // btnOpTile6
         // 
         this->btnOpTile6->Location = System::Drawing::Point(110, 290);
         this->btnOpTile6->Name = L"btnOpTile6";
         this->btnOpTile6->Size = System::Drawing::Size(60, 60);
         this->btnOpTile6->TabIndex = 0;
         btnOpTile6->UseVisualStyleBackColor = true;
         //this->btnOpTile6->Text = L"Tile 1";
         this->btnOpTile6->Click += gcnew System::EventHandler(this, &GameWindow::btnOpTile6_Click);
         this->btnOpTile6->BackgroundImage = btnOpTile6->BackgroundImage->FromFile("../Pieces/TileOptions/RosetteC.png");



         //
         // btnRollDice
         //
         this->btnRollDice->Location = System::Drawing::Point(700, 390);
         this->btnRollDice->Name = L"btnRollDice";
         this->btnRollDice->Size = System::Drawing::Size(100, 100);
         this->btnRollDice->TabIndex = 0;
         this->btnRollDice->Text = L"Roll Dice";
         this->btnRollDice->UseVisualStyleBackColor = true;
         this->btnRollDice->Click += gcnew System::EventHandler(this, &GameWindow::btnRollDice_Click);

         //
         // lblLogo
         //
         this->lblLogo->SetBounds(48, 25, 863, 272);
         this->lblLogo->Name = L"lblLogo";
         this->lblLogo->TabIndex = 0;
         this->lblLogo->BackgroundImage = lblLogo->BackgroundImage->FromFile("../Pieces/Logo.png");
         //
         // tiles
         //
         InitTiles();
         InitOpTiles();
         // 
         // GameWindow
         // 
         this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
         this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
         this->ClientSize = System::Drawing::Size(WINDOW_WIDTH, WINDOW_HEIGHT);

         boxPersonality->Controls->Add(radAdam);
         boxPersonality->Controls->Add(radAlex);
         boxPersonality->Controls->Add(radAnimal);
         boxPersonality->Controls->Add(radBailey);
         boxPersonality->Controls->Add(radDan);
         boxPersonality->Controls->Add(radEdward);
         boxPersonality->Controls->Add(radEve);
         boxPersonality->Controls->Add(radJun);
         boxPersonality->Controls->Add(radStorm);
         boxSingleOrMulti->Controls->Add(radSingle);
         boxSingleOrMulti->Controls->Add(radMulti);
         boxGameMode->Controls->Add(radChariot);
         boxGameMode->Controls->Add(radRace);
         Controls->Add(boxPersonality);
         Controls->Add(boxSingleOrMulti);
         Controls->Add(boxGameMode);

         this->Controls->Add(this->btnStart);
         Controls->Add(btnInstruct);
         Controls->Add(btnExit);
         Controls->Add(btnOptions);

         Controls->Add(btnOpTile1);
         Controls->Add(btnOpTile2);
         Controls->Add(btnOpTile3);
         Controls->Add(btnOpTile4);
         Controls->Add(btnOpTile5);
         Controls->Add(btnOpTile6);

         Controls->Add(btnOptionsBack);
         Controls->Add(btnOptionsStart);

         Controls->Add(btnInstructionBack);
         Controls->Add(btnInstructionStart);
         Controls->Add(txtInstruction);

         this->Controls->Add(this->btnRollDice);
         this->Controls->Add(this->lblLogo);
         Controls->Add(lblCurTurnImage);
         Controls->Add(lblCurTurn);

         Controls->Add(lblPlayer1ScoreImage);
         Controls->Add(lblPlayer2ScoreImage);
         Controls->Add(lblPlayer1ScoreBaseImage);
         Controls->Add(lblPlayer2ScoreBaseImage);
         Controls->Add(lblPlayer1BowlImage);
         Controls->Add(lblPlayer2BowlImage);

         Controls->Add(btnPlacePiece);
         //Controls->Add(lblPieces);
         Controls->Add(btnInGameOption);
         Controls->Add(btnRedo);
         Controls->Add(btnUndo);
         Controls->Add(lblPlayer1Score);
         Controls->Add(lblPlayer2Score);

         Controls->Add(lblVictoryDisplay);

         Controls->Add(menuStrip);

         ToggleGameMenu(false);
         ToggleMainMenu(true);
         ToggleOptionsMenu(false);
         ToggleInstructionMenu(false);
         this->Name = L"GameOfUr";
         this->Text = L"Game of Ur";
         this->ResumeLayout(false);
      }
   private:
      //----------------------------------------------------------------------------
      // optional tile 1 event handler. Clears the board.
      //----------------------------------------------------------------------------
      System::Void btnOpTile1_Click(System::Object^  sender, System::EventArgs^  e)
      {
         for (int j = 0; j < NUM_VER_TILES; j++)
         {
            for (int i = 0; i < NUM_HOR_TILES; i++)
            {
               opTiles[i, j]->BackgroundImage = (opTiles[i, j]->BackgroundImage->FromFile("../Pieces/TileOptions/op1.png"));
               opTiles[i, j]->Tag = "1";
            }
         }
      }

      //----------------------------------------------------------------------------
      // optional tile 2 event handler. Turns optile 2 on or off and sets the default
      // values on the board. Note. In future we may want a save state for preferred
      // player choices. ###
      //----------------------------------------------------------------------------
      System::Void btnOpTile2_Click(System::Object^  sender, System::EventArgs^  e)
      {
         optionalTile2 = !optionalTile2;
         if (optionalTile2)
         {
            btnOpTile2->BackgroundImage = btnOpTile2->BackgroundImage->FromFile("../Pieces/TileOptions/op2.png");
            opTiles[2, 0]->BackgroundImage = (opTiles[2, 0]->BackgroundImage->FromFile("../Pieces/TileOptions/op2.png"));
            opTiles[2, 0]->Tag = "2";
            opTiles[1, 1]->BackgroundImage = (opTiles[1, 1]->BackgroundImage->FromFile("../Pieces/TileOptions/op2.png"));
            opTiles[1, 1]->Tag = "2";
            opTiles[4, 1]->BackgroundImage = (opTiles[4, 1]->BackgroundImage->FromFile("../Pieces/TileOptions/op2.png"));
            opTiles[4, 1]->Tag = "2";
            opTiles[7, 1]->BackgroundImage = (opTiles[7, 1]->BackgroundImage->FromFile("../Pieces/TileOptions/op2.png"));
            opTiles[7, 1]->Tag = "2";
            opTiles[2, 2]->BackgroundImage = (opTiles[2, 2]->BackgroundImage->FromFile("../Pieces/TileOptions/op2.png"));
            opTiles[2, 2]->Tag = "2";
         }
         else
         {
            btnOpTile2->BackgroundImage = btnOpTile2->BackgroundImage->FromFile("../Pieces/TileOptions/DotsC.png");
            for (int j = 0; j < NUM_VER_TILES; j++)
            {
               for (int i = 0; i < NUM_HOR_TILES; i++)
               {
                  if (opTiles[i, j]->Tag == "2")
                  {
                     opTiles[i, j]->BackgroundImage = (opTiles[i, j]->BackgroundImage->FromFile("../Pieces/TileOptions/op1.png"));
                     opTiles[i, j]->Tag = "1";
                  }
               }
            }
         }
      }


      //----------------------------------------------------------------------------
      // optional tile 3 event handler. Turns optile 3 on or off and sets the default
      // values on the board. Note. In future we may want a save state for preferred
      // player choices. ###
      //----------------------------------------------------------------------------
      System::Void btnOpTile3_Click(System::Object^  sender, System::EventArgs^  e)
      {
         optionalTile3 = !optionalTile3;
         if (optionalTile3)
         {
            btnOpTile3->BackgroundImage = btnOpTile3->BackgroundImage->FromFile("../Pieces/TileOptions/op3.png");
            opTiles[7, 0]->BackgroundImage = (opTiles[7, 0]->BackgroundImage->FromFile("../Pieces/TileOptions/op3.png"));
            opTiles[7, 0]->Tag = "3";
            opTiles[7, 2]->BackgroundImage = (opTiles[7, 2]->BackgroundImage->FromFile("../Pieces/TileOptions/op3.png"));
            opTiles[7, 2]->Tag = "3";
         }
         else
         {
            btnOpTile3->BackgroundImage = btnOpTile3->BackgroundImage->FromFile("../Pieces/TileOptions/FourDotsC.png");
            for (int j = 0; j < NUM_VER_TILES; j++)
            {
               for (int i = 0; i < NUM_HOR_TILES; i++)
               {
                  if (opTiles[i, j]->Tag == "3")
                  {
                     opTiles[i, j]->BackgroundImage = (opTiles[i, j]->BackgroundImage->FromFile("../Pieces/TileOptions/op1.png"));
                     opTiles[i, j]->Tag = "1";
                  }
               }
            }
         }
      }

      //----------------------------------------------------------------------------
      // optional tile 4 event handler. Turns optile 4 on or off and sets the default
      // values on the board. Note. In future we may want a save state for preferred
      // player choices. ###
      //----------------------------------------------------------------------------
      System::Void btnOpTile4_Click(System::Object^  sender, System::EventArgs^  e)
      {
         optionalTile4 = !optionalTile4;
         if (optionalTile4)
         {
            btnOpTile4->BackgroundImage = btnOpTile4->BackgroundImage->FromFile("../Pieces/TileOptions/op4.png");
            opTiles[2, 1]->BackgroundImage = (opTiles[2, 1]->BackgroundImage->FromFile("../Pieces/TileOptions/op4.png"));
            opTiles[2, 1]->Tag = "4";
            opTiles[5, 1]->BackgroundImage = (opTiles[5, 1]->BackgroundImage->FromFile("../Pieces/TileOptions/op4.png"));
            opTiles[5, 1]->Tag = "4";
         }
         else
         {
            btnOpTile4->BackgroundImage = btnOpTile4->BackgroundImage->FromFile("../Pieces/TileOptions/GuardC.png");
            for (int j = 0; j < NUM_VER_TILES; j++)
            {
               for (int i = 0; i < NUM_HOR_TILES; i++)
               {
                  if (opTiles[i, j]->Tag == "4")
                  {
                     opTiles[i, j]->BackgroundImage = (opTiles[i, j]->BackgroundImage->FromFile("../Pieces/TileOptions/op1.png"));
                     opTiles[i, j]->Tag = "1";
                  }
               }
            }
         }
      }

      //----------------------------------------------------------------------------
      // optional tile 5 event handler. Turns optile 5 on or off and sets the default
      // values on the board. Note. In future we may want a save state for preferred
      // player choices. ###
      //----------------------------------------------------------------------------
      System::Void btnOpTile5_Click(System::Object^  sender, System::EventArgs^  e)
      {
         optionalTile5 = !optionalTile5;
         if (optionalTile5)
         {
            btnOpTile5->BackgroundImage = btnOpTile5->BackgroundImage->FromFile("../Pieces/TileOptions/op5.png");
            opTiles[1, 0]->BackgroundImage = (opTiles[1, 0]->BackgroundImage->FromFile("../Pieces/TileOptions/op5.png"));
            opTiles[1, 0]->Tag = "5";
            opTiles[3, 0]->BackgroundImage = (opTiles[3, 0]->BackgroundImage->FromFile("../Pieces/TileOptions/op5.png"));
            opTiles[3, 0]->Tag = "5";
            opTiles[6, 1]->BackgroundImage = (opTiles[6, 1]->BackgroundImage->FromFile("../Pieces/TileOptions/op5.png"));
            opTiles[6, 1]->Tag = "5";
            opTiles[1, 2]->BackgroundImage = (opTiles[1, 2]->BackgroundImage->FromFile("../Pieces/TileOptions/op5.png"));
            opTiles[1, 2]->Tag = "5";
            opTiles[3, 2]->BackgroundImage = (opTiles[3, 2]->BackgroundImage->FromFile("../Pieces/TileOptions/op5.png"));
            opTiles[3, 2]->Tag = "5";
         }
         else
         {
            btnOpTile5->BackgroundImage = btnOpTile5->BackgroundImage->FromFile("../Pieces/TileOptions/DotsV2C.png");
            for (int j = 0; j < NUM_VER_TILES; j++)
            {
               for (int i = 0; i < NUM_HOR_TILES; i++)
               {
                  if (opTiles[i, j]->Tag == "5")
                  {
                     opTiles[i, j]->BackgroundImage = (opTiles[i, j]->BackgroundImage->FromFile("../Pieces/TileOptions/op1.png"));
                     opTiles[i, j]->Tag = "1";
                  }
               }
            }
         }
      }


      //----------------------------------------------------------------------------
      // optional tile 6 event handler. Turns optile 6 on or off and sets the default
      // values on the board. Note. In future we may want a save state for preferred
      // player choices. ###
      //----------------------------------------------------------------------------
      System::Void btnOpTile6_Click(System::Object^  sender, System::EventArgs^  e)
      {
         optionalTile6 = !optionalTile6;
         if (optionalTile6)
         {
            btnOpTile6->BackgroundImage = btnOpTile6->BackgroundImage->FromFile("../Pieces/TileOptions/op6.png");
            opTiles[0, 0]->BackgroundImage = (opTiles[0, 0]->BackgroundImage->FromFile("../Pieces/TileOptions/op6.png"));
            opTiles[0, 0]->Tag = "6";
            opTiles[6, 0]->BackgroundImage = (opTiles[6, 0]->BackgroundImage->FromFile("../Pieces/TileOptions/op6.png"));
            opTiles[6, 0]->Tag = "6";
            opTiles[3, 1]->BackgroundImage = (opTiles[3, 1]->BackgroundImage->FromFile("../Pieces/TileOptions/op6.png"));
            opTiles[3, 1]->Tag = "6";
            opTiles[0, 2]->BackgroundImage = (opTiles[0, 2]->BackgroundImage->FromFile("../Pieces/TileOptions/op6.png"));
            opTiles[0, 2]->Tag = "6";
            opTiles[6, 2]->BackgroundImage = (opTiles[6, 2]->BackgroundImage->FromFile("../Pieces/TileOptions/op6.png"));
            opTiles[6, 2]->Tag = "6";
         }
         else
         {
            btnOpTile6->BackgroundImage = btnOpTile6->BackgroundImage->FromFile("../Pieces/TileOptions/RosetteC.png");
            for (int j = 0; j < NUM_VER_TILES; j++)
            {
               for (int i = 0; i < NUM_HOR_TILES; i++)
               {
                  if (opTiles[i, j]->Tag == "6")
                  {
                     opTiles[i, j]->BackgroundImage = (opTiles[i, j]->BackgroundImage->FromFile("../Pieces/TileOptions/op1.png"));
                     opTiles[i, j]->Tag = "1";
                  }
               }
            }
         }
      }


      //----------------------------------------------------------------------------
      // Start button event handler (for the initial screen start button)
      //----------------------------------------------------------------------------
      System::Void btnStart_Click(System::Object^  sender, System::EventArgs^  e)
      {
         ToggleMainMenu(false);
         ToggleGameMenu(true);
      }

      //----------------------------------------------------------------------------
      // Start button event handler (for option menu start button)
      //----------------------------------------------------------------------------
      System::Void btnOptionsStart_Click(System::Object^  sender, System::EventArgs^  e)
      {
         ToggleGameMenu(true);
         ToggleOptionsMenu(false);
      }

      

      //----------------------------------------------------------------------------
      // Start button event handler (for Instruction menu start button)
      //----------------------------------------------------------------------------
      System::Void btnInstructionStart_Click(System::Object^  sender, System::EventArgs^  e)
      {
         ToggleInstructionMenu(false);
         ToggleGameMenu(true);
      }


      //----------------------------------------------------------------------------
      // back button event handler (for Instruction menu back button)
      //----------------------------------------------------------------------------
      System::Void btnInstructionBack_Click(System::Object^  sender, System::EventArgs^  e)
      {
         ToggleInstructionMenu(false);
         ToggleMainMenu(true);
      }


      //----------------------------------------------------------------------------
      // Roll dice button event handler
      //----------------------------------------------------------------------------
      System::Void btnRollDice_Click(System::Object^  sender, System::EventArgs^  e)
      {
         if (!animating)
         {
            if (!gm->GetHasRolled())
            {
               gm->Roll();
               string gifName = "../Pieces/Animations24/" + gm->GetRollNumbers() + "24.gif";
               String^ path = gcnew String(gifName.c_str());
               this->btnRollDice->Text = "";
               this->btnRollDice->Image = btnRollDice->Image->FromFile(path);
               RollTimer->Enabled = true;
               animating = true;
               timeDuration = 9;
            }
         }
      }


      //----------------------------------------------------------------------------
      // Toggles option menu visibility
      //----------------------------------------------------------------------------
      void ToggleInstructionMenu(bool toggle)
      {

         string line, word;
         String^msg;
         String^filename = "../gameUr/instructions.txt";
         string file = marshal_as<string>(filename);
         ifstream ifs(file);
         getline(ifs, line);
         while (!ifs.eof())
         {
            msg = gcnew String(line.c_str());
            txtInstruction->AppendText("\r\n");

            txtInstruction->AppendText(msg);
            getline(ifs, line);
         }
         ifs.close();
         txtInstruction->SelectionStart = 0;
         txtInstruction->ScrollToCaret();         
         btnInstructionBack->Visible = toggle;
         btnInstructionStart->Visible = toggle;
         txtInstruction->Visible = toggle;
      }



      //----------------------------------------------------------------------------
      // Toggles option menu visibility
      //----------------------------------------------------------------------------
      void ToggleOptionsMenu(bool toggle)
      {
         btnOpTile1->Visible = toggle;
         btnOpTile2->Visible = toggle;
         btnOpTile3->Visible = toggle;
         btnOpTile4->Visible = toggle;
         btnOpTile5->Visible = toggle;
         btnOpTile6->Visible = toggle;

         boxPersonality->Visible = toggle;
         boxGameMode->Visible = toggle;
         boxSingleOrMulti->Visible = toggle;
         radAdam->Visible = toggle;
         radAlex->Visible = toggle;
         radAnimal->Visible = toggle;
         radBailey->Visible = toggle;
         radDan->Visible = toggle;
         radEdward->Visible = toggle;
         radEve->Visible = toggle;
         radJun->Visible = toggle;
         radStorm->Visible = toggle;
         radChariot->Visible = toggle;
         radMulti->Visible = toggle;
         radSingle->Visible = toggle;
         radRace->Visible = toggle;

         btnOptionsBack->Visible = toggle;
         btnOptionsStart->Visible = toggle;

         for (int j = 0; j < NUM_VER_TILES; j++)
         {
            for (int i = 0; i < NUM_HOR_TILES; i++)
            {
               opTiles[i, j]->Visible = toggle;
               tiles[i, j]->Tag = opTiles[i, j]->Tag;
               //if(tiles[i, j]->Tag != "0")
               tiles[i, j]->BackgroundImage = tiles[i, j]->BackgroundImage->FromFile("../Pieces/TileOptions/tile" + tiles[i, j]->Tag + ".png");
            }
         }
         opTiles[4, 0]->Visible = false;
         opTiles[5, 0]->Visible = false;
         opTiles[4, 2]->Visible = false;
         opTiles[5, 2]->Visible = false;
      }

      //----------------------------------------------------------------------------
      // Toggles Main menu visibility
      //----------------------------------------------------------------------------
      void ToggleMainMenu(bool toggle)
      {
         btnStart->Visible = toggle;
         lblLogo->Visible = toggle;
         btnExit->Visible = toggle;
         btnInstruct->Visible = toggle;
         btnOptions->Visible = toggle;
      }

      //----------------------------------------------------------------------------
      // Toggles Game menu visibility
      //----------------------------------------------------------------------------
      void ToggleGameMenu(bool toggle)
      {
         menuStrip->Visible = toggle;
         if (toggle)
         {
            if (singlePlayer)
               gm->SetupAI(getSelectedPersonality(), getSelectedMode());
            gm->SetGame(Chariot);
         }
         for (int j = 0; j < NUM_VER_TILES; j++)
         {
            for (int i = 0; i < NUM_HOR_TILES; i++)
            {
               tiles[i, j]->Visible = toggle;
            }
         }
         tiles[4, 0]->Visible = false;
         tiles[5, 0]->Visible = false;
         tiles[4, 2]->Visible = false;
         tiles[5, 2]->Visible = false;

         //tiles[3, 0]->Image = (tiles[3, 0]->Image->FromFile("../Pieces/Animations/Black Piece.png"));
         //tiles[3, 2]->Image = (tiles[3, 2]->Image->FromFile("../Pieces/Animations/White Piece.png"));
         btnRollDice->Visible = toggle;
         lblCurTurnImage->Visible = toggle;
         lblCurTurn->Visible = toggle;
         //lblPieces->Visible = toggle;

         lblPlayer1Score->Visible = toggle;
         lblPlayer2Score->Visible = toggle;
         btnPlacePiece->Visible = toggle;
         btnInGameOption->Visible = toggle;
         btnRedo->Visible = toggle;
         btnUndo->Visible = toggle;
         lblPlayer1BowlImage->Visible = toggle;
         lblPlayer2BowlImage->Visible = toggle;
         lblPlayer1ScoreBaseImage->Visible = toggle;
         lblPlayer2ScoreBaseImage->Visible = toggle;
         lblPlayer1ScoreImage->Visible = toggle;
         lblPlayer2ScoreImage->Visible = toggle;
         if (toggle)
         {
            lblPlayer1ScoreImage->BringToFront();
            lblPlayer2ScoreImage->BringToFront();
            lblPlayer1ScoreImage->Image = lblPlayer1ScoreImage->Image->FromFile("../Pieces/PiecesDisplay/ScoreKTop0b.jpg");
            lblPlayer2ScoreImage->Image = lblPlayer2ScoreImage->Image->FromFile("../Pieces/PiecesDisplay/ScoreWTop0.jpg");
            lblPlayer1ScoreBaseImage->Image = lblPlayer1ScoreBaseImage->Image->FromFile("../Pieces/PiecesDisplay/ScoreKBase" + gm->GetMaxScore() + "b.jpg");
            lblPlayer2ScoreBaseImage->Image = lblPlayer2ScoreBaseImage->Image->FromFile("../Pieces/PiecesDisplay/ScoreWBase" + gm->GetMaxScore() + ".jpg");
            if (singlePlayer && gm->IsAITurn())
            {
               AIRoll();
            }
         }
         else
         {
            lblPlayer1ScoreImage->SendToBack();
            lblPlayer2ScoreImage->SendToBack();
         }
         // Sets the image to display whos turn it is
         if (gm->IsPlayer1Turn())
         {
            lblCurTurnImage->Image = lblCurTurnImage->Image->FromFile("../Pieces/Animations/Black Piece.png");
         }
         else
         {
            lblCurTurnImage->Image = lblCurTurnImage->Image->FromFile("../Pieces/Animations/White Piece.png");
         }
         lblPlayer1BowlImage->Image = lblPlayer1BowlImage->Image->FromFile("../Pieces/PiecesDisplay/BlackBowl" + gm->GetNumPieces(PLAYER1) + "b.jpg");
         lblPlayer2BowlImage->Image = lblPlayer2BowlImage->Image->FromFile("../Pieces/PiecesDisplay/WhiteBowl" + gm->GetNumPieces(PLAYER2) + ".jpg");
      }

      //----------------------------------------------------------------------------
      // Toggles Victory menu visibility
      //----------------------------------------------------------------------------
      void ToggleVictoryMenu(bool toggle, bool player1Won)
      {
         ToggleGameMenu(false);
         lblVictoryDisplay->Visible = toggle;
         if (toggle)
         {
            if (player1Won)
               lblVictoryDisplay->Image = lblVictoryDisplay->Image->FromFile("../Pieces/Animations/player1Wins.gif");
            else
               lblVictoryDisplay->Image = lblVictoryDisplay->Image->FromFile("../Pieces/Animations/player2Wins.gif");
            gm->KillEmAll();

            for (int row = 0; row < NUM_VER_TILES; row++)
            {
               for (int col = 0; col < NUM_HOR_TILES; col++)
                  tiles[col, row]->Image = nullptr;
            }

            VictoryTimer->Enabled = true;
            timeDuration = 45;
         }
      }

      //----------------------------------------------------------------------------
      // Initializes the tile array
      //----------------------------------------------------------------------------
      void InitTiles()
      {
         for (int j = 0; j < NUM_VER_TILES; j++)
         {
            int curYPos = STARTING_Y_POS + TILE_SPACING * j;
            for (int i = 0; i < NUM_HOR_TILES; i++)
            {
               int curXPos = STARTING_X_POS + TILE_SPACING * i;
               tiles[i, j] = (gcnew System::Windows::Forms::Button());
               tiles[i, j]->Location = System::Drawing::Point(curXPos, curYPos);
               tiles[i, j]->Name = L"btnTile" + i + j;
               tiles[i, j]->Size = System::Drawing::Size(TILE_SIZE, TILE_SIZE);
               tiles[i, j]->TabIndex = 0;
               tiles[i, j]->UseVisualStyleBackColor = true;
               tiles[i, j]->Visible = false;
               tiles[i, j]->BackgroundImage = (tiles[i, j]->BackgroundImage->FromFile("../Pieces/Button_Blank.png"));
               tiles[i, j]->Tag = "1";
               Controls->Add(tiles[i, j]);
            }
         }
         tiles[3, 0]->BackgroundImage = (tiles[3, 0]->BackgroundImage->FromFile("../Pieces/GateA.png"));
         tiles[3, 2]->BackgroundImage = (tiles[3, 2]->BackgroundImage->FromFile("../Pieces/GateA.png"));

         tiles[0, 0]->Click += gcnew EventHandler(this, &GameWindow::tile_Click00);
         tiles[0, 1]->Click += gcnew EventHandler(this, &GameWindow::tile_Click01);
         tiles[0, 2]->Click += gcnew EventHandler(this, &GameWindow::tile_Click02);
         tiles[1, 0]->Click += gcnew EventHandler(this, &GameWindow::tile_Click10);
         tiles[1, 1]->Click += gcnew EventHandler(this, &GameWindow::tile_Click11);
         tiles[1, 2]->Click += gcnew EventHandler(this, &GameWindow::tile_Click12);
         tiles[2, 0]->Click += gcnew EventHandler(this, &GameWindow::tile_Click20);
         tiles[2, 1]->Click += gcnew EventHandler(this, &GameWindow::tile_Click21);
         tiles[2, 2]->Click += gcnew EventHandler(this, &GameWindow::tile_Click22);
         tiles[3, 0]->Click += gcnew EventHandler(this, &GameWindow::tile_Click30);
         tiles[3, 1]->Click += gcnew EventHandler(this, &GameWindow::tile_Click31);
         tiles[3, 2]->Click += gcnew EventHandler(this, &GameWindow::tile_Click32);
         //tiles[4, 0]->Click += gcnew EventHandler(this, &GameWindow::tile_Click00);
         tiles[4, 1]->Click += gcnew EventHandler(this, &GameWindow::tile_Click41);
         //tiles[4, 2]->Click += gcnew EventHandler(this, &GameWindow::tile_Click00);
         //tiles[5, 0]->Click += gcnew EventHandler(this, &GameWindow::tile_Click00);
         tiles[5, 1]->Click += gcnew EventHandler(this, &GameWindow::tile_Click51);
         //tiles[5, 2]->Click += gcnew EventHandler(this, &GameWindow::tile_Click00);
         tiles[6, 0]->Click += gcnew EventHandler(this, &GameWindow::tile_Click60);
         tiles[6, 1]->Click += gcnew EventHandler(this, &GameWindow::tile_Click61);
         tiles[6, 2]->Click += gcnew EventHandler(this, &GameWindow::tile_Click62);
         tiles[7, 0]->Click += gcnew EventHandler(this, &GameWindow::tile_Click70);
         tiles[7, 1]->Click += gcnew EventHandler(this, &GameWindow::tile_Click71);
         tiles[7, 2]->Click += gcnew EventHandler(this, &GameWindow::tile_Click72);
      }

      //----------------------------------------------------------------------------
      // Initializes the options tile array
      //----------------------------------------------------------------------------
      void InitOpTiles()
      {
         for (int j = 0; j < NUM_VER_TILES; j++)
         {
            int curYPos = STARTING_Y_POS_OP + TILE_SIZE_OP * j;
            for (int i = 0; i < NUM_HOR_TILES; i++)
            {
               int curXPos = STARTING_X_POS_OP + TILE_SIZE_OP * i;
               opTiles[i, j] = (gcnew System::Windows::Forms::Button());
               opTiles[i, j]->Location = System::Drawing::Point(curXPos, curYPos);
               opTiles[i, j]->Name = L"btnTile" + i + j;
               opTiles[i, j]->Size = System::Drawing::Size(TILE_SIZE_OP, TILE_SIZE_OP);
               opTiles[i, j]->TabIndex = 0;
               opTiles[i, j]->UseVisualStyleBackColor = true;
               opTiles[i, j]->Visible = false;
               opTiles[i, j]->BackgroundImage = (opTiles[i, j]->BackgroundImage->FromFile("../Pieces/TileOptions/Button_BlankC2.png"));
               opTiles[i, j]->Tag = "1";

               Controls->Add(opTiles[i, j]);
            }
         }
         opTiles[0, 0]->Click += gcnew EventHandler(this, &GameWindow::opTile_Click00);
         opTiles[0, 1]->Click += gcnew EventHandler(this, &GameWindow::opTile_Click01);
         opTiles[0, 2]->Click += gcnew EventHandler(this, &GameWindow::opTile_Click02);
         opTiles[1, 0]->Click += gcnew EventHandler(this, &GameWindow::opTile_Click10);
         opTiles[1, 1]->Click += gcnew EventHandler(this, &GameWindow::opTile_Click11);
         opTiles[1, 2]->Click += gcnew EventHandler(this, &GameWindow::opTile_Click12);
         opTiles[2, 0]->Click += gcnew EventHandler(this, &GameWindow::opTile_Click20);
         opTiles[2, 1]->Click += gcnew EventHandler(this, &GameWindow::opTile_Click21);
         opTiles[2, 2]->Click += gcnew EventHandler(this, &GameWindow::opTile_Click22);
         opTiles[3, 0]->Click += gcnew EventHandler(this, &GameWindow::opTile_Click30);
         opTiles[3, 1]->Click += gcnew EventHandler(this, &GameWindow::opTile_Click31);
         opTiles[3, 2]->Click += gcnew EventHandler(this, &GameWindow::opTile_Click32);
         opTiles[4, 1]->Click += gcnew EventHandler(this, &GameWindow::opTile_Click41);
         opTiles[5, 1]->Click += gcnew EventHandler(this, &GameWindow::opTile_Click51);
         opTiles[6, 0]->Click += gcnew EventHandler(this, &GameWindow::opTile_Click60);
         opTiles[6, 1]->Click += gcnew EventHandler(this, &GameWindow::opTile_Click61);
         opTiles[6, 2]->Click += gcnew EventHandler(this, &GameWindow::opTile_Click62);
         opTiles[7, 0]->Click += gcnew EventHandler(this, &GameWindow::opTile_Click70);
         opTiles[7, 1]->Click += gcnew EventHandler(this, &GameWindow::opTile_Click71);
         opTiles[7, 2]->Click += gcnew EventHandler(this, &GameWindow::opTile_Click72);
      }





      //----------------------------------------------------------------------------
      // Moves Piece on the selected tile
      //----------------------------------------------------------------------------
      void Move_Piece(int currCol, int currRow)
      {
         if (!animating)
         {
            Coordinate * currC = gm->MovePiece(currRow, currCol);
            if (currC != NULL)
            {
               tiles[currCol, currRow]->Image = nullptr;
               int row = currC->GetRow();
               int col = currC->GetCol();
               c = new Coordinate(row, col);
               // Add checks for turnstate and whether the piece is faceup or face down.
               ///We could check here if the currCol == currC->GetCol()... to check for 0 -Adam
               if (!gm->IsPlayer1Turn())
               {
                  if (tiles[col, row]->Tag == "1")
                     tiles[col, row]->Image = (tiles[col, row]->Image->FromFile("../Pieces/Animations24/BlackToBlank24.gif"));
                  else
                  {
                     tiles[col, row]->Image = (tiles[col, row]->Image->FromFile("../Pieces/OpTileAnimations/flpOp" +
                        tiles[col, row]->Tag + "K10.gif"));
                  }
               }
               else
               {
                  if (tiles[col, row]->Tag == "1")
                     tiles[col, row]->Image = (tiles[col, row]->Image->FromFile("../Pieces/Animations24/WhiteToBlank24.gif"));
                  else
                  {
                     tiles[col, row]->Image = (tiles[col, row]->Image->FromFile("../Pieces/OpTileAnimations/flpOp" +
                        tiles[col, row]->Tag + "W10.gif"));
                  }
               }
               FlipPieceDownTimer->Enabled = true;
               animating = true;
               timeDuration = 7;
            }
         }
      }

      //----------------------------------------------------------------------------
      // creates the tile array button click events
      //----------------------------------------------------------------------------
      System::Void tile_Click00(System::Object^  sender, System::EventArgs^  e)
      {
         Move_Piece(0, 0);
      }
      System::Void tile_Click01(System::Object^  sender, System::EventArgs^  e)
      {
         Move_Piece(0, 1);
      }
      System::Void tile_Click02(System::Object^  sender, System::EventArgs^  e)
      {
         Move_Piece(0, 2);
      }
      System::Void tile_Click10(System::Object^  sender, System::EventArgs^  e)
      {
         Move_Piece(1, 0);
      }
      System::Void tile_Click11(System::Object^  sender, System::EventArgs^  e)
      {
         Move_Piece(1, 1);
      }
      System::Void tile_Click12(System::Object^  sender, System::EventArgs^  e)
      {
         Move_Piece(1, 2);
      }
      System::Void tile_Click20(System::Object^  sender, System::EventArgs^  e)
      {
         Move_Piece(2, 0);
      }
      System::Void tile_Click21(System::Object^  sender, System::EventArgs^  e)
      {
         Move_Piece(2, 1);
      }
      System::Void tile_Click22(System::Object^  sender, System::EventArgs^  e)
      {
         Move_Piece(2, 2);
      }
      System::Void tile_Click30(System::Object^  sender, System::EventArgs^  e)
      {
         Move_Piece(3, 0);
      }
      System::Void tile_Click31(System::Object^  sender, System::EventArgs^  e)
      {
         Move_Piece(3, 1);
      }
      System::Void tile_Click32(System::Object^  sender, System::EventArgs^  e)
      {
         Move_Piece(3, 2);
      }
      System::Void tile_Click41(System::Object^  sender, System::EventArgs^  e)
      {
         Move_Piece(4, 1);
      }
      System::Void tile_Click51(System::Object^  sender, System::EventArgs^  e)
      {
         Move_Piece(5, 1);
      }
      System::Void tile_Click60(System::Object^  sender, System::EventArgs^  e)
      {
         Move_Piece(6, 0);
      }
      System::Void tile_Click61(System::Object^  sender, System::EventArgs^  e)
      {
         Move_Piece(6, 1);
      }
      System::Void tile_Click62(System::Object^  sender, System::EventArgs^  e)
      {
         Move_Piece(6, 2);
      }
      System::Void tile_Click70(System::Object^  sender, System::EventArgs^  e)
      {
         Move_Piece(7, 0);
      }
      System::Void tile_Click71(System::Object^  sender, System::EventArgs^  e)
      {
         Move_Piece(7, 1);
      }
      System::Void tile_Click72(System::Object^  sender, System::EventArgs^  e)
      {
         Move_Piece(7, 2);
      }


      //----------------------------------------------------------------------------
      // creates the option tile click array. Iterates to the next icon ###
      //----------------------------------------------------------------------------
      System::Void opTile_Click00(System::Object^  sender, System::EventArgs^  e)
      {
         int x = Next_Op(0, 0);
         opTiles[0, 0]->Tag = "" + x;
         opTiles[0, 0]->BackgroundImage = (opTiles[0, 0]->BackgroundImage->FromFile("../Pieces/TileOptions/Op" + x + ".png"));

      }
      System::Void opTile_Click10(System::Object^  sender, System::EventArgs^  e)
      {
         int x = Next_Op(1, 0);
         opTiles[1, 0]->Tag = "" + x;
         opTiles[1, 0]->BackgroundImage = (opTiles[1, 0]->BackgroundImage->FromFile("../Pieces/TileOptions/Op" + x + ".png"));
      }
      System::Void opTile_Click20(System::Object^  sender, System::EventArgs^  e)
      {
         int x = Next_Op(2, 0);
         opTiles[2, 0]->Tag = "" + x;
         opTiles[2, 0]->BackgroundImage = (opTiles[2, 0]->BackgroundImage->FromFile("../Pieces/TileOptions/Op" + x + ".png"));
      }
      System::Void opTile_Click30(System::Object^  sender, System::EventArgs^  e)
      {
         int x = Next_Op(3, 0);
         opTiles[3, 0]->Tag = "" + x;
         opTiles[3, 0]->BackgroundImage = (opTiles[3, 0]->BackgroundImage->FromFile("../Pieces/TileOptions/Op" + x + ".png"));
      }
      System::Void opTile_Click40(System::Object^  sender, System::EventArgs^  e)
      {
         int x = Next_Op(4, 0);
         opTiles[4, 0]->Tag = "" + x;
         opTiles[4, 0]->BackgroundImage = (opTiles[4, 0]->BackgroundImage->FromFile("../Pieces/TileOptions/Op" + x + ".png"));
      }
      System::Void opTile_Click50(System::Object^  sender, System::EventArgs^  e)
      {
         int x = Next_Op(5, 0);
         opTiles[5, 0]->Tag = "" + x;
         opTiles[5, 0]->BackgroundImage = (opTiles[5, 0]->BackgroundImage->FromFile("../Pieces/TileOptions/Op" + x + ".png"));
      }
      System::Void opTile_Click60(System::Object^  sender, System::EventArgs^  e)
      {
         int x = Next_Op(6, 0);
         opTiles[6, 0]->Tag = "" + x;
         opTiles[6, 0]->BackgroundImage = (opTiles[6, 0]->BackgroundImage->FromFile("../Pieces/TileOptions/Op" + x + ".png"));
      }
      System::Void opTile_Click70(System::Object^  sender, System::EventArgs^  e)
      {
         int x = Next_Op(7, 0);
         opTiles[7, 0]->Tag = "" + x;
         opTiles[7, 0]->BackgroundImage = (opTiles[7, 0]->BackgroundImage->FromFile("../Pieces/TileOptions/Op" + x + ".png"));
      }


      System::Void opTile_Click01(System::Object^  sender, System::EventArgs^  e)
      {
         int x = Next_Op(0, 1);
         opTiles[0, 1]->Tag = "" + x;
         opTiles[0, 1]->BackgroundImage = (opTiles[0, 1]->BackgroundImage->FromFile("../Pieces/TileOptions/Op" + x + ".png"));
      }
      System::Void opTile_Click11(System::Object^  sender, System::EventArgs^  e)
      {
         int x = Next_Op(1, 1);
         opTiles[1, 1]->Tag = "" + x;
         opTiles[1, 1]->BackgroundImage = (opTiles[1, 1]->BackgroundImage->FromFile("../Pieces/TileOptions/Op" + x + ".png"));
      }
      System::Void opTile_Click21(System::Object^  sender, System::EventArgs^  e)
      {
         int x = Next_Op(2, 1);
         opTiles[2, 1]->Tag = "" + x;
         opTiles[2, 1]->BackgroundImage = (opTiles[2, 1]->BackgroundImage->FromFile("../Pieces/TileOptions/Op" + x + ".png"));
      }
      System::Void opTile_Click31(System::Object^  sender, System::EventArgs^  e)
      {
         int x = Next_Op(3, 1);
         opTiles[3, 1]->Tag = "" + x;
         opTiles[3, 1]->BackgroundImage = (opTiles[3, 1]->BackgroundImage->FromFile("../Pieces/TileOptions/Op" + x + ".png"));
      }
      System::Void opTile_Click41(System::Object^  sender, System::EventArgs^  e)
      {
         int x = Next_Op(4, 1);
         opTiles[4, 1]->Tag = "" + x;
         opTiles[4, 1]->BackgroundImage = (opTiles[4, 1]->BackgroundImage->FromFile("../Pieces/TileOptions/Op" + x + ".png"));
      }
      System::Void opTile_Click51(System::Object^  sender, System::EventArgs^  e)
      {
         int x = Next_Op(5, 1);
         opTiles[5, 1]->Tag = "" + x;
         opTiles[5, 1]->BackgroundImage = (opTiles[5, 1]->BackgroundImage->FromFile("../Pieces/TileOptions/Op" + x + ".png"));
      }
      System::Void opTile_Click61(System::Object^  sender, System::EventArgs^  e)
      {
         int x = Next_Op(6, 1);
         opTiles[6, 1]->Tag = "" + x;
         opTiles[6, 1]->BackgroundImage = (opTiles[6, 1]->BackgroundImage->FromFile("../Pieces/TileOptions/Op" + x + ".png"));
      }
      System::Void opTile_Click71(System::Object^  sender, System::EventArgs^  e)
      {
         int x = Next_Op(7, 1);
         opTiles[7, 1]->Tag = "" + x;
         opTiles[7, 1]->BackgroundImage = (opTiles[7, 1]->BackgroundImage->FromFile("../Pieces/TileOptions/Op" + x + ".png"));
      }

      System::Void opTile_Click02(System::Object^  sender, System::EventArgs^  e)
      {
         int x = Next_Op(0, 2);
         opTiles[0, 2]->Tag = "" + x;
         opTiles[0, 2]->BackgroundImage = (opTiles[0, 2]->BackgroundImage->FromFile("../Pieces/TileOptions/Op" + x + ".png"));
      }
      System::Void opTile_Click12(System::Object^  sender, System::EventArgs^  e)
      {
         int x = Next_Op(1, 2);
         opTiles[1, 2]->Tag = "" + x;
         opTiles[1, 2]->BackgroundImage = (opTiles[1, 2]->BackgroundImage->FromFile("../Pieces/TileOptions/Op" + x + ".png"));
      }
      System::Void opTile_Click22(System::Object^  sender, System::EventArgs^  e)
      {
         int x = Next_Op(2, 2);
         opTiles[2, 2]->Tag = "" + x;
         opTiles[2, 2]->BackgroundImage = (opTiles[2, 2]->BackgroundImage->FromFile("../Pieces/TileOptions/Op" + x + ".png"));
      }
      System::Void opTile_Click32(System::Object^  sender, System::EventArgs^  e)
      {
         int x = Next_Op(3, 2);
         opTiles[3, 2]->Tag = "" + x;
         opTiles[3, 2]->BackgroundImage = (opTiles[3, 2]->BackgroundImage->FromFile("../Pieces/TileOptions/Op" + x + ".png"));
      }
      System::Void opTile_Click42(System::Object^  sender, System::EventArgs^  e)
      {
         int x = Next_Op(4, 2);
         opTiles[4, 2]->Tag = "" + x;
         opTiles[4, 2]->BackgroundImage = (opTiles[4, 2]->BackgroundImage->FromFile("../Pieces/TileOptions/Op" + x + ".png"));
      }
      System::Void opTile_Click52(System::Object^  sender, System::EventArgs^  e)
      {
         int x = Next_Op(5, 2);
         opTiles[5, 2]->Tag = "" + x;
         opTiles[5, 2]->BackgroundImage = (opTiles[5, 2]->BackgroundImage->FromFile("../Pieces/TileOptions/Op" + x + ".png"));
      }
      System::Void opTile_Click62(System::Object^  sender, System::EventArgs^  e)
      {
         int x = Next_Op(6, 2);
         opTiles[6, 2]->Tag = "" + x;
         opTiles[6, 2]->BackgroundImage = (opTiles[6, 2]->BackgroundImage->FromFile("../Pieces/TileOptions/Op" + x + ".png"));
      }
      System::Void opTile_Click72(System::Object^  sender, System::EventArgs^  e)
      {
         int x = Next_Op(7, 2);
         opTiles[7, 2]->Tag = "" + x;
         opTiles[7, 2]->BackgroundImage = (opTiles[7, 2]->BackgroundImage->FromFile("../Pieces/TileOptions/Op" + x + ".png"));
      }




      int Next_Op(int currCol, int currRow)
      {

         System::String^ text;
         string text2;
         text = opTiles[currCol, currRow]->Tag->ToString();
         text2 = msclr::interop::marshal_as< std::string >(text);
         int x = stoi(text2);

         if (optionalTile2 && (x < 2))
            return 2;
         if (optionalTile3 && (x < 3))
            return 3;
         if (optionalTile4 && (x < 4))
            return 4;
         if (optionalTile5 && (x < 5))
            return 5;
         if (optionalTile6 && (x < 6))
            return 6;
         return 1;
      }



      //----------------------------------------------------------------------------
      // The timer for piece flip animation
      //----------------------------------------------------------------------------
      System::Void FlipPieceDownTimer_Tick(System::Object^  sender, System::EventArgs^  e)
      {
         if (second != timeDuration)
         {
            second++;
         }
         if (second >= timeDuration)
         {
            ResetImage();
            FlipPieceDownTimer->Enabled = false;
            second = 0;
         }
      }

      //----------------------------------------------------------------------------
      // The timer for roll dice animation
      //----------------------------------------------------------------------------
      System::Void RollTimer_Tick(System::Object^  sender, System::EventArgs^  e)
      {
         if (second != timeDuration)
         {
            second++;
         }
         if (second >= timeDuration)
         {
            RollTimer->Enabled = false;
            second = 0;
            animating = false;
            EndRollAnimation();
         }
      }

      //----------------------------------------------------------------------------
      // The timer for the victory screen animation
      //----------------------------------------------------------------------------
      System::Void VictoryTimer_Tick(System::Object^  sender, System::EventArgs^  e)
      {
         if (second != timeDuration)
         {
            second++;
         }
         if (second >= timeDuration)
         {
            EndVictoryAnimation();
            VictoryTimer->Enabled = false;
            second = 0;
            animating = false;
         }
      }

      System::Void FlipPieceUpTimer_Tick(System::Object^  sender, System::EventArgs^  e)
      {
         if (second != timeDuration)
         {
            second++;
         }
         if (second >= timeDuration)
         {
            FlipPieceUpTimer->Enabled = false;
            second = 0;
            animating = false;
            EndFlipUpAnimation();
         }
      }

      //----------------------------------------------------------------------------
      // A function to replace the flipping piece animations with static images
      //----------------------------------------------------------------------------
      void EndFlipUpAnimation()
      {
         forward_list<Coordinate>::iterator iter;
         if (IsFlippingPlayer1)
         {
            for (iter = list->begin(); iter != list->end(); iter++)
            {
               tiles[iter->GetCol(), iter->GetRow()]->Image = tiles[iter->GetCol(), iter->GetRow()]->Image->
                  FromFile("../Pieces/Animations/Black Piece.png");
            }

            if (gm->AreAllPiecesDown(false))
            {
               list = gm->FlipAllPiecesUp(false);
               forward_list<Coordinate>::iterator iter;
               for (iter = list->begin(); iter != list->end(); iter++)
               {
                  tiles[iter->GetCol(), iter->GetRow()]->Image = tiles[iter->GetCol(), iter->GetRow()]->Image->
                     FromFile("../Pieces/Animations24/WhiteToDots24.gif");
               }
               FlipPieceUpTimer->Enabled = true;
               timeDuration = 7;
               IsFlippingPlayer1 = false;
            }
            else
            {
               if (singlePlayer && gm->IsAITurn())
               {
                  AIRoll();
               }
            }
         }
         else
         {
            for (iter = list->begin(); iter != list->end(); iter++)
            {
               tiles[iter->GetCol(), iter->GetRow()]->Image = tiles[iter->GetCol(), iter->GetRow()]->Image->
                  FromFile("../Pieces/Animations/White Piece.png");
            }
            if (singlePlayer && gm->IsAITurn())
            {
               AIRoll();
            }
         }
      }

      //----------------------------------------------------------------------------
      // A function to return to the main menu after a victory animation
      //----------------------------------------------------------------------------
      void EndVictoryAnimation()
      {
         lblVictoryDisplay->Image = nullptr;
         ToggleMainMenu(true);
         ToggleVictoryMenu(false, NULL);
      }

      //----------------------------------------------------------------------------
      // A function to replace the roll dice animation with a static image
      //----------------------------------------------------------------------------
      void EndRollAnimation()
      {
         string roll = gm->GetRollNumbers();
         string gifName = "../Pieces/Animations/" + roll + "b.png";
         String^ path = gcnew String(gifName.c_str());
         this->btnRollDice->Image = btnRollDice->Image->FromFile(path);

         if (!gm->IsThereMove())
         {
            if (!gm->IsPlayer1Turn())
               lblCurTurnImage->Image = lblCurTurnImage->Image->FromFile("../Pieces/Animations/White Piece.png");
            else
               lblCurTurnImage->Image = lblCurTurnImage->Image->FromFile("../Pieces/Animations/Black Piece.png");
            if (singlePlayer && gm->IsAITurn())
               AIRoll();
         }
         else
         {
            if (singlePlayer && gm->IsAITurn())
               AIMove();
         }
      }

      //----------------------------------------------------------------------------
      // A function to replace the piece flip animation with a static image and switch turns
      //----------------------------------------------------------------------------
      void ResetImage()
      {
         int col = c->GetCol();
         int row = c->GetRow();
         // Add checks for turnstate and whether the piece is faceup or face down.
         if (!gm->IsPlayer1Turn())
         {
            tiles[col, row]->Image = (tiles[col, row]->Image->FromFile("../Pieces/Animations/Black Piece Down.png"));
            lblCurTurnImage->Image = lblCurTurnImage->Image->FromFile("../Pieces/Animations/White Piece.png");
         }
         else
         {
            tiles[col, row]->Image = (tiles[col, row]->Image->FromFile("../Pieces/Animations/White Piece Down.png"));
            lblCurTurnImage->Image = lblCurTurnImage->Image->FromFile("../Pieces/Animations/Black Piece.png");
         }
         if (gm->IsPieceDone())
         {
               tiles[col, row]->Image = nullptr;
         }
         //lblPieces->Text = "Pieces: " + gm->GetNumPieces();
         lblPlayer1BowlImage->Image = lblPlayer1BowlImage->Image->FromFile("../Pieces/PiecesDisplay/BlackBowl" + gm->GetNumPieces(PLAYER1) + "b.jpg");
         lblPlayer2BowlImage->Image = lblPlayer2BowlImage->Image->FromFile("../Pieces/PiecesDisplay/WhiteBowl" + gm->GetNumPieces(PLAYER2) + ".jpg");



         int player1Score = gm->GetPlayerScore(true);
         int player2Score = gm->GetPlayerScore(false);
         //lblPlayer1Score->Text = "Player 1 Score: " + player1Score;
         lblPlayer1ScoreImage->Image = lblPlayer1ScoreImage->Image->FromFile("../Pieces/PiecesDisplay/ScoreKTop" + player1Score + "b.jpg");
         lblPlayer2ScoreImage->Image = lblPlayer2ScoreImage->Image->FromFile("../Pieces/PiecesDisplay/ScoreWTop" + player2Score + ".jpg");


         lblPlayer1ScoreBaseImage->Image = lblPlayer1ScoreBaseImage->Image->FromFile("../Pieces/PiecesDisplay/ScoreKBase" + gm->GetMaxScore() + "b.jpg");
         lblPlayer2ScoreBaseImage->Image = lblPlayer2ScoreBaseImage->Image->FromFile("../Pieces/PiecesDisplay/ScoreWBase" + gm->GetMaxScore() + ".jpg");

         if (player1Score == gm->GetMaxScore())
            ToggleVictoryMenu(true, true);
         else if (player2Score == gm->GetMaxScore())
            ToggleVictoryMenu(true, false);
         if (gm->AreAllPiecesDown(true))
         {
            list = gm->FlipAllPiecesUp(true);
            forward_list<Coordinate>::iterator iter;
            for (iter = list->begin(); iter != list->end(); iter++)
            {
               if (tiles[iter->GetCol(), iter->GetRow()]->Tag == "1")
                  tiles[iter->GetCol(), iter->GetRow()]->Image = tiles[iter->GetCol(), iter->GetRow()]->Image->
                  FromFile("../Pieces/Animations24/BlackToDots24.gif");
               else
               {
                  tiles[iter->GetCol(), iter->GetRow()]->Image = (tiles[iter->GetCol(), iter->GetRow()]->Image->FromFile(
                     "../Pieces/OpTileAnimations/flpOp" + tiles[iter->GetCol(), iter->GetRow()]->Tag + "K01.gif"));
               }
            }
            FlipPieceUpTimer->Enabled = true;
            timeDuration = 7;
            IsFlippingPlayer1 = true;
         }
         else if (gm->AreAllPiecesDown(false))
         {
            list = gm->FlipAllPiecesUp(false);
            forward_list<Coordinate>::iterator iter;
            for (iter = list->begin(); iter != list->end(); iter++)
            {
               if (tiles[iter->GetCol(), iter->GetRow()]->Tag == "1")
                  tiles[iter->GetCol(), iter->GetRow()]->Image = tiles[iter->GetCol(), iter->GetRow()]->Image->
                  FromFile("../Pieces/Animations24/WhiteToDots24.gif");
               else
               {
                  tiles[iter->GetCol(), iter->GetRow()]->Image = (tiles[iter->GetCol(), iter->GetRow()]->Image->FromFile(
                     "../Pieces/OpTileAnimations/flpOp" + tiles[iter->GetCol(), iter->GetRow()]->Tag + "W01.gif"));
               }
            }
            FlipPieceUpTimer->Enabled = true;
            timeDuration = 7;
            IsFlippingPlayer1 = false;
         }
         else
         {
            animating = false;
            if (singlePlayer && gm->IsAITurn())
               AIRoll();
         }
         delete c;
      }

      //----------------------------------------------------------------------------
      // Place piece button event handler
      //----------------------------------------------------------------------------
      System::Void btnPlacePiece_Click(System::Object^  sender, System::EventArgs^  e)
      {
         if (!animating)
         {
            if (gm->GetHasRolled())
            {
               if (gm->IsPlayer1Turn())
               {
                  Coordinate * c = gm->MovePiece(-1, -1);
                  if (c != NULL)
                  {
                     tiles[c->GetCol(), c->GetRow()]->Image = (tiles[c->GetCol(), c->GetRow()]->Image->FromFile("../Pieces/Animations/Black Piece.png"));
                     lblCurTurnImage->Image = lblCurTurnImage->Image->FromFile("../Pieces/Animations/White Piece.png");
                  }
               }
               else
               {
                  Coordinate * c = gm->MovePiece(-1, -1);
                  if (c != NULL)
                  {
                     tiles[c->GetCol(), c->GetRow()]->Image = (tiles[c->GetCol(), c->GetRow()]->Image->FromFile("../Pieces/Animations/White Piece.png"));
                     lblCurTurnImage->Image = lblCurTurnImage->Image->FromFile("../Pieces/Animations/Black Piece.png");
                  }
               }
               lblPlayer1BowlImage->Image = lblPlayer1BowlImage->Image->FromFile("../Pieces/PiecesDisplay/BlackBowl" + gm->GetNumPieces(PLAYER1) + "b.jpg");
               lblPlayer2BowlImage->Image = lblPlayer2BowlImage->Image->FromFile("../Pieces/PiecesDisplay/WhiteBowl" + gm->GetNumPieces(PLAYER2) + ".jpg");
            }
         }
         if (singlePlayer && gm->IsAITurn())
            AIRoll();
      }

      //----------------------------------------------------------------------------
      // InGameOption button event handler.
      //----------------------------------------------------------------------------
      System::Void btnInGameOption_Click(System::Object^  sender, System::EventArgs^  e)
      {

      }

      void SetGameToState()
      {
         for (int j = 0; j < NUM_VER_TILES; j++)
         {
            for (int i = 0; i < NUM_HOR_TILES; i++)
            {
               if (!gm->ContainsPiece(j, i))
                  tiles[i, j]->Image = nullptr; /// Needs to get the piece at a [i][j] and fill in corresponding image
               else
               {
                  if (gm->IsPieceOwnedByPlayer(j, i, true))
                  {
                     if (gm->IsPieceDotsDown(j, i))
                        tiles[i, j]->Image = tiles[i, j]->Image->FromFile("../Pieces/Animations/Black Piece Down.png");
                     else
                        tiles[i, j]->Image = tiles[i, j]->Image->FromFile("../Pieces/Animations/Black Piece.png");
                  }
                  else
                  {
                     if (gm->IsPieceDotsDown(j, i))
                        tiles[i, j]->Image = tiles[i, j]->Image->FromFile("../Pieces/Animations/White Piece Down.png");
                     else
                        tiles[i, j]->Image = tiles[i, j]->Image->FromFile("../Pieces/Animations/White Piece.png");
                  }
               }
            }
         }

         if (gm->IsPlayer1Turn())
            lblCurTurnImage->Image = lblCurTurn->Image->FromFile("../Pieces/Animations/Black Piece.png");
         else
            lblCurTurnImage->Image = lblCurTurn->Image->FromFile("../Pieces/Animations/White Piece.png");

         lblPlayer1BowlImage->Image = lblPlayer1BowlImage->Image->FromFile("../Pieces/PiecesDisplay/BlackBowl" + gm->GetNumPieces(PLAYER1) + "b.jpg");
         lblPlayer2BowlImage->Image = lblPlayer2BowlImage->Image->FromFile("../Pieces/PiecesDisplay/WhiteBowl" + gm->GetNumPieces(PLAYER2) + ".jpg");

         lblPlayer1ScoreImage->Image = lblPlayer1ScoreImage->Image->FromFile("../Pieces/PiecesDisplay/ScoreKTop" + gm->GetPlayerScore(true) + "b.jpg");
         lblPlayer2ScoreImage->Image = lblPlayer2ScoreImage->Image->FromFile("../Pieces/PiecesDisplay/ScoreWTop" + gm->GetPlayerScore(false) + ".jpg");
      }

      //----------------------------------------------------------------------------
      // Redo button event handler.
      //----------------------------------------------------------------------------
      System::Void btnRedo_Click(System::Object^  sender, System::EventArgs^  e)
      {
         if (gm->Redo())
         {
            SetGameToState();
         }
      }


      //----------------------------------------------------------------------------
      // Undo button event handler.
      //----------------------------------------------------------------------------
      System::Void btnUndo_Click(System::Object^  sender, System::EventArgs^  e)
      {
         if (gm->Undo())
         {
            SetGameToState();
         }
      }



      //----------------------------------------------------------------------------
      // Instruction button event handler.
      //----------------------------------------------------------------------------
      System::Void btnInstruct_Click(System::Object^  sender, System::EventArgs^  e)
      {
         ToggleMainMenu(false);
         ToggleInstructionMenu(true);
      }

      //----------------------------------------------------------------------------
      // Options button event handler.
      //----------------------------------------------------------------------------
      System::Void btnOptions_Click(System::Object^  sender, System::EventArgs^  e)
      {
         ToggleOptionsMenu(true);
         ToggleMainMenu(false);
      }

      //----------------------------------------------------------------------------
      // Exit button event handler.
      //----------------------------------------------------------------------------
      System::Void btnExit_Click(System::Object^  sender, System::EventArgs^  e)
      {
         this->Close();
      }

      //----------------------------------------------------------------------------
      // Options screen back button event handler.
      //----------------------------------------------------------------------------
      System::Void btnOptionsBack_Click(System::Object^  sender, System::EventArgs^  e)
      {
         ToggleOptionsMenu(false);
         ToggleMainMenu(true);
      }

      //----------------------------------------------------------------------------
      // Gets the newly checked option of either singleplayer or multiplayer
      //----------------------------------------------------------------------------
      System::Void radSingleOrMulti_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
      {
         if (radMulti->Checked)
            boxPersonality->Enabled = false;
         else
            boxPersonality->Enabled = true;
         singlePlayer = radSingle->Checked;
      }

      System::Void radMode_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
      {

      }

      System::Void radPersonality_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
      {

      }

      string getSelectedPersonality()
      {
         System::String^ text;

         if (radAdam->Checked)
            text = radAdam->Text;
         else if (radAlex->Checked)
            text = radAlex->Text;
         else if (radAnimal->Checked)
            text = radAnimal->Text;
         else if (radBailey->Checked)
            text = radBailey->Text;
         else if (radDan->Checked)
            text = radDan->Text;
         else if (radEdward->Checked)
            text = radEdward->Text;
         else if (radEve->Checked)
            text = radEve->Text;
         else if (radJun->Checked)
            text = radJun->Text;
         else if (radStorm->Checked)
            text = radStorm->Text;

         return msclr::interop::marshal_as< std::string >(text);
      }

      GameType getSelectedMode()
      {
         System::String^ text;

         if (radChariot->Checked)
            text = radChariot->Text;

         string type = msclr::interop::marshal_as< std::string >(text);
         if (type == "Chariot")
            return Chariot;
      }

      void AIRoll()
      {
         btnRollDice->PerformClick();
      }

      void AIMove()
      {
         Coordinate * c = gm->GetAIPieceToMove();
         if (c == NULL) // Fail safe maybe? Doesn't really work though -- Dan
            AIRoll();
         else if (c->GetCol() < 0 || c->GetRow() < 0)
         {
            delete c;
            btnPlacePiece->PerformClick();
         }
         else
            tiles[c->GetCol(), c->GetRow()]->PerformClick();
      }
   };
}
