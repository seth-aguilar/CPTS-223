/*
 *  Separate chaining hashtable
 */

#ifndef __CHAINING_HASH_H
#define __CHAINING_HASH_H

// Standard library includes
#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>
#include <algorithm>

// Custom project includes
#include "Hash.h"

// Namespaces to include
using std::vector;
using std::list;
using std::pair;

using std::cout;
using std::endl;

//
// Separate chaining based hash table - derived from Hash
//
template<typename K, typename V>
class ChainingHash : public Hash<K,V> {
private:
    vector<list<pair<K, V>>> table;  // The hash table
    int currentSize;                 // Current number of elements in the table

    void rehash() {
        vector<list<pair<K, V>>> oldTable = table;
        table.resize(findNextPrime(2 * table.size()));
        for (auto& bucket : table) {
            bucket.clear();
        }
        currentSize = 0;
        for (auto& bucket : oldTable) {
            for (auto& pair : bucket) {
                insert(pair);
            }
        }
    }

public:
    ChainingHash(int n = 11) : table(n), currentSize(0) {
    }

    ~ChainingHash() {
        this->clear();
    }

    int size() {
        return currentSize;
    }

    V operator[](const K& key) {
        int bucket = hash(key);
        for (auto& pair : table[bucket]) {
            if (pair.first == key) {
                return pair.second;
            }
        }
        throw std::out_of_range("Key not found");
    }

    bool insert(const std::pair<K, V>& pair) {
        int bucket = hash(pair.first);
        auto it = std::find_if(table[bucket].begin(), table[bucket].end(),
            [&pair](const std::pair<K, V>& existingPair) {
                return existingPair.first == pair.first;
            });
        if (it != table[bucket].end()) {
            return false;  // Element with the same key already exists
        }
        table[bucket].push_back(pair);
        if (++currentSize > table.size() * 0.75) {
            rehash();
        }
        return true;
    }

    void erase(const K& key) {
        int bucket = hash(key);
        for (auto it = table[bucket].begin(); it != table[bucket].end(); ++it) {
            if (it->first == key) {
                table[bucket].erase(it);
                --currentSize;
                return;
            }
        }
    }

    void clear() {
        for (auto& bucket : table) {
            bucket.clear();
        }
        currentSize = 0;
    }

    int bucket_count() {
        return table.size();
    }

    float load_factor() {
        return static_cast<float>(currentSize) / table.size();
    }

private:
    int findNextPrime(int n)
    {
        while (!isPrime(n))
        {
            n++;
        }
        return n;
    }

    int isPrime(int n)
    {
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                return false;
            }
        }

        return true;
    }

    int hash(const K& key) {
        return 0;       
    }

};

#endif //__CHAINING_HASH_H
