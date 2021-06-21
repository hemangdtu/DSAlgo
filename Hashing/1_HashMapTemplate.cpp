// Implement HashMap - Seperate Chaining Technique

#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Node
{
	private:
		// string key;
		// T value;
		// Node<T>* next;

	public:
		string key;
		T value;
		Node<T>* next;

		Node(string key, T val)
		{
			this -> key = key;
			value = val;
			next = NULL;
		}

		~Node()
		{
			if(next != NULL)
				delete next;
		}
};

template<typename T>
class HashTable
{
	private:
		Node<T>** table;	// Pointer to array of pointers
		int currentSize;
		int tableSize;

		int hashFunc(string key)
		{
			int index = 0;
			int p = 1;
			for (int i = 0; i < key.length(); i++)
			{
				index = index + (key[i] * p) % tableSize;
				index = index % tableSize;
				p = (p * 27) % tableSize;
			}
			return index;
		}

	public:
		HashTable(int ts = 7)	// By default the size of table will be 7
		{
			tableSize = ts;
			table = new Node<T>*[tableSize];
			currentSize = 0;
			for (int i = 0; i < tableSize; i++)
				table[i] == NULL;	// Istead of having a Garbage Value we initialize the pointers with NULL
		}

		void insert(string key, T value)
		{
			int index = hashFunc(key);
			Node<T>* n = new Node<T>(key, value);

			n -> next = table[index];	// Insertion at
			table[index] = n;			// HEAD of Linked List
			currentSize++;

			// TODO: Rehashing
		}

		// T search(string key)
		// {
		// 	//
		// }

		// void erase(string key)
		// {
		// 	//
		// }

		void print()
		{
			for (int i = 0; i < tableSize; i++)
			{
				cout << "Bucket " << i << " : ";
				Node<T>* temp = table[i];
				while(temp != NULL)
				{
					cout << temp -> key << " -> ";
					temp = temp -> next;
				}
				cout << "\n";
			}
		}
};

int main()
{
	HashTable<int> priceMenu;
	priceMenu.insert("Coke", 25);
	priceMenu.insert("Burger", 120);
	priceMenu.insert("Pepsi", 20);
	priceMenu.insert("Noodles", 25);
	priceMenu.insert("Samosa", 5);
	priceMenu.print();
	return 0;
}