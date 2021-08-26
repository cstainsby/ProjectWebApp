#pragma once

#ifndef HASH_TABLE_COLLECTION
#define HASH_TABLE_COLLECTION

#include "Collection.h"
#include "ArrayList.h"
#include <functional>

template<typename K, typename V>
class HashTableCollection : public Collection<K, V>
{
public:
    //constructor, destructor, copy constructor, assignment operator respectivly
    HashTableCollection();
    ~HashTableCollection();
    HashTableCollection(const HashTableCollection<K, V>& rhs);
    HashTableCollection& operator=(const HashTableCollection<K, V>& rhs);

    //functions from collection.h 
    void add(const K& a_key, const V& a_val);
    void remove(const K& a_key);
    bool find(const K& search_key, V& the_val) const;
    void find(const K& k1, const K& k2, ArrayList<K>& keys) const;
    void keys(ArrayList<K>& all_keys) const;
    void sort(ArrayList<K>& all_keys_sorted) const;
    size_t size() const;


    //these three functions find the indicated value of the hash table
    size_t min_chain_length();
    size_t max_chain_length();
    double avg_chain_length();


private:
    //the chain
    struct Node {
        K key;
        V value;
        Node* next;
    };

    //the (resizable) has table
    Node** hash_table;

    //number of kv pairs stored in the collection
    size_t length;

    //current number of buckets in the hash table
    size_t table_capacity;

    //load factor of the has table
    double load_factor_threshold = 0.75;

    //double size and rehash the hash table
    void resize_and_rehash();
};

// Constructor
template <typename K, typename V>
HashTableCollection<K, V>::HashTableCollection() : table_capacity(10), length(0), hash_table(nullptr)
{
    //the has table is set to an array that can store up to 10 nodes
    hash_table = new Node * [table_capacity];

    //set every value in hash_table to nullptr
    for (size_t i = 0; i < table_capacity; ++i) {
        hash_table[i] = nullptr;
    }
}

// Destructor
template<typename K, typename V>
HashTableCollection<K, V>::~HashTableCollection()
{
    Node* curr_node;
    Node* next_node;

    //move through the hash table deallocating each node, then delete hash table
    for (size_t i = 0; i < table_capacity; ++i) {
        curr_node = hash_table[i];

        while (curr_node != nullptr) {
            next_node = curr_node->next;
            delete curr_node;
            curr_node = next_node;
        }
        hash_table[i] = nullptr;
    }
    delete[]hash_table;
}

// Copy Constructor
template <typename K, typename V>
HashTableCollection<K, V>::HashTableCollection(const HashTableCollection<K, V>& rhs)
    : table_capacity(10), length(0), hash_table(nullptr)
{
    *this = rhs;
}

// Assignment Operator
template <typename K, typename V>
HashTableCollection<K, V>& HashTableCollection<K, V>::operator=(const HashTableCollection<K, V>& rhs)
{
    //if the current hash table and rhs arent the same, create new hash table  
    if (this != &rhs) {
        delete[]hash_table;

        Node* curr_node;
        Node* next_node;
        length = rhs.length;
        table_capacity = rhs.table_capacity;
        length = 0;
        hash_table = new Node * [table_capacity];

        //fill the new hash table with nullptr
        for (size_t i = 0; i < table_capacity; ++i) {
            hash_table[i] = nullptr;
        }

        //copy all elements from rhs into hash table
        for (size_t i = 0; i < table_capacity; ++i) {
            curr_node = rhs.hash_table[i];
            while (curr_node != nullptr) {
                add(curr_node->key, curr_node->value);
                curr_node = curr_node->next;
            }
        }
    }
    return *this;
}

// Add function
template <typename K, typename V>
void HashTableCollection<K, V>::add(const K& a_key, const V& a_val)
{
    //For our implementation, when adding to the hash table we will mod the value given by
    //the hash functioned key with the table_capacity to find the new index
    //c++ has a generic hash function that we can use 
    std::hash<K> hash_function;
    size_t new_index = hash_function(a_key) % table_capacity;
    Node* new_node;
    new_node = new Node;
    new_node->value = a_val;
    new_node->key = a_key;

    if (avg_chain_length() > load_factor_threshold) {
        resize_and_rehash();
    }

    //if the table is empty, set the new node to the head
    if (hash_table[new_index] == nullptr) {
        hash_table[new_index] = new_node;
        new_node->next = nullptr;
    }
    //else, do the same but move current head back
    else {
        new_node->next = hash_table[new_index];
        hash_table[new_index] = new_node;
    }
    ++length;
}

// Remove function
template <typename K, typename V>
void HashTableCollection<K, V>::remove(const K& a_key)
{
    //We will use the has function and the given key to find the index of the node and remove it
    std::hash<K> hash_function;
    size_t index = hash_function(a_key) % table_capacity;
    Node* curr_node = hash_table[index];
    Node* pre_node;

    while (curr_node != nullptr && curr_node->key != a_key) {
        pre_node = curr_node;
        curr_node = curr_node->next;
    }
    if (hash_table[index] == curr_node) {
        hash_table[index] = nullptr;
    }
    else {
        pre_node->next = curr_node->next;
        curr_node = nullptr;
    }
    --length;
}

