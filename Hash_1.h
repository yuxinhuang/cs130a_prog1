//1_Hash.h
#ifndef HASH_1_H
#define HASH_1_H

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
		void setcoef(int a1,int a2,int a3,int a4); //set coeffeicent of hash function 

 
	private:
		std::vector<std::list<std::string> > table ;

		size_t hash(std::string name); //hash function that will output the index of the function;
		size_t size; //the size of the hashtable
		std::vector<size_t> max;
		std::vector<int> a; //coeff
		int sucins; //successfully inserted
		int sucdel; //successfully deleted
		//std::vector<size_t> collision; //number of items in each list


};

#endif 