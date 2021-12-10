CC = g++ -std=c++11
exe_file = prog
$(exe_file): pokemon.o pokedex.o prog.o
	$(CC) pokemon.o pokedex.o prog.o -o $(exe_file)
pokemon.o: pokemon.cpp
	$(CC) -c pokemon.cpp
pokedex.o: pokedex.cpp
	$(CC) -c pokedex.cpp
prog.o: prog.cpp
	$(CC) -c prog.cpp

clean:
	rm -f *.out *.o $(exe_file)

# prog:
# 	g++ -std=c++11 pokemon.cpp pokedex.cpp prog.cpp -o prog
# clean:
# 	rm -f *.out *.o prog