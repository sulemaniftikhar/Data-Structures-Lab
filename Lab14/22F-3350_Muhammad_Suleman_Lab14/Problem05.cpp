//#include <iostream>
//#include <cassert>
//#include <string>
//#include <fstream>
//#include <sstream>
//
//using namespace std;
//
//template <class v>
//struct HashItem
//{
//	int key;
//	v value;
//	short status;   // 0: Empty, 1: Occupied, -1: Deleted
//};
//
//template <class v>
//class HashMap
//{
//public:
//	HashItem<v>* hashArray;
//	int capacity;
//	int currentElements;
//	double loadFactorThreshold = 0.75;
//
//	void doubleCapacity();
//	virtual int getNextCandidateIndex(int key, int i);
//
//public:
//	HashMap()
//		: HashMap(10) {}
//	HashMap(int const capacity);
//	void insert(int const key, v const value);
//	bool deleteKey(int const key);
//	v* get(int const key);
//	~HashMap();
//};
//
//template <class v>
//HashMap<v>::HashMap(int const capacity)
//{
//	assert(capacity > 1 && "Capacity must be greater than 1");
//	this->capacity = capacity;
//	hashArray = new HashItem<v>[capacity]();
//	currentElements = 0;
//}
//
//template <class v>
//void HashMap<v>::doubleCapacity()
//{
//	int oldCapacity = capacity;
//	HashItem<v>* oldArray = hashArray;
//
//	capacity *= 2;
//	hashArray = new HashItem<v>[capacity]();
//
//	for (int i = 0; i < oldCapacity; ++i)
//	{
//		if (oldArray[i].status == 1)
//		{
//			int key = oldArray[i].key;
//			v value = oldArray[i].value;
//			insert(key, value);
//		}
//	}
//
//	delete[] oldArray;
//}
//
//template <class v>
//int HashMap<v>::getNextCandidateIndex(int key, int i)
//{
//	return (key + i) % capacity;
//}
//
//template <class v>
//void HashMap<v>::insert(int const key, v const value)
//{
//	if (currentElements >= loadFactorThreshold * capacity)
//	{
//		doubleCapacity();
//	}
//
//	int i = 0;
//	int index = key % capacity;
//	while (i < capacity)
//	{
//		if (hashArray[index].status != 1)
//		{
//			hashArray[index].key = key;
//			hashArray[index].value = value;
//			hashArray[index].status = 1;  // Mark as occupied
//			currentElements++;
//			return;
//		}
//		i++;
//		index = getNextCandidateIndex(key, i);
//	}
//	cout << "Hash Table is full, Cannot insert" << endl;
//}
//
//template <class v>
//bool HashMap<v>::deleteKey(int const key)
//{
//	int i = 0;
//	int index = key % capacity;
//	while (i < capacity && (hashArray[index].status == 1 || hashArray[index].status == -1))
//	{
//		if (hashArray[index].status == 1 && hashArray[index].key == key)
//		{
//			hashArray[index].status = -1;  // Mark as deleted
//			currentElements--;
//			return true;
//		}
//		i++;
//		index = getNextCandidateIndex(key, i);
//	}
//	return false;
//}
//
//template <class v>
//v* HashMap<v>::get(int const key)
//{
//	int i = 0;
//	int index = key % capacity;
//	while (i < capacity && (hashArray[index].status == 1 || hashArray[index].status == -1))
//	{
//		if (hashArray[index].status == 1 && hashArray[index].key == key)
//		{
//			return &(hashArray[index].value);
//		}
//		i++;
//		index = getNextCandidateIndex(key, i);
//	}
//	return nullptr;  // Key not found or table is full
//}
//
//template <class v>
//HashMap<v>::~HashMap()
//{
//	delete[] hashArray;
//}
//
//void populateHash(string filename, HashMap<string> *hash)
//{
//	ifstream dataFile(filename);
//	if (!dataFile)
//	{
//		cout << "Not able to open " << filename << endl;
//		return;
//	}
//
//	string line;
//	while (getline(dataFile, line))
//	{
//		istringstream iss(line);
//		string id, name;
//		if (iss >> id >> name)
//		{
//			hash->insert(stoi(id), name);
//		}
//	}
//	dataFile.close();
//}
//
//template <class v>
//class QHashMap : public HashMap<v>
//{
//private:
//	virtual int getNextCandidateIndex(int key, int i) override
//	{
//		return (key + (i*i)) % capacity; // Adding square of i
//	}
//public:
//	HashMap<v>::HashMap;
//};
//
//
//template <class v>
//class DHashMap : public HashMap<v>
//{
//private:
//	virtual int getNextCandidateIndex(int key, int i) override
//	{
//		int prime = 5;
//		int first_value = key % capacity;
//		int second_value = (prime - (key % prime));
//		return (first_value + i * second_value) % capacity; // Double hashing
//	}
//
//public:
//	HashMap<v>::HashMap;
//};
//
//int main()
//{
//	HashMap<string> *map;
//	map = new HashMap<string>;
//	populateHash("students.txt", map);
//	cout << *map->get(9);
//	map->deleteKey(9);
//	assert(map->get(9) == nullptr);
//	delete map;
//	cout << endl;
//
//	map = new QHashMap<string>;
//	populateHash("students.txt", map);
//	cout << *map->get(98);
//	map->deleteKey(98);
//	assert(map->get(98) == nullptr);
//	delete map;
//	cout << endl;
//
//
//	map = new DHashMap<string>;
//	populateHash("students.txt", map);
//	cout << *map->get(101);
//	map->deleteKey(101);
//	assert(map->get(101) == nullptr);
//	delete map;
//	cout << endl;
//
//	system("pause");
//	return 0;
//}