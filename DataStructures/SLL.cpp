#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
};
class SLL
{
public:
    node *head, *last;
    void Create();
    void Display();
    void Length();
    void Search();
    void Insert();
    void Delete();
    SLL()  
    {
        head = NULL;
        last = NULL;
    }
};
void SLL::Create()
{
    int val;
    node *temp;
    cout << "Enter a value";
    cin >> val;
    temp = new node;
    temp->data = val;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
        last = temp;
    }
    else
    {
        last->next = temp;
        last = temp;
    }
}
void SLL::Display()
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
void SLL::Length()
{
    int len = 0;
    node *temp;
    temp = head;
    if (temp == NULL)
    {
        cout << "SLL is empty";
    }
    else
    {
        while (temp != NULL)
        {
            len++;
            temp = temp->next;
        }
        cout << "\n Length of SLL is :" << len << endl;
    }
}
void SLL::Search()
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
void SLL::Insert()
{
    node *temp = head;
    node *newNode;
    int val, key;
    if (temp != NULL)
    {

        int menu;
        cout << "Where do you want to insert the node" << endl;
        cout << "1. At the beginning" << endl;
        cout << "2. At the end" << endl;
        cout << "3. After a particular element" << endl;
        cin >> menu;
        cout << "Enter the value you want to add ";
        cin >> val;
        newNode = new node;
        newNode->data = val;
        newNode->next = NULL;
        switch (menu)
        {
        case 1:
            newNode->next = head;
            head = newNode;
            break;
        case 2:
            last->next = newNode;
            last = newNode;
            break;
        case 3:
            cout << "Enter the value after which you want to insert the element " << endl;
            cin >> key;
            while (temp != NULL)
            {
                if (temp->data == key)
                {
                    newNode->next = temp->next;
                    temp->next = newNode;
                    break;
                }
                else
                {
                    temp = temp->next;
                }
            }
            cout << "Node inserted after " << key << endl;
            break;
        default:
            cout << "Invalid input " << endl;
            break;
        }
    }
    else
    {
        cout << "The linked list does not exist.  " << endl;
    }
}
void SLL::Delete()
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
            last = temp;
            temp = temp->next;
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
            delete temp;
            break;
        default:
            cout << "Invalid input " << endl;
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
    SLL s;
    cout << "*****Welcome to SLL*****" << endl;
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
            s.Create();
            break;
        case 2:
            s.Display();
            break;
        case 3:
            s.Length();
            break;
        case 4:
            s.Search();
            break;
        case 5:
            s.Insert();
            break;
        case 6:
            s.Delete();
            break;
            
        case 7:
            return 0;
            break;
        default:
            cout << "Invalid input";
            break;
        }
    } while (ch != 7);
    return 0;
}