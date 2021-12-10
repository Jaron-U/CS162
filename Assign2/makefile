CC = g++ -std=c++11
exe_file = prog
$(exe_file): pokemon.o bulbasaur.o charmander.o squirtle.o trainer.o arena.o prog.o
	$(CC) pokemon.o bulbasaur.o charmander.o squirtle.o trainer.o arena.o prog.o -o $(exe_file)
pokemon.o: pokemon.cpp
	$(CC) -c pokemon.cpp
bulbasaur.o: bulbasaur.cpp
	$(CC) -c bulbasaur.cpp
charmander.o: charmander.cpp
	$(CC) -c charmander.cpp
squirtle.o: squirtle.cpp
	$(CC) -c squirtle.cpp
trainer.o: trainer.cpp
	$(CC) -c trainer.cpp
arena.o: arena.cpp
	$(CC) -c arena.cpp
prog.o: prog.cpp
	$(CC) -c prog.cpp

clean:
	rm -f *.out *.o $(exe_file)