#include<iostream>

typedef struct treenode{
    int data;
    struct treenode *l_ptr, *r_ptr, *p_ptr;
}TreeNode;

class SearchTree
{
private:
    TreeNode* root;

    TreeNode* search(TreeNode* Ptr, int data);
    void insert(TreeNode* *Ptr, int data);
    void remove(TreeNode* *Ptr, int data);

public:
    SearchTree();

    TreeNode* search(int data);
    void insert(int data);
    void remove(int data);
};

SearchTree::SearchTree()
{
    root = NULL;
}

TreeNode* SearchTree::search(int dd)
{
    return search(root, dd);
}

TreeNode* SearchTree::search(TreeNode* Ptr, int dd)
{
    if(!Ptr){
        return NULL;
    }
    if(Ptr->data == dd){
        return Ptr;
    }
    if(dd < Ptr->data){
        return search(Ptr->l_ptr, dd);
    }
    return search(Ptr->r_ptr, dd);
}

void SearchTree::insert(int dd)
{
    insert(&root, dd);
}

void SearchTree::insert(TreeNode** node, int dd)
{
    TreeNode* ptr, *temp = search(dd);
    if( temp == NULL || (*node) ){
        //dd not in the tree
        ptr = new TreeNode;
        ptr->data = dd;
        ptr->l_ptr = ptr->r_ptr = NULL;

        if(*node){
            if(dd < temp->data){
                temp->l_ptr = ptr;
            }else{
                            temp->r_ptr = ptr;
            }
        }else{
                    *node = ptr;
        }
    }
}