#include <iostream>
#include <fstream>

#include "Functions.h"
#include "Node.h"

using namespace std;

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
    myFile.open("example.txt");
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
