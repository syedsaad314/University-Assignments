#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};
node* head = NULL; // Global Head Declaration

void insert(int value) {
    node* newnode = new node;
    newnode->data = value;
    newnode->next = head;
    head = newnode;
}

void display() {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " --> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
//Task 4: Write a function to delete the last node in the list.
void delete_last() {
    if (head == NULL)
        return;

    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    node* temp = head;

    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;
}

//Task 5: Write a function to reverse the linked list iteratively.
void reverse() {
    node* prev = NULL;
    node* current = head;
    node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

//Task 6: Write a function to sort the linked list in ascending order.
void sort_list() {
    if (head == NULL)
        return;
    bool swapped;
    node* temp;
    do {
        swapped = false;
        temp = head;

        while (temp->next != NULL) {
            if (temp->data > temp->next->data) {
                int t = temp->data;
                temp->data = temp->next->data;
                temp->next->data = t;
                swapped = true;
            }
            temp = temp->next;
        }

    } while (swapped);
}

int main()
{
    insert(25);
    insert(5);
    insert(15);
    insert(30);

    cout << "Original List: " << endl;
    display();

    cout << "\nAfter Deleting Last Node:" << endl;
    delete_last();
    display();

    cout << "\nAfter Reversing List:" << endl;
    reverse();
    display();

    cout << "\nAfter Sorting List (Ascending):" << endl;
    sort_list();
    display();

    return 0;
}