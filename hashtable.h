#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "linkedlist.h"
#include "DSString.h"
#include "variable.h"
#include "functional"
#include <iostream>
#include <stdexcept>
using namespace std;

template <class K, class V>
class HashNode
{
protected:
    K key;
    V value;
    HashNode<K,V>* next;

public:
    HashNode<K,V>(K& k, V& v)
    {
        key=k;
        value=v;
        next=NULL;
    }

    K getKey()
    {
        return key;
    }

    V getValue()
    {
        return value;
    }

    void setValue(V val)
    {
        HashNode<K,V>::value=val;
    }

    void incrementValue()
    {
        value++;
    }

    HashNode* getNext()
    {
        return next;
    }

    void setNext(HashNode* n)
    {
        HashNode<K,V>::next=n;
    }
};

template <class K, class V>
class HashTable
{
public:
    HashTable(); //Constructor
    HashTable(int); //Constructor with given length
    void insert(K&,V); //Insert new item into Hash Table
    void incrementValue(K&);
    int getLength(); //Returns number of spots in Hash Table
    V getItemByKey(K&); //Returns an item from Hash Table by key
    ~HashTable(); //Destructor


private:
    int length;
    HashNode<K,V>** hashTable;
};


//Constructor
template <class K, class V>
HashTable<K,V>::HashTable()
{
    hashTable = nullptr;
    length = 0;

}

//Constructor with given length
template <class K, class V>
HashTable<K,V>::HashTable(int l)
{
    length = l;
    hashTable = new HashNode<K,V>*[length];
    for(int i=0; i<length; i++)
    {
        hashTable[i] = NULL;
    }

}

//Insert new item into Hash Table
template <class K, class V>
void HashTable<K,V>::insert(K& k, V v)
{
    size_t val1 = hash<char>{}(k[0]);
    size_t val2 = hash<char>{}(k[1]);
    size_t val3 = hash<char>{}(k[3]);
    size_t val = val1 + val2 + val3;
    HashNode<K,V>* e = hashTable[val];
    HashNode<K,V>* prev = NULL;
    //Something at that hash location
    if(e != NULL)
    {
        //Increase value at that location (key)
        e->incrementValue();
    }
    //Nothing at that hash location
    if(e == NULL)
    {
        //Make new hash node
        e = new HashNode<K,V>(k,v);
        if(prev == NULL)
        {
            hashTable[val] = e;
        }
        else
        {
            prev->setNext(e);
        }
    }

}

//Increment value of specified key
template <class K, class V>
void HashTable<K,V>::incrementValue(K& k)
{
    int hashIndex1 = hash<char>{}(k[0]);
    int hashIndex2 = hash<char>{}(k[1]);
    int hashIndex3 = hash<char>{}(k[2]);
    int hashIndex = hashIndex1 + hashIndex2 + hashIndex3;
    int oldVal = hashTable[hashIndex]->getValue();
    hashTable[hashIndex1]->setValue(oldVal++);

}

//Returns number of spots in Hash Table
template <class K, class V>
int HashTable<K,V>::getLength()
{
    return length;

}

//Returns an item from Hash Table by key
template <class K, class V>
V HashTable<K,V>::getItemByKey(K& k)
{
    int hashIndex = hash<char>{}(k[0]);

    if (hashTable[hashIndex] == NULL)
        return -1;
    else
        return hashTable[hashIndex]->getValue();

}

//Destructor
template <class K, class V>
HashTable<K,V>::~HashTable()
{
    for (int i=0; i<length; i++)
    {
        HashNode<K,V>* entry = hashTable[i];
        while (entry != NULL)
        {
            HashNode<K, V>* prev = entry;
            entry = entry->getNext();
            delete prev;
        }
        hashTable[i] = NULL;
    }

    delete [] hashTable;

}

#endif // HASHTABLE_H
