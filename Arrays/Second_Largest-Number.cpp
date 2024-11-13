/*Write a program to find second largest element in the array.
Time complexity: O(nlogn)*/

#include<iostream>
using namespace std;

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
    int largest = arr[0];
    int s_largest = -1;
    int len = sizeof(arr);
    if( len < 2)
    {
        return -1;
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {
            s_largest = largest;
            largest = arr[i];
        }
        else if(arr[i] < largest && arr[i] > s_largest){
            s_largest = arr[i];
        }
    }
    cout << "The second largest element is: " << s_largest;
}