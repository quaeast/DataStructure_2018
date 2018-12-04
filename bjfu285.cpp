//bjfu285
//
#include <iostream>
#include <iomanip>
using namespace std;

const int MaxSize=130;

typedef struct Graph{
    int v_num;
    int vertex[130];
    int **mat;
}Graph;

void initGraph(Graph &g, int v, int arcs){
    g.v_num=v;
    for (int i = 0; i < v; ++i) {
        char t;
        cin>>t;
        g.vertex[i]=t;
    }
    g.mat=new int*[MaxSize];
    for (int i = 0; i < MaxSize; ++i) {
        g.mat[i]=new int[MaxSize];
        for (int j = 0; j < MaxSize; ++j) {
            g.mat[i][j]=0;
        }
    }
    for (int i = 0; i < arcs; ++i) {
        char a,b;
        cin>>a>>b;
        g.mat[a][b]=1;
        g.mat[b][a]=1;
    }
}

int** copy(int **a){
    int **res;
    res = new int*[MaxSize];
    for (int i = 0; i < MaxSize; ++i) {
        res[i]=new int [MaxSize];
        for (int j = 0; j < MaxSize; ++j) {
            res[i][j]=a[i][j];
        }
    }
    return res;
}

void matmul(int **a, int **b, int **&result,int beg, int end){
    int **res = new int*[MaxSize];
    for (int i = 0; i < MaxSize; ++i) {
        res[i]=new int[MaxSize];
    }
    for (int i = beg; i < end; ++i) {
        for (int j = beg; j < end; ++j) {
            res[i][j]=0;
            for (int k = beg; k < end; ++k) {
                res[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    result = copy(res);
}


bool isLink(Graph g, char a, char b, int l){
    int **res=copy(g.mat);
    for (int i = 0; i < l-1; ++i) {
        matmul(res, g.mat, res, 0, MaxSize);
    }
    return res[a][b]&&res[b][a];
}


int main(){
    while (1){
        int a,b,c;
        cin>>a>>b>>c;
        if(a==0&&b==0){
            break;
        }
        Graph g;
        initGraph(g, a, b);
        char p1,p2;
        cin>>p1>>p2;
        if(isLink(g, p1, p2, c)){
            cout<<"YES"<<endl;
        } else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}