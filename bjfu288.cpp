//bjfu288
//
#include <iostream>
using namespace std;

typedef struct Node{
    char datum;
    struct Node *L;
    struct Node *R;
}Node,*BiTree;

int initBiTree(BiTree &root){
    char c;
    cin>>c;
    if(c=='#'){
        root=NULL;
        return 0;
    } else{
        root = new Node;
        root->datum=c;
        initBiTree(root->L);
        initBiTree(root->R);
        return 1;
    }
}

void PreOrder(BiTree root){
    if(root==NULL){
        return;
    }
    cout<<root->datum;
    PreOrder(root->L);
    PreOrder(root->R);
}

int isSortTree(BiTree root){
    if(root==NULL){
        return 1;
    }
    bool left=root->L==NULL||root->L->datum<=root->datum;
    bool right=root->R==NULL||root->R->datum>=root->datum;
    if(left&&right){
        return isSortTree(root->L)&&isSortTree(root->R);
    } else{
        return 0;
    }
}

int main() {
    while (1){
        BiTree t;
        if(!initBiTree(t)){
            break;
        }
        PreOrder(t);
        if(isSortTree(t)){
            cout<<"YES"<<endl;
        } else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}