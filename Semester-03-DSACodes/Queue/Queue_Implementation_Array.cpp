#include <iostream>
using namespace std;

const int SIZE = 5;  // Maximum size of queue
int queueArr[SIZE];
int front = -1, rear = -1;

bool isEmpty() {
    return (front == -1 || front > rear);
}
bool isFull() {
    return (rear == SIZE - 1);
}
void enqueueElement(int val) {
    if (isFull()) {
        cout << "Queue Overflow! No more space available.\n";
        return;
    }

    if (front == -1)
        front = 0;

    queueArr[++rear] = val;
}
void dequeueElement() {
    if (isEmpty()) {
        cout << "Queue Underflow! Queue is already empty.\n";
        return;
    }
    cout << "Deleted element: " << queueArr[front++] << endl;
    // Reset if queue becomes empty
    if (front > rear)
        front = rear = -1;
}
void peekElement() {
    if (isEmpty()) {
        cout << "Queue is empty.\n";
        return;
    }
    cout << "Front element is: " << queueArr[front] << endl;
}
void displayQueue() {
    if (isEmpty()) {
        cout << "Queue is empty.\n";
        return;
    }
    cout << "Queue elements (Front to Rear): ";
    for (int i = front; i <= rear; i++)
        cout << queueArr[i] << " ";
    cout << endl;
}
// TASK: Queue Implementation Using Array with User Input
int main() {
    int choice, val, n;

    cout << "\nAssalam-O-Alaikum! Queue Service is Ready! What do you want me do?\n";
    cout << "1. Enqueue into Queue\n";
    cout << "2. Dequeue from Queue\n";
    cout << "3. Peek Front Element\n";
    cout << "4. Display Queue\n";
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
            cout << "\nYou entered choice 1: Enqueue Operation.\n";
            cout << "How many values do you want to insert? ";
            cin >> n;

            for (int i = 1; i <= n; i++) {
                cout << "Enter value " << i << ": ";
                cin >> val;
                enqueueElement(val);
            }
            cout << "Enqueue operation completed successfully.\n\n";
            displayQueue();
            break;

        case 2:
            cout << "\nYou entered choice 2: Dequeue Operation.\n";
            cout << "How many values do you want to delete? ";
            cin >> n;

            for (int i = 1; i <= n; i++) {
                if (isEmpty()) {
                    cout << "Queue became empty. Stopping dequeue.\n";
                    break;
                }
                dequeueElement();
            }

            cout << "Dequeue operation completed.\n";
            cout << "\nUpdated Queue After Dequeue: \n";
            displayQueue();
            break;

        case 3:
            cout << "\nYou entered choice 3: Peek Operation\n";
            peekElement();
            cout << "Peek operation completed.\n";
            break;

        case 4:
            cout << "\nYou entered choice 4: Display Operation\n";
            displayQueue();
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