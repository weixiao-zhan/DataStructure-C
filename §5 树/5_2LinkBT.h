#include<iostream>

class Node
{
private:
    int data;
    Node *l_Ptr, *r_Ptr, *p_Ptr;

public:
    bool l_Thread, r_Thread;

    Node(int dd)
    :data(dd), l_Ptr(NULL), r_Ptr(NULL), l_Thread(false), r_Thread(false){}
    
    void l_link(Node* ptr){l_Ptr = ptr;}
    void r_link(Node* ptr){r_Ptr = ptr;}
    void p_link(Node* ptr){r_Ptr = ptr;}

    int getDate()const {return data;}
    Node* getL() const {return l_Ptr;}
    Node* getR() const {return r_Ptr;}
    Node* getP() const {return p_Ptr;}


    void operator=(const Node&);
    void print(){printf("%4d", data);}
};

void Node::operator=(const Node& target)
{
    this->data = target.getDate();
    this->l_Ptr = target.getL();
    this->r_Ptr = target.getR();
    this->p_Ptr = target.getP();
    this->l_Thread = target.l_Thread;
    this->r_Thread = target.r_Thread;
}


class L_BT
{
private:
    Node root;
public:
    Node* currentNodePtr;

    L_BT(const Node&);
    void insertLeft(Node&);
    void insertRight(Node&);

    void switchTo(char&);

    void MidTraversePrint();
};

L_BT::L_BT(const Node& rr)
:root(rr)
{
    root.l_Thread = true;
    root.r_Thread = true;
    currentNodePtr = &root;
}

void L_BT::insertLeft(Node& temp)
{
    
    if( !(*currentNodePtr).l_Thread ){
        puts("current Node has a left child!\tInsert failed");
        return;
    }
    if(temp.getL() != NULL && temp.getR() != NULL && temp.getP() != NULL){
        puts("The node may already in another tree!\tInsert failed!");
        return;
    }

    (*currentNodePtr).l_Thread = false;
    temp.l_Thread = true;
    temp.r_Thread = true;

    temp.l_link((*currentNodePtr).getL());
    temp.r_link(currentNodePtr);
    (*currentNodePtr).l_link(&temp);
}

void L_BT::insertRight(Node& temp)
{
    if( !(*currentNodePtr).r_Thread ){
        puts("current Node has a right child!\tInsert failed");
        return;
    }
    if(temp.getL() != NULL && temp.getR() != NULL && temp.getP() != NULL){
        puts("The node may already in another tree!\tInsert failed!");
        return;
    }


    (*currentNodePtr).r_Thread = false;
    temp.r_Thread = true;
    temp.l_Thread = true;

    temp.l_link(currentNodePtr);
    temp.r_link((*currentNodePtr).getR());

    (*currentNodePtr).r_link(&temp);
}


void L_BT::switchTo(char& s)
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

void L_BT::MidTraversePrint()
{
    Node* nPtr = &root;
    while(!nPtr->l_Thread){
        nPtr = nPtr->getL();
    }
    while(nPtr->getR() != NULL){
        nPtr->print();
        nPtr = nPtr->getR();
    }
    nPtr->print();
    printf("\n");
}