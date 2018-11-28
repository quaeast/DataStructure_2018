//bjfu281
//
#include <iostream>
using namespace std;

const int MaxSize=100;

typedef struct Graph{
    int vertex[MaxSize];
    int arcs[MaxSize][MaxSize];
    int arc_num, vertex_num;
}Graph;

int initGraph(Graph &g){
    cin>>g.vertex_num>>g.arc_num;
    if(g.arc_num==0&&g.vertex_num==0){
        return 0;
    }
    for (int i = 1; i < g.vertex_num+1; ++i) {
        g.vertex[i]=i;
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
    for (int i = 0; i < g.vertex_num; ++i) {
        cout<<' '<<g.vertex[i+1];
    }
    cout<<endl;
    for (int i = 1; i < g.vertex_num+1; ++i) {
        cout<<g.vertex[i];
        for (int j = 1; j < g.vertex_num+1; ++j) {
            cout<<' '<<g.arcs[i][j];
        }
        cout<<endl;
    }
};

void addArc(Graph &g){
    int a,b;
    cin>>a>>b;
    g.arc_num++;
    g.arcs[a][b]=0;
    g.arcs[b][a]=0;
}

int main() {
    while (1){
        Graph g;
        if (!initGraph(g)){
            break;
        }
        addArc(g);
        showGraph(g);
    }
    return 0;
}