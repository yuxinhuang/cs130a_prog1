//main_2.cpp
#include <iostream>
#include <sstream>
#include <fstream>
#include "Hash_2.h"
using namespace std;
int main(){
	
	std::string size;
	std::string key;
	std::string ip;

	//std::cout<<"hi"<<std::endl;

	std::cin>>size;
	
	//std::cout<<size<<std::endl;

//std::cout<<"hi"<<std::endl;

	
	HashTable ht(stoi(size));
	//ht.setcoef(8,4);
	
	//ht.insert("121.180.184.61");


	//ht.setcoef(162,210,89,10);
	//std::cout<<"hi"<<std::endl;
	

	while(!cin.eof()){
		//std::cout<<"hi"<<std::endl;

		std::cin>>key;
		//std::cout<<"hi1"<<std::endl;
		
		if (key=="insert"){
			//std::cout<<"hi1"<<std::endl;
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
			//std::cout<<"hi1"<<std::endl;
			return 0;
		}
		
	}

	return 0;
}