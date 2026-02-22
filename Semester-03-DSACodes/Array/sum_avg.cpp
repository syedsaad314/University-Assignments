#include <iostream>
using namespace std;

// Function to calculate sum and average
void sumAndAverage(int arr[], int n) {
    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += arr[i];

    double avg = (double)sum / n;
    cout << "Sum : " << sum << endl;
    cout << "Average: " << avg << endl;
}

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int n = 5;

    // Call function
    sumAndAverage(arr, n);

    return 0;
}