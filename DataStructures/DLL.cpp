#include <iostream>
using namespace std;
class node
{
public:
    node *prev;
    int data;
    node *next;
};
class DLL
{
public:
    node *head, *last;
    void Create();
    void Traverse();
    void Length();
    void Search();
    void Insert();
    void Delete();
    DLL()
    {
        head = NULL;
        last = NULL;
    }
};
void DLL::Create()
{
    int val;
    node *temp;
    cout << "Enter a value" << endl;
    cin >> val;
    temp = new node;
    temp->data = val;
    temp->next = NULL;
    temp->prev = NULL;
    if (head == NULL)
    {
        head = temp;
        last = temp;
    }
    else
    {
        last->next = temp;
        temp->prev = last;
        last = temp;
    }
}
void DLL::Traverse()
{
    node *temp = head;
    if (temp != NULL)
    {
        cout << "Linked list elements are : " << endl;

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    else
    {
        cout << "The list does not exist " << endl;
    }
}
void DLL::Length()
{
    int len = 0;
    node *temp;
    temp = head;
    if (temp == NULL)
    {
        cout << "DLL is empty";
    }
    else
    {
        while (temp != NULL)
        {
            len++;
            temp = temp->next;
        }
        cout << "Length of DLL is :" << len << endl;
    }
}
void DLL::Search()
{
    int key;
    node *temp;
    cout << "Enter the value to search" << endl;
    cin >> key;
    if (head == NULL)
    {
        cout << "Empty" << endl;
    }
    else
    {
        temp = head;
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                cout << key << " is found" << endl;
                break;
            }
            else
            {
                temp = temp->next;
            }
            if (temp == NULL)
            {
                cout << key << " is not found";
            }
        }
    }
}
void DLL::Insert()
{
    int val, ch, key;
    node *temp, *temp1;
    cout << "Enter value you wish to insert: " << endl;
    cin >> val;

    temp = new node;
    temp->data = val;
    temp->next = NULL;
    temp->prev = NULL;

    cout << "Enter where you want to insert : " << endl;
    cout << "1.At the beginning : " << endl;
    cout << "2.At the end : " << endl;
    cout << "3.After a particular element : " << endl;
    cout << "4.End" << endl;
    cin >> ch;
    switch (ch)
    {
    case 1:
        temp->next = head;
        head->prev = temp;
        head = temp;
        break;

    case 2:
        last->next = temp;
        temp->prev = last;
        last = temp;
        break;

    case 3:
        cout << "Enter the value after which you want the element : " << endl;
        cin >> key;
        temp1 = head;
        while (temp1 != NULL)
        {
            if (temp1->data == key)
                break;
            else
                temp1 = temp1->next;
        }
        temp->next = temp1->next;
        temp1->next->prev = temp;
        temp1->next = temp;
        temp->prev = temp1;
        break;
    case 4:
        cout << "End";
        break;
    default:
        cout << "Enter valid number" << endl;
        break;
    }
}

void DLL::Delete()
{
    node *temp = head;
    node *newNode;
    int val, key;
    if (temp != NULL)
    {

        int menu;
        cout << "Where do you want to delete the node from" << endl;
        cout << "1. At the beginning" << endl;
        cout << "2. At the end" << endl;
        cout << "3. Delete a particular element" << endl;
        cin >> menu;
        switch (menu)
        {
        case 1:
            temp = head;
            head = head->next;
            delete temp;
            break;

        case 2:
            while (temp->next != last)
            {
                temp = temp->next;
            }
            temp = last;
            last = last->prev;
            delete temp;
            last->next = NULL;
            break;

        case 3:
            cout << "Enter the value which you want to delete";
            cin >> key;
            while (temp != NULL)
            {
                if (temp->data == key)
                {
                    break;
                }
                else
                {
                    newNode = temp;
                    temp = temp->next;
                }
            }
            newNode->next = temp->next;
            temp->next->prev = newNode;
            delete temp;
            break;
        default:
            cout << "Please enter a valid input. " << endl;
            break;
        }
    }
    else
    {
        cout << "The linked list does not exist. " << endl;
    }
}

int main()
{
    int ch;
    DLL d;
    cout << "*****Welcome to DLL*****" << endl;
    cout << "1.Create a node" << endl;
    cout << "2.Display node" << endl;
    cout << "3.Length" << endl;
    cout << "4.Search" << endl;
    cout << "5.Insert" << endl;
    cout << "6.Delete" << endl;
    cout << "7.Exit" << endl;
    do
    {
        cout << "Enter your choice" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            d.Create();
            break;
        case 2:
            d.Traverse();
            break;
        case 3:
            d.Length();
            break;
        case 4:
            d.Search();
            break;
        case 5:
            d.Insert();
            break;
        case 6:
            d.Delete();
            break;
        case 7:
            return 0;
            break;
        default:
            cout << "Invalid Input ";
            break;
        }
    } while (ch != 7);
    return 0;
}