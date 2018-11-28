//bjfu280
//
#include <iostream>
using namespace std;

const int MaxSize=100;

typedef struct Node{
    int datum;
    struct Node *next=NULL;
}Node,*Np;

typedef struct Graph{
    int vertex_num,arc_num;
    Np list[MaxSize];
}Graph;

int initGraph(Graph &g){
    cin>>g.vertex_num>>g.arc_num;
    if(g.vertex_num==0&&g.arc_num==0){
        return 0;
    }
    for (int i = 1; i < MaxSize; ++i) {
        g.list[i]=new Node;
        g.list[i]->datum=i;
    }
    for (int i = 0; i < g.arc_num; ++i) {
        int a,b;
        cin>>a>>b;
        Np t1=new Node;
        t1->datum=a;
        t1->next=g.list[b]->next;
        g.list[b]->next=t1;
        Np t2=new Node;
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

void deleteArc(Graph g){
    int a,b;
    cin>>a>>b;
    Np t=g.list[a];
    while (1){
        if(t->next==NULL){
            break;
        }
        if(t->next->datum==b){
            Np d=t->next;
            t->next=t->next->next;
            delete d;
            break;
        }
    }
    t=g.list[b];
    while (1){
        if(t->next==NULL){
            break;
        }
        if (t->next->datum==a){
            Np d=t->next;
            t->next=t->next->next;
            delete d;
            break;
        }
    }
}

int main() {
    while (1){
        Graph g;
        if(!initGraph(g)){
            break;
        }
        deleteArc(g);
        showGraph(g);
    }
    return 0;
}