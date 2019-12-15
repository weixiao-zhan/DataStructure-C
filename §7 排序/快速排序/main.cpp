#include<iostream>
#include"QuickSort.h"
using namespace std;



int main()
{
    int array[10];
    for(int i = 0; i < 10; i++){
        array[i] = 10 - i;
    }

    quicksort<int> (array, 0, 9);
    for(int i = 0; i < 10; i++){
        cout << array[i] << " ";
    }
    cout << endl;
    return 0;
}