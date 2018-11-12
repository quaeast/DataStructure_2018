//bjfu269
//
#include <iostream>
using namespace std;

typedef struct Node{
    char datum;
    struct Node *L;
    struct Node *R;
}Node,*BiTree;

int init(BiTree &root){
    char t;
    cin>>t;
    if(t=='0'){
        root = NULL;
        return 0;
    } else{
        root = new Node;
        root->datum=t;
        init(root->L);
        init(root->R);
    }
    return 1;
}

void PreOrderTraverse(BiTree &root){
    if(root==NULL){
        return;
    } else{
        cout<<root->datum;
        PreOrderTraverse(root->L);
        PreOrderTraverse(root->R);
    }
}

void InOrderTraverse(BiTree &root){
    if(root==NULL){
        return;
    } else{
        InOrderTraverse(root->L);
        cout<<root->datum;
        InOrderTraverse(root->R);
    }
}

void PostOrderTraverse(BiTree &root){
    if(root==NULL){
        return;
    } else{
        PostOrderTraverse(root->L);
        PostOrderTraverse(root->R);
        cout<<root->datum;
    }
}


int main() {
    while (1){
        BiTree root;
        if(init(root)==0){
            break;
        }
        PreOrderTraverse(root);
        cout<<endl;
        InOrderTraverse(root);
        cout<<endl;
        PostOrderTraverse(root);
        cout<<endl;
    }
    return 0;
}