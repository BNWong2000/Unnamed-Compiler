#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define INITIAL_CAPACITY 1024

/** Implementation of a hash table. 
 * 
 * This implementation uses Chaining to avoid collisions. 
 */ 


typedef struct HashTable HashTable;
typedef struct HashTableEntry HashTableEntry;

/**
 * A function to allocate and create a table entry. 
 */ 
HashTableEntry *createTableEntry(const char *key, void *value);

/**
 * A function to delete the table entry. 
 * 
 * Since the table entry is a linked list, it deletes all of the children of the list as well. 
 */ 
void destroyTableEntry(HashTableEntry *entry);

/**
 * A function to contruct a hash table. 
 */
HashTable *constructTable();

/**
 * A function to destroy the table. 
 */
void destroyTable(HashTable *table);

/**
 * A function to get the value from the table.
 *
 * Returns a pointer to the item (if it exists) or NULL if it doesnt. 
 */
void *hashTableGet(HashTable *table, const char *key);

/**
 * A function to set a value in the hash table.
 *
 * returns a pointer to the hash table entry that it set. 
 * value CANNOT be NULL.
 */
HashTableEntry *hashTableSet(HashTable *table, const char *key, void *value);

/**
 * Structure for the Hash Table
 */
struct HashTable {
    HashTableEntry **tableEntries;
    int arrayLen;
    int numEntries;
};




#endif
