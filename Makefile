CXX = g++
CXXFLAGS = -g -Wall -std=c++17
INCLUDE = -I./
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system
OBJS = main.o src/clock_counter.o src/game_object.o src/game.o src/keyboard.o src/moving_object.o src/player.o src/ship.o src/window.o lib/cpu.o lib/debug.o lib/semaphore.o lib/system.o lib/thread.o src/main_screen.o src/bullet.o

all: main

main: $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o main $(OBJS) $(SFML_LIBS)

main.o: main.cc
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c main.cc -o main.o

src/clock_counter.o: src/clock_counter.cc headers/clock_counter.h
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c src/clock_counter.cc -o src/clock_counter.o

src/game_object.o: src/game_object.cc headers/game_object.h
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c src/game_object.cc -o src/game_object.o

src/game.o: src/game.cc headers/game.h
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c src/game.cc -o src/game.o

src/keyboard.o: src/keyboard.cc headers/keyboard.h
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c src/keyboard.cc -o src/keyboard.o

src/moving_object.o: src/moving_object.cc headers/moving_object.h
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c src/moving_object.cc -o src/moving_object.o

src/player.o: src/player.cc headers/player.h
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c src/player.cc -o src/player.o

src/ship.o: src/ship.cc headers/ship.h
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c src/ship.cc -o src/ship.o

src/window.o: src/window.cc headers/window.h
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c src/window.cc -o src/window.o

src/main_screen.o: src/main_screen.cc headers/main_screen.h
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c src/main_screen.cc -o src/main_screen.o

src/bullet.o: src/bullet.cc headers/bullet.h
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c src/bullet.cc -o src/bullet.o

lib/%.o: lib/%.cc lib/%.h
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f *.o src/*.o lib/*.o main
