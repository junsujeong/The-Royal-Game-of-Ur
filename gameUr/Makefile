# Makefile for test program

CFILESDICE=RollDice.h RollDice.cpp RollDiceTestBed.cpp

CFILESPATH=RollDice.h RollDice.cpp Personality.h Coordinate.h Coordinate.cpp GameType.h Path.h Path.cpp PathTestBed.cpp

CFILESPIECE=RollDice.h RollDice.cpp Personality.h Coordinate.h Coordinate.cpp GameType.h Path.h Path.cpp Piece.h Piece.cpp PieceTestBed.cpp

CFILESCELL=RollDice.h RollDice.cpp Personality.h Coordinate.h Coordinate.cpp GameType.h Path.h Path.cpp Piece.h Piece.cpp Cell.h Cell.cpp CellTestBed.cpp

CFILESPATHGENERATOR=RollDice.h RollDice.cpp Personality.h Coordinate.h Coordinate.cpp GameType.h Path.h Path.cpp Piece.h Piece.cpp Cell.h Cell.cpp PathGenerator.h PathGenerator.cpp PathGeneratorTestBed.cpp

CFILESPIECEFACTORY=RollDice.h RollDice.cpp Personality.h Coordinate.h Coordinate.cpp GameType.h Path.h Path.cpp Piece.h Piece.cpp Cell.h Cell.cpp PathGenerator.h PathGenerator.cpp PieceFactory.h PieceFactory.cpp PieceFactoryTestBed.cpp

CFILESBOARD=RollDice.h RollDice.cpp Personality.h Coordinate.h Coordinate.cpp GameType.h Path.h Path.cpp Piece.h Piece.cpp Cell.h Cell.cpp PathGenerator.h PathGenerator.cpp PieceFactory.h PieceFactory.cpp Board.h Board.cpp BoardTestBed.cpp

CFILESPLAYER=RollDice.h RollDice.cpp Personality.h Coordinate.h Coordinate.cpp GameType.h Path.h Path.cpp Piece.h Piece.cpp Cell.h Cell.cpp PathGenerator.h PathGenerator.cpp PieceFactory.h PieceFactory.cpp Board.h Board.cpp Player.h Player.cpp PlayerTestBed.cpp

CFILESAI=RollDice.h RollDice.cpp Personality.h Coordinate.h Coordinate.cpp GameType.h Path.h Path.cpp Piece.h Piece.cpp Cell.h Cell.cpp PathGenerator.h PathGenerator.cpp PieceFactory.h PieceFactory.cpp Board.h Board.cpp Player.h Player.cpp AI.h AI.cpp AITestBed.cpp

CFILESSTATE=RollDice.h RollDice.cpp Personality.h Coordinate.h Coordinate.cpp GameType.h Path.h Path.cpp Piece.h Piece.cpp Cell.h Cell.cpp PathGenerator.h PathGenerator.cpp PieceFactory.h PieceFactory.cpp Board.h Board.cpp Player.h Player.cpp AI.h AI.cpp State.h State.cpp StateTestBed.cpp

CFILESMOVECOMMAND=RollDice.h RollDice.cpp Personality.h Coordinate.h Coordinate.cpp GameType.h Path.h Path.cpp Piece.h Piece.cpp Cell.h Cell.cpp PathGenerator.h PathGenerator.cpp PieceFactory.h PieceFactory.cpp Board.h Board.cpp Player.h Player.cpp AI.h AI.cpp State.h State.cpp Command.h MoveCommand.h MoveCommand.cpp MoveCommandTestBed.cpp

CFILESGAMEMANAGER=RollDice.h RollDice.cpp Personality.h Coordinate.h Coordinate.cpp GameType.h Path.h Path.cpp Piece.h Piece.cpp Cell.h Cell.cpp PathGenerator.h PathGenerator.cpp PieceFactory.h PieceFactory.cpp Board.h Board.cpp Player.h Player.cpp AI.h AI.cpp State.h State.cpp Command.h MoveCommand.h MoveCommand.cpp GameManager.h GameManager.cpp GameManagerTestBed.cpp

