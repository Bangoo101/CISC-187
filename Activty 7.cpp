#include <iostream>
using namespace std;

// defines the Node structure
struct Node {
    int data;
    Node* next; // pointer to the next node
};

// Create a LinkedList class to manage the linked list
class LinkedList {
    private:
        Node* head; // pointer to the head of the list
    public:
        LinkedList() { // constructor
            head = nullptr; // initialize head to null
        }

        // function to insert a node at the start of the list
        void insertAtStart(int value) {
            Node* newNode = new Node(); // create new node
            newNode->data = value; // set data
            newNode-> next = head; // point new node to current head
            head = newNode; // update head to new node.
            cout << value << " added to start of List" << endl;
        }

        // function to delete the node at the start
        void deleteAtStart() {
            if (head == nullptr) { // if statement to check if the list is empty
                cout << "List is empty" << endl;
                return;
            }
            Node* temp = head; // create a temporary pointer to the head
            head = head->next; // update head to the next node
            cout << temp->data << " was deleted from the start" << endl;
            delete temp; // delete the old head
        }

};

int main() {
    LinkedList list;
    list.insertAtStart(3);
    list.insertAtStart(123);
    list.deleteAtStart();
    list.deleteAtStart();
    list.deleteAtStart(); // delete from an empty list
    return 0;
}