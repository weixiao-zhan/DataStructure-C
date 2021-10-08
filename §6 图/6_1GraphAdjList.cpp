#include<iostream>

typedef struct node{
    int NodeIndex;
    struct node* Ptr;
}Node;

int max(int a, int b)
{
    return (a>b)?a:b;
}

class graph
{
private:
    Node* Nodes;
    int size;
public:
    graph(int, int);
    void print();
};

graph::graph(int v_num, int e_num)
:size(v_num)
{
    Nodes = new Node[v_num]();
    for(int i = 0; i < v_num; i++){
        Nodes[i].NodeIndex = i;
        Nodes[i].Ptr = NULL;
    }

    printf("PLz input the edges:\n");
    int temp1, temp2;
    for(int i = 0; i < e_num; i++){
        std::cin >> temp1 >> temp2;

        Node* temp = new Node;
        temp->NodeIndex = temp2;
        Node* old = Nodes[temp1].Ptr;

        Nodes[temp1].Ptr = temp;
        temp->Ptr = old;
    }
    puts("Graph created!");
}

void graph::print()
{
    int g[size][size];
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            g[i][j] = 0;
        }
    }

    for(int i = 0; i < size; i++){
        Node* temp = Nodes[i].Ptr;
        while(temp != NULL){
            g[i][temp->NodeIndex] = 1;
            temp = temp->Ptr;
        }
    }

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            printf("%d ", max(g[i][j], g[j][i]));
        }
        printf("\n");
    }
}


int main()
{
    printf("Plz input the number of the vertexs and edges: ");
    int v, e;
    std::cin >> v >> e;
    graph G(v,e);
    G.print();
}
