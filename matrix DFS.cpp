//matrix DFS
//
#include <iostream>
using namespace std;

const int MaxSize=100;

typedef struct {
    int vertex[MaxSize];                    //begin 1
    int arcs[MaxSize][MaxSize];             //begin 1
    int vex_num, arc_num;
}Graph;

int initGraph(Graph &g){
    cin>>g.vex_num>>g.arc_num;
    if(g.vex_num==0&&g.arc_num==0){
        return 0;
    }
    for (int i = 0; i < g.vex_num; ++i) {
        g.vertex[i+1]=i+1;
    }
    for (int i = 0; i < MaxSize; ++i) {
        for (int j = 0; j < MaxSize; ++j) {
            g.arcs[i][j]=0;
        }
    }
    for (int i = 0; i < g.arc_num; ++i) {
        int a,b;
        cin>>a>>b;
        g.arcs[a][b]=1;
        g.arcs[b][a]=1;
    }
    return 1;
}

void showGraph(Graph g){
    cout<<0;
    for (int i = 1; i < g.vex_num+1; ++i) {
        cout<<' '<<g.vertex[i];
    }
    cout<<endl;
    for (int i = 1; i < g.vex_num+1; ++i) {
        cout<<g.vertex[i];
        for (int j = 1; j < g.vex_num+1; ++j) {
            cout<<' '<<g.arcs[i][j];
        }
        cout<<endl;
    }
}

void addVertex(Graph &g, int v){
    g.vex_num++;
    g.vertex[g.vex_num]=v;
}

int visited[MaxSize+2];  //memset 0 before use

void DFS(Graph g, int v){
    cout<<v;
    visited[v]=1;
    for (int i = 1; i < g.vex_num+2; ++i) {
        if((g.arcs[v][i]!=0)&&(visited[i]==0)){
            DFS(g, i);
        }
    }
}

int main() {
    while (1){
        Graph g;
        if(!initGraph(g)){
            break;
        }
//        showGraph(g);
        for (int i = 0; i < MaxSize+2; ++i) {
            visited[i]=0;
        }
        int b;
        cin>>b;
        DFS(g, b);
    }
    return 0;
}