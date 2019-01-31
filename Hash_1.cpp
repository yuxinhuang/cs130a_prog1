//Hash_1.cpp
//Yuxin Huang 5557277
#include <iostream>
#include <sstream>
#include <string>


#include "Hash_1.h"
using namespace std;
HashTable::HashTable(size_t size){
	this->sucdel=0;
	this->sucins=0;
	this->size=size+1;
	for (size_t i=0; i<size+1;i++){
		max.push_back(0);
	}
	
	table.resize(size+1);
	this->setcoef();
	
}   

void HashTable::setcoef(){
	//a.push_back(10);
	//a.push_back(89);
	//a.push_back(210);
	//a.push_back(162);
	
	for (int i=0;i<4;i++){
		int coe=rand()%(257); 
		a.push_back(coe);
	}
}   

size_t HashTable::hash(string ip){
	std::istringstream iss(ip);
	std::string byte;
	size_t accumulator=0;
	std::vector<int> address;
	int ind =0; //index of coef
	while (getline(iss,byte,'.')){

		int i_byte=atoi(byte.c_str());
		address.push_back(i_byte);
		accumulator+=a[3-ind]*address[ind];
		ind++;
	}
	return accumulator % (257);


}
void HashTable::insert(string ip){

	if (exists(ip)){
		cout<<"Error : could not insert "<<ip<<" because it exists."<<endl;
		return;
	}
	size_t index=hash (ip);
	max[index]++;
	table[index].push_back(ip);
	this->sucins++;
	return;

}     

void HashTable::remove(string ip){
	if (!exists(ip)){
		cout<<"Error : could not delete "<<ip<<" because it does not exist."<<endl;
		return;
	}
	size_t index=hash (ip);
	for (list<string>::iterator p = table[index].begin(); p!=table[index].end(); p++){
		if (ip.compare(*p)==0){
			table[index].erase(p);
			this->sucdel++;
	        
			return;
		}
	}
	return;
}

bool HashTable::exists(string ip){

	size_t index=hash(ip);

	if (table[index].empty()){
		return false;
	}
	for (list<string>::iterator p = table[index].begin(); p!=table[index].end(); p++){
	
		if (ip.compare(*p)==0){

			return true;
		}
	}

	
	return false;
}

void HashTable::print(){
	for (int i=0;i<4;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;//print out the coef
	cout<<sucins<<endl;
	cout<<sucdel<<endl;
	int emp=0;
	int oneslot=0;
	size_t maxsize=0;
	size_t maxindex=0;
	for (size_t i=0;i<table.size();i++){
		if (table[i].empty()){
			emp++;
		}
		if (table[i].size()==1){
			oneslot++;
		}
	
		
		for (size_t i=0;i<max.size();i++){
			if (max[i]>=maxsize){
				maxsize=max[i];
				maxindex=i;
			}
		}
		
	}
	cout<<emp<<endl;
	cout<<oneslot<<endl;
	cout<<maxsize<<" "<<maxindex<<endl;
	return;


}                                                                                            
