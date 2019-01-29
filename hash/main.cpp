#include <iostream>
#include "HashTable.h"

int main(){

	HashTable ht(11);

	ht.insert("matthew");
	ht.insert("alexi");

	ht.print();

	return 0;

}
