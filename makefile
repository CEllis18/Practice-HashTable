myHash: keyData.o hashTable.o main.o
	g++ -o myHash keyData.o hashTable.o main.o -std=c++11

keyData.o: keyData.cpp
	g++ -c keyData.cpp -std=c++11
	
hashTable.o: hashTable.cpp keyData.h
	g++ -c hashTable.cpp -std=c++11
	
main.o: hashTable.o main.cpp
	g++ -c main.cpp -std=c++11
	
clean:
	rm *.o myHash
