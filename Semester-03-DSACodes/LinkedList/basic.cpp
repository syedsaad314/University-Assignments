#include <iostream>
using namespace std;

// Structing Node
struct Node {
    int data;
    Node* next;
};
 
int main() {
    
// Step 001: Creating the Nodes manually
Node* head = new Node();
Node* second = new Node();
Node* third = new Node();

// Step 002: adding data to the Nodes:
head -> data = 100;
second -> data = 200;
third -> data = 300;

// Step 003: Linking the Nodes together:
 head -> next = second;
 second -> next = third;
 third -> next = NULL;

 //Step 004: Printing the Nodes using While Loop:
 Node* temp = head;
 while (temp!= NULL) {
    cout<< temp->data << " -> ";
    temp = temp -> next;
 }

 cout << "NULL";
 return 0; 


}


