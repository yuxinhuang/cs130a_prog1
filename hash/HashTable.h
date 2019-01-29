#include <list>
#include <string>
#include <vector>

class HashTable{

	public:
		HashTable(int size);
		void insert(std::string name);
		void remove(std::string name);
		bool exists(std::string name);
		void print();

	private:
		std::vector<std::list<std::string>> table;
		int hash(std::string name);
		int size;

};
