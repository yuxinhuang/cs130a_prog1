//Hash_2.h
#ifndef HASH_2_H
#define HASH_2_H

#include <list>
#include <string>
#include <vector>

class HashTable{

	public:
		HashTable(size_t size);
		void insert(std::string ip); //insert 
		void remove(std::string ip); //delete 
		bool exists(std::string ip); //check if the ip address exists
		void print(); //stat
		 
		std::string convertip(std::string ip); 
		std::string convertToBin(int num); //convert an 8 bit binary
		int Prime(int num);
		bool isPrime(int num);
		int convertToDec(std::string num);//convert to a decimal
		//void setcoef(int b, int k); //set coeffeicent of hash function
 
	private:
		std::vector<std::list<std::string> > table ;
		size_t hash(std::string name); //hash function that will output the index of the function;
		size_t size; //the size of the hashtable
		std::vector<int> a; //coeff
		void setcoef(int b, int k); //set coeffeicent of hash function
		//int prime[33]={0,3,5,11,17,37,67,131,257,521,1031,2053,4099,8209,16411,32771,65537,131101,262147,524309,}; //prime 2^1 to 2^32, but for convenience start from prime[1]
		int sucins; //successfully inserted
		int sucdel; //successfully deleted
		//std::vector<size_t> collision; //number of items in each list
		int b;
		int k;
		std::vector<size_t> max;


};

#endif 