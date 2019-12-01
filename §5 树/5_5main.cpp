#include"5_5AVL.cpp"
using namespace std;

int main()
{
    AVLTree A;
    A << 1 << 3 << 5 << 7 << 9;
    cout <<( A.search(4) ? "Exist!" : "Not Exist" )<< endl;
}