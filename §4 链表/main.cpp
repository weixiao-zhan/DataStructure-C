#include<iostream>
#include<ctime>
#include<stdlib.h>
#include "FastTranspose.h"

using namespace std;

int main()
{
    //srand( (unsigned)time( NULL ) );//srand()函数产生一个以当前时间开始的随机种子 
    clock_t start1, start2, end1, end2;
    term a[100001], b[100001], c[100001];
    //2000000000
    //10000 00001
    a[0].col = 100;
    a[0].row = 100;
    a[0].value = 10000;

    for(int i = 1; i <= 100; i++){
        for(int j = 1; j <= 100; j++){
            a[(i-1) * 100 + j].col = i;
            a[(i-1) * 100 + j].row = j;
            a[(i-1) * 100 + j].value = rand() % 10000;
        }
    }
    start1 = clock();
    common_tranpose(a, b);
    end1 = clock();

    start2 = clock();
    fast_transpose(a, c);
    cout << "!" <<endl;
    end2 = clock();

    cout << "Common Transpose = " << (double)(start1 - end1) / CLOCKS_PER_SEC * 1000  << "ms" << endl;
    cout << " Fast  Transpose = " << (double)(start2 - end1) / CLOCKS_PER_SEC * 1000 << "ms" << endl;

    return 0;
}