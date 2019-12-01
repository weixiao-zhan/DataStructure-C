#include<iostream>
typedef int TreeNode;

void swap(TreeNode* p1, TreeNode* p2)
{
    TreeNode temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

class MaxTree
{
private:
    TreeNode* tree;//tree[0] : count; tree[1] : root
    int size;
    void insert(TreeNode);
public:
    MaxTree(int size);
    int GetSize(){return tree[0];}

    MaxTree& operator<<(TreeNode item);
    TreeNode pop();
};

MaxTree::MaxTree(int ss)
:size(ss)
{
    tree = new TreeNode[ss];
    tree[0] = 0;
}

void MaxTree::insert(TreeNode item)
{
    int i;

    if(tree[0] == size){
        puts("MaxTree full!");
    }
    tree[0]++;
    i = tree[0];
    while( (i != 1) && (item > tree[i/2]) ){
        tree[i] = tree[i/2];
        i /= 2;
    }
    tree[i] = item;
}

TreeNode MaxTree::pop()
{
    int parent, child;
    TreeNode item, temp;

    if(tree[0] == 0){
        puts("MaxTree empty!");
        return 0;
    }

    item = tree[1];
    temp = tree[tree[0]];
    tree[0]--;
    
    parent = 1;
    child = 2;

    while(child <= tree[0]){
        if(child < tree[0] && tree[child] < tree[child + 1]){
            child++;
        }
        if(temp >= tree[child]){
            break;
        }
        tree[parent] = tree[child];
        parent = child;
        child *= 2;
    }
    tree[parent] = temp;
    return item;
}

MaxTree& MaxTree::operator<<(TreeNode item)
{
    insert(item);
    return (*this);
}