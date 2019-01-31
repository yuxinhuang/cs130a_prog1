//Hash_2.h
//Yuxin Huang, 5557277
#ifndef HASH_2_H
#define HASH_2_H

#include <list>
#include <string>
#include <vector>
#include <cstdlib>
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
		
 
	private:
		std::vector<std::list<std::string> > table ;
		size_t hash(std::string ip); //hash function that will output the index of the function;
		size_t size; //the size of the hashtable
		std::vector<int> a; //coeff
		//void setcoef();
		std::vector<size_t> max;
		void setcoef(int b, int k); //set coeffeicent of hash function
	
		int sucins; //successfully inserted
		int sucdel; //successfully deleted
        
		int b;
		int k;
		


};

#endif 
