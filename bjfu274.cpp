//bjfu274
//
#include <iostream>
#include <iomanip>
using namespace std;

const int MaxSize=20;

struct Graph{
    int **vertex;
    int v_num;
};

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

int initGraph(Graph &g){
    cin>>g.v_num;
    int arcs;
    cin>>arcs;
    if(g.v_num==0&&arcs==0){
        return 0;
    }
    g.vertex=new int*[MaxSize];
    for (int i = 0; i < MaxSize; ++i) {
        g.vertex[i]=new int[MaxSize];
        for (int j = 0; j < MaxSize; ++j) {
            g.vertex[i][j]=0;
        }
    }
    for (int i = 0; i < arcs; ++i) {
        int a,b;
        cin>>a>>b;
        g.vertex[a][b]=1;
        g.vertex[b][a]=1;
    }
    return 1;
}

void Show_2D_Array(int **a, int n){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n-1; ++j) {
            cout<<a[i][j]<<' ';
        }
        cout<<a[i][n-1]<<endl;
    }
}

void matmul(int **a, int **b, int **&res,int beg, int end){
    res = new int*[MaxSize];
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
}

void add(int **a, int **b, int **&res,int beg, int end){
    res = new int*[MaxSize];
    for (int i = 0; i < MaxSize; ++i) {
        res[i]=new int[MaxSize];
    }
    for (int i = beg; i < end; ++i) {
        for (int j = beg; j < end; ++j) {
            res[i][j]=a[i][j]+b[i][j];
        }
    }
}

void show_probability(int **p, int num){
    int n=0;
    cout<<setiosflags(ios::fixed)<<setprecision(2);
    for (int i = 1; i < num+1; ++i) {
        n=0;
        for (int j = 1; j < num+1; ++j) {
            if(p[i][j]!=0){
                n++;
            }
        }
        cout<<i<<": "<<(float)(100*n/num)<<'%'<<endl;
    }
}

int main(){
    while (1){
        Graph g;
        if(!initGraph(g)){
            break;
        }
//        initGraph(g);
        int **temp=copy(g.vertex);
        int **result=copy(g.vertex);
        for (int i = 0; i < 5; ++i) {
            matmul(temp, g.vertex ,temp, 1, g.v_num+1);
            add(result, temp, result ,1, g.v_num+1);
        }
        show_probability(result, g.v_num);
    }
    return 0;
}