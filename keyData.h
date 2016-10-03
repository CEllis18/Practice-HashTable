#ifndef KEYDATA_H
#define KEYDATA_H

#include <string>

//still need a retrieval function

struct keyDataPair{
	std::string key;
	std::string data;
};


class keyData{
	public:
		keyData(std::string key, std::string data);
		std::string getKey();
		std::string getData();
	
	private:
		keyDataPair entry;
};

#endif