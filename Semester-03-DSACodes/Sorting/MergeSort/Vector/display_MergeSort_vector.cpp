#include <iostream>
#include <vector>
using namespace std;

// Merge Function
vector<int> merge(vector<int> left, vector<int> right)
{
    vector<int> result;
    int i = 0, j = 0;

    while(i < left.size() && j < right.size())
    {
        if(left[i] <= right[j])
        {
            result.push_back(left[i]);
            i++;
        }
        else
        {
            result.push_back(right[j]);
            j++;
        }
    }

    // Remaining elements
    while(i < left.size())
    {
        result.push_back(left[i]);
        i++;
    }

    while(j < right.size())
    {
        result.push_back(right[j]);
        j++;
    }

    return result;
}

// Merge Sort Function
vector<int> mergeSort(vector<int> arr)
{
    if(arr.size() <= 1)
        return arr;

    int mid = arr.size() / 2;

    vector<int> left(arr.begin(), arr.begin() + mid);
    vector<int> right(arr.begin() + mid, arr.end());

    vector<int> sortedLeft = mergeSort(left);
    vector<int> sortedRight = mergeSort(right);

    return merge(sortedLeft, sortedRight);
}

// Print Function (your touch)
void printArray(vector<int> arr)
{
    for(int x : arr)
        cout << x << " ";
    cout << endl;
}

int main()
{
    vector<int> arr = {8, 3, 1, 7, 0, 10, 2};

    cout << "Before Sorting: ";
    printArray(arr);

    arr = mergeSort(arr);

    cout << "After Sorting: ";
    printArray(arr);

    return 0;
}