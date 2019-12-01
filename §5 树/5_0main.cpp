#include"5_0binaryTree.cpp"
#include<iostream>
using namespace std;

int main()
{
    char l = 'l';
    char r = 'r';
    char p = 'p';
    char R = 'R';

    Node root(0);
    Node Node1(1), Node2(2), Node3(3);

    BinaryTree tree(root);

    tree.printCurrentNode();

    tree.insertLeft(&Node1);
    tree.insertRight(&Node2);

    tree.switchTo(l);
    tree.printCurrentNode();

    tree.insertLeft(&Node3);
    tree.switchTo(l);
    tree.printCurrentNode();

    tree.switchTo(R);
    tree.printCurrentNode();

    cout << endl;
    tree.TraversePrint('f');
    tree.TraversePrint('m');
    tree.TraversePrint('l');
    

    return 0;
}