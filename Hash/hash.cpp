#include <iostream>
#include <vector>
using namespace std;

// Function to calculate the first hash index
int hash_function_1(int key, int size) {
    return key % size;
}

// Function to calculate the step size for double hashing
int hash_function_2(int key, int prime, int size) {
    return prime - (key % prime);
}

// Function to insert keys into the hash table using double hashing
vector<int> double_hashing_insert(const vector<int>& keys, int size) {
    vector<int> hash_table(size, -1); // Initialize hash table with -1 (indicating empty)

    int prime = 7; // Prime number used for the second hash function

    for (int key : keys) {
        int index = hash_function_1(key, size);

        if (hash_table[index] == -1) {
            hash_table[index] = key;
        } else {
            int step = hash_function_2(key, prime, size);
            int original_index = index;

            // Continue probing until an empty slot (-1) or the same key is found
            while (hash_table[index] != -1 && hash_table[index] != key) {
                index = (index + step) % size;

                // Stop if we have looped back to the original index
                if (index == original_index) {
                    break;
                }
            }

            // If we found an empty slot, insert the key
            if (hash_table[index] == -1) {
                hash_table[index] = key;
            }
        }
    }

    return hash_table;
}

int main() {
    vector<int> keys = {112, 125, 15, 82, 124, 145, 188, 178, 125, 58, 57};
    int table_size = 11;

    vector<int> hash_table = double_hashing_insert(keys, table_size);

    // Print the hash table
    cout << "Hash Index\tKey" << endl;
    for (int i = 0; i < table_size; ++i) {
        cout << i << "\t\t";
        if (hash_table[i] == -1) {
            cout << "-" << endl;
        } else {
            cout << hash_table[i] << endl;
        }
    }

    return 0;
}
