//先序表达式建立二叉树

#include<iostream>
#include<string>
using namespace std;

typedef struct node{
    int data;
    struct node* lptr;
    struct node* rPtr;
}Node;


void build(Node* t, string& s, int& n)
{
    char ch = s[n++];
    if( ch == ';'){
        return;
    }
    if(ch != '#'){
        t = new Node;
        (*t).data = ch;
        build((*t).lptr, s, n);
        build((*t).rPtr, s, n);
    }else{
        t = NULL;
    }    
}

int main()
{
    Node root;
    string s = "123##45#6##7###;";
    int n = 0;
    build(&root, s, n);
    cout << root.data << endl;
    cout << root.lptr->data<< endl;
    //cout << (*(root.lptr->lptr)).data << "\t" << (*(root.lptr->rPtr)).data << endl;
}