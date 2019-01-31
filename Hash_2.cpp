//Hash_2.cpp
//Yuxin Huang, 5557277

#include <iostream>
#include <sstream>
#include <string>
#include <math.h>
#include "Hash_2.h"
#include <stdlib.h>
#include <cmath>
#include <algorithm>
using namespace std;
HashTable::HashTable(size_t size){
	
	this->sucdel=0;
	this->sucins=0;
	this->size=Prime(size);
	table.resize(Prime(size));
	for (size_t i=0; i<this->size;i++){
		max.push_back(0);
	}
	this->b=log(size)/log(2);
	
	
	if (32%b==0){
		this->k=32/b;
	}else{
		this->k= (32/b)+1; //divided into k groups 
	}
	
	this->setcoef(this->b, this->k);
	
}      

bool HashTable::isPrime(int num){
	for (int i=2;i<=pow(num,0.5);i++){
		if ((num%i)==0){
			return false;
		}
	}
	return true;
}
int HashTable::Prime(int num){
	num++; //it has to be larger than itself
	while (!isPrime(num)){
		num++;
	}
	return num;

}
/*
void HashTable::setcoef(){
	a.push_back(9);
	a.push_back(24);
	a.push_back(55);
	a.push_back(9);
	a.push_back(20);
	a.push_back(58);
	//a.push_back(2);
	//a.push_back(13);
}
*/

void HashTable::setcoef(int b, int k){
  int p=Prime(pow(2,b));
	for (int i=0;i<k;i++){
		int coe=rand()%(p); //range from 0 to p-1
		a.push_back(coe);

	}
	return;
}

size_t HashTable::hash(string ip){

	
	int p=Prime(pow(2,b)); //prime p;
	string x[k]; //groups of ip address in decimal
	string ipbin=convertip(ip); //32 bits
	if (32%b==0){
		int acc=0;
		for (int i=k-1;i>=0;i--){
			x[i]=ipbin.substr(acc,b);
			acc+=b;
		}
	}else{
		int msc=32%b; //len of most significant chunk
	
	
		x[k-1]=ipbin.substr(0,msc);
		string ip1=ipbin.substr(msc,32-msc);
		int acc=0;
		for (int i=k-2;i>=0;i--){
			x[i]=ip1.substr(acc,b);
			acc+=b;
		}
	}
	std::vector<int> add;
	
	//int ip add in decimal
	for (int p=0;p<k;p++){
		add.push_back(convertToDec(x[p]));
	}


	size_t accumulator=0;
	for (int j=0;j<k;j++){
		accumulator+=a[j]*add[j];
	}

	return accumulator % p;


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

string HashTable::convertip(string ip){
	std::istringstream iss(ip);
	std::string byte;
	string convert; //a 32 bit ip address
	while (getline(iss,byte,'.')){
		convert+=convertToBin(atoi(byte.c_str())); 
	}
	return convert;

}

string HashTable::convertToBin(int num){ 
	int BinarynumReverse[8]={0,0,0,0,0,0,0,0};
	int Binarynum[8];
	int i=0;
	while (num>0){
		BinarynumReverse[i]=num%2;
		num=num/2;
		i++;
	}

	int k=0;
	for (int j=7;j>=0;j--){
		Binarynum[k++]=BinarynumReverse[j];  //an 8 bit binary
	}
	string number;
	for (int x=0;x<8;x++){
		number+=to_string(Binarynum[x]);
	}
	return number;

}
int HashTable::convertToDec(std::string num){
	int num1=atoi(num.c_str());

	int base=1;
	int result=0;
	while(num1){
		int last_digit=num1%10;
		num1=num1/10;
		result+=last_digit*base;
		base=base*2;

	}
	return result;
	

}

void HashTable::print(){
	for (size_t i=0;i<a.size();i++){
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