// Find single node function
template <typename K, typename V>
bool HashTableCollection<K, V>::find(const K& search_key, V& the_val) const
{
    //We will use the has function and the given key to find the index of the node and remove it
    std::hash<K> hash_function;
    size_t index = hash_function(search_key) % table_capacity;
    Node* curr_node = hash_table[index];

    while (curr_node != nullptr) {
        if (curr_node->key == search_key) {
            the_val = curr_node->value;
            return true;
        }
        curr_node = curr_node->next;
    }
    return false;
}

// Find a range of nodes
template <typename K, typename V>
void HashTableCollection<K, V>::find(const K& k1, const K& k2, ArrayList<K>& keys) const
{
    Node* curr_node;
    //move through each node and if it is within the range add it to the keys list
    for (size_t i = 0; i < table_capacity; ++i) {
        curr_node = hash_table[i];
        while (curr_node != nullptr) {
            if (curr_node->key >= k1 && curr_node->key <= k2) {
                keys.add(curr_node->key);
            }
            curr_node = curr_node->next;
        }
    }
}

// Returns a list of all keys on the hash table
template <typename K, typename V>
void HashTableCollection<K, V>::keys(ArrayList<K>& all_keys) const
{
    Node* curr_node;
    //loop through all keys and add them to an array list
    for (size_t i = 0; i < table_capacity; ++i) {
        curr_node = hash_table[i];
        while (curr_node != nullptr) {
            all_keys.add(curr_node->key);
            curr_node = curr_node->next;
        }
    }
}

// Returns a sorted list of all keys in the list
template <typename K, typename V>
void HashTableCollection<K, V>::sort(ArrayList<K>& all_keys_sorted) const
{
    //use keys function to key all the keys within the list, then sort them
    keys(all_keys_sorted);
    all_keys_sorted.sort();
}

//returns current length of the Hash table array
template <typename K, typename V>
size_t HashTableCollection<K, V>::size() const
{
    return length;
}

//
template <typename K, typename V>
size_t HashTableCollection<K, V>::min_chain_length()
{
    //min chain length is the index with the smallest # of nodes
    size_t smallest_chain;
    size_t curr_chain_size;
    Node* curr_node;

    //set the smallest chain to the first value
    curr_node = hash_table[0];
    while (curr_node != nullptr) {
        ++smallest_chain;
        curr_node = curr_node->next;
    }

    //loop through the rest of the chains and compare
    for (size_t i = 0; i < table_capacity - 1; ++i) {
        curr_node = hash_table[i];
        curr_chain_size = 0;

        while (curr_node != nullptr) {
            ++curr_chain_size;
            curr_node = curr_node->next;
        }
        //if the current chain is now the smallest set it to the smallest chain
        if (curr_chain_size < smallest_chain) {
            smallest_chain = curr_chain_size;
        }
    }
    return smallest_chain;
}

template <typename K, typename V>
size_t HashTableCollection<K, V>::max_chain_length()
{
    //max chain length is the index with the largest # of nodes
    size_t largest_chain;
    size_t curr_chain_size;
    Node* curr_node;

    //set the largest chain to the first value
    curr_node = hash_table[0];
    while (curr_node != nullptr) {
        ++largest_chain;
        curr_node = curr_node->next;
    }

    //loop through the rest of the chains and compare
    for (size_t i = 0; i < table_capacity - 1; ++i) {
        curr_node = hash_table[i];
        curr_chain_size = 0;

        while (curr_node != nullptr) {
            ++curr_chain_size;
            curr_node = curr_node->next;
        }
        //if the current chain is now the smallest set it to the smallest chain
        if (curr_chain_size > largest_chain) {
            largest_chain = curr_chain_size;
        }
    }
    return largest_chain;
}

template <typename K, typename V>
double HashTableCollection<K, V>::avg_chain_length()
{
    //to find the avg chain length divide the # of buckets with > zero elements with # of key value pairs in the collection
    return double(length) / table_capacity;
}

template <typename K, typename V>
void HashTableCollection<K, V>::resize_and_rehash()
{
    //resize the hash table array
    std::hash<K> hash_function;
    size_t new_table_capacity = table_capacity * 2;
    int new_index;
    Node** temp = new Node * [new_table_capacity];
    Node* curr_node;

    //set all values in the new table to nullptr
    for (size_t i = 0; i < new_table_capacity; ++i) {
        temp[i] = nullptr;
    }

    //move through each node stored in the hash table and rehash them into temp
    for (size_t i = 0; i < table_capacity; ++i) {
        curr_node = hash_table[i];
        while (curr_node != nullptr) {
            new_index = hash_function(curr_node->key) % new_table_capacity;
            hash_table[i] = hash_table[i]->next;
            curr_node->next = temp[new_index];
            temp[new_index] = curr_node;

            curr_node = hash_table[i];
        }
    }
    //delete the old hash table and set temp to the new hash table
    table_capacity = new_table_capacity;
    delete[]hash_table;
    hash_table = temp;
}

#endif