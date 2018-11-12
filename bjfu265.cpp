//bjfu265
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
        cout<<root->datum;
        PreOrderTraverse(root->R);
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
    }
    return 0;
}