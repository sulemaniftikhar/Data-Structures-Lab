#include <iostream>
#include <string>

using namespace std;

struct Node
{
    int key;
    Node *next;
};
// Re-Hashing
class Rehashing
{
private:
    int size;
    Node **table;

public:
    Rehashing(int size)
        : size(size)
    {
        table = new Node *[size];
        for (int i = 0; i < size; i++)
        {
            table[i] = nullptr;
        }
    }

    int hashFunc(int key)
    {
        return key % size;
    }

    void insert(int key)
    {
        int index = hashFunc(key);
        Node *newNode = new Node();
        newNode->key = key;
        newNode->next = nullptr;

        if (table[index] == nullptr)
        {
            table[index] = newNode;
        }
        else
        {
            Node *curr = table[index];
            while (curr->next != nullptr)
            {
                curr = curr->next;
            }
            curr->next = newNode;
        }
    }

    void remove(int key)
    {
        int index = hashFunc(key);
        Node *curr = table[index];
        Node *prev = nullptr;

        while (curr != nullptr && curr->key != key)
        {
            prev = curr;
            curr = curr->next;
        }

        if (curr == nullptr)
        {
            return;
        }

        if (prev == nullptr)
        {
            table[index] = curr->next;
        }
        else
        {
            prev->next = curr->next;
        }

        delete curr;
    }

    bool search(int key)
    {
        int index = hashFunc(key);
        Node *curr = table[index];

        while (curr != nullptr)
        {
            if (curr->key == key)
            {
                return true;
            }
            curr = curr->next;
        }
        return false;
    }
};

// Double-Hashing
class DoubleHashing
{
private:
    int size;
    int *table;
    bool *isOccupied;

public:
    DoubleHashing(int size)
        : size(size)
    {
        table = new int[size];
        isOccupied = new bool[size];
        for (int i = 0; i < size; i++)
        {
            table[i] = -1;
            isOccupied[i] = false;
        }
    }

    int hashFunc1(int key)
    {
        return key % size;
    }

    int hashFunc2(int key)
    {
        return 3 - (key % 3);
    }

    void insert(int key)
    {
        int index = hashFunc1(key);
        int step = hashFunc2(key);

        while (isOccupied[index])
        {
            index = (index + step) % size;
        }

        table[index] = key;
        isOccupied[index] = true;
    }

    void remove(int key)
    {
        int index = hashFunc1(key);
        int step = hashFunc2(key);

        while (table[index] != -1)
        {
            if (table[index] == key)
            {
                table[index] = -1;
                isOccupied[index] = false;
                return;
            }
            index = (index + step) % size;
        }
    }

    bool search(int key)
    {
        int index = hashFunc1(key);
        int step = hashFunc2(key);

        while (table[index] != -1)
        {
            if (table[index] == key)
            {
                return true;
            }
            index = (index + step) % size;
        }
        return false;
    }
};

// Bucketing
class Bucketing
{
private:
    int size;
    Node **table;

public:
    Bucketing(int size)
        : size(size)
    {
        table = new Node *[size];
        for (int i = 0; i < size; i++)
        {
            table[i] = nullptr;
        }
    }

    int hashFunc(int key)
    {
        return key % size;
    }

    void insert(int key)
    {
        int index = hashFunc(key);
        Node *newNode = new Node();
        newNode->key = key;
        newNode->next = nullptr;

        if (table[index] == nullptr)
        {
            table[index] = newNode;
        }
        else
        {
            Node *curr = table[index];
            while (curr->next != nullptr)
            {
                curr = curr->next;
            }
            curr->next = newNode;
        }
    }

    void remove(int key)
    {
        int index = hashFunc(key);
        Node *curr = table[index];
        Node *prev = nullptr;

        while (curr != nullptr && curr->key != key)
        {
            prev = curr;
            curr = curr->next;
        }

        if (curr == nullptr)
        {
            return;
        }

        if (prev == nullptr)
        {
            table[index] = curr->next;
        }
        else
        {
            prev->next = curr->next;
        }

        delete curr;
    }

    bool search(int key)
    {
        int index = hashFunc(key);
        Node *curr = table[index];

        while (curr != nullptr)
        {
            if (curr->key == key)
            {
                return true;
            }
            curr = curr->next;
        }
        return false;
    }
};

void searchAndPrint(int val, bool found)
{
    cout << "Search result for " << val << ": ";
    if (found)
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }
}

int main()
{
    // Rehashing
    Rehashing reHash(10);
    reHash.insert(5);
    reHash.insert(15);
    reHash.insert(25);

    cout << "HashTable-Rehashing: " << endl;
    searchAndPrint(5, reHash.search(5));
    searchAndPrint(15, reHash.search(15));
    searchAndPrint(25, reHash.search(25));

    reHash.remove(15);
    searchAndPrint(15, reHash.search(15));

    // DoubleHashing
    DoubleHashing doubleHash(10);
    doubleHash.insert(5);
    doubleHash.insert(15);
    doubleHash.insert(25);

    cout << "\nHashTable-DoubleHashing: " << endl;
    searchAndPrint(5, doubleHash.search(5));
    searchAndPrint(15, doubleHash.search(15));
    searchAndPrint(25, doubleHash.search(25));

    doubleHash.remove(15);
    searchAndPrint(15, doubleHash.search(15));

    // Bucketing
    Bucketing Bucketing(10);
    Bucketing.insert(5);
    Bucketing.insert(15);
    Bucketing.insert(25);

    cout << "\nHashTable-Bucketing: " << endl;
    searchAndPrint(5, Bucketing.search(5));
    searchAndPrint(15, Bucketing.search(15));
    searchAndPrint(25, Bucketing.search(25));

    Bucketing.remove(15);
    searchAndPrint(15, Bucketing.search(15));

    return 0;
}