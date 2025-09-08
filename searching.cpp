#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int target, int &steps){
    steps = 0; 
    for(int i = 0; i<size; i ++){
        steps++;
        if (arr[i] == target) {
            // return i for index if found
            return i;
        }
    }
    // return -1 if not found
    return -1;
}

int binarySearch(int arr[], int size, int target, int &steps){
    int low = 0;
    int high = size - 1;
    steps = 0;
    while (low <= high) {
        steps++;
        int mid = low + (high - low) / 2;
        if (arr[mid] == target){
            // target found
            return mid;
        } else if (arr[mid] < target){
            low = mid +1;
        } else {
            high = mid -1;
        }
    }
    // not found
    return -1;
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    // divide total bytes by bytes of one element for the integer size in single whole numbers
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 14;
    int stepsLinear = 0;
    int stepsBinary = 0;
    int giveLinear = linearSearch(arr, size, target, stepsLinear);
    int giveBinary = binarySearch(arr, size, target, stepsBinary);
    cout << "Linear Search: Target found at index " << giveLinear << " in " << stepsLinear << " steps." << endl;
    cout << "Binary Search: Target found at index " << giveBinary << " in " << stepsBinary << " steps." << endl;
    return 0;
}