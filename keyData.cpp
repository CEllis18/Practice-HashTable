#include "keyData.h"

#include <string>

std::string keyData::getKey(){
	//return keyData.keyDataPair.key;
	return entry.key;
}

std::string keyData::getData(){
	return this->entry.data;
}

//class constructor
keyData::keyData(std::string newKey, std::string newData){
	entry.key = newKey;
	entry.data = newData;
}