#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

struct item {
    char key[100];
    char value[100];
    struct item *next;
};

int hash(char *str);
void add_pair(struct item hashTable[], char *key, char *value);
struct item *get_item(struct item hashTable[], char *key);

int main() {
    struct item hashTable[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; ++i) {
        hashTable[i].key[0] = '\0';
    }

    add_pair(hashTable, "key", "value");
    add_pair(hashTable, "key2", "val2");
    add_pair(hashTable, "hi", "bye");
    add_pair(hashTable, "key2", "val3");
    printf("%s\n", get_item(hashTable, "key")->value);
    printf("%s\n", get_item(hashTable, "key2")->value);
    printf("%s\n", get_item(hashTable, "hi")->value);
    return 0;
}

int hash(char *str) {
    int result = 0;
    for (; *str != '\0'; str++) {
        result = result * 37 + *str;
    }
    return result % TABLE_SIZE;
}

void add_pair(struct item hashTable[], char *key, char *value) {
    struct item *target = get_item(hashTable, key);
    if (*(target->key)) {
        // already in table, replace value with new value
        printf("%s in table, replace\n", key);
        strcpy(target->value, value);
        return;
    }
    // not in table, add key, value
    // and make a new empty item for .next to point to
    strcpy(target->key, key);
    strcpy(target->value, value);
    target->next = (struct item *)malloc(sizeof(struct item));
}

struct item *get_item(struct item hashTable[], char *key) {
    // returns pointer to item if found, else empty item where it should be
    // placed
    int index = hash(key);
    struct item *target = &hashTable[index];
    // find last item in list
    while (*(target->key) && strcmp(target->key, key) != 0) {
        // printf("val with hash %d exists, indexing next\n", index);
        target = target->next;
    }
    return target;
}
