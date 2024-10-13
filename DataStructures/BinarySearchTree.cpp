#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
};
class BST
{
public:
    node *root;
    void create();
    void search(node *, int);
    void insert(node *, node *);
    void inorder(node *);
    void preorder(node *);
    void postorder(node *);
    BST()
    {
        root = NULL;
    }
};
void BST::create()
{
    node *temp;
    int val;
    cout << "Enter a value " << endl;
    cin >> val;
    temp = new node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        insert(root, temp);
    }
}
void BST::insert(node *root, node *temp)
{
    if (temp->data < root->data)
    {
        if (root->left == NULL)
            root->left = temp;
        else
            insert(root->left, temp);
    }
    else
    {
        if (root->right == NULL)
            root->right = temp;
        else
            insert(root->right, temp);
    }
}
void BST::search(node *root, int val)
{
    if (root == NULL)
    {
        cout << "Element does not exist " << endl;
    }
    else
    {
        if (val < root->data)
            search(root->left, val);
        else if (val > root->data)
            search(root->right, val);
        else if (root->data == val)
        {
            cout << root->data << " found " << endl;
        }
    }
}
void BST::inorder(node *temp)
{
    if (temp != NULL)
    {
        inorder(temp->left);
        cout << " " << temp->data;
        inorder(temp->right);
    }
}
void BST::preorder(node *temp)
{
    if (temp != NULL)
    {
        cout << " " << temp->data;
        preorder(temp->left);
        preorder(temp->right);
    }
}
void BST::postorder(node *temp)
{
    if (temp != NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        cout << " " << temp->data;
    }
}
int main()
{
    int ch;
    BST bt;
    cout << "*****Welcome to Binary search tree*****" << endl;
    cout << "1.Create " << endl;
    cout << "2.Search " << endl;
    cout << "3.Preorder Traversal " << endl;
    cout << "4.Inorder Traversal " << endl;
    cout << "5.Postorder Traversal " << endl;
    cout << "6.Exit" << endl;
    do
    {
        cout << "Enter your choice" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            bt.create();
            break;
        case 2:
            int val;
            cout << "Enter the value you want to search " << endl;
            cin >> val;
            bt.search(bt.root, val);
            break;
        case 3:
            bt.preorder(bt.root);
            break;
        case 4:
            bt.inorder(bt.root);
            break;
        case 5:
            bt.postorder(bt.root);
            break;
        case 6:
            return 0;
            break;
        default:
            cout << "Invalid input";
            break;
        }
    } while (ch != 6);
    return 0;
}
