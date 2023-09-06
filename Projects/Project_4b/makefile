CXX = g++
CXXFLAGS = -Wall

proj4: proj4.cpp Game.o Area.o Entity.o Terran.o Zerg.o Marine.o Ghost.o Battlecruiser.o Zergling.o Mutalisk.o Hydralisk.o
	$(CXX) $(CXXFLAGS) Game.o Area.o Entity.o Terran.o Zerg.o Marine.o Ghost.o Battlecruiser.o Zergling.o Mutalisk.o Hydralisk.o proj4.cpp -o proj4
Game.o: Game.h Game.cpp Area.o Entity.o Terran.o Zerg.o Marine.o Ghost.o Battlecruiser.o Zergling.o Mutalisk.o Hydralisk.o
	$(CXX) $(CXXFLAGS) -c Game.cpp
Area.o: Area.h Area.cpp
	$(CXX) $(CXXFLAGS) -c Area.cpp
Hydralisk.o: Hydralisk.h Hydralisk.cpp Zerg.o Entity.o
	$(CXX) $(CXXFLAGS) -c Hydralisk.cpp
Mutalisk.o: Mutalisk.h Mutalisk.cpp Zerg.o Entity.o
	$(CXX) $(CXXFLAGS) -c Mutalisk.cpp
Zergling.o: Zergling.h Zergling.cpp Zerg.o Entity.o
	$(CXX) $(CXXFLAGS) -c Zergling.cpp
Battlecruiser.o: Battlecruiser.h Battlecruiser.cpp Terran.o Entity.o
	$(CXX) $(CXXFLAGS) -c Battlecruiser.cpp
Ghost.o: Ghost.h Ghost.cpp Terran.o Entity.o
	$(CXX) $(CXXFLAGS) -c Ghost.cpp
Marine.o: Marine.h Marine.cpp Terran.o Entity.o
	$(CXX) $(CXXFLAGS) -c Marine.cpp
Zerg.o: Zerg.h Zerg.cpp Entity.o
	$(CXX) $(CXXFLAGS) -c Zerg.cpp
Terran.o: Terran.h Terran.cpp Entity.o
	$(CXX) $(CXXFLAGS) -c Terran.cpp
Entity.o: Entity.h Entity.cpp
	$(CXX) $(CXXFLAGS) -c Entity.cpp
