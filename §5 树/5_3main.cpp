#include"5_3MaxTree.h"
using namespace std;

int main()
{
    MaxTree t(10);
    t << 5 << 10 << 12 << 1;

    int temp = t.pop();
    while(temp != 0){
        printf("%d > ", temp);
        temp = t.pop();
    }
}