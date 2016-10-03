#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "keyData.h"
#include <vector>
#include <string>
#include <list>

class hashTable{
	public:
		hashTable(int startMaxSize);
		void insert(std::string key, std::string data);
		bool remove(std::string key);
		std::string retrieve(std::string key);
		int hashingFunct(std::string key);
		float currentLoadFactor();
		int currentSize();
	
	
	private:
		std::vector<std::list<keyData> > myHashTable;
		int size = 0;
		int maxContentSize = 0;
		
};




#endif