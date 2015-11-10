#include "Node.h"

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
