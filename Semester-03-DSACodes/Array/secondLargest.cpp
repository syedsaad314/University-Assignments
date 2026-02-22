#include <iostream>
using namespace std;

void findSecondLargest(int arr[], int size)
{
    if (size < 2)
    {
        cout << "Second largest element cannot be found." << endl;
        return;
    }

    int largest = arr[0];
    int secondLargest = arr[0];

    for (int i = 1; i < size; i++)
    {
        if (arr[i] > largest)
        {
            secondLargest = largest;
            largest = arr[i];
        }
        else if (arr[i] > secondLargest && arr[i] != largest)
        {
            secondLargest = arr[i];
        }
    }

    if (largest == secondLargest)
    {
        cout << "Second largest element not found!" << endl;
    }
    else
    {
        cout << "Second Largest Element: " << secondLargest << endl;
    }
}

int main()
{
    int size;

    cout << "\nEnter the Size of Array: ";
    cin >> size;

    int arr[size];

    for (int i = 0; i < size; i++)
    {
        cout << "Enter the Array Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    findSecondLargest(arr, size);

    return 0;
}
