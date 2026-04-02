#include <iostream>
#include <vector>
using namespace std;

vector<int> merge(vector<int> left, vector<int> right)
{
    vector<int> result;
    int i = 0, j = 0;

    while(i < left.size() && j < right.size())
    {
        if(left[i] <= right[j])
            result.push_back(left[i++]);
        else
            result.push_back(right[j++]);
    }

    while(i < left.size())
        result.push_back(left[i++]);

    while(j < right.size())
        result.push_back(right[j++]);

    return result;
}

vector<int> mergeSort(vector<int> arr)
{
    if(arr.size() <= 1)
        return arr;

    int mid = arr.size() / 2;

    vector<int> left(arr.begin(), arr.begin() + mid);
    vector<int> right(arr.begin() + mid, arr.end());

    return merge(mergeSort(left), mergeSort(right));
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++)
    {
        cout << "Enter element [" << i << "]: ";
        cin >> arr[i];
    }

    arr = mergeSort(arr);

    cout << "Sorted Array: ";
    for(int x : arr)
        cout << x << " ";

    return 0;
}