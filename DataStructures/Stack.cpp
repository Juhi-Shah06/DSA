#include <iostream>
using namespace std;
#define size 5
class Stack
{
    int stack[size], top;
public:
    void push();
    void pop();
    bool isEmpty();
    bool isFull();
    void display();
    Stack()
    {
        top = -1;
    }
};
bool Stack ::isFull()
{
    if (top == size - 1)
        return true;
    else
        return false;
}
bool Stack ::isEmpty()
{
    if (top == -1)
        return true;
    else
        return false;
}
void Stack ::push()
{
    int val;
    if (isFull())
    {
        cout << "The stack is full " << endl;
    }
    else
    {
        cout << "Enter value " << endl;
        cin >> val;
        top++;
        stack[top] = val;
    }
}
void Stack ::pop()
{
    if (isEmpty())
    {
        cout << "The stack is empty" << endl;
    }
    else
    {
        cout << "Element deleted " << endl;
        top--;
    }
}
void Stack ::display()
{
    if (isEmpty())
    {
        cout << "The stack is empty " << endl;
    }
    else
    {
        cout << "The stack elements are : ";
        for (int i = top; i >= 0; i--)
            cout << stack[i] << " ";
    }
}
int main()
{
    Stack s;
    int ch;
    cout << "*****WELCOME TO THE PROGRAM OF STACK*****" << endl;
    cout << "1).Push " << endl;
    cout << "2).Pop " << endl;
    cout << "3).Display " << endl;
    cout << "4).Exit " << endl;
    do
    {
        cout << "Enter your choice " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            s.push();
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.display();
            break;
        case 4:
            return 0;
            break;
        default:
            cout << "Invalid choice " << endl;
            break;
        }
    } while (ch != 4);
}