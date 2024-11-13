/*Write a program to print your name n times by using recursion*/
// Time complexity: O(N)
// Space complexity: O(N)

#include <iostream>
using namespace std;

//Method - 1 
// void name()
// {
//     string name = "Juhi";
//     for (int i = 1; i <= 5; i++)
//     {
//         cout << name << endl;
//     }
// }
// int main()
// {
//     name();
//     return 0;
// }

//Method - 2
void name(int i, int n)
{
    string names = "Juhi";
    if (i > n)
    {
        return;
    }
    else
    {
        cout << names << endl;
        name(i + 1, n);
    }
}

int main()
{
    int n;
    cout << "Enter value for n: ";
    cin >> n;
    name(1, n);
}
