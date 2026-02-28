#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};
Node* head = NULL;

// Task 01: Implement the DLL Concepts
void traverseForward() {      //Forward Traversal
    Node* temp = head;
    cout << "Forward Traversal: ";
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void traverseBackward() {     //Backward Traversal
    if (head == NULL) {
        cout << "Backward Traversal: NULL" << endl;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    cout << "Backward Traversal: ";
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->prev;
    }
    cout << "NULL" << endl;
}

void insertAtBeginning(int val) {  //Insertion At Beginning
    Node* newNode = new Node();
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;
}
 
void insertAtEnd(int val) {       //Insertion at End
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// Task 02: Search for a Value
bool searchValue(int key) {
    Node* temp = head;

    while (temp != NULL) {
        if (temp->data == key)
            return true;
        temp = temp->next;
    }
    return false;
}

// Task 03: Count total number of Nodes in DLL
int countNodes() {
    int count = 0;
    Node* temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Usage of InsertAtPosition() instead of InsertAtEnd() for inserting at End
void insertAtPosition(int val, int position) {

    if (position <= 0) {
        cout << "Invalid Position" << endl;
        return;
    }

    if (position == 1) {
        insertAtBeginning(val);
        return;
    }

    Node* newNode = new Node();
    newNode->data = val;

    Node* temp = head;

    for (int i = 1; i < position - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Invalid Position" << endl;
        return;
    }

    if (temp->next == NULL) {
        newNode->next = NULL;
        newNode->prev = temp;
        temp->next = newNode;
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    temp->next->prev = newNode;
    temp->next = newNode;
}

int main() {

    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter values for DLL 0" << i+1<< ": ";
        cin >> value;
        insertAtEnd(value);
    }

    traverseForward();
    traverseBackward();

    cout << "\nTotal Nodes: " << countNodes() << endl;

    int searchKey;
    cout << "Enter value to search: ";
    cin >> searchKey;

    if (searchValue(searchKey))
        cout << "Value Found" << endl;
    else
        cout << "Value Not Found" << endl;

    int position, newVal;
    cout << "\nEnter value and position to insert: ";
    cin >> newVal >> position;

    insertAtPosition(newVal, position);

    cout << "\nAfter Insertion:\n";
    traverseForward();
    traverseBackward();

    return 0;
}