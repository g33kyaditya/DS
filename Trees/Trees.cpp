/*****************************************************************************************
 *   Author: Aditya Dev Sharma                                                           *
 *   Roll: UE143003                                                                      *
 *   Data Structures Assignment - Diwali Holidays                                        *
 *   Compiler : GNU GCC                                                                  *
 *   The whole code can be found on: https://github.com/g33kyaditya/DS/tree/master/Trees *
 *****************************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;
class Node
{
    public:
        int getData() const;
        Node* getLeft() const;
        Node* getRight() const;
        void setData(int);
        void setLeft(Node*);
        void setRight(Node*);
    protected:
    private:
        int m_Data;
        Node* p_Left;
        Node* p_Right;
};

void insertBinaryTree();
void insertBinaryTreeFromFile();
Node* preorderTraverse(Node*);
Node* inorderTraverse(Node*);
Node* postorderTraverse(Node*);

void insert(int);
void insert(Node*,int);
Node* createNode(int);

static Node* Root = nullptr;
int main()
{
    char ch;
    do {
        cout << "\t****************Operations****************\n";
        cout << "\t 1. Insert a Binary Tree\n";
        cout << "\t 2. Insert a Binary Tree from local file\n";
        cout << "\t 3. Preorder Traversal\n";
        cout << "\t 4. Inorder Traversal\n";
        cout << "\t 5. Postorder Traversal\n";
        cout << "\t Enter your Choice : ";
        int choice;
        cin >> choice;
        switch(choice)
        {
            case 1:
                    insertBinaryTree();
                    break;
            case 2:
                    insertBinaryTreeFromFile();
                    break;
            case 3:
                    cout << "Preorder Traversal \n";
                    preorderTraverse(Root);
                    cout << "\n";
                    break;
            case 4:
                    cout << "Inorder Traversal \n";
                    inorderTraverse(Root);
                    cout << "\n";
                    break;
            case 5:
                    cout << "Postorder Traversal \n";
                    postorderTraverse(Root);
                    cout << "\n";
                    break;
            default:
                    cout << "\t Wrong Choice! Exiting ";
                    return 0;
        }
        cout << "Want to perform more functions (y/n) ? ";
        cin >> ch;
    }while(ch == 'Y' || ch == 'y');
    return 0;
}

void insert(int data)
{
    if (Root == nullptr)
    {
        Node* temp = createNode(data);
        Root = temp;
    }
    else
    {
        insert(Root,data);
    }
}

void insert(Node* Leaf, int data)
{
    if (data <= Leaf->getData())
    {
        if (Leaf->getLeft() != nullptr)
            insert(Leaf->getLeft(),data);
        else
        {
            Node *t = createNode(data);
            Leaf->setLeft(t);
        }
    }
    else
    {
        if (Leaf->getRight() != nullptr)
            insert(Leaf->getRight(),data);
        else
        {
            Node *t = createNode(data);
            Leaf->setRight(t);
        }
    }
}

int Node::getData() const
{
    return m_Data;
}

Node* Node::getLeft() const
{
    return p_Left;
}

Node* Node::getRight() const
{
    return p_Right;
}
void insertBinaryTree()
{
    int n;
    cout << "Enter the number of nodes you want to insert in the Tree : ";
    cin >> n;
    int t = n;
    while (n--)
    {
        cout << "Enter the data : ";
        int data;
        cin >> data;
        insert(data);
    }

}

void insertBinaryTreeFromFile()
{
    ifstream myFile;
    myFile.open("example.txt");     //NOTE: Store it in the same directory as the Trees.cpp with the data.
    int c = 0;
    char array[1000];
    if (myFile.fail())
    {
        cout << "Error! Cannot open File \n";
    }
    if (myFile.is_open())
    {
        while(!myFile.eof())
        {
            myFile.get(array[c++]);
        }
    }
    int arr[1000];
    for (int i=0;i<c;i++)
    {
        arr[i] = array[i]-'0';
    }
    for (int i=0;i<c;i++)
    {
        insert(arr[i]);
    }
}

Node* createNode(int val = -1)
{
    Node* temp = new Node;
    temp->setData(val);
    temp->setLeft(nullptr);
    temp->setRight(nullptr);
}

Node* preorderTraverse(Node* root)
{
    if (root == nullptr)
        return nullptr;

    if(root->getData() > 0)
    cout << root->getData() << " -> ";
    preorderTraverse(root->getLeft());
    preorderTraverse(root->getRight());
}

Node* inorderTraverse(Node* root)
{
    if (root == nullptr)
        return nullptr;


    preorderTraverse(root->getLeft());
    if(root->getData() > 0)
    cout << root->getData() << " -> ";
    preorderTraverse(root->getRight());
}

Node* postorderTraverse(Node* root)
{
    if (root == nullptr)
        return nullptr;


    postorderTraverse(root->getLeft());
    postorderTraverse(root->getRight());
    if(root->getData() > 0)
    cout << root->getData() << " -> ";
}
void Node::setData(int val)
{
    m_Data = val;
}

void Node::setLeft(Node* p)
{
    p_Left = p;
}

void Node::setRight(Node* p)
{
    p_Right = p;
}
