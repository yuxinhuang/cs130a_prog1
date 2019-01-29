//Hash_2.cpp

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
	
	//double x=0.693147;
	this->sucdel=0;
	this->sucins=0;
	this->size=Prime(size);
	table.resize(Prime(size));
	//this->b=int(log(size)/x);
	this->b=8;
	this->k=4;
	setcoef(this->b, this->k);
	/*
	if (32%b==0){
		this->k=32/b;
	}else{
		this->k= (32/b)+1; //divided into k groups 
	}
	*/
	//this->setcoef(this->b, this->k);
	
	
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
void HashTable::setcoef(int b, int k){ 
	for (int i=0;i<k;i++){
		int coe=rand()%(Prime(2^b)); //range from 0 to p-1
		a.push_back(coe);

	}
	return;
}
size_t HashTable::hash(string ip){

	
	int p=Prime(2^b); //prime p;
	string x[k]; //groups of ip address in decimal
	//string x;
	string ipbin=convertip(ip); //32 bits
	int msc=32%b; //len of most significant chunk
	//x+=ipbin.substr(0,msc);
	
	x[k-1]=ipbin.substr(0,msc);
	string ip1=ipbin.substr(msc,32-msc);
	int acc=0;
	for (int i=k-2;i>=0;i--){
		//x+=".";
		//x+=ip1.substr(acc,b);
		x[i]=ip1.substr(acc,b);
		acc+=b;
	}
	std::vector<int> add;
	//string ipn;
	//std::istringstream iss(x);
	//while(getline(iss, ipn, ".")){
	//	add.push_back(stoi(ipn));

	//}
	//int add[k]; 
	//for (int p=0;p<k;p++){
	//	std::istringstream iss(x[p]);
	//	add[p]=stoi(iss);
	//}
	//int ip add in decimal
	for (int p=0;p<k;p++){
		//cout<<"hi"<<endl;
		add.push_back(convertToDec(x[p]));

	}


	//setcoef(162,210,89,10);
	//cout<<"hellp in hash"<<endl;
	size_t accumulator=0;
	for (int j=0;j<k;j++){
		accumulator+=a[j]*add[j];
	}
	
	//for (size_t i=0; i<address.size();i++){
	//	cout<<address[i]<<endl;
	//}
	return accumulator % p;


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

string HashTable::convertip(string ip){
	std::istringstream iss(ip);
	std::string byte;
	string convert; //a 32 bit ip address
	while (getline(iss,byte,'.')){
		convert+=convertToBin(stoi(byte)); 
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
	int num1=stoi(num);
	//cout<<"convert"<<endl;

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
		if (table[i].size()>=maxsize){
			maxsize=table[i].size();
			maxindex=i;
		}
	}
	cout<<emp<<endl;
	cout<<oneslot<<endl;
	cout<<maxsize<<" "<<maxindex<<endl;
	return;


}                                                                                            