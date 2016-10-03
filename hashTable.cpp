#include "keyData.h"
#include "hashTable.h"
#include <vector>
#include <string>
#include <list>
#include <iostream>

bool DEBUG = false;

hashTable::hashTable(int startMaxSize){
	myHashTable.resize(startMaxSize);
	maxContentSize = startMaxSize;
}

void hashTable::insert(std::string key, std::string data){
	keyData newKeyDatapair = keyData(key,data);
	int hash = hashTable::hashingFunct(key);
	myHashTable[hash].push_back(newKeyDatapair);
	size++;
}

bool hashTable::remove(std::string key){
	int hash = hashTable::hashingFunct(key);
	for(std::list<keyData>::iterator itr=myHashTable[hash].begin(); itr != myHashTable[hash].end(); itr++){
		if(itr->getKey() == key){
			myHashTable[hash].erase(itr);
			size--;
			return true;
		}
	}
	return false;
}

std::string hashTable::retrieve(std::string key){
	int hash = hashingFunct(key);
	for(std::list<keyData>::iterator itr=myHashTable[hash].begin(); itr != myHashTable[hash].end(); itr++){
		if(itr->getKey() == key){
				return itr->getData();
			}
	}
}


int hashTable::hashingFunct(std::string key){
	int sum = 0;
	for(int x = 0; x < key.size(); x++){
		sum += (int)key[x];
	}
	if(DEBUG){std::cout << "DEBUG: hashFunct->sum = " << sum % 87 << std::endl;}
	return sum % 87;
}

float hashTable::currentLoadFactor(){
	float loadFact = ((float)size/(float)maxContentSize);
	if(DEBUG){std::cout << "DEBUG: size = " << size << ", maxContentSize = " << maxContentSize << std::endl;}
	return loadFact;
}

int hashTable::currentSize(){
	return size;
}