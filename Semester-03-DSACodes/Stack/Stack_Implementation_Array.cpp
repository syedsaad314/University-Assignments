#include <iostream>
using namespace std;

const int SIZE = 5;  //use instead #define SIZE=5

int stack[SIZE];
int top = -1;

void pushElement(int val) {
    if (top == SIZE - 1) {
        cout << "Stack Overflow! No more space available.\n";
        return;
    }
    stack[++top] = val;
}
void popElement() {
    if (top == -1) {
        cout << "Stack Underflow! Stack is already empty.\n";
        return;
    }
    cout << "Deleted element: " << stack[top--] << endl;
}
void peekElement() {
    if (top == -1) {
        cout << "Stack is empty.\n";
        return;
    }

    cout << "Top element is: " << stack[top] << endl;
}
void displayStack() {
    if (top == -1) {
        cout << "Stack is empty.\n";
        return;
    }
    cout << "Stack elements (Top to Bottom):\n";
    for (int i = top; i >= 0; i--)
        cout << stack[i] << endl;
}

// TASK 01: Stack Implementation Using Array with User Input.
int main()
{   int choice, val, n;
    cout << "\nAssalam-O-Alaikum! Stack Service is Ready! What do you want me do?\n";
    cout << "1. Push into Stack\n";
    cout << "2. Pop from Stack\n";
    cout << "3. Peek Top Element\n";
    cout << "4. Display Stack\n";
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
            cout << "\nYou entered choice 1: Push Operation.\n";
            cout << "How many values do you want to insert? ";
            cin >> n;

            for (int i = 1; i <= n; i++) {
                cout << "Enter value " << i << ": ";
                cin >> val;
                pushElement(val);
            }
            cout << "Push operation completed successfully.\n";
            displayStack();
            break;

        case 2:
            cout << "\nYou entered choice 2: Pop Operation.\n";
            popElement();
            cout << "Pop operation completed.\n";
            cout << "\nUpdated Stack: ";
            displayStack();
            break;

        case 3:
            cout << "\nYou entered choice 3: Peek Operation\n";
            peekElement();
            cout << "Peek operation completed.\n";
            break;

        case 4:
            cout << "\nYou entered choice 4: Display Operation\n";
            displayStack();
            cout << "Display completed.\n";
            break;

        default:
            cout << "\nInvalid choice. Please select a valid option carefully with Eyen Open Akhi.\n";
            break;
        }
        cout << "Process completed. Please refer to the options and tell me what should I do next Saad Bhai.\n";
    }
    return 0;
}