#include <iostream>
#include <unordered_map>//REVIEW -  
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

void removeDuplicates(Node* head) {
    if (head == NULL || head->next == NULL) {
        return;
    }

    unordered_map<int, bool> seen;
    Node* curr = head;
    Node* prev = NULL;

    while (curr != NULL) {
        // Check if the current node's value is already in the map
        if (seen[curr->data]) {
            // Duplicate found, remove the current node
            prev->next = curr->next;
            delete curr; // Free up the memory
        } else {
            // Mark the value as seen
            seen[curr->data] = true;
            prev = curr; // Move prev to current node
        }
        curr = prev->next; // Move to the next node //REVIEW - 
    }
}
// Helper function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Creating a sample unsorted linked list
    Node* head = new Node(10);
    head->next = new Node(12);
    head->next->next = new Node(11);
    head->next->next->next = new Node(11);
    head->next->next->next->next = new Node(12);
    head->next->next->next->next->next = new Node(11);
    head->next->next->next->next->next->next = new Node(10);

    cout << "Original Linked List: " << endl;
    printList(head);

    // Remove duplicates
    removeDuplicates(head);

    cout << "\nLinked List after removing duplicates: " << endl;
    printList(head);

    return 0;
}
