#include <iostream> 
using namespace std;

// binary search tree node structure
struct Node {
    int data;
    Node* left; // pointer to left 
    Node* right; // pointer to right 
};
// new node creation function
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value; // makes the initial node data
    newNode->left = nullptr; // empty left and right pointers
    newNode->right = nullptr;
    return newNode;
}
//insert function for BST
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return createNode(value); // make new node if empty
    } else if (value < root-> data ) {
        root->left = insert(root->left, value); // insert to left if smaller
    } else if (value > root->data) {
        root->right = insert(root->right, value); // insert to right if bigger
    }
    return root; // return unchanged root pointer
}

// prints BST in order
void printInOrder(Node* root) {
    if (root != nullptr) {
        printInOrder(root->left);
        cout << root->data << " ";
        printInOrder(root->right);
    }
}
// biggest value in BST
int findMax(Node* root){
    Node* current = root;
    while (current->right != nullptr){
        current = current->right; 
    }
    return current->data;
}

int main() {
    int value[] = {1,5,9,2,4,10,6,3,8}; // given values
    int size = sizeof(value)/sizeof(value[0]); // size of array 

    Node* root = nullptr;
    for (int i = 0; i < size; i++) {
        root = insert(root, value[i]); // insert values into BST
    }
    // print the BST in order
    cout << "BST in order: ";
    printInOrder(root); 
    cout << endl;
    // print biggest value
    cout << "Biggest value: " << findMax(root) << endl;
    return 0;

}