CFILESGAMEMASTER=RollDice.h RollDice.cpp RollDiceTestBed.cpp Personality.h Coordinate.h Coordinate.cpp GameType.h Path.h Path.cpp PathTestBed.cpp Piece.h Piece.cpp PieceTestBed.cpp Cell.h Cell.cpp CellTestBed.cpp PathGenerator.h PathGenerator.cpp PathGeneratorTestBed.cpp PieceFactory.h PieceFactory.cpp PieceFactoryTestBed.cpp Board.h Board.cpp BoardTestBed.cpp Player.h Player.cpp PlayerTestBed.cpp AI.h AI.cpp AITestBed.cpp State.h State.cpp StateTestBed.cpp Command.h MoveCommand.h MoveCommand.cpp MoveCommandTestBed.cpp GameManager.h GameManager.cpp GameManagerTestBed.cpp

OBJFILESDICE=$(CFILESDICE:.cpp=.o)

OBJFILESGAMETYPE=$(CFILESGAMETYPE:.cpp=.o)

OBJFILESPATH=$(CFILESPATH:.cpp=.o)

OBJFILESPIECE=$(CFILESPIECE:.cpp=.o)

OBJFILESCELL=$(CFILESCELL:.cpp=.o)

OBJFILESPATHGENERATOR=$(CFILESPATHGENERATOR:.cpp=.o)

OBJFILESPIECEFACTORY=$(CFILESPIECEFACTORY:.cpp=.o)

OBJFILESBOARD=$(CFILESBOARD:.cpp=.o)

OBJFILESPLAYER=$(CFILESPLAYER:.cpp=.o)

OBJFILESAI=$(CFILESAI:.cpp=.o)

OBJFILESSTATE=$(CFILESSTATE:.cpp=.o)

OBJFILESMOVECOMMAND=$(CFILESMOVECOMMAND:.cpp=.o)

OBJFILESGAMEMANAGER=$(CFILESGAMEMANAGER:.cpp=.o)

OBJFILESGAMEMASTER=$(CFILESGAMEMASTER:.cpp=.o)

CPPFLAGS=-g -std=c++11 -fprofile-arcs -ftest-coverage

# add support for C++ (using g++ by default)
.SUFFIXES: .cpp .cpp.gcov
%.o : %.cpp
	g++ $(CPPFLAGS) -c $<

testdice: $(OBJFILESDICE)
	g++ $(CPPFLAGS) $(OBJFILESDICE) -o test

testpath: $(OBJFILESPATH)
	g++ $(CPPFLAGS) $(OBJFILESPATH) -o test

testpiece: $(OBJFILESPIECE)
	g++ $(CPPFLAGS) $(OBJFILESPIECE) -o test

testcell: $(OBJFILESCELL)
	g++ $(CPPFLAGS) $(OBJFILESCELL) -o test

testpathgenerator: $(OBJFILESPATHGENERATOR)
	g++ $(CPPFLAGS) $(OBJFILESPATHGENERATOR) -o test

testpiecefactory: $(OBJFILESPIECEFACTORY)
	g++ $(CPPFLAGS) $(OBJFILESPIECEFACTORY) -o test

testboard: $(OBJFILESBOARD)
	g++ $(CPPFLAGS) $(OBJFILESBOARD) -o test

testplayer: $(OBJFILESPLAYER)
	g++ $(CPPFLAGS) $(OBJFILESPLAYER) -o test

testai: $(OBJFILESAI)
	g++ $(CPPFLAGS) $(OBJFILESAI) -o test

teststate: $(OBJFILESSTATE)
	g++ $(CPPFLAGS) $(OBJFILESSTATE) -o test

testmovecommand: $(OBJFILESMOVECOMMAND)
	g++ $(CPPFLAGS) $(OBJFILESMOVECOMMAND) -o test

testgamemanager: $(OBJFILESGAMEMANAGER)
	g++ $(CPPFLAGS) $(OBJFILESGAMEMANAGER) -o test

testmaster: $(OBJFILESMASTER)
	g++ $(CPPFLAGS) $(OBJFILESMASTER) -o test

%.cpp.gcov: %.cpp
	gcov $<
	
covdice: $(CFILESDICE:.cpp=.cpp.gcov)
	-rm -f stl_*.h.gcov iostream.gcov basic_string.h.gcov *.tcc.gcov new.gcov

