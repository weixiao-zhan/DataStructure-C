#include<iostream>

class Node
{
private:
    int data;
    Node *l_chPtr, *r_chPtr, *parentPtr;

public:
    void l_link(Node* lPtr){l_chPtr = lPtr;}
    void r_link(Node* rPtr){r_chPtr = rPtr;}
    void P_link(Node*pPtr){parentPtr = pPtr;}

    Node(int data);
    Node(int data, Node& l_ch, Node& r_ch);

    int getDate(){return data;}
    Node* getL(){return l_chPtr;}
    Node* getR(){return r_chPtr;}
    Node* getP(){return parentPtr;}
    void operator=(Node&);

    void print(){std::cout << data << std::endl;};
};

class BinaryTree
{
private:
    Node root;
    void _midTraverse(Node* Ptr) const;
    void _fTraverse(Node* Ptr) const;
    void _lTraverse(Node* Ptr) const;

public:
    Node* currentNodePtr;

    BinaryTree(Node&);
    void insertLeft(Node*);
    void insertRight(Node*);
    
    void switchTo(Node*);
    void switchTo(char&);

    void printCurrentNode() const {(*currentNodePtr).print();}
    void TraversePrint(char c);

    //bool Delete(Node*);//删除后父节点不知道左继or右继换为NULL
};