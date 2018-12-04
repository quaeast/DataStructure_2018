//bjfu283
//
#include <iostream>
using namespace std;

const int MaxSize = 150;

typedef struct Graph{
    int vertexs[MaxSize];
    int **mat;
    int vertex_num;
}Graph;

typedef struct Node{
    bool flag = true;
    int path[MaxSize];
    int node_num=0;
    int length=0;
}Node;

void initGraph(Graph &g, int v, int arc){
    g.vertex_num=v;
    g.mat = new int*[MaxSize];
    for (int i = 0; i < MaxSize; ++i) {
        g.mat[i]=new int[MaxSize];
        for (int j = 0; j < MaxSize; ++j) {
            g.mat[i][j]=1e6;
        }
    }
    for (int i = 0; i < arc; ++i) {
        int a,b;
        cin>>a>>b;
        int l;
        cin>>l;
        g.mat[a][b]=l;
        g.mat[b][a]=l;
    }
}

void Dijsktra(Graph g, Node *ans, int tar){
    //init
    Node cur[MaxSize];
    int v=g.vertex_num;
    cur[tar].flag= false;
    for (int i = 1; i <= v; ++i) {
        cur[i].length=g.mat[tar][i];
        cur[i].path[0]=tar;
        cur[i].node_num=0;
        if(g.mat[tar][i]!=1e6){
            cur[i].path[1]=i;
            cur[i].node_num++;
        }
    }
    ans[0].length=1e6;
    for (int i = 1; i < v; ++i) {
        //select
        Node min=ans[0];
        int minpos=-1;
        for (int j = 1; j <= v; ++j) {
            if(!cur[j].flag){
                continue;
            }
            if(cur[j].length<min.length){
                min=cur[j];
                minpos=j;
            }
        }
        ans[i]=min;
        cur[minpos].flag = false;
        //renew
        for (int j = 1; j <= v; ++j) {
            if(!cur[j].flag){
                continue;
            }
            int point=ans[i].path[ans[i].node_num];
            if(cur[j].length>ans[i].length+g.mat[point][j]){
                cur[j]=ans[i];
                cur[j].length+=g.mat[point][j];
                cur[j].node_num++;
                cur[j].path[cur[j].node_num]=j;
            }
        }
    }
}

int main() {
    while (1){
        int v,a;
        cin>>v>>a;
        if(v==0&&a==0){
            break;
        }
        Graph g;
        initGraph(g, v, a);
        Node ans[MaxSize];
        int beg;
        cin>>beg;
        Dijsktra(g, ans , beg);
        int pos;
        int min=1e6;
        for(int i=1; i<v; ++i){
            if(ans[i].length<min){
                pos=i;
            }
        }
        cout<<ans[pos].path[ans[pos].node_num]<<endl<<ans[pos].length<<endl;
    }
    return 0;
}