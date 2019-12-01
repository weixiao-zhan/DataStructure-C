#include"5_2LinkBT.h"
using namespace std;

int main()
{
    Node n0(0);
    Node n1(1);
    Node n2(2);
    Node n3(3);
    Node n4(4);

    char l = 'l', R = 'R', r = 'r';
    L_BT tree(n0);
    tree.insertLeft(n1);
    tree.insertRight(n2);
    tree.switchTo(l);
    tree.insertRight(n3);
    tree.insertLeft(n4);
    tree.MidTraversePrint();
}