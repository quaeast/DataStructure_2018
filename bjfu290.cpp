//bjfu290
//
#include <iostream>
using namespace std;

typedef struct Node{
    int datum;
    int count=0;
    struct Node *L=NULL;
    struct Node *R=NULL;
}Node, *BiTree;

void insertBiSortTree(BiTree &root, int d){
    if(root==NULL){
        root = new Node;
        root->datum=d;
        return;
    }
    if(d<root->datum){
        insertBiSortTree(root->L, d);
    } else if(d>root->datum){
        insertBiSortTree(root->R, d);
    } else{
        root->count++;
    }
}

int it;
int result[100];

void showBiSortTree(BiTree root){
    if (root==NULL){
        return;
    }
    showBiSortTree(root->L);
    result[it]=root->datum;
    it++;
    showBiSortTree(root->R);
}

int itc;
int cresult[100];

void showcount(BiTree root){
    if(root==NULL){
        return;
    }
    showcount(root->L);
    cresult[itc]=root->count;
    itc++;
    showcount(root->R);
}

int main() {
    while (1){
        int n;
        cin>>n;
        if(n==0){
            break;
        }
        BiTree t=NULL;
        for (int i = 0; i < n+1; ++i) {
            int d;
            cin>>d;
            insertBiSortTree(t, d);
        }
        it=0;
        showBiSortTree(t);
        for (int j = 0; j < it-1; ++j) {
            cout<<result[j]<<' ';
        }
        cout<<result[it-1]<<endl;
        itc=0;
        showcount(t);
        for (int i = 0; i < itc-1; ++i) {
            cout<<cresult[i]<<' ';
        }
        cout<<cresult[itc-1]<<endl;
    }
    return 0;
}