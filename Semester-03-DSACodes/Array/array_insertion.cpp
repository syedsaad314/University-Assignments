#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    int arr[size];

    //  Take the Input elements from the user
    for(int i = 0; i < size; i++) {
        cout << "Enter element " << i+1 << ": ";
        cin >> arr[i];
    }

    // Display the inserted Array elements
    cout << "Array Elements: ";
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}