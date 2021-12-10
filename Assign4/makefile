CC = g++ -std=c++11
exe_file = test
$(exe_file): Linked_List.o test.o
	$(CC) Linked_List.o test.o -o $(exe_file)
Linked_List.o: Linked_List.cpp
	$(CC) -c Linked_List.cpp
test.o: test.cpp
	$(CC) -c test.cpp


clean:
	rm -f *.out *.o $(exe_file)