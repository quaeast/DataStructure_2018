//bjfu282
//
#include <iostream>
using namespace std;

const int MaxNum=100;

typedef struct Node{
    int datum;
    struct Node *next=NULL;
}Node, *Np;

typedef struct Graph{
    int arc_num,vertex_num;
    Np list[MaxNum];
}Graph;

void endInsert(Np &head, int a){
    Np t = head;
    while (1){
        if(t->next==NULL){
            Np temp=new Node;
            temp->datum=a;
            t->next=temp;
            break;
        }
        t=t->next;
    }
}

int initGraph(Graph &g){
    cin>>g.vertex_num>>g.arc_num;
    if(g.vertex_num==0&&g.arc_num==0){
        return 0;
    }
    for (int i = 0; i < MaxNum; ++i) {
        g.list[i]=new Node;
        g.list[i]->datum=i;
    }
    for (int i = 1; i < g.arc_num+1; ++i) {
        int a,b;
        cin>>a>>b;
        endInsert(g.list[a], b);
        endInsert(g.list[b], a);
    }
    return 1;
}

void showGraph(Graph g){
    for (int i = 1; i < g.vertex_num; ++i) {
        Np t=g.list[i];
        while (1){
            if(t->next==NULL){
                break;
            }
            cout<<t->datum<<' ';
            t=t->next;
        }
        cout<<t->datum<<endl;
    }
};

int visited[MaxNum];
int result[MaxNum];
int num;
void DFS(Graph g, int v){
    result[num]=v;
    num++;
    visited[v]=1;
    Np p=g.list[v]->next;
    while (p!=NULL){
        if(visited[p->datum]==0){
            DFS(g, p->datum);
        }
        p=p->next;
    }
}

int main() {
    while (1){
        Graph g;
        if(initGraph(g)==0){
            break;
        }
//        showGraph(g);
        int b;
        cin>>b;
        for (int i = 0; i < MaxNum; ++i) {
            visited[i]=0;
            result[i]=0;
        }
        num=0;
        DFS(g, b);
        for (int i = 0; i < num-1; ++i) {
            cout<<result[i]<<' ';
        }
        cout<<result[num-1]<<endl;
    }
    return 0;
}