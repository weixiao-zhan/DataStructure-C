#include "5_0binaryTree.h"

Node::Node(int dd)
{
    data = dd;
    l_chPtr = NULL;
    r_chPtr = NULL;
    parentPtr = NULL;
}

Node::Node(int dd, Node& ll, Node& rr)
{
    data = dd;
    l_chPtr = &ll;
    r_chPtr = &rr;
    parentPtr = NULL;
}

void Node::operator=(Node& target)
{
    this->data = target.getDate();
    this->l_chPtr = target.getL();
    this->r_chPtr = target.getR();
    this->parentPtr = target.getP();
}

BinaryTree::BinaryTree(Node& rr)
:root(rr)
{
    currentNodePtr = &root;
}

void BinaryTree::insertLeft(Node* targetPtr)
{
    if( (*currentNodePtr).getL() != NULL){
        std::cout << "Current Node has a left Child!    Insert Failed" << std::endl;
        return;
    }
    (*currentNodePtr).l_link(targetPtr);
    (*targetPtr).P_link(currentNodePtr);
}

void BinaryTree::insertRight(Node* targetPtr)
{
    if( (*currentNodePtr).getR() != NULL){
        std::cout << "Current Node has a right Child!   Insert Failed" << std::endl;
        return;
    }
    (*currentNodePtr).r_link(targetPtr);
    (*targetPtr).P_link(currentNodePtr);
}

void BinaryTree::switchTo(Node* targetPtr)
{
    currentNodePtr = targetPtr;
}

void BinaryTree::switchTo(char& s)
{
    if(s == 'p'){//去往父节点
        currentNodePtr = (*currentNodePtr).getP();
        return;
    }

    if(s == 'l'){//去往左节点
        if((*currentNodePtr).getL() == NULL){
            std::cout << "No left children" << std::endl;
            return;
        }
        currentNodePtr = (*currentNodePtr).getL();
        return;
    }

    if(s == 'r'){//去往右节点
        if((*currentNodePtr).getR() == NULL){
            std::cout << "No right children" << std::endl;
            return;
        }
        currentNodePtr = (*currentNodePtr).getR();
    }

    if(s == 'R'){//回到根节点
        currentNodePtr = &root;
    }
}

void BinaryTree::TraversePrint(char c)
{
    Node* ptr = &root;
    switch(c)
    {
        case 'm':
            _midTraverse(ptr);
            break;
        case 'f':
            _fTraverse(ptr);
            break;
        case 'l':
            _lTraverse(ptr);
            break;
    }
}

void BinaryTree::_midTraverse(Node* ptr) const
{
    if(ptr == NULL){
        return;
    }
    _midTraverse( ptr->getL() );
    (*ptr).print();
    _midTraverse( ptr->getR() );
}

void BinaryTree::_fTraverse(Node* ptr) const
{
    if(ptr == NULL){
        return;
    }
    (*ptr).print();
    _fTraverse( ptr->getL() );
    _fTraverse( ptr->getR() );
}

void BinaryTree::_lTraverse(Node* ptr) const
{
    if(ptr == NULL){
        return;
    }
    _fTraverse( ptr->getL() );
    _fTraverse( ptr->getR() );
    (*ptr).print();
}