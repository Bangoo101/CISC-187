#include <iostream>
using namespace std;

int main() {
    // #1 create an array of 100 elements
    int arr[100];
    // #2 The size of each element is 4 bytes
    cout << "Size of each element: " << sizeof(arr[0]) << " bytes" << endl;
    // #5 memory address
    cout << "Memory address of the first element: " << &arr[0] << endl;
    
}