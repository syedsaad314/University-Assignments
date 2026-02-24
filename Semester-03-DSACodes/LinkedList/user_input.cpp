#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
 int main() {
    int n;
    cout << "\nEnter the Number of Nodes in the Linked List: ";
    cin >> n;

    Node* head = NULL;  // at first the list is Empty
    Node* temp = NULL;  // used for the tracking of the Nodes

    for (int i=0; i<n; i++) {
        Node* newNode = new Node();   //Create a new Node everytime
        cout << "Enter the Data in the Node " << i+1 << ": ";
        cin >> newNode -> data;   // Data stored in the node entered
        newNode -> next = NULL;

        if (head == NULL) {   // IF Condition True only at the first time after that else runs.
            head = newNode;
            temp = newNode;
         }
         else {
            temp -> next = newNode;
            temp = newNode; 
         }       
    }
    
    // Display the Linked List:
    cout << "Linked List: ";
    Node* display = head;
    while (display != NULL) {
        cout << display -> data << " --> ";
        display = display -> next;
    }
    cout << "NULL" << endl;

    // 001: Linked List Insertion at the Beginning: 
    Node* insertNode = new Node();
    cout << "\nEnter the Node you want to insert at the Beginning: ";
    cin >> insertNode -> data;

    Node* temp2 = head;
    head = insertNode;
    head -> next = temp2;

    //Display Updated Linked List:
    Node* display2 = head;
    cout << "Updated Linked List after Insertion: ";
    while (display2 != NULL) {
        cout << display2->data << " --> ";
        display2 = display2-> next;
    }
    cout << "NULL" << endl;

    // 002: Insertion of the Node in the End:

    Node* insertEnd = new Node();  // Creating new Node to be inserted in the End
    cout << "\nEnter the Node you want to Enter in the End: ";
    cin >> insertEnd -> data;
    insertEnd -> next = NULL;

    if (head == NULL) {
        head = insertEnd;
    } 
    else {
        
    Node* temp3 = head;   // Traverse the list till the last Node
    while (temp3 -> next != NULL) {
        temp3 = temp3 -> next;
    }
    temp3 -> next = insertEnd;  // Link the last node to the inserted ode to be added in the End
    }

    // Display the Updated End Inserted Linked List
    Node* display3 = head;
    cout << "Updated Linked List after End Insertion: ";
    while (display3 != NULL) {
        cout<< display3 -> data << " --> " ;
        display3 = display3 -> next;
    }
    cout << "NULL" << endl;

    // 003: Insertion of the Node in between the Linked List at given position:

    int position;
    cout << "\nEnter the Position you want the Node to be Added (Starting from 1): ";
    cin >> position;

    // Just for the correctness in the suffix of the position
    string suffix;

    if (position % 100 >= 11 && position % 100 <= 13) {
        suffix = "th";
    }
    else if (position % 10 == 1) {
        suffix = "st";
    }
    else if (position % 10 == 2) {
        suffix = "nd";
    }
    else if (position % 10 == 3) {
        suffix = "rd";
    }
    else {
        suffix = "th";
    }

    Node* insertX = new Node();
    cout << "Enter the Node to be Added in " << position << suffix << " Position: ";
    cin >> insertX -> data;

    // If adding in the beginning
    if (position == 1) {
        insertX -> next = head;
        head = insertX;
    }
    else {
        Node* temp4 = head;

        // Now traversing till (Position-1)
        for ( int i=1; i< position-1 && temp4 !=NULL; i++){
            temp = temp -> next;
        }
        if (temp4 == NULL) {
            cout << "Invalid Position!";
        }
        else {
             insertX->next = temp4->next;
             temp4->next = insertX; 
        }
    }
    // Display Updated Linked List after Insertion:
    Node* display4 = head;
    cout << "Updated Linked List after adding Node in " << position << suffix << " Position: ";
    while (display4 != NULL){
        cout << display4->data << " --> ";
        display4 = display4->next;
    }
    cout << "NULL" << endl;



     return 0; 

 }