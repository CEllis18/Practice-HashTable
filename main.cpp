#include "hashTable.h"
#include <iostream>
#include <string>

/*
Basic first attempt at a hashTable
Currently keeps track of loadfactor, but is not self resizing when load factor exceeds 0.5 (TODO)
ACCORDING TO CLRS, USE a prime number as the other part for the hash function? so maybe 89 instead
so maybe just sum and mod by 89? (prime number)

ideally: choose a number like this

suppose we dont mind examining an average of 3 elements in an unsuccessful search
we will have approximately 2000 pieces of data to store
we make the hash table size of 701 because its a prime number near 2000/3 but not near any power of 2000
h(k) = k mod 701

also review double hashing etc in the book around pg 275

*/


int main(){
	std::cout << "Program Start" << std::endl;
	
	hashTable testHashTable = hashTable(1000);
	testHashTable.insert("Gundam","RX-79");
	testHashTable.insert("ArmSlave", "Leviatean");
	std::cout << "key=Gundam, corresponding data = " << testHashTable.retrieve("Gundam") << std::endl;
	testHashTable.insert("dddddh","Dutchess");
	std::cout << "key=dddddh, corresponding data = " << testHashTable.retrieve("dddddh") << std::endl;
	std::cout << "key=ArmSlave, corresponding data = " << testHashTable.retrieve("ArmSlave") << std::endl;
	bool test = testHashTable.remove("dddddh");
	std::cout << "removing dddddh was: " << test << " note: 1 = true" << std::endl;
	bool test2 = testHashTable.remove("BLARGH");
	std::cout << "removing BLARGH was: " << test2 << " note: 1 = true" << std::endl;
	std::cout << "Current Load Factor = " << testHashTable.currentLoadFactor() << std::endl;
	std::cout << "Current Size = " << testHashTable.currentSize() << std::endl;
	
	
}