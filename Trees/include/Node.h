#ifndef NODE_H
#define NODE_H


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

#endif // NODE_H
