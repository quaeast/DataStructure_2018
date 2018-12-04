//bjfu273
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
    bool flag= true;
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
    for (int i = 0; i < v; ++i) {
        char c;
        cin>>c;
        g.vertexs[i]=c;
    }
    for (int i = 0; i < arc; ++i) {
        char a,b;
        cin>>a>>b;
        int l;
        cin>>l;
        g.mat[a][b]=l;
//        g.mat[b][a]=l;
    }
}




void dijsktra(Graph g, Node *ans, int tar){              //ans begin from 1
    ans[0].length=1e6;
    Node cur[MaxSize];

    //init
    for (int i = 0; i < MaxSize; ++i) {
        if(tar==i){
            cur[i].flag= false;
        }
        cur[i].length=g.mat[tar][i];
        cur[i].path[0]=tar;
        if(g.mat[tar][i]==1e6){
            cur[i].node_num=0;
        } else{
            cur[i].node_num=1;
            cur[i].path[1]=i;
        }
    }
    for (int i = 0; i < g.vertex_num-1; ++i) {
        //renew
        if(i>0){
            for (int j = 0; j < MaxSize; ++j) {
                if(cur[j].flag == false){
                    continue;
                }
                int t=ans[i].path[ans[i].node_num];
                if(ans[i].length+g.mat[t][j]<cur[j].length){
                    cur[j]=ans[i];
                    int temp=++cur[j].node_num;
                    cur[j].path[temp]=j;
                    cur[j].length+=g.mat[t][j];
                }
            }
        }
        //select
        Node minNode=cur[0];
        int minpos=0;
        for (int j = 0; j < MaxSize; ++j) {
            if(cur[j].flag == false){
                continue;
            }
            if(cur[j].length<minNode.length){
                minpos=j;
                minNode=cur[j];
            }
        }
        ans[i+1]=minNode;
        cur[minpos].flag = false;
//        cout<<ans[i+1].length<<' '<<ans[i+1].node_num<<endl;
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
        char be,end;
        cin>>be>>end;
        Node ans[100];
        dijsktra(g, ans, (int) be);
        int end_pos;
        for (int j = 0; j < g.vertex_num; ++j) {
            if(ans[j].path[ans[j].node_num]==end){
                end_pos=j;
            }
        }
        cout<<ans[end_pos].length<<endl;
        for (int i = 0; i < ans[end_pos].node_num; ++i) {
            cout<<(char)ans[end_pos].path[i]<<' ';
        }
        cout<<(char)ans[end_pos].path[ans[end_pos].node_num]<<'\n';
    }
    return 0;
}