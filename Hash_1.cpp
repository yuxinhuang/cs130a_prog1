//1_Hash.cpp
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
	
}      

void HashTable::setcoef(int a1,int a2,int a3,int a4){
	a.push_back(a1);
	a.push_back(a2);
	a.push_back(a3);
	a.push_back(a4);
	return;
}
size_t HashTable::hash(string ip){
	//cout<<"hellp in hash"<<endl;

	setcoef(162,210,89,10);
	//cout<<"hellp in hash"<<endl;
	std::istringstream iss(ip);
	std::string byte;
	size_t accumulator=0;
	std::vector<int> address;
	int ind =0; //index of coef
	while (getline(iss,byte,'.')){

		int i_byte=stoi(byte);
		address.push_back(i_byte);
		accumulator+=a[ind]*address[ind];
		ind++;
	}
	//for (size_t i=0; i<address.size();i++){
	//	cout<<address[i]<<endl;
	//}
	return accumulator % (257);


}
void HashTable::insert(string ip){
	//cout<<"hi in insert"<<endl;
	if (exists(ip)){
		//cout<<"hi in insert haha"<<endl;
		cout<<"Error : could not insert "<<ip<<" because it exists."<<endl;
		return;
	}
	//cout<<"hi in insert"<<endl;
	size_t index=hash (ip);
	max[index]++;
	table[index].push_back(ip);
	this->sucins++;
	return;

}     

void HashTable::remove(string ip){
	if (!exists(ip)){
		cout<<"Error : could not delete "<<ip<<" because it does not exists."<<endl;
		return;
	}
	size_t index=hash (ip);
	for (list<string>::iterator p = table[index].begin(); p!=table[index].end(); p++){
		if (ip.compare(*p)==0){
			table[index].erase(p);
			this->sucdel++;
			//this->collision[index]--;
			return;
		}
	}
	return;
}

bool HashTable::exists(string ip){
	//cout<<"hi in exists"<<endl;
	size_t index=hash(ip);
	//cout<<"hi in exists"<<endl;
	if (table[index].empty()){
		return false;
	}
	for (list<string>::iterator p = table[index].begin(); p!=table[index].end(); p++){
		//cout<<"hi in exists before  "<<endl;
		if (ip.compare(*p)==0){

			return true;
		}
	}
	//cout<<"hi in exists after "<<endl;
	
	return false;
}

void HashTable::print(){
	for (int i=3;i>=0;i--){
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
		/*
		if (table[i].size()>=maxsize){
			maxsize=table[i].size();
			maxindex=i;
		}
		*/
		
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