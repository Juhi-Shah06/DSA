/*Write a program to check if a string is palindrome.

Example:
Input: Str =  “ABCDCBA”
Output: Palindrome

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>
using namespace std;

void palindromeString(string s)
{
    int len = s.length();
    for (int i = 0; i < len / 2; i++)
    {
        if (s[i] != s[len - i - 1])
        {
            cout << " Not Palindrome";
            return;
        }
    }
    cout << "Palindrome";
}

int main()
{
    string s = "";
    cout << "Enter a string: ";
    cin >> s;
    palindromeString(s);
}
