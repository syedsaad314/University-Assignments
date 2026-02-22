#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "\nEnter the Size of Array: ";
    cin >> size;

    int arr [size];
    for (int i=0 ; i<size ; i++ ) {
        cout << "Enter the Array Elements "<< i + 1 <<": ";
        cin >> arr [i];
    }

    int max = arr[0];
    int min = arr[0];

    for (int i=1; i< size; i++) {
        if (arr [i]> max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr [i];
        }
    }
    
    cout << "\nMaximum Value: " << max << endl;
    cout << "Minimum Value: " << min << endl;

    return 0;
}