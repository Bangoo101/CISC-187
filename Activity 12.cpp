#include <iostream>
using namespace std;

struct Node {
    bool isNum; 
    int value;
    Node* children; // linked list of children
    Node* next; // next sibling same level

    // constructor for a number
    Node(int v) {
        isNum = true;
        value = v;
        children = nullptr;
        next = nullptr;
    }
    // constructor for a list
    Node() {
        isNum = false;
        value = 0;
        children = nullptr;
        next = nullptr;
    }
};

// add a child to a list node
void addChild(Node* parentList, Node* child){
    if (parentList ->children == nullptr){
        parentList ->children = child;
    } else {
        Node* temp = parentList -> children;
        while (temp -> next != nullptr){
            temp = temp->next;
        }
        temp -> next = child;
    }
}
//recursive funct to print all numbers
void printNumbers(Node* node){
    while(node != nullptr){
        if (node-> isNum){
            cout << node->value<< " ";
        } else {
            printNumbers(node->children);//goes agian for all numbs in list
        }
        node = node -> next;
    }
}

int main(){
    // initialize lsit
    Node*  root = new Node();
    //adding 1, 2, 3
    addChild(root, new Node(1));
    addChild(root, new Node(2));
    addChild(root, new Node(3));
    // adding [4,5,6]
    Node* list1 = new Node();
    addChild(list1, new Node(4));
    addChild(list1, new Node(5));
    addChild(list1, new Node(6));
    addChild(root, list1); //combines prev inputs into root
    // adding 7 
    addChild(root, new Node(7));
    // adding [8, [9,10,11,[12,13,14]]]
    Node* list2 = new Node();
    addChild(list2, new Node(8));

    Node* list2_1 = new Node();
    addChild(list2_1, new Node(9));
    addChild(list2_1, new Node(10));
    addChild(list2_1, new Node(11));

    Node* list2_2 = new Node();
    addChild(list2_2, new Node(12));
    addChild(list2_2, new Node(13));
    addChild(list2_2, new Node(14));
    addChild(list2_1, list2_2);
    addChild(list2, list2_1);
    addChild(root, list2);
    
    //adding [15,16,17,18,19,[20,21,22,[23,24,25,[26,27,29],30,31],32],33]
    //need 4 new lists
    Node* list3 = new Node();
    addChild(list3, new Node(15));
    addChild(list3, new Node(16));
    addChild(list3, new Node(17));
    addChild(list3, new Node(18));
    addChild(list3, new Node(19));
    Node* list4 = new Node();
    addChild(list4, new Node(20));
    addChild(list4, new Node(21));
    addChild(list4, new Node(22));
    Node* list5 = new Node();
    addChild(list5, new Node(23));
    addChild(list5, new Node(24));
    addChild(list5, new Node(25));
    Node* list6 = new Node();
    addChild(list6, new Node(26));
    addChild(list6, new Node(27));
    addChild(list6, new Node(29)); // no 28
    addChild(list5, list6);
    // back it up
    addChild(list5, new Node(30));
    addChild(list5, new Node(31));
    addChild(list4, list5);

    addChild(list4, new Node(32));
    addChild(list3, list4);

    addChild(list3, new Node(33));
    addChild(root, list3);

    printNumbers(root);
    return 0;
}