covpath: $(CFILESPATH:.cpp=.cpp.gcov)
	-rm -f stl_*.h.gcov iostream.gcov basic_string.h.gcov *.tcc.gcov new.gcov

covpiece: $(CFILESPIECE:.cpp=.cpp.gcov)
	-rm -f stl_*.h.gcov iostream.gcov basic_string.h.gcov *.tcc.gcov new.gcov

covcell: $(CFILESCELL:.cpp=.cpp.gcov)
	-rm -f stl_*.h.gcov iostream.gcov basic_string.h.gcov *.tcc.gcov new.gcov

covpathgenerator: $(CFILESPATHGENERATOR:.cpp=.cpp.gcov)
	-rm -f stl_*.h.gcov iostream.gcov basic_string.h.gcov *.tcc.gcov new.gcov

covpiecefactory: $(CFILESPIECEFACTORY:.cpp=.cpp.gcov)
	-rm -f stl_*.h.gcov iostream.gcov basic_string.h.gcov *.tcc.gcov new.gcov

covboard: $(CFILESBOARD:.cpp=.cpp.gcov)
	-rm -f stl_*.h.gcov iostream.gcov basic_string.h.gcov *.tcc.gcov new.gcov

covplayer: $(CFILESPLAYER:.cpp=.cpp.gcov)
	-rm -f stl_*.h.gcov iostream.gcov basic_string.h.gcov *.tcc.gcov new.gcov

covai: $(CFILESAI:.cpp=.cpp.gcov)
	-rm -f stl_*.h.gcov iostream.gcov basic_string.h.gcov *.tcc.gcov new.gcov

covstate: $(CFILESSTATE:.cpp=.cpp.gcov)
	-rm -f stl_*.h.gcov iostream.gcov basic_string.h.gcov *.tcc.gcov new.gcov

covmovecommand: $(CFILESMOVECOMMAND:.cpp=.cpp.gcov)
	-rm -f stl_*.h.gcov iostream.gcov basic_string.h.gcov *.tcc.gcov new.gcov

covgamemanager: $(CFILESGAMEMANAGER:.cpp=.cpp.gcov)
	-rm -f stl_*.h.gcov iostream.gcov basic_string.h.gcov *.tcc.gcov new.gcov

covmaster: $(CFILESMASTER:.cpp=.cpp.gcov)
	-rm -f stl_*.h.gcov iostream.gcov basic_string.h.gcov *.tcc.gcov new.gcov

clean:
	rm -f a.out *.o test *.gcda *.gch *.gcno *.bbg *.gcov *~

depend:
	sed -n '1,/^##DEPENDENCIES##/p' <Makefile >Makefile.bak
	gcc -MM $(CPPFLAGS) $(CFILESDICE) | cat Makefile.bak - >Makefile
	-rm -f Makefile.bak

##DEPENDENCIES##
RollDice.o: RollDice.cpp RollDice.h
RollDiceTestBed.o: RollDiceTestBed.cpp
Personality.o: Personality.h
Coordinate.o: Coordinate.h Coordinate.cpp
GameType.o: GameType.h
Path.o: Path.cpp Path.h
PathTestBed.o: PathTestBed.cpp
Piece.o: Piece.cpp Piece.h
PieceTestBed.o: PieceTestBed.cpp
Cell.o: Cell.cpp Cell.h
CellTestBed.o: CellTestBed.cpp
PathGenerator.o: PathGenerator.h PathGenerator.cpp
PathGeneratorTestBed.o: PathGeneratorTestBed.cpp
PieceFactory.o: PieceFactory.cpp PieceFactory.h
PieceFactoryTestBed.o: PieceFactoryTestBed.cpp
Board.o: Board.cpp Board.h
BoardTestBed.o: BoardTestBed.cpp
Player.o: Player.cpp Player.h
PlayerTestBed.o: PlayerTestBed.cpp
AI.o: AI.cpp AI.h
AITestBed.o: AITestBed.cpp
State.o: State.cpp State.h
StateTestBed.o: StateTestBed.cpp
Command.o: Command.h
MoveCommand.o: MoveCommand.cpp MoveCommand.h
MoveCommandTestBed: MoveCommandTestBed.h
GameManager.o: GameManager.cpp GameManager.h
GameManagerTestBed.o: GameManagerTestBed.cpp