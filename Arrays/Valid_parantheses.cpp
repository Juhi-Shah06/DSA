/*Problem Statement: Given a string s containing just the characters
'(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
1.Open brackets must be closed by the same type of brackets.
2.Open brackets must be closed in the correct order.
3.Every close bracket has a corresponding open bracket of the same type.
Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "()[]{}"
Output: true

Example 3:
Input: s = "(]"
Output: false
Time complexity: O(N)
*/

#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string s;
    cout << "Enter the string: ";
    cin >> s;
    stack<char> st;
    bool isValid = true;
    for (char ch : s)
    {
        if (ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch);
        }
        else
        {
            if (st.empty())
            {
                isValid = false;
                break;
            }
            char top = st.top();
            st.pop();
            if ((ch == ')' && top != '(') || (ch == '}' && top != '{') || (ch == ']' && top != '['))
            {
                isValid = false;
                break;
            }
        }
    }
    if (!st.empty())
    {
        isValid = false;
    }

    if (isValid)
    {
        cout << "The string is valid." << endl;
    }
    else
    {
        cout << "The string is not valid." << endl;
    }
    return 0;
}
