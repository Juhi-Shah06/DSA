#include <iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int number)
{
    if (low > high)
    {
        return -1;
    }
    int mid = (low + high) / 2;
    if (number == arr[mid])
    {
        return mid;
    }
    else if (number < arr[mid])
    {
        return binarySearch(arr, low, mid - 1, number);
    }
    else
    {
        return binarySearch(arr, mid + 1, high, number);
    }
}

int main()
{
    int number;
    int size;
    cout << "Enter the value of array size: ";
    cin >> size; 
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter array value: ";
        cin >> arr[i];
    }
    cout << "Enter the target value: ";
    cin >> number;
    int low = 0, high = size - 1;
    int index = binarySearch(arr, low, high, number);
    if (index != -1)
    {
        cout << "Element found at index " << index;
    }
    else
    {
        cout << "Element not found in the array";
    }
    return 0;
}
