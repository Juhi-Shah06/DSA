#include <bits/stdc++.h>
using namespace std;

int main()
{
    // say we have {1,5,3,2,6,4} and we want to sort this
    int a, n;
    sort(a, a + 6); // syntax: sort(first number, last number(pointer is after the last digit so that all the numbers are sorted))

    // if we want to sort from 2nd to 4th element
    sort(a + 2, a + 4);

    // sort in descending order
    sort(a, a + n, greater<int>);

}