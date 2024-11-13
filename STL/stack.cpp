/* STL:
 STACK: Last In First Out [LIFO]
 Time complexity : O(1)   everything happens in constant time
 */

#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> st;
    st.push(1);    //{1}
    st.push(2);    //{2,1}
    st.push(3);    //{3,2,1}
    st.push(4);    //{4,3,2,1}
    st.emplace(5); //{5,4,3,2,1}

    cout << st.top(); // print 5  **st[2] is not valid in stack

    st.pop(); // will remove or delete the topmost element of stack

    cout << st.top();

    cout << st.size(); // returns 4 as answer

    cout << st.empty(); // returns boolean value whether stack is empty or not       here->false

    stack<int> s1, s2;
    s1.swap(s2); // to swap the contents of both the stacks
}