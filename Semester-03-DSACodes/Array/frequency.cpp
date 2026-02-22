//Write a function that calculates the frequency of each unique element in the array.

#include <iostream>
using namespace std;

void elementFrequency(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int count = 1;
        bool isRepeated = false;

        for (int j = 0; j < i; j++)
        {
            if (arr[i] == arr[j])
            {
                isRepeated = true;
                break;
            }
        }

        if (isRepeated == true)
            continue;

        for (int k = i + 1; k < size; k++)
        {
            if (arr[i] == arr[k])
                count++;
        }

        cout << arr[i] << " occurs " << count << " times" << endl;
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

    cout << "\nFrequency of each unique element:\n";
    elementFrequency(arr, size);

    return 0;
}
