#include<iostream>

int max(int a, int b)
{
    return a>b ? a : b;
}

typedef struct node {
    int data;
    int height;
    struct node* left;
    struct node* right;
}Node;

class AVLTree
{
private:
    Node* root;

    int C_Height(Node*) const;
    int BalanceFactor(Node*);

    Node* RotateR(Node*);
    Node* RotateL(Node*);

    Node* Balance(Node*);

    void insert(Node**, int);
    //void remove(Node**, int);
    bool search(Node*, int);

public:
    AVLTree();
    int C_Height(){return C_Height(root);}
    void insert(int val){insert(&root, val);}
    AVLTree& operator<<(int val){insert(&root, val);return *this;}
    //void remove(int val){remove(&root, val);}
    bool search(int val){return search(root, val);}
};

AVLTree::AVLTree()
:root(NULL)
{
    ;
}

int AVLTree::C_Height(Node* rr) const 
{
    if(rr == NULL){
        return 0;
    }else{
        return max(C_Height(rr->left), C_Height(rr->right)) + 1;
    }
}

int AVLTree::BalanceFactor(Node* rr)
{
    if(rr == NULL){
        return 0;
    }else{
        return rr->left->height - rr->right->height;
    }
}

Node* AVLTree::RotateR(Node* rr)
{
    Node* left = rr->left;
    
    rr->left = left->right; // 将将要被抛弃的节点连接为旋转后的 root 的左孩子
    left->right = rr; // 调换父子关系

    left->height = max(C_Height(left->left), C_Height(left->right))+1;
    rr->height = max(C_Height(rr->left), C_Height(rr->right))+1;
    
    return left;
}

Node* AVLTree::RotateL(Node* rr)
{
    Node* right = rr->right;

    rr->right = right->left;
    right->left = rr;

    rr->height = max(C_Height(rr->left), C_Height(rr->right))+1;
    right->height = max(C_Height(right->left), C_Height(right->right))+1;

    return right;
}


Node* AVLTree::Balance(Node* root)
{

    int  factor = BalanceFactor(root);

    if(factor > 1 && BalanceFactor(root->left) > 0) // LL
        return RotateR(root);
    
    else if(factor > 1 && BalanceFactor(root->left) <= 0){ //LR
        root->left = RotateL(root->left);
        return RotateR(root);
    }

    if(factor < -1 && BalanceFactor(root -> right) <= 0) //RR
        return RotateL(root);
    else if(factor < -1 && BalanceFactor(root->right) > 0){ //RL
        root->right = RotateR(root->right);
        return RotateL(root);
    }

    else{
        return root;
    }
}

void AVLTree::insert(Node** rootptr, int value)
{
    Node* newNode;
    Node* root = *rootptr;

    if(root == NULL) {
        newNode = new Node;
        newNode->data = value;
        newNode->left = newNode->right = NULL;
        *rootptr = newNode;
    } else if(root->data == value) {
        printf("element exist in tree!\n");
        return;
    }else{
        if(root->data < value)
            insert(&root->right, value);
        else
            insert(&root->left, value);
    }
    Balance(root);
}

/*
void AVLTree::remove(Node** rootptr, int value)
{
    Node* toFree; // 拜拜了您呐
    Node* root = *rootptr;

    if(root){
        if(root->data == value) {

            if(root->right) {
                root->data = treeDeleteMin(&(root->right));
            } else {
                toFree = root;
                *rootptr = toFree->left;
                free(toFree);
            }

        } else {
        if(root->data < value)
            remove(&root->right, value);
        else
            remove(&root->left, value);
        }
        Balance(root);
    }else{
        puts("element not in tree!");
    }
}
*/

bool AVLTree::search(Node* rr, int val)
{
    if(rr == NULL){
        return false;
    }else if(val == rr->data){
        return true;
    }else{
        return (val < rr->data) ? search(rr->left, val) : search(rr->right, val);
    }
}