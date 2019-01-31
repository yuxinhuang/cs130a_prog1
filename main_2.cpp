//main_2.cpp
//Yuxin Huang 5557277
#include <iostream>
#include <sstream>
#include <fstream>
#include "Hash_2.h"
using namespace std;
int main(){
	
	std::string size;
	std::string key;
	std::string ip;


	std::cin>>size;

	
	HashTable ht(stoi(size));


	while(!cin.eof()){
	
		std::cin>>key;
		
		if (key=="insert"){
		
			std::cin>>ip;
			ht.insert(ip);
			
		}
		
		if (key=="delete"){
			std::cin>>ip;
			ht.remove(ip);
		}
		if (key=="lookup"){
			std::cin>>ip;
			ht.exists(ip);
			if (ht.exists(ip)){
				cout<<ip<<": found."<<endl;
			}else{
				cout<<ip<<": not found."<<endl;
			}
		}
		if (key=="stat"){
			ht.print();
		
			return 0;
		}
		
	}

	return 0;
}
