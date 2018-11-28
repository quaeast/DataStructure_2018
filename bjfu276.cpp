//bjfu276
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

int main() {
    while (1){
        Graph g;
        if(!initGraph(g)){
            break;
        }
        int v;
        cin>>v;
        addVertex(g, v);
        showGraph(g);
    }
    return 0;
}