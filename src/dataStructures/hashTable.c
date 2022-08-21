#include "hashTable.h"

/**
 * Collision prevention
 * 
 */ 
struct HashTableEntry {
    char *key;
    void *value;
    HashTableEntry *next;
};

/**
 * Function for searching the chain in the hash map
 * Returns NULL if it isn't found. 
 */ 
static HashTableEntry *searchTableEntryChain(HashTableEntry *chain, const char *key);

/**
 * Function for setting or creating an item in the hash map chain
 * Returns the item.
 */ 
static HashTableEntry *setTableEntryInChain(HashTableEntry *chain, const char *key, void *value);

/**
 * A function for hashing a string
 */ 
static uint64_t hashString (const char *strEntry);

HashTableEntry *createTableEntry(const char *key, void *value) {
    HashTableEntry *newEntry = (HashTableEntry *) malloc( sizeof(HashTableEntry) );
    if ( newEntry == NULL ) {
        fprintf(stderr, "ERROR: Out of memory. \n");
        return NULL;
    }

    char *keyVal = (char *) malloc( sizeof(key) );
    if ( keyVal == NULL ) {
        free(newEntry);
        fprintf(stderr, "ERROR: Out of memory. \n");
        return NULL;
    }

    //TODO: change to strncpy
    strcpy(keyVal, key);
    newEntry->key = keyVal;
    newEntry->value = value;
    newEntry->next = NULL;

    return newEntry;
}

void destroyTableEntry(HashTableEntry *entry){
    if( entry == NULL ) return;

    HashTableEntry *currEntry = entry;
    HashTableEntry *nextEntry = entry->next;
    while(nextEntry != NULL){
        free(currEntry->key);
        free(currEntry);
        currEntry = nextEntry;
        nextEntry = currEntry->next;
    } 

    free(currEntry);
}

HashTable *constructTable(){
    HashTable *table = (HashTable *) malloc( sizeof(HashTable) );

    if ( table == NULL ) {
        fprintf(stderr, "ERROR: Out of memory. \n");
        return NULL;
    }
    
    // calloc chosen over malloc so we init values to null. 
    table->tableEntries = (HashTableEntry **) calloc ( (size_t) INITIAL_CAPACITY, sizeof(HashTableEntry *));
    table->arrayLen = INITIAL_CAPACITY;
    table->numEntries = 0;

    if( table->tableEntries == NULL ){
        free( table );
        fprintf(stderr, "ERROR: Out of memory. \n");
        return NULL;
    }

    return table;
}

void destroyTable(HashTable *table){
    for (int i = 0; i < table->arrayLen; i++) {
        destroyTableEntry(table->tableEntries[i]);
    }
    free(table);
}

void *hashTableGet(HashTable *table, const char *key){
    if (table == NULL || key == NULL) {
        return NULL;
    }

    // Get the index in the table to insert info into. 
    // Mod it with size, so we stay within the array bounds. 
    uint64_t index = hashString(key) % table->arrayLen;

    HashTableEntry *searchResult = searchTableEntryChain(table->tableEntries[index], key);
    if(searchResult == NULL){
        return NULL;
    }
    return searchResult->value;
}

static HashTableEntry *searchTableEntryChain(HashTableEntry *chain, const char *key) {
    if( chain == NULL ){
        return NULL;
    }

    HashTableEntry *curr = chain;

    while(curr != NULL) {
        if( strcmp(key, curr->key) == 0){
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}


static HashTableEntry *setTableEntryInChain(HashTableEntry *chain, const char *key, void *value) {
    HashTableEntry *curr = chain;
    // This function is only called when chain is not null, so we don't check for nullness. 
    while(curr->next != NULL) {
        if(strcmp(curr->key, key) == 0) {
            // match found in the chain
            curr->value = value;
            return curr;
        }
    }

    // if we break out, we haven't found it. 
    HashTableEntry *newEntry = createTableEntry(key, value);
    curr->next = newEntry;
    return curr->next;
}

HashTableEntry *hashTableSet(HashTable *table, const char *key, void *value){
    if (table == NULL || key == NULL || value == NULL) {
        return NULL;
    }

    // Get the index in the table to insert info into. 
    // Mod it with size, so we stay within the array bounds. 
    uint64_t index = hashString(key) % table->arrayLen;

    if( table->tableEntries[index] == NULL ) {
        // create new entry (no chain)
        HashTableEntry *newEntry = createTableEntry(key, value);
        table->tableEntries[index] = newEntry;
        return newEntry;
    } else {
        // search for and set value inside of a chain. 
        return setTableEntryInChain(table->tableEntries[index], key, value);
    } 
}

/**
 * Constants used for the hashing function. 
 * see source below. 
 */ 
#define FNV_OFFSET_BASIS 14695981039346656037UL
#define FNV_PRIME 1099511628211UL

/** 
 * Based on the FNV-1a hashing function.
 * https://en.wikipedia.org/wiki/Fowler%E2%80%93Noll%E2%80%93Vo_hash_function
 * 
 * strEntry - String to hash. MUST BE NULL TERMINATED
 */
static uint64_t hashString (const char *strEntry) {
    uint64_t hash = FNV_OFFSET_BASIS;
    for( const char *item = strEntry; *item; item++ ){
        // iterate through the string.
        hash = hash ^ ((uint64_t) (unsigned char) (*item));
        hash = hash * FNV_PRIME;
    }
    return hash;
}


static void printChain(HashTableEntry *entry){
    HashTableEntry *curr = entry;
    while(curr->next != NULL) {
        printf("%s -> ", curr->key);
        curr = curr->next;
    }
    printf("%s -> NULL", curr->key);
}

void printHashTable(HashTable *table){
    for (int i = 0; i < table->arrayLen; i++) {
        if (table->tableEntries[i] == NULL) {
            printf("---");
        } else {
            printChain(table->tableEntries[i]);
        }

        printf("\n");
    }
}
