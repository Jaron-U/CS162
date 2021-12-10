CC = g++ -std=c++11
exe_file = prog
$(exe_file): event.o wumpus.o bats.o pit.o gold.o player.o room.o rope.o game.o prog.o
	$(CC) event.o wumpus.o bats.o pit.o gold.o player.o room.o rope.o game.o prog.o -o $(exe_file)
event.o: event.cpp
	$(CC) -c event.cpp
wumpus.o: wumpus.cpp
	$(CC) -c wumpus.cpp
bats.o: bats.cpp
	$(CC) -c bats.cpp
pit.o: pit.cpp
	$(CC) -c pit.cpp
gold.o: gold.cpp
	$(CC) -c gold.cpp
player.o: player.cpp
	$(CC) -c player.cpp
room.o: room.cpp
	$(CC) -c room.cpp
rope.o: rope.cpp
	$(CC) -c rope.cpp	
game.o: game.cpp
	$(CC) -c game.cpp
prog.o: prog.cpp
	$(CC) -c prog.cpp

clean:
	rm -f *.out *.o $(exe_file)