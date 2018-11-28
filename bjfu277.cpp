//bjfu277
//
#include <iostream>
using namespace std;

const int MaxSize=100;

typedef struct Node{
    int datum;
    struct Node *next=NULL;
}Node, *Np;

typedef struct Graph{
    Np list[MaxSize];
    int vertex_num,arc_num;
}Graph;

int initGraph(Graph &g){
    cin>>g.vertex_num>>g.arc_num;
    if(g.arc_num==0&&g.vertex_num==0){
        return 0;
    }
    for (int i = 0; i < MaxSize; ++i) {
        g.list[i]=new Node;
        g.list[i]->datum=i;
    }
    for (int i = 0; i < g.arc_num; ++i) {
        int a,b;
        cin>>a>>b;
        Np t1,t2;
        t1=new Node;
        t1->datum=a;
        t1->next=g.list[b]->next;
        g.list[b]->next=t1;
        t2=new Node;
        t2->datum=b;
        t2->next=g.list[a]->next;
        g.list[a]->next=t2;
    }
    return 1;
}

void showGraph(Graph g){
    for (int i = 1; i < g.vertex_num+1; ++i) {
        Np t=g.list[i];
        while (t->next!=NULL){
            cout<<t->datum<<' ';
            t=t->next;
        }
        cout<<t->datum<<endl;
    }
}

void deleteVertex(Graph &g, int v){
    g.vertex_num--;
    Np t=g.list[v]->next;
    while (t!=NULL){
        Np t2=g.list[t->datum];
        while (t2->next!=NULL){
            if(t2->next->datum==v){
                Np t3=t2->next;
                t2->next=t3->next;
                delete t3;
                break;
            }
            t2=t2->next;
        }
        t=t->next;
    }
    for (int i = v; i <= g.vertex_num; ++i) {
        g.list[i]=g.list[i+1];
    }
}

int main() {
    while (1){
        Graph g;
        if(!initGraph(g)){
            break;
        }
        int v;
        cin>>v;
        deleteVertex(g, v);
        showGraph(g);
    }
    return 0;
}