#ifndef __PROBING_HASH_H
#define __PROBING_HASH_H

#include <vector>
#include <stdexcept>

#include "Hash.h"

using std::vector;
using std::pair;

// Can be used for tracking lazy deletion for each element in your table
enum EntryState {
    EMPTY = 0,
    VALID = 1,
    DELETED = 2
};

template<typename K, typename V>
class ProbingHash : public Hash<K,V> { // derived from Hash
private:
    vector<pair<K, V>> table;             // The hash table
    vector<EntryState> entryState;        // State of each entry (EMPTY, VALID, DELETED)
    int currentSize;                      // Current number of VALID elements in the table

    void rehash() {
        vector<pair<K, V>> oldTable = table;
        vector<EntryState> oldEntryState = entryState;

        int newSize = findNextPrime(2 * table.size());
        table.resize(newSize);
        entryState.resize(newSize, EMPTY);

        currentSize = 0;
        for (size_t i = 0; i < oldTable.size(); ++i) {
            if (oldEntryState[i] == VALID) {
                int bucket = hash(oldTable[i].first);
                while (entryState[bucket] == VALID) {  // Find the next available slot
                    bucket = (bucket + 1) % table.size();
                }
                table[bucket] = oldTable[i];
                entryState[bucket] = VALID;
                ++currentSize;
            }
        }
    }

public:
    ProbingHash(int n = 11) : table(n), entryState(n, EMPTY), currentSize(0) {
    }

    ~ProbingHash() {
        this->clear();
    }

    int size() {
        return currentSize;
    }

    V operator[](const K& key) {
        int bucket = hash(key);
        int originalBucket = bucket;
        do {
            if (entryState[bucket] == VALID && table[bucket].first == key) {
                return table[bucket].second;
            }
            bucket = (bucket + 1) % table.size();
        } while (bucket != originalBucket);
        throw std::out_of_range("Key not found");
    }

    bool insert(const std::pair<K, V>& pair) {
        int bucket = hash(pair.first);
        int originalBucket = bucket;
        do {
            if (entryState[bucket] == EMPTY || entryState[bucket] == DELETED) {
                table[bucket] = pair;
                entryState[bucket] = VALID;
                ++currentSize;
                if (static_cast<float>(currentSize) / table.size() > 0.75) {
                    rehash();
                }
                return true;
            }
            bucket = (bucket + 1) % table.size();
        } while (bucket != originalBucket);

        return false;  // Table is full    
    }

    void erase(const K& key) {
        int bucket = hash(key);
        int originalBucket = bucket;
        do {
            if (entryState[bucket] == VALID && table[bucket].first == key) {
                entryState[bucket] = DELETED;
                --currentSize;
                return;
            }
            bucket = (bucket + 1) % table.size();
        } while (bucket != originalBucket);
    }

    void clear() {
        for (size_t i = 0; i < table.size(); ++i) {  // Change int to size_t
            entryState[i] = EMPTY;
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

#endif //__PROBING_HASH_H
