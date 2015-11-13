/*************************************************
 *   Author: Aditya Dev Sharma                   *
 *   Roll: UE143003                              *
 *   Data Structures Assignment - Diwali Holidays*
 *   Compiler : GNU GCC                          *
 *************************************************/


#include <iostream>

#include "Node.h"
#include "Functions.h"
using namespace std;

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
