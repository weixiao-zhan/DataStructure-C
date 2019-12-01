#include"5_4SearchTree.h"

int main()
{
    SearchTree s;
    s.insert(1);
    s.insert(2);
    s.insert(3);

    TreeNode* ptr = s.search(3);
    printf("%d", ptr->data);
}