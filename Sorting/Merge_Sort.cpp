#include<iostream>
using namespace std;

void merge(){
    int arr[10];
    int temp;
    int mid, high, low;
    int left, right;
    left = low;
    right = mid + 1;
    while (left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            // temp.push_back(arr[left]);
        }
    }
}
int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int arr[50];
    cout << "Enter the elements in the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "The unsorted array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
}