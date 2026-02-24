#include <iostream>
using namespace std;

// Creation of Node
struct node
{
    int data;
    node* next;
};
node* head = NULL;

//Task 1: Write a function to insert a new node at the beginning.
void insert(int value) {
    node* newnode = new node;
    newnode->data = value;
    newnode->next = head;
    head = newnode;
}

//Task 2: Count the total number of nodes in the linked list.
int count() {
    int count = 0;
    node* temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

//Task 3: Write a function to search for a value in the linked list.
void search(int value) {
    node* temp = head;

    while (temp != NULL) {
        if (temp->data == value) {
            cout << value << " Found in the List" << endl;
            return;
        }
        temp = temp->next;
    }
    cout << value << " Not Found in the List" << endl;
}

// Display pattern
void display()
{
    node* temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " --> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

int main()
{
    // Inserting nodes
    insert(30);
    insert(20);
    insert(10);

    cout << "Linked List: " << endl;
    display();

    cout << "\nTotal Nodes: " << count() << endl;

    cout << endl;
    search(20);
    search(50);

    return 0;
}