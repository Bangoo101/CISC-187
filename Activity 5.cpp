#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
//array = [200, 400, 100, 50, 350]
void sortArray(int arr[], int size) {
    for (int i = 0; i < size - 1; i++){
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int array[5] = {200, 400, 100, 50, 350};
    int size = sizeof(array) / sizeof(array[0]);
    sortArray(array, size);
    unordered_map<int, bool> lookup;
    for (int i = 0; i<size; i++){
        lookup[array[i]] = true;
    }
    int key = 100;
    if(lookup.find(key) != lookup.end()){
        cout << key << " was found" << endl;
    } else {
        cout << key << " was not found" << endl;
    }
    // prob 2
    string name = "Branden";
    hash<string> hash_fn;
    size_t hash = hash_fn(name);
    cout << "The hash value for " << name << " is: " << hash << endl;

    return 0;
}

