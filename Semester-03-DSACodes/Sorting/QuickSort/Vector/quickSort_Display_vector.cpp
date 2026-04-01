#include <iostream>
#include <vector>
using namespace std;

// Partition Function
int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];   // last element as pivot
    int i = low - 1;

    for(int j = low; j < high; j++)
    {
        if(arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Quick Sort Function
void quickSort(vector<int> &arr, int low, int high)
{
    if(low < high)
    {
        int p = partition(arr, low, high);

        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

// Print Function 
void printArray(const vector<int> &arr)
{
    for(int num : arr)
        cout << num << " ";
    cout << endl;
}

int main()
{
    // Initial Array
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90, 5};

    cout << "Before Sorting: ";
    printArray(arr);

    // Applying Quick Sort
    quickSort(arr, 0, arr.size() - 1);

    cout << "After Sorting: ";
    printArray(arr);

    return 0;
}