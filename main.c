#include <stdlib.h>

typedef struct ArrayMap {
    int size;
    int *keys;
    int *values;
} ArrayMap;

/**
 * Function to set a value in a map
 * @param map The map to set the value in
 * @param key The key to set the value for
 * @param value The value to set
*/
void set(ArrayMap *map, int key, int value) {
    // Check if the key exists
    for (int i = 0; i < map->size; i++) {
        if (map->keys[i] == key) {
            map->values[i] = value;
            return;
        }
    }

    // Key doesn't exist, add it
    map->size++;
    map->keys = realloc(map->keys, sizeof(int) * map->size);
    map->values = realloc(map->values, sizeof(int) * map->size);
    map->keys[map->size - 1] = key;
    map->values[map->size - 1] = value;
}

/**
 * Function to create a new map
 * @return The new map
*/
ArrayMap *new() {
    ArrayMap *map = malloc(sizeof(ArrayMap));
    map->size = 0;
    map->keys = malloc(sizeof(int) * map->size);
    map->values = malloc(sizeof(int) * map->size);
    return map;
}

/**
 * Function to get a value from a map
 * @param map The map to get the value from
 * @param key The key to get the value for
 * @return The value for the key
*/
int get(ArrayMap *map, int key) {
    // Check if the key exists
    for (int i = 0; i < map->size; i++) {
        if (map->keys[i] == key) {
            // Key exists, return the value
            return map->values[i];
        }
    }

    // Key doesn't exist, return -1
    return -1;
}

// Main function
int main(int argc, char *argv[]) {
    // Create a new map
    ArrayMap *map = new();

    // Set some values
    set(map, 1, 10);

    // Get some values
    printf("%d\n", get(map, 1));

    return 0;
}