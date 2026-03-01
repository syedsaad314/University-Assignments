#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};
Node* head1 = NULL;
Node* head2 = NULL;

// Insert At End (for building linkedlists)
void insertAtEnd(Node*& head, int val) {
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

// TASK 1: Delete At Position
void deleteAtPosition(Node*& head, int pos) {
    if (head == NULL) {
        cout << "UNDERFLOW" << endl;
        return;
    }
    if (pos == 1) {
        Node* temp = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        delete temp;
        return;
    }
    Node* temp = head;
    for (int i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL) {
        cout << "Invalid Position" << endl;
        return;
    }
    if (temp->next == NULL) {
        temp->prev->next = NULL;
        delete temp;
        return;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
}

// TASK 2: Reverse DLL
void reverseDLL(Node*& head) {
    Node* temp = NULL;
    Node* current = head;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL)
        head = temp->prev;
}

// TASK 3: Merge Two DLLs
Node* mergeDLL(Node* head1, Node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    Node* temp = head1;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = head2;
    head2->prev = temp;
    return head1;
}

// Display
void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// TASK 4: Menu Driven Program
int main() {
    int choice, val, pos, n;

    cout << "\nAssalam-O-Alaikum! What do you want me to do Saad Bhai?\n";
    cout << "1. Insert into List 01\n";
    cout << "2. Insert into List 02\n";
    cout << "3. Delete at Position (List1)\n";
    cout << "4. Reverse List1\n";
    cout << "5. Merge List1 and List2\n";
    cout << "6. Display List1\n";
    cout << "0. Exit\n";

    while (true) {
        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 0) {
            cout << "\nMa'ssalaame! Exiting program...\n";
            break;
        }

        switch (choice) {
        case 1:
            cout << "\nYou selected: Insert into List 01\n";
            cout << "How many values do you want to insert? ";
            cin >> n;

            for (int i = 1; i <= n; i++) {
                cout << "Enter value " << i << ": ";
                cin >> val;
                insertAtEnd(head1, val);
            }

            cout << "Insertion completed successfully.\n";
            display(head1);
            break;

        case 2:
            cout << "\nYou selected: Insert into List 02\n";
            cout << "How many values do you want to insert? ";
            cin >> n;

            for (int i = 1; i <= n; i++) {
                cout << "Enter value " << i << ": ";
                cin >> val;
                insertAtEnd(head2, val);
            }

            cout << "Insertion completed successfully.\n";
            display(head2);
            break;

        case 3:
            cout << "\nYou selected: Delete at Position (List 01)\n";
            cout << "Enter position to delete: ";
            cin >> pos;

            deleteAtPosition(head1, pos);
            cout << "Deletion completed.\n";
            display(head1);
            break;

        case 4:
            cout << "\nYou selected: Reverse List 01\n";
            reverseDLL(head1);
            cout << "Reverse completed.\n";
            display(head1);
            break;

        case 5:
            cout << "\nYou selected: Merge List 01 and List 02\n";
            head1 = mergeDLL(head1, head2);
            cout << "Merge completed.\n";
            display(head1);
            break;

        case 6:
            cout << "\nDisplaying List 01:\n";
            display(head1);
            break;

        default:
            cout << "\nInvalid choice. Please refer to the menu option with Eyes Open Akhi.\n";
        }

        cout << "\nProcess completed. Please refer to the options and tell me what should I do next Saad Bhai.\n";
    }

    return 0;
}