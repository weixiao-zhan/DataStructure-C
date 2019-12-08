#ifndef TRANSPOSE
#define TRANSPOSE

#include<iostream>
#define MAX_SIZE 20000

typedef struct{
    int col, row;
    int value;
}term;//稀疏矩阵存储三元组
//数组[0].col = 矩阵列数，[0].row = 矩阵行数，[0].value = 矩阵元素个数
//按行优先排列

void fast_transpose(term a[], term b[], int n = MAX_SIZE)
{
    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].value = a[0].value;
    int num_cols = a[0].col, num_terms = a[0].value;

    int row_terms[n], starting_pos[n];

    if(num_terms <= 0){
        return;
    }

    for(int i = 0; i < num_terms; i++){
        row_terms[i] = 0;
    }

    for(int i = 0; i <= num_terms; i++){
        row_terms[a[i].col]++;
    }//把每行数据个数统计并计入 row_terms 中

    starting_pos[0] = 1;
    for(int i = 1; i <= num_terms; i++){
        starting_pos[i] = starting_pos[i-1] + row_terms[i];//计算每行开始的index
    }

    for(int i = 1; i <= num_terms; i++){
        int j = starting_pos[a[i].col]++;
        b[j].row = a[i].col;
        b[j].col = a[i].row;
        b[j].value = a[i].value;
    }
    return;
}

void common_tranpose(term a[], term b[])
{
    int n = a[0].value;
    b[0].col = a[0].row;
    b[0].row = a[0].col;
    b[0].value = a[0].value;

    if(n <= 0){
        return;
    }

    int current_b_pos = 1;
    for(int i = 0; i < a[i].col; i++){
        for(int j = 0; j <= n; j++){
            if(a[j].col == i){
                b[current_b_pos].col = a[j].row;
                b[current_b_pos].row = a[j].col;
                b[current_b_pos].value = a[j].value;
                current_b_pos++;
            }
        }
    }
}

#endif