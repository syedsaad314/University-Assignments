#include <iostream>
using namespace std;
int main(){
    int size;
    cout<<"Enter the size: ";
    cin>>size;
    int arr[size];
    
    for(int i=0; i<size ; i++) {
        cout<<"Enter the array elements " << i+1 <<": ";
        cin>>arr[i];
    }
    cout<<"\nOriginal Array: ";
    for(int i=0; i<size ; i++){
        cout<<arr[i] << " ";
    }
    cout<<"\nArray in Reverse Order: ";
    for(int i=size-1; i>=0; i--){
        cout<<arr[i] << " ";
    }
    return 0;
}